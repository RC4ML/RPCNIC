package cloud_fpga

import common.storage._
import common.Delay
import common.connection._
import common.axi._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import network.roce.util._
import network.roce._
import common.Collector
import common.ToZero
import common.RSHIFT
import common._
import serialization._





class SplitDeMul() extends Module{
	val io = IO(new Bundle{

        //deser in
        val meta_in             = Flipped(Decoupled(new DeserMeta))
        val data_in             = Flipped(Decoupled(AXIS(512)))
        //deser out
        val de_idle             = Input(UInt(2.W))
        val split_meta_out      = Vec(2,(Decoupled(new DeserMeta)))
        val split_data_out      = Vec(2,(Decoupled(AXIS(512))))
	})

    Collector.fire(io.split_meta_out(0))
    Collector.fire(io.split_data_out(0))
    Collector.fire(io.split_meta_out(1))
    Collector.fire(io.split_data_out(1))


    val meta_fifo   = XQueue(new DeserMeta(), 16)
    val data_fifo   = XQueue(AXIS(512), 1024)
    val de_idle     = RegNext(io.de_idle)

    io.meta_in      <> meta_fifo.io.in
    io.data_in      <> data_fifo.io.in


	val sIdle :: sSendMeta0 :: sSendData0 :: sSendMeta1 :: sSendData1 :: sDropMeta :: sDropData :: Nil = Enum(7)
	val state	= RegInit(sIdle)

    
    ToZero(io.split_meta_out(0).valid)
    ToZero(io.split_meta_out(0).bits)
    ToZero(io.split_data_out(0).valid)
    ToZero(io.split_data_out(0).bits)
    ToZero(io.split_meta_out(1).valid)
    ToZero(io.split_meta_out(1).bits)
    ToZero(io.split_data_out(1).valid)
    ToZero(io.split_data_out(1).bits)

    meta_fifo.io.out.ready              := ((state === sSendMeta0) & io.split_meta_out(0).ready) || ((state === sSendMeta1) & io.split_meta_out(1).ready) || (state === sDropMeta)
    data_fifo.io.out.ready              := ((state === sSendData0) & io.split_data_out(0).ready) || ((state === sSendData1) & io.split_data_out(1).ready) || (state === sDropData)

	switch(state){
		is(sIdle){
			when(de_idle(0) === 1.U){
                state                   := sSendMeta0
            }.elsewhen(de_idle(1) === 1.U){
                state                   := sSendMeta1
			}.elsewhen(meta_fifo.io.count > 8.U){
                state                   := sDropMeta
			}
		}
		is(sSendMeta0){
			when(meta_fifo.io.out.fire()){
                io.split_meta_out(0).valid := 1.U
                io.split_meta_out(0).bits  := meta_fifo.io.out.bits
                state                   := sSendData0
			}
		}
		is(sSendData0){
			when(data_fifo.io.out.fire()){
                io.split_data_out(0).valid := 1.U
                io.split_data_out(0).bits  := data_fifo.io.out.bits
                when(data_fifo.io.out.bits.last.asBool){
                    state               := sIdle
                }.otherwise{
                    state               := sSendData0
                }
			}
		}     
		is(sSendMeta1){
			when(meta_fifo.io.out.fire()){
                io.split_meta_out(1).valid := 1.U
                io.split_meta_out(1).bits  := meta_fifo.io.out.bits
                state                   := sSendData1
			}
		}
		is(sSendData1){
			when(data_fifo.io.out.fire()){
                io.split_data_out(1).valid := 1.U
                io.split_data_out(1).bits  := data_fifo.io.out.bits
                when(data_fifo.io.out.bits.last.asBool){
                    state               := sIdle
                }.otherwise{
                    state               := sSendData1
                }
			}
		}            
		is(sDropMeta){
			when(meta_fifo.io.out.fire()){
                state                   := sDropData
			}
		}
		is(sDropData){
			when(data_fifo.io.out.fire()){
                when(data_fifo.io.out.bits.last.asBool){
                    state               := sIdle
                }.otherwise{
                    state               := sDropData
                }
			}
		} 
	}

}