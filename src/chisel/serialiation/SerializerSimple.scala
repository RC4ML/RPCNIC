package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._
import network.roce.util._

class SerializerSimple() extends Module{
	val io = IO(new Bundle{
        val meta_in             = Flipped(Decoupled(new SerMeta))
        val host_data_in        = Flipped(Decoupled(UInt(512.W)))
        val device_data_in      = Flipped(Decoupled(UInt(512.W)))
		val class_meta_req	    = (Decoupled(new ClassMetaReq))
		val class_meta_rsp	    = Flipped(Decoupled(new ClassMetaRsp))

        val meta_out            = (Decoupled(new SerOutMeta()))
        val data_out            = (Decoupled(new AXIS(512)))        
	})

		val writer_req	        = Flipped(Decoupled(new WriteReq))
        val meta_out            = (Decoupled(new DerOutMeta()))
        val host_data_out       = (Decoupled(UInt(512.W)))
        val device_data_out     = (Decoupled(UInt(512.W)))




    Collector.fire(io.meta_in)
    Collector.fire(io.host_data_in)
    Collector.fire(io.device_data_in)

    Collector.fire(io.meta_out)
    Collector.fire(io.data_out)

    val meta_reg = RegInit(0.U.asTypeOf(new SerMeta()))
    val delay_cnt = RegInit(0.U(16.W))
    val host_length = RegInit(0.U(16.W))
    val device_length = RegInit(0.U(16.W))

	val sIdle :: sHost :: sDevice :: sDelay :: sSendMeta :: sSendData :: Nil = Enum(6)
	val state	= RegInit(sIdle)

    ToZero(io.class_meta_req.valid)
    ToZero(io.class_meta_req.bits) 

    io.class_meta_rsp.ready         := 1.U
    

    ToZero(io.meta_out.valid)
    ToZero(io.meta_out.bits)     
    ToZero(io.data_out.valid)
    ToZero(io.data_out.bits)   

    io.meta_in.ready                := state === sIdle
    io.host_data_in.ready           := state === sHost
    io.device_data_in.ready         := state === sDevice

		switch(state){
			is(sIdle){
				when(io.meta_in.fire){
                    meta_reg    := io.meta_in.bits
                    host_length := io.meta_in.bits.host_length
                    device_length   := io.meta_in.bits.device_length
					state		:= sHost
				}
			}
			is(sHost){
				when(io.host_data_in.fire){
					when(meta_reg.host_length >64.U){
                        meta_reg.host_length    := meta_reg.host_length - 64.U
                        state		            := sHost
                    }.elsewhen(meta_reg.device_length === 0.U){
                        device_length           := meta_reg.host_length
                        state		            := sDelay
                    }.otherwise{
                        state		            := sDevice
                    }
				}
			}
			is(sDevice){
				when(io.device_data_in.fire){
					when(meta_reg.device_length >64.U){
                        meta_reg.device_length    := meta_reg.device_length - 64.U
                        state		            := sDevice
                    }.otherwise{
                        state		            := sDelay
                    }
				}
			}
			is(sDelay){
				when(delay_cnt > 30.U){
                    delay_cnt               := 0.U
                    state		            := sSendMeta
				}.otherwise{
                    delay_cnt               := delay_cnt + 1.U
                    state		            := sDelay
                }
			}
			is(sSendMeta){
				when(io.meta_out.ready){
                    io.meta_out.valid           := 1.U
                    io.meta_out.bits.class_id   := meta_reg.class_id
                    io.meta_out.bits.length     := ((device_length + host_length)>>6.U)<<6.U
                    device_length               := ((device_length + host_length)>>6.U)<<6.U
                    state                       := sSendData
                }
			}            
			is(sSendData){
				when(io.data_out.ready){
                    io.data_out.valid           := 1.U
                    io.data_out.bits.data       := device_length
                    io.data_out.bits.keep       := -1.S(64.W).asTypeOf(UInt(64.W))
                    device_length               := device_length - 64.U
                    when(device_length <= 64.U){
                        io.data_out.bits.last   := 1.U
                        state                       := sIdle
                    }.otherwise{
                        state                       := sSendData
                    }
                    
                }
			} 
		}    



}

