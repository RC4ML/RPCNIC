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
import network.ip.util._
import network.ip._
import common.Collector
import common.ToZero
import aes._
import serialization._
import qdma._

class cloudfpgaSerhwSim() extends Module{
	val io = IO(new Bundle{

		val axib 				= Flipped(new AXIB)    


        val m_mem_read_cmd      = (Decoupled(new MEM_CMD()))
        val s_mem_read_data	    = Flipped(Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
        val m_mem_write_cmd     = (Decoupled(new MEM_CMD()))
        val m_mem_write_data	= (Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
   

        val status              = Output(Vec(512,UInt(32.W)))
	})

    
    val ser = Module(new Serializerhw())
    val meta_table = Module(new ClassMetaTable())


	val control = Module(new Control())


	control.io.axi 				<> io.axib	
	control.io.free_index.ready		:= 1.U
    control.io.metadata_init 	<> meta_table.io.class_meta_init
    control.io.ser_cmd    	 	<> ser.io.meta_in
	control.io.eng_cmd.ready	:= 1.U


    ToZero(io.m_mem_write_cmd.valid)
    ToZero(io.m_mem_write_cmd.bits)
    


    ToZero(io.m_mem_write_data.valid)
    ToZero(io.m_mem_write_data.bits)

    io.m_mem_read_cmd.valid                       	:= ser.io.host_data_cmd.valid
    io.m_mem_read_cmd.bits.vaddr                   	:= ser.io.host_data_cmd.bits.vaddr		
    io.m_mem_read_cmd.bits.length 		            := ser.io.host_data_cmd.bits.length
	ser.io.host_data_cmd.ready						:= io.m_mem_read_cmd.ready


        io.s_mem_read_data.ready               		:= ser.io.host_data_in.ready
		ser.io.host_data_in.valid			:= io.s_mem_read_data.valid      
		ser.io.host_data_in.bits		:= io.s_mem_read_data.bits.data
    	ser.io.done.ready             	:= 1.U
    

    	ser.io.class_meta_req <> meta_table.io.s_class_meta_req
    	ser.io.class_meta_rsp <> meta_table.io.s_class_meta_rsp

		ToZero(meta_table.io.d_class_meta_req.valid)
		ToZero(meta_table.io.d_class_meta_req.bits)
		ToZero(meta_table.io.d_class_meta_rsp.ready)


    ToZero(io.status)

    Collector.connect_to_status_reg(io.status,0)
    
}              


