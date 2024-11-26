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
import common.LSHIFT
import common._
import serialization._


class SerOutMeta extends Bundle {
    val class_id = UInt(10.W)
    val length = UInt(32.W)
}

class MemToNet() extends Module{
	val io = IO(new Bundle{
        //ser cmd
        val meta_in             = Flipped(Decoupled(new SerOutMeta()))
        val data_in             = Flipped(Decoupled(new AXIS(512)))
        // //deser notify
        // val done                = (Decoupled(new RoceMsg()))   
        // //deser start cmd
        // val start               = Flipped(Decoupled(new RoceSend()))      
        val qpn               = Input(UInt(16.W))                 
        //Roce out
        val m_send_data         = (Decoupled(new AXIS(512)))
        val s_tx_meta           = (Decoupled(new TX_META()))

	})



    val rpc_lshift = Module(new LSHIFT(8,512))

    val send_data_fifo        = XQueue(AXIS(512), 4096)

    io.m_send_data          <> send_data_fifo.io.out    


    val serout_meta        = RegInit(0.U.asTypeOf(new SerOutMeta()))


	val sIdle :: send_meta :: send_data :: Nil = Enum(3)
	val state_aw	= RegInit(sIdle)
    val state_w	= RegInit(sIdle)
    ToZero(send_data_fifo.io.in.valid)
    ToZero(send_data_fifo.io.in.bits)
    ToZero(io.s_tx_meta.valid)
    ToZero(io.s_tx_meta.bits)

    rpc_lshift.io.in                        <> io.data_in

    
    rpc_lshift.io.out.ready                 := ((state_aw === send_data) & send_data_fifo.io.in.ready) ||  ((state_aw === send_meta) & send_data_fifo.io.in.ready& io.s_tx_meta.ready)
    send_data_fifo.io.in.bits.keep                := -1.S(64.W).asTypeOf(UInt(64.W))
    send_data_fifo.io.in.bits.last                := rpc_lshift.io.out.bits.last





    io.meta_in.ready          := state_aw === sIdle


	switch(state_aw){
		is(sIdle){
			when(io.meta_in.fire()){
                serout_meta             := io.meta_in.bits
                state_aw                := send_meta
			}
		}
		is(send_meta){
            when(rpc_lshift.io.out.fire()){
                send_data_fifo.io.in.valid            := 1.U
                send_data_fifo.io.in.bits.data        := Cat(rpc_lshift.io.out.bits.data(511,64),0.U(16.W),serout_meta.length,0.U(22.W),serout_meta.class_id)
                when(rpc_lshift.io.out.bits.last === 1.U){
                    state_aw                    := sIdle
                }.otherwise{
                    state_aw                    := send_data
                }
                io.s_tx_meta.valid        := 1.U
                io.s_tx_meta.bits.rdma_cmd:= APP_OP_CODE.APP_SEND
                io.s_tx_meta.bits.qpn     := io.qpn
                io.s_tx_meta.bits.length  := ((serout_meta.length + 8.U + 63.U) / 64.U) << 6.U                
            }

		}
		is(send_data){
            when(rpc_lshift.io.out.fire()){
                send_data_fifo.io.in.valid            := 1.U
                send_data_fifo.io.in.bits.data        := rpc_lshift.io.out.bits.data
                when(rpc_lshift.io.out.bits.last === 1.U){
                    state_aw                    := sIdle
                }.otherwise{
                    state_aw                    := send_data
                }
            }
		}

	}


		// class ila_m2n(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_m2n = Module(new ila_m2n(Seq(	
		// 	state_aw,
        //     rpc_lshift.io.out.valid,
        //     rpc_lshift.io.out.ready,
        //     io.s_tx_meta.ready,
        //     io.s_tx_meta.valid,
        //     send_data_fifo.io.in.valid,
        //     send_data_fifo.io.in.ready,
		// )))
		// instila_m2n.connect(clock)

}