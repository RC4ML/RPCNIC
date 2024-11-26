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





class SplitDe() extends Module{
	val io = IO(new Bundle{

        //deser in
        val meta_in             = Flipped(Decoupled(new DeserMeta))
        val data_in             = Flipped(Decoupled(AXIS(512)))
        //deser out
        val de_idle             = Input(UInt(1.W))
        val split_meta_out      = (Decoupled(new DeserMeta))
        val split_data_out      = (Decoupled(AXIS(512)))
	})

    Collector.fire(io.split_meta_out)
    Collector.fire(io.split_data_out)

    val meta_fifo   = XQueue(new DeserMeta(), 16)
    val data_fifo   = XQueue(AXIS(512), 1024)
    val de_idle     = RegNext(io.de_idle)

    io.meta_in      <> meta_fifo.io.in
    io.data_in      <> data_fifo.io.in


	val sIdle :: sSendMeta :: sSendData :: sDropMeta :: sDropData :: Nil = Enum(5)
	val state	= RegInit(sIdle)


    ToZero(io.split_meta_out.valid)
    ToZero(io.split_meta_out.bits)
    ToZero(io.split_data_out.valid)
    ToZero(io.split_data_out.bits)

    meta_fifo.io.out.ready              := ((state === sSendMeta) & io.split_meta_out.ready)  || (state === sDropMeta)
    data_fifo.io.out.ready              := ((state === sSendData) & io.split_data_out.ready) || (state === sDropData)

	switch(state){
		is(sIdle){
			when(de_idle === 1.U){
                state                   := sSendMeta
            }.elsewhen(meta_fifo.io.count > 8.U){
                state                   := sDropMeta
			}
		}
		is(sSendMeta){
			when(meta_fifo.io.out.fire()){
                io.split_meta_out.valid := 1.U
                io.split_meta_out.bits  := meta_fifo.io.out.bits
                state                   := sSendData
			}
		}
		is(sSendData){
			when(data_fifo.io.out.fire()){
                io.split_data_out.valid := 1.U
                io.split_data_out.bits  := data_fifo.io.out.bits
                when(data_fifo.io.out.bits.last.asBool){
                    state               := sIdle
                }.otherwise{
                    state               := sSendData
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