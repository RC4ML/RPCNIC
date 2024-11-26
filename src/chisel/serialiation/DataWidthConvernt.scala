package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._





class DataWidthConvernt() extends Module{
	val io = IO(new Bundle{
        val meta_in             = Flipped(Decoupled(new DeserMeta))
        val meta_out            = (Decoupled(new DeserMeta))
        val data_in             = Flipped(Decoupled(AXIS(512)))
		val data_out	        = (Decoupled(AXIS(128)))        
	})


    val meta_in_fifo = XQueue(new DeserMeta(), entries=8)
    val data_in_fifo = XQueue(AXIS(512), entries=4096)

    io.meta_in                  <> meta_in_fifo.io.in
    io.data_in                  <> data_in_fifo.io.in

	val sIDLE :: sSend0 :: sSEND1 :: sSEND2 :: sSEND3 :: Nil = Enum(5)
	val state                   = RegInit(sIDLE)

    val data_tmp            = RegInit(UInt(512.W),0.U)
    val cnt                 = RegInit(UInt(2.W),0.U)
    val last                = RegInit(UInt(1.W),0.U)
    val length              = RegInit(UInt(3.W),0.U)

    ToZero(io.data_out.valid)
    ToZero(io.data_out.bits)
    ToZero(io.meta_out.valid)
    ToZero(io.meta_out.bits)


    data_in_fifo.io.out.ready        := (state === sSend0) & io.data_out.ready
    meta_in_fifo.io.out.ready        := (state === sIDLE) & io.meta_out.ready

	switch(state){
		is(sIDLE){
			when(meta_in_fifo.io.out.fire()){
                length                  := Mux(meta_in_fifo.io.out.bits.length(3,0) === 0.U, meta_in_fifo.io.out.bits.length(5,4), (meta_in_fifo.io.out.bits.length(5,4) + 1.U))
                io.meta_out.valid       := 1.U
                io.meta_out.bits        := meta_in_fifo.io.out.bits
                state                   := sSend0
			}
		}
		is(sSend0){
			when(data_in_fifo.io.out.fire()){
                data_tmp                := data_in_fifo.io.out.bits.data >> 128.U
                io.data_out.valid       := 1.U
                io.data_out.bits.data   := data_in_fifo.io.out.bits.data(127,0)
                last                    := data_in_fifo.io.out.bits.last
                when((data_in_fifo.io.out.bits.last === 1.U) & (length === 1.U)){
                    io.data_out.bits.last   := 1.U
                }
                state                   := sSEND1
			}
		}
		is(sSEND1){
            when(io.data_out.ready){
                when((last===1.U) & (length === 1.U)){
                    io.data_out.valid       := 0.U
                }.otherwise{
                    io.data_out.valid       := 1.U
                }
                io.data_out.bits.data   := data_tmp(127,0) 
                data_tmp                := data_tmp >> 128.U  
                state                   := sSEND2   
                when((last===1.U) & (length === 2.U)){
                    io.data_out.bits.last   := 1.U
                }                
            }
		}
		is(sSEND2){
            when(io.data_out.ready){
                when((last===1.U) & ((length === 1.U) || (length === 2.U))){
                    io.data_out.valid       := 0.U
                }.otherwise{
                    io.data_out.valid       := 1.U
                }
                io.data_out.bits.data   := data_tmp(127,0) 
                data_tmp                := data_tmp >> 128.U  
                state                   := sSEND3   
                when((last===1.U) & (length === 3.U)){
                    io.data_out.bits.last   := 1.U
                }                
            }
		}
		is(sSEND3){
            when(io.data_out.ready){
                when((last===1.U) & ((length === 1.U) || (length === 2.U) || (length === 3.U))){
                    io.data_out.valid       := 0.U
                }.otherwise{
                    io.data_out.valid       := 1.U
                }
                io.data_out.bits.data   := data_tmp(127,0)  
                when((last===1.U)){
                    io.data_out.bits.last   := 1.U
                    state                   := sIDLE
                }.otherwise{
                    state                   := sSend0
                }                
            }
		}

	}


}

