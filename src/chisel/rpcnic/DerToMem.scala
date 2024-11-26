package cloud_fpga

import common.storage._
import common.Delay
import common.connection._
import common.axi._
import common._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import network.roce.util._
import network.roce._
import common.Collector
import common.ToZero
import common.RSHIFT
import serialization._
import qdma._





class DerToMem() extends Module{
	val io = IO(new Bundle{

        val meta_in             = Flipped(Decoupled(new DerOutMeta()))
        val host_data_in        = Flipped(Decoupled(UInt(512.W)))
        val device_data_in      = Flipped(Decoupled(UInt(512.W)))

        val free_index          = Flipped(Decoupled(UInt(32.W)))

        val hbmCtrlAw   = (Decoupled(new RoceMsg))
        val hbmCtrlW    = (Decoupled(UInt(512.W)))

        
        val m_mem_write_cmd     = (Decoupled(new C2H_CMD))
        val m_mem_write_data	= (Decoupled(new C2H_DATA))  
    
        val dma_base_addr       = Input(UInt(64.W))
        val hbm_base_addr       = Input(UInt(64.W))

        val notice_addr         = Input(UInt(64.W))
        val thread_num          = Input(UInt(8.W))
	})


    Collector.fire(io.m_mem_write_cmd)
    Collector.fire(io.m_mem_write_data)

    val meta_fifo           = XQueue(new DerOutMeta(), 512)
    val host_fifo           = XQueue(UInt(512.W), 4096)
    val device_fifo         = XQueue(UInt(512.W), 4096)
    val free_index_fifo     = XQueue(UInt(32.W), 32)

    io.meta_in              <> meta_fifo.io.in
    io.host_data_in         <> host_fifo.io.in
    io.device_data_in       <> device_fifo.io.in
    io.free_index           <> free_index_fifo.io.in

    io.hbmCtrlW             <> device_fifo.io.out


    val meta_reg        = RegInit(0.U.asTypeOf(new DerOutMeta()))
    val host_length     = RegInit(UInt(32.W),0.U)
    val dma_base_addr   = RegNext(io.dma_base_addr)
    val hbm_base_addr   = RegNext(io.hbm_base_addr)
    val thread_num      = RegNext(io.thread_num - 1.U)

    val notice_addr     = RegInit(VecInit(Seq.fill(16)(0.U(64.W))))
    val notice_cnt      = RegInit(VecInit(Seq.fill(16)(1.U(32.W))))
    for(i<- 0 until 16){
        notice_addr(i)  := RegNext(io.notice_addr + 64.U*i.U)
    }
    val notice_flag     = RegInit(UInt(4.W),0.U)

    val freelist_index = RegInit(0.U(7.W))
    val buffer_index = RegInit(0.U(6.W))
    val free_list = XQueue(UInt(6.W), CLCONFIG.DDR_BUFFER_NUM)


	val sIdle :: sNewBuffer :: sWrite :: sNotice :: Nil = Enum(4)
	val state	= RegInit(sIdle)


    ToZero(io.hbmCtrlAw.valid)
    ToZero(io.hbmCtrlAw.bits)
    ToZero(io.m_mem_write_cmd.valid)
    ToZero(io.m_mem_write_cmd.bits)
    ToZero(io.m_mem_write_data.valid)
    ToZero(io.m_mem_write_data.bits)    
    host_fifo.io.out.ready              := io.m_mem_write_data.ready & (state === sWrite)

    meta_fifo.io.out.ready          := state === sIdle

    free_list.io.out.ready          := state === sNewBuffer & io.hbmCtrlAw.ready & io.m_mem_write_cmd.ready

    free_index_fifo.io.out.ready    := 1.U
    when(free_index_fifo.io.out.fire())  {
        free_list.io.in.valid   := 1.U
        free_list.io.in.bits    := free_index_fifo.io.out.bits
        freelist_index          := freelist_index   
    }.elsewhen((freelist_index < CLCONFIG.DDR_BUFFER_NUM.U) & (!free_list.io.almostfull) & (!reset.asBool) & free_list.io.in.ready){
        free_list.io.in.valid   := 1.U
        free_list.io.in.bits    := freelist_index
        freelist_index          := freelist_index + 1.U
    }.otherwise{
        free_list.io.in.valid   := 0.U
        free_list.io.in.bits    := 0.U
        freelist_index          := freelist_index
    }

	switch(state){
		is(sIdle){
			when(meta_fifo.io.out.fire()){
                meta_reg                := meta_fifo.io.out.bits
                state                   := sNewBuffer
			}
		}
		is(sNewBuffer){
			when(free_list.io.out.fire()){
                when(meta_reg.device_length =/= 0.U){
                    io.hbmCtrlAw.valid              := 1.U
                    io.hbmCtrlAw.bits.addr          := hbm_base_addr + (free_list.io.out.bits << 13.U)
                    io.hbmCtrlAw.bits.length        := (meta_reg.device_length + 63.U) & 0x7fffffc0.U                    
                }
                io.m_mem_write_cmd.valid        := 1.U
                io.m_mem_write_cmd.bits.addr    := dma_base_addr + (free_list.io.out.bits << 13.U)
                io.m_mem_write_cmd.bits.len     := (meta_reg.host_length + 63.U) & 0x7fffffc0.U
                host_length                     := (meta_reg.host_length + 63.U) & 0x7fffffc0.U
                state                           := sWrite        
			}
		}
        is(sWrite){
            when(host_fifo.io.out.fire()){
                io.m_mem_write_data.bits.data       := host_fifo.io.out.bits
                io.m_mem_write_data.valid           := 1.U               
                when(host_length <= 64.U){
                    io.m_mem_write_data.bits.last   := 1.U
                    state                       := sNotice
                }.otherwise{
                    host_length                 := host_length - 64.U
                    state                       := sWrite            
                }
                
            }
        }
        is(sNotice){
            when(io.m_mem_write_cmd.ready & io.m_mem_write_data.ready){
                io.m_mem_write_cmd.valid        := 1.U                
                io.m_mem_write_cmd.bits.len     := 64.U  
                io.m_mem_write_data.valid       := 1.U  
                io.m_mem_write_data.bits.last   := 1.U
                when(notice_flag >= thread_num){
                    notice_flag                     := 0.U
                }.otherwise{
                    notice_flag                     := notice_flag + 1.U
                }
                state                           := sIdle
                io.m_mem_write_cmd.bits.addr    := notice_addr(notice_flag)
                io.m_mem_write_data.bits.data   := notice_cnt(notice_flag)
                notice_cnt(notice_flag)         := notice_cnt(notice_flag) + 1.U

            }
        }
	}



        // val data = Wire(UInt(16.W))
        // data    := io.m_mem_write_data.bits.data(15,0)
		// class ila_net(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_net = Module(new ila_net(Seq(	
		// 	io.m_mem_write_cmd.ready,
        //     io.m_mem_write_cmd.valid,
        //     io.m_mem_write_cmd.bits.addr,
        //     io.m_mem_write_cmd.bits.len,
        //     io.m_mem_write_data.ready,
        //     io.m_mem_write_data.valid,
        //     io.m_mem_write_data.bits.last,
        //     data,
        //     state,
		// )))
		// instila_net.connect(clock)



}