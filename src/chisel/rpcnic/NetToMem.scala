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


class NetToMem() extends Module{
	val io = IO(new Bundle{

        //Roce out
        val s_recv_data         = Flipped(Decoupled(new AXIS(512)))
        val s_recv_meta         = Flipped(Decoupled(new RECV_META()))
        // //DDR interface
        // val axi_ddr             = (new AXI(34, 512, 6, 0, 8))
        // //deser notify
        // val done                = (Decoupled(new RoceMsg()))
        // //deser start cmd
        // val start               = Flipped(Decoupled(new RoceMsg()))
        //deser cmd
        val deser_meta_out      = (Decoupled(new DeserMeta))
        val deser_data_out      = (Decoupled(AXIS(512)))
	})

    Collector.fire(io.s_recv_data)
    Collector.fire(io.s_recv_meta)
    Collector.fire(io.deser_meta_out)
    Collector.fire(io.deser_data_out)
    



    val recv_meta           = RegInit(0.U.asTypeOf(new RECV_META()))
    val recv_length         = RegInit(0.U(32.W))
    val r_length            = RegInit(0.U(32.W))
    

    val recv_data_fifo = XQueue(AXIS(512), 4096)

    val msg_length_fifo = XQueue(UInt(32.W), 1024)


	val sIdle :: sWrite :: sSendMeta :: Nil = Enum(3)
	val state_aw	= RegInit(sIdle)
    val state_r	    = RegInit(sIdle)


    val rpc_rshift = Module(new RSHIFT(8,512))



    ToZero(io.deser_meta_out.valid)
    ToZero(io.deser_meta_out.bits)
    ToZero(io.deser_data_out.valid)
    ToZero(io.deser_data_out.bits)
    ToZero(recv_data_fifo.io.in.valid)
    ToZero(recv_data_fifo.io.in.bits)    
    ToZero(msg_length_fifo.io.in.valid)
    ToZero(msg_length_fifo.io.in.bits)


    io.s_recv_meta.ready                := state_aw === sIdle

    io.s_recv_data.ready                := (state_aw === sWrite) & recv_data_fifo.io.in.ready


	switch(state_aw){
		is(sIdle){
			when(io.s_recv_meta.fire()){
                recv_meta               := io.s_recv_meta.bits
                state_aw                := sWrite
			}
		}
        is(sWrite){
            when(io.s_recv_data.fire()){
                recv_data_fifo.io.in.valid      := 1.U
                recv_data_fifo.io.in.bits       := io.s_recv_data.bits
                when(io.s_recv_data.bits.last === 1.U){
                    when(recv_meta.pkg_num =/= recv_meta.pkg_total){
                        recv_length                     := recv_length + recv_meta.length
                        recv_data_fifo.io.in.bits.last  := 0.U
                    }.otherwise{
                        recv_length                     := 0.U
                        msg_length_fifo.io.in.valid     := 1.U
                        msg_length_fifo.io.in.bits      := recv_length + recv_meta.length
                    }
                    state_aw                := sIdle
                }
                
            }
        }
	}

    msg_length_fifo.io.out.ready              := state_r === sIdle


	switch(state_r){
		is(sIdle){
			when(msg_length_fifo.io.out.fire()){
				r_length                := msg_length_fifo.io.out.bits
                state_r                 := sSendMeta
			}
		}
        is(sSendMeta){
            when(recv_data_fifo.io.out.fire()){
                io.deser_meta_out.valid             := 1.U
                io.deser_meta_out.bits.class_id     := recv_data_fifo.io.out.bits.data(9,0)
                io.deser_meta_out.bits.length       := recv_data_fifo.io.out.bits.data(63,32)
                io.deser_meta_out.bits.result_base_addr := 0x10000.U
                when(r_length > 64.U){
                    r_length                := r_length - 64.U
                    state_r                 := sWrite
                }.otherwise{
                    state_r                 := sIdle
                }
            }
        }
        is(sWrite){
            when(recv_data_fifo.io.out.fire()){
                when(r_length > 64.U){
                    r_length                := r_length - 64.U
                    state_r                 := sWrite
                }.otherwise{
                    state_r                 := sIdle
                }
            }
        }
	}


    
    rpc_rshift.io.in.valid                  := recv_data_fifo.io.out.fire
    recv_data_fifo.io.out.ready             := (rpc_rshift.io.in.ready & (state_r === sWrite)) || (rpc_rshift.io.in.ready & (state_r === sSendMeta) & io.deser_meta_out.ready) 
    rpc_rshift.io.in.bits.data              := recv_data_fifo.io.out.bits.data
    rpc_rshift.io.in.bits.keep              := -1.S(64.W).asTypeOf(UInt(64.W))
    rpc_rshift.io.in.bits.last              := recv_data_fifo.io.out.fire() & (r_length <= 64.U)

    io.deser_data_out                       <> rpc_rshift.io.out


		// val w_data = WireInit(0.U(64.W))
		// w_data 	:= io.deser_data_out.bits.data(63,0) 
		// class ila_net(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_net = Module(new ila_net(Seq(	
		// 	aw.ready,
        //     aw.valid,
        //     aw.bits.addr,
        //     aw.bits.len,
		// 	w.ready,
        //     w.valid,
        //     w.bits.last,
		// 	ar.ready,
        //     ar.valid,
        //     ar.bits.addr,
        //     ar.bits.len,
        //     r.valid,
        //     r.ready,
        //     r.bits.last,


		// )))
		// instila_net.connect(clock)

}