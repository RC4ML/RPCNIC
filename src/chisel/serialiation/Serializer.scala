package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._
import network.roce.util._


class SerMeta extends Bundle {
    val class_id = UInt(10.W)
    val host_length = UInt(32.W)
    val device_length = UInt(32.W)
    val host_base_addr = UInt(64.W)
    val device_base_addr = UInt(64.W)
    val result_base_addr = UInt(16.W)
}


class read_cmd extends Bundle {
    val addr = UInt(64.W)
    val length = UInt(32.W)
}

class SerWriteReq extends Bundle {
    val data = UInt(512.W)
    val length = UInt(16.W)
    val addr = UInt(16.W)
    val is_host = Bool()
    val done = Bool()
}


class Serializer() extends Module{
	val io = IO(new Bundle{
        val meta_in             = Flipped(Decoupled(new SerMeta))
        val host_data_in        = Flipped(Decoupled(UInt(512.W)))
        val device_data_in      = Flipped(Decoupled(UInt(512.W)))
		val writer_req	        = (Decoupled(new SerWriteReq))
		val class_meta_req	    = (Decoupled(new ClassMetaReq))
		val class_meta_rsp	    = Flipped(Decoupled(new ClassMetaRsp))
        val done                = (Decoupled(UInt(10.W)))
	})


    Collector.fire(io.meta_in)
    Collector.fire(io.host_data_in)
    Collector.fire(io.device_data_in)

    Collector.fire(io.writer_req)
    Collector.fire(io.done)


    val meta_in_fifo = XQueue(new SerMeta(), entries=8)
    val host_data_in_fifo = XQueue(UInt(512.W), entries=1024)
    val device_data_in_fifo = XQueue(UInt(512.W), entries=1024)
    val class_meta_rsp_fifo = XQueue(new ClassMetaRsp(), entries=8)
    val data_encoder = Module(new VarintEncode)
    val varint_data = WireInit(UInt(64.W),0.U)
    
    


    io.meta_in                      <> meta_in_fifo.io.in
    io.host_data_in                      <> host_data_in_fifo.io.in
    io.device_data_in                    <> device_data_in_fifo.io.in
    io.class_meta_rsp                    <> class_meta_rsp_fifo.io.in


    val meta_reg = RegInit(0.U.asTypeOf(new SerMeta()))
    val class_id   = RegInit(UInt(10.W),0.U)

    val NUM_BITS_FOR_STATES = 5
    val sVarint = 0.U(NUM_BITS_FOR_STATES.W)
    val s64bit  = 1.U(NUM_BITS_FOR_STATES.W)
    val sLengthDelim  = 2.U(NUM_BITS_FOR_STATES.W)
    val sStartGroup  = 3.U(NUM_BITS_FOR_STATES.W)
    val sEndGroup  = 4.U(NUM_BITS_FOR_STATES.W)
    val s32bit  = 5.U(NUM_BITS_FOR_STATES.W)

    val sReadSer  = 6.U(NUM_BITS_FOR_STATES.W)

    val sReadHost  = 7.U(NUM_BITS_FOR_STATES.W)
    val sMoveHostFirst  = 8.U(NUM_BITS_FOR_STATES.W)
    val sMoveHost  = 9.U(NUM_BITS_FOR_STATES.W)
    val sMoveStringFirst  = 10.U(NUM_BITS_FOR_STATES.W)
    val sMoveString  = 11.U(NUM_BITS_FOR_STATES.W)
    val sWriteLength  = 12.U(NUM_BITS_FOR_STATES.W)
    val sWriteTag  = 13.U(NUM_BITS_FOR_STATES.W)
    val sMsgLen  = 14.U(NUM_BITS_FOR_STATES.W)
    val sMsgTag  = 15.U(NUM_BITS_FOR_STATES.W)    
    val sEnd  = 16.U(NUM_BITS_FOR_STATES.W)
    val sGetMeta  = 17.U(NUM_BITS_FOR_STATES.W)
    val sJudgeField  = 18.U(NUM_BITS_FOR_STATES.W)    
    val sReadMeta = 19.U(NUM_BITS_FOR_STATES.W)
    val sRepeatedLengthDelim = 20.U(NUM_BITS_FOR_STATES.W)
    val sRepeatedLength = 21.U(NUM_BITS_FOR_STATES.W)
    





	val field_stack = Reg(Vec(13, new ClassMetaRsp()))
    val msg_length = RegInit(VecInit(Seq.fill(16)(0.U(20.W))))
    // val current_addr = RegInit(VecInit(Seq.fill(16)(0.U(32.W))))
    val field_num = RegInit(VecInit(Seq.fill(16)(0.U(6.W))))

    val current_base_addr = RegInit(UInt(16.W),0.U)
    val move_tmp_addr = RegInit(UInt(16.W),0.U)
    val c_field_length = RegInit(UInt(16.W),0.U)
    val c_field_tag = RegInit(UInt(16.W),0.U)
    val total_length = RegInit(UInt(16.W),0.U)
    val current_field_num = RegInit(UInt(6.W),0.U)
    val c_sub_metadata = RegInit(0.U.asTypeOf(new SubMetaState))
    val c_msg_length = RegInit(UInt(20.W),0.U)
    val repeat_num = RegInit(UInt(8.W),0.U)
    val stack_num   = RegInit(UInt(4.W),0.U)

    
    val field_length = WireInit(UInt(32.W),0.U)
    val tag = WireInit(UInt(3.W),0.U)


    val host_data_tmp       = RegInit(UInt(512.W),0.U) 
    val data_result         = WireInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val host_remain_length  = RegInit(UInt(32.W),0.U)
    val remain_bytes        = RegInit(UInt(7.W),0.U)
    val host_field_length   = RegInit(UInt(16.W),0.U)
    val device_field_length = RegInit(UInt(32.W),0.U)
    val repeat_device_length= RegInit(UInt(32.W),0.U)
    val current_field_length= RegInit(UInt(32.W),0.U)

    val device_fifo_ready   = Wire(UInt(1.W))
    val host_fifo_ready     = Wire(UInt(1.W))

    //

    // host_rd_en                  := false.B
    device_fifo_ready           := 0.U
    host_fifo_ready             := 0.U
    


    device_data_in_fifo.io.out.ready                := device_fifo_ready;
    host_data_in_fifo.io.out.ready                  := host_fifo_ready;

    //varint

    data_encoder.io.inputData := varint_data
    varint_data                 := 0.U

    //fsm

	val state                   = RegInit(sReadSer)

    
    meta_in_fifo.io.out.ready               := (state === sReadSer)& io.class_meta_req.ready
    class_meta_rsp_fifo.io.out.ready        := state === sGetMeta

    ToZero(io.class_meta_req.valid)
    ToZero(io.class_meta_req.bits)  
    ToZero(io.writer_req.valid)
    ToZero(io.writer_req.bits)
    ToZero(io.done.valid)
    ToZero(io.done.bits)


    switch(state){
        is(sReadSer){
            when(meta_in_fifo.io.out.fire()){
                meta_reg                    := meta_in_fifo.io.out.bits
                current_base_addr           := meta_in_fifo.io.out.bits.result_base_addr
                when(meta_in_fifo.io.out.bits.host_length =/= 0.U){
                    host_remain_length              := meta_in_fifo.io.out.bits.host_length
                }
                io.class_meta_req.valid          := 1.U
                io.class_meta_req.bits.class_id  := meta_in_fifo.io.out.bits.class_id
                class_id                        := meta_in_fifo.io.out.bits.class_id
                stack_num                   := 0.U
                state                       := sGetMeta
            }
        }
        is(sGetMeta){
            when(class_meta_rsp_fifo.io.out.fire()){
                field_stack(stack_num)      := class_meta_rsp_fifo.io.out.bits
                msg_length(stack_num)       := 0.U
                c_msg_length                := 0.U
                field_num(stack_num)        := class_meta_rsp_fifo.io.out.bits.class_meta.max_field_num
                current_field_num           := class_meta_rsp_fifo.io.out.bits.class_meta.max_field_num
                state                       := sReadMeta
            }
        }
        is(sReadMeta){
            when(current_field_num === 0.U){
                when(stack_num === 0.U){
                    state                   := sEnd
                }.otherwise{
                    state                   := sMsgLen
                }
            }.elsewhen((field_stack(stack_num).class_meta.field_type(current_field_num).field_type === 0.U)){
                state                       := sReadMeta
                current_field_num           := current_field_num - 1.U
            }.otherwise{
                c_sub_metadata              := field_stack(stack_num).class_meta.field_type(current_field_num)
                state                       := sJudgeField                
            }
        }
        is(sJudgeField){
                tag                             := PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type)
                when(c_sub_metadata.is_repeated){
                    when(c_sub_metadata.is_host){
                        when(c_sub_metadata.field_type === PROTO_TYPES.TYPE_MESSAGE){
                            current_field_num                       := current_field_num - 1.U
                            state                   := sJudgeField//fix it
                        }.otherwise{
                            state                   := sReadHost
                        }
                    }.otherwise{
                        device_fifo_ready               := 1.U
                        when(device_data_in_fifo.io.out.fire()){
                            repeat_num              := device_data_in_fifo.io.out.bits
                            device_field_length     := 0.U
                            when(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_VARINT){
                                state               := sVarint
                            }.elsewhen(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_64bit){
                                state               := s64bit
                            }.elsewhen(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_32bit){ 
                                state               := s32bit
                            }.otherwise{
                                state               := sRepeatedLengthDelim
                            } 
                        }.otherwise{
                            state                   := sJudgeField
                        }
                    }
                }.otherwise{
                    c_field_length              := data_encoder.io.outputBytes
                    varint_data                 := Cat(current_field_num,tag)
                    c_field_tag                 := data_encoder.io.outputData
                    when(c_sub_metadata.is_host){
                        when((c_sub_metadata.field_type) === PROTO_TYPES.TYPE_MESSAGE){
                            io.class_meta_req.valid                 := 1.U
                            io.class_meta_req.bits.class_id         := c_sub_metadata.sub_class_id
                            field_num(stack_num)                    := current_field_num
                            msg_length(stack_num)                   := c_msg_length
                            stack_num                               := stack_num + 1.U
                            state                                   := sGetMeta
                        }.otherwise{
                            state               := sReadHost
                        }
                    }.otherwise{
                        repeat_num              := 0.U
                        when(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_VARINT){
                            state               := sVarint
                        }.elsewhen(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_64bit){
                            state               := s64bit
                        }.elsewhen(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_32bit){ 
                            state               := s32bit
                        }.otherwise{
                            state               := sLengthDelim
                        }               
                    }
                }
        }
        is(sVarint){
            device_fifo_ready               := 1.U
            when(device_data_in_fifo.io.out.fire()){
                varint_data      := device_data_in_fifo.io.out.bits(63,0)      
                when(repeat_num === 0.U){
                    io.writer_req.valid         := 1.U
                    when(c_field_length === 1.U){
                        io.writer_req.bits.data     := Cat(data_encoder.io.outputData,c_field_tag(7,0))
                    }.otherwise{
                        io.writer_req.bits.data     := Cat(data_encoder.io.outputData,c_field_tag(15,0))
                    }
                    io.writer_req.bits.length   := data_encoder.io.outputBytes + c_field_length
                    io.writer_req.bits.addr     := current_base_addr - data_encoder.io.outputBytes - c_field_length
                    current_base_addr           := current_base_addr - data_encoder.io.outputBytes - c_field_length
                    c_msg_length                := c_msg_length + data_encoder.io.outputBytes + c_field_length
                    current_field_num           := current_field_num - 1.U
                    state                       := sReadMeta
                }.elsewhen(repeat_num === 1.U){
                    io.writer_req.valid         := 1.U
                    io.writer_req.bits.data     := data_encoder.io.outputData
                    io.writer_req.bits.length   := data_encoder.io.outputBytes
                    io.writer_req.bits.addr     := current_base_addr - data_encoder.io.outputBytes
                    current_base_addr           := current_base_addr - data_encoder.io.outputBytes
                    c_msg_length                := c_msg_length + data_encoder.io.outputBytes
                    device_field_length         := device_field_length + data_encoder.io.outputBytes
                    state                       := sWriteLength                   
                }.otherwise{
                    io.writer_req.valid         := 1.U
                    io.writer_req.bits.data     := data_encoder.io.outputData
                    io.writer_req.bits.length   := data_encoder.io.outputBytes
                    io.writer_req.bits.addr     := current_base_addr - data_encoder.io.outputBytes
                    current_base_addr           := current_base_addr - data_encoder.io.outputBytes
                    c_msg_length                := c_msg_length + data_encoder.io.outputBytes
                    device_field_length         := device_field_length + data_encoder.io.outputBytes
                    state                               := sVarint
                    repeat_num                          := repeat_num - 1.U
                }  
            }
        }  
        is(s32bit){
            device_fifo_ready               := 1.U
            when(device_data_in_fifo.io.out.fire()){    
                when(repeat_num === 0.U){
                    io.writer_req.valid         := 1.U
                    when(c_field_length === 1.U){
                        io.writer_req.bits.data     := Cat(0.U,device_data_in_fifo.io.out.bits(31,0),c_field_tag(7,0))
                    }.otherwise{
                        io.writer_req.bits.data     := Cat(0.U,device_data_in_fifo.io.out.bits(31,0),c_field_tag(15,0))
                    }
                    io.writer_req.bits.length   := 4.U + c_field_length
                    io.writer_req.bits.addr     := current_base_addr - 4.U - c_field_length
                    current_base_addr           := current_base_addr - 4.U - c_field_length
                    c_msg_length                := c_msg_length + 4.U + c_field_length
                    current_field_num        := current_field_num - 1.U
                    state                       := sReadMeta
                }.elsewhen(repeat_num === 1.U){
                    io.writer_req.valid         := 1.U
                    io.writer_req.bits.data     := device_data_in_fifo.io.out.bits(31,0)
                    io.writer_req.bits.length   := 4.U
                    io.writer_req.bits.addr     := current_base_addr - 4.U
                    current_base_addr           := current_base_addr - 4.U
                    c_msg_length                := c_msg_length + 4.U
                    device_field_length         := device_field_length + 4.U
                    state                       := sWriteLength                  
                }.otherwise{
                    io.writer_req.valid         := 1.U
                    io.writer_req.bits.data     := device_data_in_fifo.io.out.bits(31,0)
                    io.writer_req.bits.length   := 4.U
                    io.writer_req.bits.addr     := current_base_addr - 4.U
                    current_base_addr           := current_base_addr - 4.U
                    c_msg_length                := c_msg_length + 4.U
                    device_field_length         := device_field_length + 4.U
                    state                               := s32bit
                    repeat_num                          := repeat_num - 1.U
                }  
            }
        } 
        is(s64bit){
            device_fifo_ready               := 1.U
            when(device_data_in_fifo.io.out.fire()){    
                when(repeat_num === 0.U){
                    io.writer_req.valid         := 1.U
                    when(c_field_length === 1.U){
                        io.writer_req.bits.data     := Cat(0.U,device_data_in_fifo.io.out.bits(63,0),c_field_tag(7,0))
                    }.otherwise{
                        io.writer_req.bits.data     := Cat(0.U,device_data_in_fifo.io.out.bits(63,0),c_field_tag(15,0))
                    }
                    io.writer_req.bits.length   := 8.U + c_field_length
                    io.writer_req.bits.addr     := current_base_addr - 8.U - c_field_length
                    current_base_addr           := current_base_addr - 8.U - c_field_length
                    c_msg_length                := c_msg_length + 8.U + c_field_length
                    current_field_num           := current_field_num - 1.U
                    state                       := sReadMeta
                }.elsewhen(repeat_num === 1.U){
                    io.writer_req.valid         := 1.U
                    io.writer_req.bits.data     := device_data_in_fifo.io.out.bits(63,0)
                    io.writer_req.bits.length   := 8.U
                    io.writer_req.bits.addr     := current_base_addr - 8.U
                    current_base_addr           := current_base_addr - 8.U
                    c_msg_length                := c_msg_length + 8.U
                    device_field_length         := device_field_length + 8.U
                    state                       := sWriteLength                   
                }.otherwise{
                    io.writer_req.valid         := 1.U
                    io.writer_req.bits.data     := device_data_in_fifo.io.out.bits(63,0)
                    io.writer_req.bits.length   := 8.U
                    io.writer_req.bits.addr     := current_base_addr - 8.U
                    current_base_addr           := current_base_addr - 8.U
                    c_msg_length                := c_msg_length + 8.U
                    device_field_length         := device_field_length + 8.U
                    state                               := s64bit
                    repeat_num                          := repeat_num - 1.U
                }  
            }            
        }
        is(sReadHost){
            when(remain_bytes>=2.U){
                host_field_length               := host_data_tmp(15,0)
                host_data_tmp                   := host_data_tmp >> 16;
                remain_bytes                    := remain_bytes - 2.U
                state                           := sMoveHostFirst
            }.otherwise{
                host_fifo_ready                 := 1.U
                when(host_data_in_fifo.io.out.fire()){
                    when(remain_bytes === 1.U){
                        host_field_length       := Cat(host_data_in_fifo.io.out.bits(7,0),host_data_tmp(7,0))
                        host_data_tmp           := host_data_in_fifo.io.out.bits >> 8;
                        remain_bytes            := 63.U
                    }.otherwise{
                        host_field_length       := host_data_in_fifo.io.out.bits(15,0)
                        host_data_tmp           := host_data_in_fifo.io.out.bits >> 16;
                        remain_bytes            := 62.U
                    }
                    state                       := sMoveHostFirst
                }.otherwise{
                    state                       := sReadHost
                }
            }
        }
        is(sMoveHostFirst){
            current_field_length       := current_field_length + host_field_length
            c_msg_length                := c_msg_length + host_field_length
            when(host_field_length <= remain_bytes){
                io.writer_req.valid             := 1.U
                io.writer_req.bits.data         := host_data_tmp//(host_field_length*8,0)
                io.writer_req.bits.length       := host_field_length
                io.writer_req.bits.addr         := current_base_addr - host_field_length  
                current_base_addr               := current_base_addr - host_field_length  
                host_data_tmp                   := host_data_tmp >> host_field_length*8.U   
                remain_bytes                    := remain_bytes - host_field_length
                current_field_num               := current_field_num - 1.U
                state                           := sReadMeta
            }.elsewhen(remain_bytes =/= 0.U){
                io.writer_req.valid             := 1.U
                io.writer_req.bits.data         := host_data_tmp//(remain_bytes*8,0)
                io.writer_req.bits.length       := remain_bytes
                io.writer_req.bits.addr         := current_base_addr - host_field_length  
                current_base_addr               := current_base_addr - host_field_length
                move_tmp_addr                   := current_base_addr - host_field_length + remain_bytes
                host_field_length               := host_field_length - remain_bytes
                remain_bytes                    := 0.U
                state                           := sMoveHost
            }.otherwise{
                host_fifo_ready                 := 1.U
                when(host_data_in_fifo.io.out.fire()){
                    when(host_field_length>64.U){
                        io.writer_req.valid             := 1.U
                        io.writer_req.bits.data         := host_data_in_fifo.io.out.bits
                        io.writer_req.bits.length       := host_field_length//64.U
                        io.writer_req.bits.addr         := current_base_addr - host_field_length  
                        current_base_addr               := current_base_addr - host_field_length 
                        move_tmp_addr                   := current_base_addr - host_field_length + 64.U
                        host_field_length               := host_field_length - 64.U 
                        remain_bytes                    := 0.U
                        state                           := sMoveHost
                    }.otherwise{
                        io.writer_req.valid             := 1.U
                        io.writer_req.bits.data         := host_data_in_fifo.io.out.bits
                        io.writer_req.bits.length       := host_field_length
                        io.writer_req.bits.addr         := current_base_addr - host_field_length  
                        current_base_addr               := current_base_addr - host_field_length 
                        host_data_tmp                   := host_data_in_fifo.io.out.bits >> host_field_length*8.U  
                        remain_bytes                    := 64.U - host_field_length
                        current_field_num               := current_field_num - 1.U
                        state                           := sReadMeta 
                    }
                }.otherwise{                    
                    state                       := sMoveHostFirst
                }
            }
        }        
        is(sMoveHost){
            host_fifo_ready                 := 1.U
            when(host_data_in_fifo.io.out.fire()){
                when(host_field_length>64.U){
                    io.writer_req.valid             := 1.U
                    io.writer_req.bits.data         := host_data_in_fifo.io.out.bits
                    io.writer_req.bits.length       := host_field_length//64.U
                    io.writer_req.bits.addr         := host_data_tmp  
                    host_data_tmp                   := host_data_tmp + 64.U 
                    host_field_length               := host_field_length - 64.U 
                    remain_bytes                    := 0.U
                    state                           := sMoveHost
                }.otherwise{
                    io.writer_req.valid             := 1.U
                    io.writer_req.bits.data         := host_data_in_fifo.io.out.bits
                    io.writer_req.bits.length       := host_field_length
                    io.writer_req.bits.addr         := host_data_tmp   
                    host_data_tmp                   := host_data_in_fifo.io.out.bits >> host_field_length*8.U  
                    remain_bytes                    := 64.U - host_field_length
                    current_field_num               := current_field_num - 1.U
                    state                           := sReadMeta 
                }
            }.otherwise{
                state                       := sMoveHost
            }
        }
        is(sLengthDelim){
            when((c_sub_metadata.field_type) === PROTO_TYPES.TYPE_MESSAGE){
                io.class_meta_req.valid                 := 1.U
                io.class_meta_req.bits.class_id         := c_sub_metadata.sub_class_id
                stack_num                               := stack_num + 1.U
                field_num(stack_num)                    := current_field_num
                msg_length(stack_num)                   := c_msg_length
                state                                   := sReadMeta
            }.otherwise{
                device_fifo_ready                       := 1.U
                when(device_data_in_fifo.io.out.fire()){
                    repeat_num                          := 0.U
                    device_field_length                 := device_data_in_fifo.io.out.bits
                    c_msg_length                        := c_msg_length + device_data_in_fifo.io.out.bits
                    state                               := sMoveStringFirst
                }.otherwise{
                    state                               := sLengthDelim
                }
            }
        }

        is(sRepeatedLengthDelim){
            device_fifo_ready                       := 1.U
            when(device_data_in_fifo.io.out.fire()){
                device_field_length                 := device_data_in_fifo.io.out.bits(31,0)
                repeat_device_length                := device_data_in_fifo.io.out.bits(31,0)
                c_msg_length                        := c_msg_length + device_data_in_fifo.io.out.bits
                state                               := sMoveStringFirst
            }.otherwise{
                state                               := sRepeatedLengthDelim
            }
        }
        is(sRepeatedLength){
            when(repeat_num === 1.U){
                varint_data                         := repeat_device_length
                io.writer_req.valid                 := 1.U
                io.writer_req.bits.data             := data_encoder.io.outputData
                io.writer_req.bits.length           := data_encoder.io.outputBytes
                io.writer_req.bits.addr             := current_base_addr - data_encoder.io.outputBytes
                current_base_addr                   := current_base_addr - data_encoder.io.outputBytes
                c_msg_length                        := c_msg_length + data_encoder.io.outputBytes
                state                               := sWriteTag
            }.otherwise{
                device_fifo_ready                       := 1.U
                when(device_data_in_fifo.io.out.fire()){
                    repeat_num                          := repeat_num - 1.U
                    device_field_length                 := device_data_in_fifo.io.out.bits(31,0)
                    repeat_device_length                := repeat_device_length + device_data_in_fifo.io.out.bits(16,0)
                    c_msg_length                        := c_msg_length + device_data_in_fifo.io.out.bits
                    state                               := sMoveStringFirst
                }.otherwise{
                    state                               := sRepeatedLength
                }
            }


        }


        is(sMoveStringFirst){
            current_field_length       := current_field_length + device_field_length
            device_fifo_ready                           := 1.U
            when(device_data_in_fifo.io.out.fire()){
                when(device_field_length>64.U){
                    io.writer_req.valid                 := 1.U
                    io.writer_req.bits.data             := device_data_in_fifo.io.out.bits
                    io.writer_req.bits.length           := device_field_length//64.U
                    io.writer_req.bits.addr             := current_base_addr - device_field_length 
                    current_base_addr                   := current_base_addr - device_field_length 
                    move_tmp_addr                       := current_base_addr - device_field_length + 64.U
                    current_field_length                := device_field_length - 64.U 
                    host_field_length                   := host_field_length - 64.U 
                    state                               := sMoveString                   
                }.otherwise{
                    io.writer_req.valid                 := 1.U
                    io.writer_req.bits.data             := device_data_in_fifo.io.out.bits
                    io.writer_req.bits.length           := device_field_length
                    io.writer_req.bits.addr             := current_base_addr - device_field_length 
                    current_base_addr                   := current_base_addr - device_field_length 
                    state                               := sWriteLength
                }     
            }
        }
        is(sMoveString){
            device_fifo_ready                           := 1.U
            when(device_data_in_fifo.io.out.fire()){
                when(current_field_length>64.U){
                    io.writer_req.valid                 := 1.U
                    io.writer_req.bits.data             := device_data_in_fifo.io.out.bits
                    io.writer_req.bits.length           := device_field_length//64.U
                    io.writer_req.bits.addr             := move_tmp_addr  
                    move_tmp_addr                       := move_tmp_addr + 64.U
                    current_field_length                := current_field_length - 64.U
                    state                               := sMoveString                   
                }.otherwise{
                    io.writer_req.valid                 := 1.U
                    io.writer_req.bits.data             := device_data_in_fifo.io.out.bits
                    io.writer_req.bits.length           := current_field_length
                    io.writer_req.bits.addr             := move_tmp_addr 
                    state                               := sWriteLength
                }     
            }           
        }
        is(sWriteLength){
            varint_data                         := device_field_length
            io.writer_req.valid                 := 1.U
            io.writer_req.bits.data             := data_encoder.io.outputData
            io.writer_req.bits.length           := data_encoder.io.outputBytes
            io.writer_req.bits.addr             := current_base_addr - data_encoder.io.outputBytes
            current_base_addr                   := current_base_addr - data_encoder.io.outputBytes
            c_msg_length                        := c_msg_length + data_encoder.io.outputBytes
            when(repeat_num === 0.U){
                state                           := sWriteTag 
            }.otherwise{
                repeat_device_length            := repeat_device_length + data_encoder.io.outputBytes
                state                           := sRepeatedLength
            }                       
        }      
        is(sWriteTag){
            tag                                 := PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type)
            varint_data                         := Cat(current_field_num,tag)
            io.writer_req.valid                 := 1.U
            io.writer_req.bits.data             := data_encoder.io.outputData
            io.writer_req.bits.length           := data_encoder.io.outputBytes
            io.writer_req.bits.addr             := current_base_addr - data_encoder.io.outputBytes
            current_base_addr                   := current_base_addr - data_encoder.io.outputBytes
            c_msg_length                        := c_msg_length + data_encoder.io.outputBytes
            current_field_num                   := current_field_num - 1.U
            state                               := sReadMeta
        }
        is(sMsgLen){
            varint_data                         := c_msg_length
            io.writer_req.valid                 := 1.U
            io.writer_req.bits.data             := data_encoder.io.outputData
            io.writer_req.bits.length           := data_encoder.io.outputBytes
            io.writer_req.bits.addr             := current_base_addr - data_encoder.io.outputBytes
            current_base_addr                   := current_base_addr - data_encoder.io.outputBytes
            msg_length(stack_num-1.U)           := msg_length(stack_num-1.U) + c_msg_length + data_encoder.io.outputBytes
            field_num(stack_num)                := current_field_num
            current_field_num                   := field_num(stack_num-1.U)
            msg_length(stack_num)               := c_msg_length
            stack_num                           := stack_num - 1.U
            state                               := sWriteTag            
        }
        is(sMsgTag){
            current_field_num                   := current_field_num - 1.U
            varint_data                         := Cat(current_field_num,WIRE_TYPES.WIRE_TYPE_LEN_DELIM)
            io.writer_req.valid                 := 1.U
            io.writer_req.bits.data             := data_encoder.io.outputData
            io.writer_req.bits.length           := data_encoder.io.outputBytes
            io.writer_req.bits.addr             := current_base_addr - data_encoder.io.outputBytes
            current_base_addr                   := current_base_addr - data_encoder.io.outputBytes
            c_msg_length                        := c_msg_length + data_encoder.io.outputBytes
            state                               := sReadMeta            
        }        
        is(sEnd){
            io.done.valid                       := 1.U
            io.done.bits                        := class_id
            remain_bytes                        := 0.U
            current_field_length                := 0.U
            state                               := sReadSer
        }
    }


        // val device_data_tmp = Wire(UInt(16.W))
        //  device_data_tmp := device_data_in_fifo.io.out.bits(15,0)

		// class ila_ser(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_ser = Module(new ila_ser(Seq(	
		// 	state,
		// 	c_sub_metadata,
        //     stack_num,
        //     current_field_num,
        //     current_field_length,
        //     device_field_length,
        //     device_data_in_fifo.io.out.ready,
        //     device_data_in_fifo.io.out.valid,
        //     device_data_tmp

		// )))
		// instila_ser.connect(clock)	



}

