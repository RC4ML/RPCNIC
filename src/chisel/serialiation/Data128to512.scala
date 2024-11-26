package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._





class Data128to512() extends Module{
	val io = IO(new Bundle{
        val in             = Flipped(Decoupled(AXIS(128)))
		val out	        = (Decoupled(UInt(512.W)))        
	})


    val data_in_fifo = XQueue(AXIS(128), entries=16)
    val data_out_fifo = XQueue(UInt(512.W), entries=4096)

    data_in_fifo.io.in        <> io.in
    data_out_fifo.io.out        <> io.out

	val sIDLE :: sSEND0:: sSEND1:: sSEND2 :: Nil = Enum(4)
	val state                   = RegInit(sIDLE)

    val data_tmp            = RegInit(UInt(512.W),0.U)

    ToZero(data_out_fifo.io.in.valid)
    ToZero(data_out_fifo.io.in.bits)
  
    data_in_fifo.io.out.ready        := data_out_fifo.io.in.ready
    

	switch(state){
		is(sIDLE){
			when(data_in_fifo.io.out.fire()){
                data_tmp                            := Cat(0.U(384.W),data_in_fifo.io.out.bits.data)
                when(data_in_fifo.io.out.bits.last === 1.U){
                    data_out_fifo.io.in.valid       := 1.U
                    data_out_fifo.io.in.bits        := Cat(0.U(384.W),data_in_fifo.io.out.bits.data)
                    state                   := sIDLE                    
                }.otherwise{
                    state                   := sSEND0
                }
			}
		}
		is(sSEND0){
            when(data_in_fifo.io.out.fire()){
                data_tmp                            := Cat(0.U(256.W),data_in_fifo.io.out.bits.data,data_tmp(127,0))
                when(data_in_fifo.io.out.bits.last === 1.U){
                    data_out_fifo.io.in.valid       := 1.U
                    data_out_fifo.io.in.bits        := Cat(0.U(256.W),data_in_fifo.io.out.bits.data,data_tmp(127,0))
                    state                   := sIDLE 
                }.otherwise{
                    state                   := sSEND1
                }             
            }
		}
		is(sSEND1){
            when(data_in_fifo.io.out.fire()){
                data_tmp                            := Cat(0.U(128.W),data_in_fifo.io.out.bits.data,data_tmp(255,0))
                when(data_in_fifo.io.out.bits.last === 1.U){
                    data_out_fifo.io.in.valid       := 1.U
                    data_out_fifo.io.in.bits        := Cat(0.U(128.W),data_in_fifo.io.out.bits.data,data_tmp(255,0))
                    state                   := sIDLE 
                }.otherwise{
                    state                   := sSEND2
                }             
            }
		}
		is(sSEND2){
            when(data_in_fifo.io.out.fire()){
                data_out_fifo.io.in.valid       := 1.U
                data_out_fifo.io.in.bits        := Cat(data_in_fifo.io.out.bits.data,data_tmp(383,0))
                state                   := sIDLE 
            }
		}        

	}


}

