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

class cloudfpgaSerSim() extends Module{
	val io = IO(new Bundle{

		val axib 				= Flipped(new AXIB)    


        val m_mem_read_cmd      = (Decoupled(new MEM_CMD()))
        val s_mem_read_data	    = Flipped(Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
        val m_mem_write_cmd     = (Decoupled(new MEM_CMD()))
        val m_mem_write_data	= (Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
   

        val status              = Output(Vec(512,UInt(32.W)))
	})



    val hbm_sim1 = Module(new DDRSimBlackbox())
    val hbm_sim2 = Module(new DDRSimBlackbox())
    
    val ser = Module(new Serializer())
    val write_ser = Module(new WriteSer())
    val meta_table = Module(new ClassMetaTable())

	val ser_hbm = Module(new AXISToHbm())

	val eng_hbm = Module(new AXISToHbm())

	val read_host = Module(new ReadHost())

	val eng_sim = Module(new EngineSim())
	val control = Module(new Control())


	control.io.axi 				<> io.axib	
	control.io.free_index.ready		:= 1.U
    control.io.metadata_init 	<> meta_table.io.class_meta_init
    control.io.ser_cmd    	 	<> read_host.io.ser_cmd
	control.io.eng_cmd			<> read_host.io.eng_cmd


    io.m_mem_write_cmd.valid          := eng_sim.io.host_write_cmd.valid
    io.m_mem_write_cmd.bits.vaddr     := eng_sim.io.host_write_cmd.bits.addr
    io.m_mem_write_cmd.bits.length    := eng_sim.io.host_write_cmd.bits.len
    eng_sim.io.host_write_cmd.ready         := io.m_mem_write_cmd.ready

    io.m_mem_write_data.valid        := eng_sim.io.host_write_data.valid
    io.m_mem_write_data.bits.data    := eng_sim.io.host_write_data.bits.data
    io.m_mem_write_data.bits.keep    := -1.S(64.W).asTypeOf(UInt(64.W)) 
    io.m_mem_write_data.bits.last    := eng_sim.io.host_write_data.bits.last
    eng_sim.io.host_write_data.ready        := io.m_mem_write_data.ready


    read_host.io.eng_cmd_out         <> eng_sim.io.meta_in
    read_host.io.eng_host_data_out   <> eng_sim.io.host_data_in
    read_host.io.eng_device_data_out <> eng_sim.io.device_data_in
    


    read_host.io.ser_cmd_out         <> ser.io.meta_in
    read_host.io.ser_host_data_out   <> ser.io.host_data_in
    read_host.io.ser_device_data_out <> ser.io.device_data_in



    io.m_mem_read_cmd.valid          := eng_sim.io.host_write_cmd.valid
    io.m_mem_read_cmd.bits.vaddr     := eng_sim.io.host_write_cmd.bits.addr
    io.m_mem_read_cmd.bits.length    := eng_sim.io.host_write_cmd.bits.len
    eng_sim.io.host_write_cmd.ready         := io.m_mem_read_cmd.ready

    io.m_mem_read_cmd.valid                       := read_host.io.m_mem_read_cmd.valid
    io.m_mem_read_cmd.bits.vaddr                   := read_host.io.m_mem_read_cmd.bits.vaddr		
    io.m_mem_read_cmd.bits.length 		            := read_host.io.m_mem_read_cmd.bits.length
	read_host.io.m_mem_read_cmd.ready				:= io.m_mem_read_cmd.ready


        io.s_mem_read_data.ready               		:= read_host.io.s_mem_read_data.ready
		read_host.io.s_mem_read_data.bits.keep		:= -1.S(64.W).asTypeOf(UInt(64.W))
		read_host.io.s_mem_read_data.valid			:= io.s_mem_read_data.valid      
		read_host.io.s_mem_read_data.bits.data		:= io.s_mem_read_data.bits.data
		read_host.io.s_mem_read_data.bits.last		:= io.s_mem_read_data.bits.last


		
		write_ser.io.meta_out.ready			:= 1.U
		write_ser.io.data_out.ready			:= 1.U



    	ser.io.writer_req       <> write_ser.io.writer_req
    	ser.io.done             <> write_ser.io.done
    

    	ser.io.class_meta_req <> meta_table.io.s_class_meta_req
    	ser.io.class_meta_rsp <> meta_table.io.s_class_meta_rsp

		ToZero(meta_table.io.d_class_meta_req.valid)
		ToZero(meta_table.io.d_class_meta_req.bits)
		ToZero(meta_table.io.d_class_meta_rsp.ready)


        ser_hbm.io.userClk     := clock
        ser_hbm.io.userRstn    := !(reset.asBool)
        ser_hbm.io.hbmClk      := clock
        ser_hbm.io.hbmRstn     := !(reset.asBool)
        ser_hbm.io.hbmCtrlAr   <> read_host.io.serhbmCtrlAr
        ser_hbm.io.hbmCtrlR    <> read_host.io.serhbmCtrlR
		ser_hbm.io.hbmCtrlAw.ready	:= 1.U
		ser_hbm.io.hbmCtrlW.ready	:= 1.U


        eng_hbm.io.userClk     := clock
        eng_hbm.io.userRstn    := !(reset.asBool)
        eng_hbm.io.hbmClk      := clock
        eng_hbm.io.hbmRstn     := !(reset.asBool)
        eng_hbm.io.hbmCtrlAr   <> read_host.io.enghbmCtrlAr
        eng_hbm.io.hbmCtrlR    <> read_host.io.enghbmCtrlR
		eng_hbm.io.hbmCtrlAw	<> eng_sim.io.enghbmCtrlAw
		eng_hbm.io.hbmCtrlW		<> eng_sim.io.enghbmCtrlW



		hbm_sim1.io.s_aresetn 					:= !(reset.asBool)
		hbm_sim1.io.s_aclk 					    := clock
		hbm_sim1.io.s_axi_awid              	:= ser_hbm.io.hbmAxi.aw.bits.id
		hbm_sim1.io.s_axi_awaddr              	:= ser_hbm.io.hbmAxi.aw.bits.addr
		hbm_sim1.io.s_axi_awlen              	:= ser_hbm.io.hbmAxi.aw.bits.len
		hbm_sim1.io.s_axi_awsize              	:= ser_hbm.io.hbmAxi.aw.bits.size
		hbm_sim1.io.s_axi_awburst              	:= ser_hbm.io.hbmAxi.aw.bits.burst
		hbm_sim1.io.s_axi_awvalid              	:= ser_hbm.io.hbmAxi.aw.valid
		hbm_sim1.io.s_axi_awready              	<> ser_hbm.io.hbmAxi.aw.ready
		hbm_sim1.io.s_axi_wdata              	:= ser_hbm.io.hbmAxi.w.bits.data(255,0)
		hbm_sim1.io.s_axi_wstrb              	:= ser_hbm.io.hbmAxi.w.bits.strb
		hbm_sim1.io.s_axi_wlast              	:= ser_hbm.io.hbmAxi.w.bits.last
		hbm_sim1.io.s_axi_wvalid              	:= ser_hbm.io.hbmAxi.w.valid
		hbm_sim1.io.s_axi_wready              	<> ser_hbm.io.hbmAxi.w.ready
		hbm_sim1.io.s_axi_bid              		<> ser_hbm.io.hbmAxi.b.bits.id
		hbm_sim1.io.s_axi_bresp              	<> ser_hbm.io.hbmAxi.b.bits.resp
		hbm_sim1.io.s_axi_bvalid              	<> ser_hbm.io.hbmAxi.b.valid
		hbm_sim1.io.s_axi_bready              	<> ser_hbm.io.hbmAxi.b.ready
		hbm_sim1.io.s_axi_arid              	<> ser_hbm.io.hbmAxi.ar.bits.id
		hbm_sim1.io.s_axi_araddr              	<> ser_hbm.io.hbmAxi.ar.bits.addr
		hbm_sim1.io.s_axi_arlen              	<> ser_hbm.io.hbmAxi.ar.bits.len
		hbm_sim1.io.s_axi_arsize              	<> ser_hbm.io.hbmAxi.ar.bits.size
		hbm_sim1.io.s_axi_arburst              	<> ser_hbm.io.hbmAxi.ar.bits.burst
		hbm_sim1.io.s_axi_arvalid              	<> ser_hbm.io.hbmAxi.ar.valid
		hbm_sim1.io.s_axi_arready              	<> ser_hbm.io.hbmAxi.ar.ready
		hbm_sim1.io.s_axi_rid              		<> ser_hbm.io.hbmAxi.r.bits.id
		hbm_sim1.io.s_axi_rdata              	<> ser_hbm.io.hbmAxi.r.bits.data
		hbm_sim1.io.s_axi_rresp              	<> ser_hbm.io.hbmAxi.r.bits.resp
		hbm_sim1.io.s_axi_rlast              	<> ser_hbm.io.hbmAxi.r.bits.last
		hbm_sim1.io.s_axi_rvalid              	<> ser_hbm.io.hbmAxi.r.valid
		hbm_sim1.io.s_axi_rready              	<> ser_hbm.io.hbmAxi.r.ready


        ser_hbm.io.userClk     := clock
        ser_hbm.io.userRstn    := !(reset.asBool)
        ser_hbm.io.hbmClk      := clock
        ser_hbm.io.hbmRstn     := !(reset.asBool)
        ser_hbm.io.hbmCtrlAr   <> read_host.io.enghbmCtrlAr
        ser_hbm.io.hbmCtrlR    <> read_host.io.enghbmCtrlR
		ser_hbm.io.hbmCtrlAw.ready	:= 1.U
		ser_hbm.io.hbmCtrlW.ready	:= 1.U


		hbm_sim2.io.s_aresetn 					:= !(reset.asBool)
		hbm_sim2.io.s_aclk 					    := clock
		hbm_sim2.io.s_axi_awid              	    := eng_hbm.io.hbmAxi.aw.bits.id
		hbm_sim2.io.s_axi_awaddr              	:= eng_hbm.io.hbmAxi.aw.bits.addr
		hbm_sim2.io.s_axi_awlen              	:= eng_hbm.io.hbmAxi.aw.bits.len
		hbm_sim2.io.s_axi_awsize              	:= eng_hbm.io.hbmAxi.aw.bits.size
		hbm_sim2.io.s_axi_awburst              	:= eng_hbm.io.hbmAxi.aw.bits.burst
		hbm_sim2.io.s_axi_awvalid              	:= eng_hbm.io.hbmAxi.aw.valid
		hbm_sim2.io.s_axi_awready              	<> eng_hbm.io.hbmAxi.aw.ready
		hbm_sim2.io.s_axi_wdata              	:= eng_hbm.io.hbmAxi.w.bits.data(255,0)
		hbm_sim2.io.s_axi_wstrb              	:= eng_hbm.io.hbmAxi.w.bits.strb
		hbm_sim2.io.s_axi_wlast              	:= eng_hbm.io.hbmAxi.w.bits.last
		hbm_sim2.io.s_axi_wvalid              	:= eng_hbm.io.hbmAxi.w.valid
		hbm_sim2.io.s_axi_wready              	<> eng_hbm.io.hbmAxi.w.ready
		hbm_sim2.io.s_axi_bid              		<> eng_hbm.io.hbmAxi.b.bits.id
		hbm_sim2.io.s_axi_bresp              	<> eng_hbm.io.hbmAxi.b.bits.resp
		hbm_sim2.io.s_axi_bvalid              	<> eng_hbm.io.hbmAxi.b.valid
		hbm_sim2.io.s_axi_bready              	<> eng_hbm.io.hbmAxi.b.ready
		hbm_sim2.io.s_axi_arid              	    <> eng_hbm.io.hbmAxi.ar.bits.id
		hbm_sim2.io.s_axi_araddr              	<> eng_hbm.io.hbmAxi.ar.bits.addr
		hbm_sim2.io.s_axi_arlen              	<> eng_hbm.io.hbmAxi.ar.bits.len
		hbm_sim2.io.s_axi_arsize              	<> eng_hbm.io.hbmAxi.ar.bits.size
		hbm_sim2.io.s_axi_arburst              	<> eng_hbm.io.hbmAxi.ar.bits.burst
		hbm_sim2.io.s_axi_arvalid              	<> eng_hbm.io.hbmAxi.ar.valid
		hbm_sim2.io.s_axi_arready              	<> eng_hbm.io.hbmAxi.ar.ready
		hbm_sim2.io.s_axi_rid              		<> eng_hbm.io.hbmAxi.r.bits.id
		hbm_sim2.io.s_axi_rdata              	<> eng_hbm.io.hbmAxi.r.bits.data
		hbm_sim2.io.s_axi_rresp              	<> eng_hbm.io.hbmAxi.r.bits.resp
		hbm_sim2.io.s_axi_rlast              	<> eng_hbm.io.hbmAxi.r.bits.last
		hbm_sim2.io.s_axi_rvalid              	<> eng_hbm.io.hbmAxi.r.valid
		hbm_sim2.io.s_axi_rready              	<> eng_hbm.io.hbmAxi.r.ready


        eng_hbm.io.userClk     := clock
        eng_hbm.io.userRstn    := !(reset.asBool)
        eng_hbm.io.hbmClk      := clock
        eng_hbm.io.hbmRstn     := !(reset.asBool)
        eng_hbm.io.hbmCtrlAr   <> read_host.io.serhbmCtrlAr
        eng_hbm.io.hbmCtrlR    <> read_host.io.serhbmCtrlR
		eng_hbm.io.hbmCtrlAw	<> eng_sim.io.enghbmCtrlAw
		eng_hbm.io.hbmCtrlW		<> eng_sim.io.enghbmCtrlW



        ser_hbm.io.hbmAxi.r.bits.user       := 0.U
        ser_hbm.io.hbmAxi.b.bits.user       := 0.U
        eng_hbm.io.hbmAxi.r.bits.user       := 0.U
        eng_hbm.io.hbmAxi.b.bits.user       := 0.U

    ToZero(io.status)

    Collector.connect_to_status_reg(io.status,0)
    
}              


