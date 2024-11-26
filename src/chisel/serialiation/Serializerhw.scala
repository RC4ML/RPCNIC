package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._
import network.roce.util._

class Serializerhw() extends Module{
	val io = IO(new Bundle{
        val meta_in             = Flipped(Decoupled(new SerMeta))
        val host_data_in        = Flipped(Decoupled(UInt(512.W)))
        val host_data_cmd       = (Decoupled(new MEM_CMD))
		val class_meta_req	    = (Decoupled(new ClassMetaReq))
		val class_meta_rsp	    = Flipped(Decoupled(new ClassMetaRsp))
        val done                = (Decoupled(UInt(10.W)))
	})


    Collector.fire(io.meta_in)
    Collector.fire(io.host_data_in)
    Collector.fire(io.host_data_cmd)
    Collector.fire(io.done)


    val meta_in_fifo = XQueue(new SerMeta(), entries=8)
    val class_meta_rsp_fifo = XQueue(new ClassMetaRsp(), entries=8)
    
    


    io.meta_in                          <> meta_in_fifo.io.in
    io.host_data_in.ready               := 1.U                   
    io.class_meta_rsp                   <> class_meta_rsp_fifo.io.in


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

    val sWait  = 7.U(NUM_BITS_FOR_STATES.W)
    val sMoveString  = 11.U(NUM_BITS_FOR_STATES.W)
    val sWriteLength  = 12.U(NUM_BITS_FOR_STATES.W)
    val sWriteTag  = 13.U(NUM_BITS_FOR_STATES.W)
    val sMsgLen  = 14.U(NUM_BITS_FOR_STATES.W)
    val sMsgTag  = 15.U(NUM_BITS_FOR_STATES.W)    
    val sEnd  = 16.U(NUM_BITS_FOR_STATES.W)
    val sGetMeta  = 17.U(NUM_BITS_FOR_STATES.W)
    val sJudgeField  = 18.U(NUM_BITS_FOR_STATES.W)    
    val sReadMeta = 19.U(NUM_BITS_FOR_STATES.W)
    





	val field_stack = Reg(Vec(15, new ClassMetaState()))

    val field_num = RegInit(VecInit(Seq.fill(16)(0.U(6.W))))

    val host_base_addr = RegInit(UInt(64.W),0.U)
    val current_field_num = RegInit(UInt(6.W),0.U)
    val c_sub_metadata = RegInit(0.U.asTypeOf(new SubMetaState))
    val repeat_num = RegInit(UInt(8.W),0.U)
    val stack_num   = RegInit(UInt(4.W),0.U)

    
    val field_length = WireInit(UInt(32.W),0.U)


    val device_field_length = RegInit(UInt(16.W),0.U)
    val current_field_length= RegInit(UInt(32.W),0.U)


	val state                   = RegInit(sReadSer)

    
    meta_in_fifo.io.out.ready               := (state === sReadSer)& io.class_meta_req.ready
    class_meta_rsp_fifo.io.out.ready        := state === sGetMeta

    ToZero(io.class_meta_req.valid)
    ToZero(io.class_meta_req.bits)  
    ToZero(io.host_data_cmd.valid)
    ToZero(io.host_data_cmd.bits)
    ToZero(io.done.valid)
    ToZero(io.done.bits)


    switch(state){
        is(sReadSer){
            when(meta_in_fifo.io.out.fire()){
                meta_reg                    := meta_in_fifo.io.out.bits
                host_base_addr              := meta_in_fifo.io.out.bits.host_base_addr
                io.class_meta_req.valid          := 1.U
                io.class_meta_req.bits.class_id  := meta_in_fifo.io.out.bits.class_id
                class_id                        := meta_in_fifo.io.out.bits.class_id
                stack_num                   := 0.U
                state                       := sGetMeta
            }
        }
        is(sGetMeta){
            when(class_meta_rsp_fifo.io.out.fire()){
                field_stack(stack_num)      := class_meta_rsp_fifo.io.out.bits.class_meta
                field_num(stack_num)        := class_meta_rsp_fifo.io.out.bits.class_meta.max_field_num
                current_field_num           := class_meta_rsp_fifo.io.out.bits.class_meta.max_field_num
                host_base_addr              := host_base_addr + 1024.U
                io.host_data_cmd.valid      := 1.U
                io.host_data_cmd.bits.vaddr := host_base_addr
                io.host_data_cmd.bits.length:= 64.U
                state                       := sWait
            }
        }
        is(sWait){
            when(io.host_data_in.fire()){
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
            }.elsewhen((field_stack(stack_num).field_type(current_field_num).field_type === 0.U)){
                state                       := sReadMeta
                current_field_num           := current_field_num - 1.U
            }.otherwise{
                c_sub_metadata              := field_stack(stack_num).field_type(current_field_num)
                state                       := sJudgeField                
            }
        }
        is(sJudgeField){
            when(c_sub_metadata.is_repeated){
                repeat_num              := c_sub_metadata.sub_class_id
                when(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_VARINT){
                    state               := sVarint
                }.elsewhen(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_64bit){
                    state               := s64bit
                }.elsewhen(PROTO_TYPES.detailedTypeToWireType(c_sub_metadata.field_type) === WIRE_TYPES.WIRE_TYPE_32bit){ 
                    state               := s32bit
                }.otherwise{
                    state               := sLengthDelim
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
        is(sVarint){    
            when(repeat_num === 0.U){
                state                       := sReadMeta
                current_field_num           := current_field_num - 1.U
            }.elsewhen(repeat_num === 1.U){
                state                       := sWriteLength                   
            }.otherwise{
                state                               := sVarint
                repeat_num                          := repeat_num - 1.U
            }  
        }  
        is(s32bit){  
            when(repeat_num === 0.U){
                state                       := sReadMeta
                current_field_num           := current_field_num - 1.U
            }.elsewhen(repeat_num === 1.U){
                state                       := sWriteLength                  
            }.otherwise{
                state                               := s32bit
                repeat_num                          := repeat_num - 1.U
            }  
        } 
        is(s64bit){   
            when(repeat_num === 0.U){
                state                       := sReadMeta
                current_field_num           := current_field_num - 1.U
            }.elsewhen(repeat_num === 1.U){
                state                       := sWriteLength                   
            }.otherwise{
                repeat_num                          := repeat_num - 1.U
            }            
        }
        is(sLengthDelim){
            when((c_sub_metadata.field_type) === PROTO_TYPES.TYPE_MESSAGE){
                io.class_meta_req.valid                 := 1.U
                io.class_meta_req.bits.class_id         := c_sub_metadata.sub_class_id
                stack_num                               := stack_num + 1.U
                field_num(stack_num)                    := current_field_num
                state                                   := sGetMeta
            }.otherwise{
                current_field_length                := c_sub_metadata.sub_class_id
                state                               := sMoveString
            }
        }
        is(sMoveString){
            when(current_field_length>0.U){
                current_field_length                := current_field_length - 1.U
                state                               := sMoveString                   
            }.otherwise{
                state                               := sWriteLength
            }               
        }
        is(sWriteLength){
            state                               := sWriteTag                      
        }      
        is(sWriteTag){
            current_field_num                   := current_field_num - 1.U
            state                               := sReadMeta
        }
        is(sMsgLen){
            field_num(stack_num)                := current_field_num
            current_field_num                   := field_num(stack_num-1.U)
            stack_num                           := stack_num - 1.U
            state                               := sWriteTag            
        }
        is(sMsgTag){
            current_field_num                   := current_field_num - 1.U
            state                               := sReadMeta            
        }        
        is(sEnd){
            io.done.valid                       := 1.U
            io.done.bits                        := class_id
            state                               := sReadSer
        }
    }



}

