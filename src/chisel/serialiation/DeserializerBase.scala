package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._


class DeserializerBase() extends Module{
	val io = IO(new Bundle{
        val meta_in             = Flipped(Decoupled(new DeserMeta))
        val data_in             = Flipped(Decoupled(AXIS(512)))
		val class_meta_req	    = (Decoupled(new ClassMetaReq))
		val class_meta_rsp	    = Flipped(Decoupled(new ClassMetaRsp))
        val idle_out            = Output(UInt(1.W))
        val total_thread_num    = Input(UInt(8.W))
        val thread_num          = Input(UInt(8.W))

        val meta_out            = (Decoupled(new DerOutMeta()))
        val host_data_out       = (Decoupled(UInt(512.W)))
        val device_data_out     = (Decoupled(UInt(512.W)))


	})


    
 
    Collector.fire(io.meta_in)
    Collector.fire(io.data_in)

    Collector.fire(io.meta_out)
    Collector.fire(io.host_data_out)
    Collector.fire(io.device_data_out)

    val data_fifo  = XQueue(AXIS(512), 4096)
    val meta_fifo  = XQueue(new DeserMeta, 32)

    io.meta_in          <> meta_fifo.io.in
    io.data_in          <> data_fifo.io.in

    val meta_reg = RegInit(0.U.asTypeOf(new DeserMeta()))
    val delay_cnt = RegInit(0.U(32.W))
    val host_length = RegInit(0.U(32.W))
    val device_length = RegInit(0.U(32.W))
    val delay_time = RegInit(0.U(32.W))
    val thread_num = RegNext(io.thread_num)
    val total_thread_num = RegNext(io.total_thread_num)

	val sIdle :: sSendMeta :: sDelay :: sSendHost :: sSendDevice :: Nil = Enum(5)
	val state	= RegInit(sIdle)

    ToZero(io.class_meta_req.valid)
    ToZero(io.class_meta_req.bits) 

    io.class_meta_rsp.ready         := 1.U
    

    ToZero(io.meta_out.valid)
    ToZero(io.meta_out.bits)     
    ToZero(io.host_data_out.valid)
    ToZero(io.host_data_out.bits)   
    ToZero(io.device_data_out.valid)
    ToZero(io.device_data_out.bits) 

    meta_fifo.io.out.ready                := state === sIdle
    data_fifo.io.out.ready                := state === sSendDevice & io.device_data_out.ready

    when((state === sIdle) & (thread_num < total_thread_num)){
        io.idle_out             := 1.U
    }.otherwise{
        io.idle_out             := 0.U
    }


		switch(state){
			is(sIdle){
				when(meta_fifo.io.out.fire){
                    meta_reg    := meta_fifo.io.out.bits
                    device_length := ((meta_fifo.io.out.bits.length) >> 6.U)<<6.U
                    delay_time  := 30.U
					state		:= sDelay
				}
			}
			is(sDelay){
				when(delay_cnt > delay_time){
                    delay_cnt               := 0.U
                    state		            := sSendMeta
				}.otherwise{
                    delay_cnt               := delay_cnt + 1.U
                    state		            := sDelay
                }
			}
			is(sSendMeta){
				when(io.meta_out.ready){
                    io.meta_out.valid                   := 1.U
                    io.meta_out.bits.host_length        := device_length
                    io.meta_out.bits.device_length      := 0.U
                    state                               := sSendDevice
                }
			}            
			is(sSendDevice){
				when(data_fifo.io.out.fire){
                    io.host_data_out.bits            := 0.U
                    when(meta_reg.length <= 64.U){
                        state                       := sIdle
                    }.otherwise{
                        meta_reg.length             := meta_reg.length - 64.U
                        state                       := sSendDevice
                    }   
                    when(device_length === 0.U){
                        io.host_data_out.valid           := 0.U
                    }.otherwise{
                        io.host_data_out.valid           := 1.U
                        device_length               := device_length - 64.U
                    }              
                }
			}            
		}   



		// class ila_deser(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_deser = Module(new ila_deser(Seq(	
		// 	state,
		// 	device_length,
		// 	delay_time,
		// 	delay_cnt

		// )))
		// instila_deser.connect(clock)

}

