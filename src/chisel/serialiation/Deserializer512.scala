package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._


class Deserializer512() extends Module{
	val io = IO(new Bundle{
        val meta_in             = Flipped(Decoupled(new SerOutMeta))
        val data_in             = Flipped(Decoupled(AXIS(512)))
		val writer_req	        = (Decoupled(new WriteReq))
		val class_meta_req	    = (Decoupled(new ClassMetaReq))
		val class_meta_rsp	    = Flipped(Decoupled(new ClassMetaRsp))
	})

    Collector.fire(io.meta_in)
    Collector.fire(io.data_in)
    Collector.fire(io.writer_req)

    val meta_in_fifo = XQueue(new SerOutMeta(), entries=16)
    val data_in_fifo = XQueue(AXIS(512), entries=1024)
    val class_meta_rsp_fifo = XQueue(new ClassMetaRsp(), entries=8)
    
    val data_decoder = Module(new VarintDecode)
    val varint_data = WireInit(VecInit(Seq.fill(10)(0.U(8.W))))

    io.meta_in                          <> meta_in_fifo.io.in
    io.data_in                          <> data_in_fifo.io.in
    io.class_meta_rsp                    <> class_meta_rsp_fifo.io.in


    val meta_reg = RegInit(0.U.asTypeOf(new SerOutMeta()))

    val NUM_BITS_FOR_STATES = 5
    val sVarint = 0.U(NUM_BITS_FOR_STATES.W)
    val s64bit  = 1.U(NUM_BITS_FOR_STATES.W)
    val sLengthDelim  = 2.U(NUM_BITS_FOR_STATES.W)
    val sStartGroup  = 3.U(NUM_BITS_FOR_STATES.W)
    val sEndGroup  = 4.U(NUM_BITS_FOR_STATES.W)
    val s32bit  = 5.U(NUM_BITS_FOR_STATES.W)
    val sVar64bit  = 6.U(NUM_BITS_FOR_STATES.W)

    val sReadDesc  = 7.U(NUM_BITS_FOR_STATES.W)
    val sReadData  = 8.U(NUM_BITS_FOR_STATES.W)
    val sReadTag  = 9.U(NUM_BITS_FOR_STATES.W)
    val sWriteMeta  = 10.U(NUM_BITS_FOR_STATES.W)
    val sStringMoveDataFirst  = 13.U(NUM_BITS_FOR_STATES.W)
    val sStringMoveData  = 11.U(NUM_BITS_FOR_STATES.W)
    val sEnd  = 12.U(NUM_BITS_FOR_STATES.W)
    val sJudgeField = 14.U(NUM_BITS_FOR_STATES.W)
    val sLengthDelimJudge = 15.U(NUM_BITS_FOR_STATES.W)
    val sVarTag = 16.U(NUM_BITS_FOR_STATES.W)
    val sVarintOut = 17.U(NUM_BITS_FOR_STATES.W)
    val sLengthDelimOut = 18.U(NUM_BITS_FOR_STATES.W)
    val sLengthDelimRepeat = 19.U(NUM_BITS_FOR_STATES.W)


	val field_stack = Reg(Vec(13, new ClassMetaRsp()))
    val msg_remain_length = RegInit(VecInit(Seq.fill(13)(0.U(32.W))))

    val current_base_addr = RegInit(UInt(32.W),0.U)
    val stack_num   = RegInit(UInt(4.W),0.U)

    val last = RegInit(UInt(1.W),0.U)


    
    val field_length = RegInit(UInt(32.W),0.U)
    val field_length_short = RegInit(UInt(6.W),0.U)
    val string_length = RegInit(UInt(32.W),0.U)
    val re_str_length = RegInit(UInt(32.W),0.U)
    val is_repeated = RegInit(false.B)
    val repeat_continue = RegInit(false.B)

    // val data_tmp            = RegInit(UInt(512.W),0.U) 
    // val data_pre            = RegInit(UInt(512.W),0.U) 
    val data_tmp            = RegInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val data_pre            = RegInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val data_wire           = WireInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val write_tmp           = WireInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val has_pre             = RegInit(false.B)
    val is_host             = RegInit(false.B)
    val data_result         = WireInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val field_num           = RegInit(UInt(6.W),0.U)
    val tag                 = RegInit(UInt(3.W),0.U)
    val total_remain_length = RegInit(UInt(32.W),0.U)
    val remain_bytes        = RegInit(UInt(7.W),0.U)
    val varint_out_len      = RegInit(UInt(7.W),0.U)
    val varint_result       = RegInit(UInt(64.W),0.U)
    val c_sub_metadata      = RegInit(0.U.asTypeOf(new SubMetaState))
    val c_msg_remain_length = RegInit(UInt(20.W),0.U)

    val data_fifo_ready     = Wire(UInt(1.W))


    data_fifo_ready             := 0.U

    data_in_fifo.io.out.ready               := data_fifo_ready;

    data_decoder.io.inputRawData := varint_data.asUInt
    

	val state                   = RegInit(sReadDesc)

    
    meta_in_fifo.io.out.ready               := (state === sReadDesc) & io.class_meta_req.ready
    class_meta_rsp_fifo.io.out.ready        := state === sWriteMeta

    ToZero(io.class_meta_req.valid)
    ToZero(io.class_meta_req.bits)
    ToZero(io.writer_req.valid)
    ToZero(io.writer_req.bits)

    io.writer_req.bits.data     := write_tmp.asUInt

    switch(state){
        is(sReadDesc){
            when(meta_in_fifo.io.out.fire()){
                meta_reg                    := meta_in_fifo.io.out.bits
                total_remain_length         := meta_in_fifo.io.out.bits.length
                current_base_addr           := 0x1000.U
                io.class_meta_req.valid          := 1.U
                io.class_meta_req.bits.class_id  := meta_in_fifo.io.out.bits.class_id
                state                       := sWriteMeta
            }
        }
        is(sWriteMeta){
            when(class_meta_rsp_fifo.io.out.fire()){
                field_stack(stack_num)      := class_meta_rsp_fifo.io.out.bits
                // msg_remain_length(stack_num):= class_meta_rsp_fifo.io.out.bits.class_meta.class_length
                current_base_addr           := current_base_addr + class_meta_rsp_fifo.io.out.bits.class_meta.class_length
                state                       := sVarTag
            }
        }
        is(sVarTag){
            when((c_msg_remain_length === 0.U)&&(stack_num =/= 0.U)){
                stack_num                   := stack_num - 1.U
                c_msg_remain_length         := msg_remain_length(stack_num - 1.U)
                // msg_remain_length(stack_num):= c_msg_remain_length
                total_remain_length         := total_remain_length
                state                       := sVarTag
            }.elsewhen(remain_bytes >= 10.U){
                for(i<- 0 until 10){
				    varint_data(i) := data_tmp(i)
			    }    
                state                       := sReadTag         
            }.elsewhen(has_pre){
                for(i<- 0 until 10){
                    when(i.U < remain_bytes){
                        varint_data(i) := data_tmp(i)
                    }.otherwise{
                        varint_data(i) := data_pre(i.U - remain_bytes)
                    }   
			    }              
                state                       := sReadTag
            }.otherwise{
                
                when(last === 1.U){
                    state                   := sReadTag
                    has_pre                 := true.B
                    for(i<- 0 until 10){
                        when(i.U < remain_bytes){
                            varint_data(i) := data_tmp(i)
                        }.otherwise{
                            varint_data(i) := 0.U
                        }   
                    }   
                    for(i<- 0 until 64){
                        data_pre(i) := 0.U
                    }
                }.otherwise{
                    data_fifo_ready             := 1.U
                    when(data_in_fifo.io.out.fire()){
                        last                    := data_in_fifo.io.out.bits.last
                        state                   := sReadTag
                        has_pre                 := true.B
                        for(i<- 0 until 10){
                            when(i.U < remain_bytes){
                                varint_data(i) := data_tmp(i)
                            }.otherwise{
                                varint_data(i) := (data_in_fifo.io.out.bits.data << (remain_bytes*8.U))(i*8+7,i*8)
                            }   
                        }   
                        for(i<- 0 until 64){
                            data_pre(i) := data_in_fifo.io.out.bits.data(i*8+7,i*8)
                        }                           
                    }.otherwise{
                        c_msg_remain_length     := c_msg_remain_length
                        total_remain_length     := total_remain_length
                        state                   := sVarTag
                    }                    
                }
            }            
            varint_out_len                  := data_decoder.io.consumedLenBytes
            tag                             := data_decoder.io.outputData & 7.U
            field_num                       := data_decoder.io.outputData >> 3                
        }
        is(sReadTag){
            c_msg_remain_length         := c_msg_remain_length - varint_out_len
            total_remain_length         := total_remain_length - varint_out_len            
            when(remain_bytes >= varint_out_len){
                remain_bytes                := remain_bytes - varint_out_len
                for(i<- 0 until 64){
				    data_tmp(i) := data_tmp((i.U + varint_out_len)%64.U)
			    }     
                state                       := sJudgeField         
            }.elsewhen(has_pre){             
                state                       := sJudgeField
                remain_bytes                := 64.U + remain_bytes - varint_out_len
                for(i<- 0 until 64){
                    data_tmp(i) := data_pre(i.U - remain_bytes + varint_out_len)
                }                     
                has_pre                 := false.B
            }                          
        }
        is(sJudgeField){
            c_sub_metadata                  := field_stack(stack_num).class_meta.field_type(field_num)
            when(field_stack(stack_num).class_meta.field_type(field_num).is_repeated === true.B){
                state                       := sLengthDelim
            }.otherwise{
                state                       := tag
            }            
        }
        is(sVarint){
            varint_result                   := data_decoder.io.outputData 
            varint_out_len                  := data_decoder.io.consumedLenBytes                
            when(remain_bytes >= 10.U){
                for(i<- 0 until 10){
				    varint_data(i) := data_tmp(i)
			    }            
                state                       := sVarintOut                   
            }.elsewhen(has_pre){
                for(i<- 0 until 10){
                    when(i.U < remain_bytes){
                        varint_data(i) := data_tmp(i)
                    }.otherwise{
                        varint_data(i) := data_pre(i.U - remain_bytes)
                    }   
			    }    
                state                       := sVarintOut              
            }.otherwise{
                when(last === 1.U){
                    state                   := sVarintOut
                    has_pre                 := true.B
                    for(i<- 0 until 10){
                        when(i.U < remain_bytes){
                            varint_data(i) := data_tmp(i)
                        }.otherwise{
                            varint_data(i) := 0.U
                        }   
                    }   
                    for(i<- 0 until 64){
                        data_pre(i) := 0.U
                    }
                }.otherwise{
                    data_fifo_ready             := 1.U
                    when(data_in_fifo.io.out.fire()){
                        last                    := data_in_fifo.io.out.bits.last
                        state                       := sVarintOut 
                        for(i<- 0 until 64){
                            data_wire(i) := data_in_fifo.io.out.bits.data(i*8+7,i*8)
                        }                     
                        for(i<- 0 until 10){
                            when(i.U < remain_bytes){
                                varint_data(i) := data_tmp(i)
                            }.otherwise{
                                varint_data(i) := data_wire(i.U-remain_bytes)
                            }   
                        }  
                        has_pre                 := true.B 
                        for(i<- 0 until 64){
                            data_pre(i) := data_in_fifo.io.out.bits.data(i*8+7,i*8)
                        }                    
                    }.otherwise{
                        state                       := sVarint
                    }
                }

            }
        }
        is(sVarintOut){
            when(io.writer_req.ready){
                io.writer_req.valid             := 1.U

                io.writer_req.bits.is_host      := c_sub_metadata.is_host
                c_msg_remain_length             := c_msg_remain_length - varint_out_len 
                when(PROTO_TYPES.detailedTypeToCppSizeLog2(c_sub_metadata.field_type) === 2.U){
                    io.writer_req.bits.length   := 4.U                     
                }.otherwise{
                    io.writer_req.bits.length   := 8.U
                }
                when(total_remain_length === varint_out_len){
                    io.writer_req.bits.done     := true.B
                    state                       := sEnd
                }.elsewhen(is_repeated && (string_length > varint_out_len)){
                    state                       := sVarint
                }.otherwise{
                    state                       := sVarTag
                }      
                when(c_msg_remain_length === varint_out_len){
                    // msg_remain_length(stack_num):= c_msg_remain_length
                    stack_num                   := stack_num - 1.U
                    c_msg_remain_length         := msg_remain_length(stack_num - 1.U)
                }
                for(i<- 0 until 8){
                    write_tmp(i) := varint_result(i*8+7,i*8)
                }                            
                total_remain_length             := total_remain_length - varint_out_len
                when(remain_bytes >= varint_out_len){               
                    remain_bytes                := remain_bytes - varint_out_len
                    for(i<- 0 until 64){
                        data_tmp(i) := data_tmp((i.U + varint_out_len)%64.U)
                    }                     
                }.otherwise{
                    remain_bytes            := 64.U + remain_bytes - varint_out_len
                    has_pre                 := false.B
                    for(i<- 0 until 64){
                        data_tmp(i) := data_pre(i.U - remain_bytes + varint_out_len)
                    }
                }
            }
        }        


        is(s64bit){
            when(io.writer_req.ready){
                io.writer_req.valid             := 1.U
                io.writer_req.bits.length       := 8.U
                io.writer_req.bits.is_host      := c_sub_metadata.is_host
                c_msg_remain_length             := c_msg_remain_length - 8.U                

                when(total_remain_length === 8.U){
                    io.writer_req.bits.done     := true.B
                    state                       := sEnd
                }.elsewhen(is_repeated && (string_length > 8.U)){
                    state                       := sVarint
                }.otherwise{
                    state                       := sVarTag
                }          
                when(c_msg_remain_length === 8.U){
                    // msg_remain_length(stack_num):= c_msg_remain_length
                    stack_num                   := stack_num - 1.U
                    c_msg_remain_length         := msg_remain_length(stack_num - 1.U)
                }                       
                total_remain_length             := total_remain_length - 8.U
                when(remain_bytes >= 8.U){
                    for(i<- 0 until 64){
                        write_tmp(i) := data_tmp(i)
                    }                 
                    remain_bytes                := remain_bytes - 8.U
                    for(i<- 0 until 64){
                        data_tmp(i) := data_tmp((i + 8)%64)
                    }                 
                }.elsewhen(has_pre){
                    for(i<- 0 until 64){
                        when(i.U < remain_bytes){
                            write_tmp(i) := data_tmp(i)
                        }.otherwise{
                            write_tmp(i) := data_pre(i.U - remain_bytes)
                        }   
                    }                 
                    remain_bytes                := 64.U + remain_bytes - 8.U
                    for(i<- 0 until 64){
                        data_tmp(i) := data_pre(i.U + remain_bytes - 8.U)
                    }                 
                    has_pre                     := false.B
                }.otherwise{
                    data_fifo_ready             := 1.U
                    when(data_in_fifo.io.out.fire()){
                        last                    := data_in_fifo.io.out.bits.last
                        remain_bytes                := 64.U + remain_bytes - 8.U
                        for(i<- 0 until 64){
                            data_tmp(i) := (data_in_fifo.io.out.bits.data >> ((remain_bytes - 8.U)*8.U))(i*8+7,i*8)
                        }                      
                    }.otherwise{
                        io.writer_req.valid         := 0.U
                        c_msg_remain_length         := c_msg_remain_length
                        total_remain_length         := total_remain_length
                        stack_num                   := stack_num
                        state                       := s64bit
                    }
                }
            }
        }
        is(s32bit){
            when(io.writer_req.ready){
                io.writer_req.valid             := 1.U
                io.writer_req.bits.length       := 4.U
                io.writer_req.bits.is_host      := c_sub_metadata.is_host
                c_msg_remain_length             := c_msg_remain_length - 4.U               

                when(total_remain_length === 4.U){
                    io.writer_req.bits.done     := true.B
                    state                       := sEnd
                }.elsewhen(is_repeated && (string_length > 4.U)){
                    state                       := sVarint
                }.otherwise{
                    state                       := sVarTag
                }    
                when(c_msg_remain_length === 4.U){
                    // msg_remain_length(stack_num):= c_msg_remain_length
                    c_msg_remain_length         := msg_remain_length(stack_num - 1.U)
                    stack_num                   := stack_num - 1.U
                }                             
                total_remain_length             := total_remain_length - 4.U
                when(remain_bytes >= 4.U){
                    for(i<- 0 until 64){
                        write_tmp(i) := data_tmp(i)
                    }                 
                    remain_bytes                := remain_bytes - 4.U
                    for(i<- 0 until 64){
                        data_tmp(i) := data_tmp((i + 4)%64)
                    }                 
                }.elsewhen(has_pre){
                    for(i<- 0 until 64){
                        when(i.U < remain_bytes){
                            write_tmp(i) := data_tmp(i)
                        }.otherwise{
                            write_tmp(i) := data_pre(i.U - remain_bytes)
                        }   
                    }                
                    remain_bytes                := 64.U + remain_bytes - 4.U
                    for(i<- 0 until 64){
                        data_tmp(i) := data_pre(i.U + remain_bytes - 4.U)
                    }                
                    has_pre                     := false.B
                }.otherwise{
                    data_fifo_ready             := 1.U
                    when(data_in_fifo.io.out.fire()){
                        last                    := data_in_fifo.io.out.bits.last      
                        remain_bytes                := 64.U + remain_bytes - 4.U
                        for(i<- 0 until 64){
                            data_tmp(i) := (data_in_fifo.io.out.bits.data >> ((remain_bytes - 4.U)*8.U))(i*8+7,i*8)
                        }                     
                    }.otherwise{
                        io.writer_req.valid         := 0.U
                        c_msg_remain_length         := c_msg_remain_length
                        total_remain_length         := total_remain_length
                        stack_num                   := stack_num
                        state                       := s64bit
                    }
                }
            }
        }



        is(sLengthDelim){
            when(remain_bytes >= 10.U){
                for(i<- 0 until 10){
				    varint_data(i) := data_tmp(i)
			    }
                state                       := sLengthDelimOut
            }.elsewhen(has_pre){
                for(i<- 0 until 10){
                    when(i.U < remain_bytes){
                        varint_data(i) := data_tmp(i)
                    }.otherwise{
                        varint_data(i) := data_pre(i.U - remain_bytes)
                    }   
			    }              
                state                       := sLengthDelimOut
            }.otherwise{
                when(last === 1.U){
                    state                   := sLengthDelimOut
                    has_pre                 := true.B
                    for(i<- 0 until 10){
                        when(i.U < remain_bytes){
                            varint_data(i) := data_tmp(i)
                        }.otherwise{
                            varint_data(i) := 0.U
                        }   
                    }   
                    for(i<- 0 until 64){
                        data_pre(i) := 0.U
                    }
                }.otherwise{
                    data_fifo_ready             := 1.U
                    when(data_in_fifo.io.out.fire()){
                        last                    := data_in_fifo.io.out.bits.last
                        state                   := sLengthDelimOut
                        for(i<- 0 until 64){
                            data_wire(i) := data_in_fifo.io.out.bits.data(i*8+7,i*8)
                        }                     
                        for(i<- 0 until 10){
                            when(i.U < remain_bytes){
                                varint_data(i) := data_tmp(i)
                            }.otherwise{
                                varint_data(i) := data_wire(i.U-remain_bytes)
                            }   
                        }
                        has_pre                 := true.B
                        for(i<- 0 until 64){
                            data_pre(i) := data_in_fifo.io.out.bits.data(i*8+7,i*8)
                        } 
                        state                       := sLengthDelimOut
                    }.otherwise{
                        state                   := sLengthDelim
                    }
                }

            }            
            field_length                    := data_decoder.io.outputData  
            varint_out_len                  := data_decoder.io.consumedLenBytes
        }
        is(sLengthDelimOut){
            when(remain_bytes >= varint_out_len){
                remain_bytes                := remain_bytes - varint_out_len
                for(i<- 0 until 64){
				    data_tmp(i) := data_tmp((i.U + varint_out_len)%64.U)
			    }                 
            }.otherwise{
                remain_bytes            := 64.U + remain_bytes - varint_out_len
                for(i<- 0 until 64){
                    data_tmp(i) := data_pre(i.U - remain_bytes + varint_out_len)
                }
                has_pre                 := false.B
            }            
            when(is_repeated){
                state                   := sLengthDelimRepeat
                re_str_length           := re_str_length - varint_out_len
            }.otherwise{
                state                   := sLengthDelimJudge
                total_remain_length             := total_remain_length - varint_out_len
                c_msg_remain_length             := c_msg_remain_length - varint_out_len                
            }

        }

        is(sLengthDelimJudge){
            field_length_short                      := field_length(5,0)
            when(c_sub_metadata.is_repeated === true.B){
                when((c_sub_metadata.field_type === PROTO_TYPES.TYPE_STRING) ||(c_sub_metadata.field_type === PROTO_TYPES.TYPE_BYTES)) {
                    c_msg_remain_length             := c_msg_remain_length - field_length
                    re_str_length                   := field_length
                    state                           := sLengthDelim
                    is_repeated                     := true.B
                    total_remain_length             := total_remain_length - field_length
                }.otherwise{
                    c_msg_remain_length             := c_msg_remain_length - field_length
                    state                           := tag
                    string_length                   := field_length
                    is_repeated                     := true.B
                    total_remain_length             := total_remain_length
                }
            }.otherwise{
                when((c_sub_metadata.field_type === PROTO_TYPES.TYPE_STRING) || (c_sub_metadata.field_type === PROTO_TYPES.TYPE_BYTES)){
                    state                           := sStringMoveDataFirst
                    c_msg_remain_length             := c_msg_remain_length - field_length
                    current_base_addr               := current_base_addr + field_length//fix
                    string_length                   := field_length
                    total_remain_length             := total_remain_length - field_length
                }.elsewhen(c_sub_metadata.field_type === PROTO_TYPES.TYPE_MESSAGE){
                    state                           := sWriteMeta
                    msg_remain_length(stack_num + 1.U)    := field_length//fix
                    msg_remain_length(stack_num)    := c_msg_remain_length - field_length
                    c_msg_remain_length             := field_length
                    stack_num                       := stack_num + 1.U
                    io.class_meta_req.valid          := 1.U
                    io.class_meta_req.bits.class_id  := c_sub_metadata.sub_class_id
                    total_remain_length             := total_remain_length
                }.otherwise{

                }
            }            
        }    
        is(sLengthDelimRepeat){
            field_length_short                      := field_length(5,0)
            state                                   := sStringMoveDataFirst
            re_str_length                           := re_str_length - field_length
            when((re_str_length - field_length) > 0.U){
                repeat_continue                     := true.B
            }.otherwise{
                is_repeated                         := false.B
                repeat_continue                     := false.B
            }
            string_length                           := field_length
       
        }             
        is(sStringMoveDataFirst){
            when(io.writer_req.ready){
                io.writer_req.valid             := 1.U
                io.writer_req.bits.is_host      := c_sub_metadata.is_host
                io.writer_req.bits.length   := field_length            
                when(remain_bytes >= field_length){
                    for(i<- 0 until 64){
                        write_tmp(i) := data_tmp(i)
                        data_tmp(i)             := data_tmp(i.U + field_length_short)
                    }                
                    remain_bytes                := remain_bytes - field_length_short
                    // io.writer_req.bits.length   := field_length
                    when(total_remain_length === 0.U){
                        io.writer_req.bits.done     := true.B
                        state                       := sEnd
                    }.elsewhen(repeat_continue){
                        state                       := sLengthDelim
                    }.otherwise{
                        state                       := sVarTag
                    }
                }.elsewhen(remain_bytes === 0.U){
                    when(has_pre){
                        when(field_length <= 64.U){
                            // io.writer_req.bits.length   := field_length
                            for(i<- 0 until 64){
                                write_tmp(i) := data_pre(i)
                                data_tmp(i)             := data_pre(i.U + field_length_short)
                            }                         
                            remain_bytes                := 64.U - field_length_short
                            has_pre                     := false.B
                            when(total_remain_length === 0.U){
                                io.writer_req.bits.done     := true.B
                                state                       := sEnd
                            }.elsewhen(repeat_continue){
                                state                       := sLengthDelim
                            }.otherwise{
                                state                       := sVarTag
                            }
                        }.otherwise{
                            for(i<- 0 until 64){
                                write_tmp(i)            := data_pre(i)
                            }                         
                            // io.writer_req.bits.length   := 64.U
                            state                       := sStringMoveData 
                            string_length               := string_length - 64.U        
                        }
                    }.otherwise{
                        io.writer_req.valid             := 0.U
                        state                       := sStringMoveData
                    }
                }.otherwise{
                    when(has_pre){
                        // io.writer_req.bits.length   := remain_bytes
                        for(i<- 0 until 64){
                            write_tmp(i)            := data_tmp(i)
                            data_tmp(i)             := data_pre(i)
                        }                    
                        remain_bytes                := 64.U
                        has_pre                     := false.B
                        state                       := sStringMoveData
                        string_length               := string_length - remain_bytes
                    }.otherwise{
                        for(i<- 0 until 64){
                            write_tmp(i)   := data_tmp(i)
                        }                    
                        // io.writer_req.bits.length   := remain_bytes
                        remain_bytes                := 0.U
                        state                       := sStringMoveData
                        string_length               := string_length - remain_bytes         
                    }
                }  
            }            
        }
        is(sStringMoveData){
            when(io.writer_req.ready){
                io.writer_req.valid             := 1.U
                io.writer_req.bits.is_host      := c_sub_metadata.is_host            

                when(remain_bytes === 0.U){
                    data_fifo_ready             := 1.U
                    when(data_in_fifo.io.out.fire()){
                        last                    := data_in_fifo.io.out.bits.last
                        for(i<- 0 until 64){
                            write_tmp(i) := data_in_fifo.io.out.bits.data(i*8+7,i*8)
                        }                      
                        when(string_length>64.U){
                            io.writer_req.bits.length   := 64.U
                            string_length                := string_length - 64.U
                        }.otherwise{
                            for(i<- 0 until 64){
                                data_tmp(i) := (data_in_fifo.io.out.bits.data >> (string_length*8.U))(i*8+7,i*8)
                            }                        
                            remain_bytes                := 64.U - string_length
                            io.writer_req.bits.length   := string_length
                            when(total_remain_length === 0.U){
                                io.writer_req.bits.done     := true.B
                                state                   := sEnd
                            }.elsewhen(repeat_continue){
                                state                       := sLengthDelim
                            }.otherwise{
                                state                   := sVarTag
                            }
                            when(c_msg_remain_length === 0.U){
                                // msg_remain_length(stack_num):= c_msg_remain_length
                                stack_num                   := stack_num - 1.U
                            } 
                        }
                    }.otherwise{
                        state                   := sStringMoveData
                    }
                }.otherwise{
                    when(string_length>64.U){
                        for(i<- 0 until 64){
                            write_tmp(i)   := data_tmp(i)
                        }                    
                        io.writer_req.bits.length   := 64.U
                        string_length                := string_length - 64.U
                        state                   := sStringMoveData
                        remain_bytes                := 0.U
                    }.otherwise{
                        for(i<- 0 until 64){
                            write_tmp(i)   := data_tmp(i)
                        }                    
                        io.writer_req.bits.length   := string_length
                        remain_bytes                := remain_bytes - string_length
                        when(total_remain_length === 0.U){
                            io.writer_req.bits.done     := true.B
                            state                   := sEnd
                        }.elsewhen(repeat_continue){
                            state                       := sLengthDelim
                        }.otherwise{
                            state                   := sVarTag
                        }
                        when(c_msg_remain_length === 0.U){
                            // msg_remain_length(stack_num):= c_msg_remain_length
                            stack_num                   := stack_num - 1.U
                        }                     
                    }
                }
            }             
        }
        is(sEnd){
                last                    := 0.U
                state                   := sReadDesc
                string_length           := 0.U
                remain_bytes            := 0.U
                has_pre                 := 0.U
            
        }

    }

		// class ila_net(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_net = Module(new ila_net(Seq(	
		// 	state

		// )))
		// instila_net.connect(clock)


}

