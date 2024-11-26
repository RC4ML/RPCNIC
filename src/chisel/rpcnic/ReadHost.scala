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
import serialization._
import common._


class HostCmdType()extends Bundle{
	val is_engine = Bool()
    val engine_num = UInt(4.W)
    val length = UInt(32.W)
}


class ReadHost() extends Module{
	val io = IO(new Bundle{

        val eng_cmd 	= Flipped(Decoupled(new EngMeta))
        val ser_cmd     = Flipped(Decoupled(new SerMeta))


        val enghbmCtrlAr   = (Decoupled(new RoceMsg))
        val enghbmCtrlR    = Flipped(Decoupled(UInt(512.W)))

        val serhbmCtrlAr   = (Decoupled(new RoceMsg))
        val serhbmCtrlR    = Flipped(Decoupled(UInt(512.W)))
        
        val m_mem_read_cmd      = (Decoupled(new MEM_CMD()))
        val s_mem_read_data	    = Flipped(Decoupled(new AXIS(512))) 
        
        val ser_cmd_out         = (Decoupled(new SerMeta))
        val ser_host_data_out   = (Decoupled(UInt(512.W)))
        val ser_device_data_out = (Decoupled(UInt(512.W)))

        val eng_cmd_out         = (Decoupled(new EngMeta))
        val eng_host_data_out   = (Decoupled(UInt(512.W)))
        val eng_device_data_out = (Decoupled(UInt(512.W)))
    
	})





    Collector.fire(io.eng_cmd)
    Collector.fire(io.ser_cmd)
    Collector.fire(io.m_mem_read_cmd)
    Collector.fire(io.s_mem_read_data)

    Collector.fire(io.enghbmCtrlAr)
    Collector.fire(io.enghbmCtrlR)

    Collector.fire(io.serhbmCtrlAr)
    Collector.fire(io.serhbmCtrlR)


    Collector.fire(io.ser_cmd_out)
    Collector.fire(io.ser_host_data_out)
    Collector.fire(io.ser_device_data_out)

    Collector.fire(io.eng_cmd_out)
    Collector.fire(io.eng_host_data_out)
    Collector.fire(io.eng_device_data_out)


    val eng_cmd_fifo            = XQueue(new EngMeta(), 32)
    val ser_cmd_fifo            = XQueue(new SerMeta(), 32)

    // val host_fifo           = XQueue(UInt(512.W), 512)
    // val device_fifo         = XQueue(UInt(512.W), 512)
    // val free_index_fifo     = XQueue(UInt(32.W), 32)
    val host_cmd_fifo           = XQueue(new HostCmdType(), 512) 
    val host_data_fifo          = XQueue(UInt(512.W), 4096)
    val ser_data_fifo           = XQueue(UInt(512.W), 4096)
    val eng_data_fifo           = XQueue(UInt(512.W), 4096)


    val eng_device_data_fifo        = XQueue(UInt(512.W), 1024)
    val ser_device_data_fifo        = XQueue(UInt(512.W), 1024)

    val eng_reg        = RegInit(0.U.asTypeOf(new EngMeta()))
    val ser_reg        = RegInit(0.U.asTypeOf(new SerMeta()))
    val host_reg       = RegInit(0.U.asTypeOf(new HostCmdType()))

    val host_length     = RegInit(UInt(32.W),0.U)



	val sIdle :: sSer :: sEng :: Nil = Enum(3)
	val state	= RegInit(sIdle)
    val state_r	= RegInit(sIdle)


    ToZero(io.enghbmCtrlAr.valid)
    ToZero(io.enghbmCtrlAr.bits)
    ToZero(io.serhbmCtrlAr.valid)
    ToZero(io.serhbmCtrlAr.bits)
    ToZero(io.m_mem_read_cmd.valid)
    ToZero(io.m_mem_read_cmd.bits)    
    ToZero(io.ser_cmd_out.valid)
    ToZero(io.ser_cmd_out.bits)
    ToZero(ser_cmd_fifo.io.in.valid)
    ToZero(ser_cmd_fifo.io.in.bits)
    ToZero(io.eng_cmd_out.valid)
    ToZero(io.eng_cmd_out.bits)
    ToZero(ser_data_fifo.io.in.valid)
    ToZero(ser_data_fifo.io.in.bits)
    ToZero(eng_data_fifo.io.in.valid)
    ToZero(eng_data_fifo.io.in.bits)
    ToZero(host_cmd_fifo.io.in.valid)
    ToZero(host_cmd_fifo.io.in.bits)



    host_data_fifo.io.in.valid      := io.s_mem_read_data.valid
    host_data_fifo.io.in.bits       := io.s_mem_read_data.bits.data
    io.s_mem_read_data.ready        := host_data_fifo.io.in.ready

    ser_data_fifo.io.out    <> io.ser_host_data_out
    eng_data_fifo.io.out    <> io.eng_host_data_out

    io.eng_cmd              <> eng_cmd_fifo.io.in
    io.ser_cmd              <> ser_cmd_fifo.io.in

    eng_device_data_fifo.io.in  <> io.enghbmCtrlR
    ser_device_data_fifo.io.in  <> io.serhbmCtrlR

    io.eng_device_data_out  <> eng_device_data_fifo.io.out
    io.ser_device_data_out  <> ser_device_data_fifo.io.out


    host_data_fifo.io.out.ready                 := ((state_r === sEng) & eng_data_fifo.io.in.ready) || ((state_r === sSer) & ser_data_fifo.io.in.ready)

    ser_cmd_fifo.io.out.ready                   := (state === sIdle)
    eng_cmd_fifo.io.out.ready                   := (state === sIdle) & (!ser_cmd_fifo.io.out.valid)

    host_cmd_fifo.io.out.ready                  := state_r === sIdle

	switch(state){
		is(sIdle){
			when(ser_cmd_fifo.io.out.fire()){
                ser_reg                 := ser_cmd_fifo.io.out.bits
                state                   := sSer
			}.elsewhen(eng_cmd_fifo.io.out.fire()){
                eng_reg                 := eng_cmd_fifo.io.out.bits
                state                   := sEng                
            }
		}
		is(sSer){
            when(io.ser_cmd_out.ready & host_cmd_fifo.io.in.ready & io.m_mem_read_cmd.ready & io.serhbmCtrlAr.ready){
                io.ser_cmd_out.valid                := 1.U
                io.ser_cmd_out.bits                 := ser_reg
                host_cmd_fifo.io.in.valid            := 1.U
                host_cmd_fifo.io.in.bits.is_engine   := false.B
                host_cmd_fifo.io.in.bits.length      := ser_reg.host_length
                io.m_mem_read_cmd.valid             := 1.U
                io.m_mem_read_cmd.bits.vaddr        := ser_reg.host_base_addr
                io.m_mem_read_cmd.bits.length       := ((ser_reg.host_length + 63.U) >> 6.U)<<6.U
                when(ser_reg.device_length =/= 0.U){
                    io.serhbmCtrlAr.valid               := 1.U
                    io.serhbmCtrlAr.bits.addr           := ser_reg.device_base_addr
                    io.serhbmCtrlAr.bits.length         := ser_reg.device_length                    
                }
                state                               := sIdle
            }
		}
		is(sEng){
            when(eng_reg.src_device){
                when(io.eng_cmd_out.ready & io.enghbmCtrlAr.ready){
                    io.eng_cmd_out.valid                := 1.U
                    io.eng_cmd_out.bits                 := eng_reg                
                    io.enghbmCtrlAr.valid               := 1.U
                    io.enghbmCtrlAr.bits.addr           := eng_reg.src_addr
                    io.enghbmCtrlAr.bits.length         := eng_reg.src_length
                    state                               := sIdle
                } 
            }.otherwise{
                when(io.eng_cmd_out.ready & host_cmd_fifo.io.in.ready & io.m_mem_read_cmd.ready){
                    io.eng_cmd_out.valid                := 1.U
                    io.eng_cmd_out.bits                 := eng_reg                
                    host_cmd_fifo.io.in.valid           := 1.U
                    host_cmd_fifo.io.in.bits.is_engine  := true.B
                    host_cmd_fifo.io.in.bits.length     := eng_reg.src_length
                    io.m_mem_read_cmd.valid             := 1.U
                    io.m_mem_read_cmd.bits.vaddr        := eng_reg.src_addr
                    io.m_mem_read_cmd.bits.length       := eng_reg.src_length
                    state                               := sIdle
                }                
            }
		}
	}


	switch(state_r){
		is(sIdle){
			when(host_cmd_fifo.io.out.fire()){
                host_reg                    := host_cmd_fifo.io.out.bits
                when(host_cmd_fifo.io.out.bits.is_engine){
                    state_r                 := sEng        
                }.otherwise{
                    state_r                 := sSer
                }
            }
		}
		is(sSer){
            when(host_data_fifo.io.out.fire()){
                ser_data_fifo.io.in.valid   := 1.U
                ser_data_fifo.io.in.bits    := host_data_fifo.io.out.bits
                when(host_reg.length > 64.U){
                    host_reg.length         := host_reg.length - 64.U
                    state_r                 := sSer
                }.otherwise{
                    state_r                 := sIdle
                }
            }
		}
		is(sEng){
            when(host_data_fifo.io.out.fire()){
                eng_data_fifo.io.in.valid   := 1.U
                eng_data_fifo.io.in.bits    := host_data_fifo.io.out.bits
                when(host_reg.length > 64.U){
                    host_reg.length         := host_reg.length - 64.U
                    state_r                 := sEng
                }.otherwise{
                    state_r                 := sIdle
                }
            }
		}
	}

}