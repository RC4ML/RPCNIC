package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._
import qdma._


class WriteDeserBase() extends Module{
	val io = IO(new Bundle{
		val writer_req	        = Flipped(Decoupled(new WriteReq))
        val dma_addr_base         = Input(UInt(64.W))
        val m_mem_write_cmd       = (Decoupled(new C2H_CMD))
        val m_mem_write_data     = (Decoupled(new C2H_DATA))
        val done               = (Decoupled(UInt(1.W)))

        val busy                = Output(UInt(1.W))
	})

    Collector.fire(io.writer_req)
    Collector.fire(io.m_mem_write_cmd)
    Collector.fire(io.m_mem_write_data)

    val writer_req_fifo = XQueue(new WriteReq(), entries=4096)

    val write_cmd_fifo = XQueue(new C2H_CMD, entries=4096)
    val write_data_fifo = XQueue(new C2H_DATA, entries=4096)

    io.m_mem_write_cmd      <> write_cmd_fifo.io.out
    io.m_mem_write_data     <> write_data_fifo.io.out

    val dma_addr_base = RegNext(io.dma_addr_base)
    val host_length = RegInit(0.U(32.W))
    val string_length = RegInit(0.U(32.W))
    val de_str_length = RegInit(0.U(32.W))
    val busy = RegInit(0.U(1.W))

    // val fifo_full = RegInit(false.B)

    // when(write_data_fifo.io.count >4000.U){
    //     fifo_full           := true.B
    // }

    // Collector.report(fifo_full)

    when(write_data_fifo.io.count >256.U){
        busy                := 1.U
    }.otherwise{
        busy                := 0.U
    }
    io.busy         := RegNext(busy)
	val sIDLE :: sHostData :: sSendData :: sMeta :: Nil = Enum(4)
	val state                   = RegInit(sIDLE)
    val state_out               = RegInit(sIDLE)    

    io.writer_req                       <> writer_req_fifo.io.in

    writer_req_fifo.io.out.ready        := (state === sIDLE) || (state === sHostData)  


    ToZero(write_cmd_fifo.io.in.bits)
    ToZero(write_cmd_fifo.io.in.valid)
    ToZero(write_data_fifo.io.in.bits)
    ToZero(write_data_fifo.io.in.valid)
    ToZero(io.done.bits)
    ToZero(io.done.valid)



    switch(state){
        is(sIDLE){
            when(writer_req_fifo.io.out.fire()){
                write_cmd_fifo.io.in.valid          := 1.U
                write_cmd_fifo.io.in.bits.addr      := dma_addr_base
                write_cmd_fifo.io.in.bits.len       := ((writer_req_fifo.io.out.bits.length + 63.U) >> 6.U)<<6.U                
                write_data_fifo.io.in.valid         := 1.U

                when(writer_req_fifo.io.out.bits.length > 64.U){
                    string_length                   := writer_req_fifo.io.out.bits.length - 64.U
                    de_str_length                   := writer_req_fifo.io.out.bits.length - 16.U
                    state                           := sHostData 
                }.elsewhen(writer_req_fifo.io.out.bits.length > 64.U){
                    string_length                   := 0.U
                    de_str_length                   := writer_req_fifo.io.out.bits.length - 16.U
                    write_data_fifo.io.in.bits.last := 1.U
                    state                           := sHostData 
                }.otherwise{
                    write_data_fifo.io.in.bits.last := 1.U
                    state                           := sIDLE
                }

                when(writer_req_fifo.io.out.bits.done){
                    io.done.valid                       := 1.U
                }
            }
        }
        is(sHostData){
            when(write_data_fifo.io.in.ready){
                de_str_length                       := de_str_length - writer_req_fifo.io.out.bits.length
                when(de_str_length > writer_req_fifo.io.out.bits.length){
                    state                           := sHostData
                }otherwise{
                    state                           := sIDLE
                }
                when(string_length === 0.U){
                    write_data_fifo.io.in.valid         := 0.U
                }.elsewhen(string_length > 64.U){
                    string_length                       := string_length - 64.U
                    write_data_fifo.io.in.valid         := 1.U
                }otherwise{
                    string_length                       := 0.U
                    write_data_fifo.io.in.valid         := 1.U
                    write_data_fifo.io.in.bits.last := 1.U
                }                
                when(writer_req_fifo.io.out.bits.done){
                    io.done.valid                       := 1.U
                }                
            }
        }
    }
}
