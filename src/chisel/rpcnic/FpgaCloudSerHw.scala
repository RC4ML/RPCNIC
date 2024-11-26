package cloud_fpga

import common.storage._
import common.Delay
import common.connection._
import common.axi._
import common.partialReconfig.AlveoStaticIO
import common._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import network.roce.util._
import network.roce._
import network.ip.util._
import network.ip._
import network._
import common.Collector
import common.ToZero
import aes._
import serialization._
import hbm._
import qdma._


class FpgaCloudSerHw extends MultiIOModule {
	override val desiredName = "AlveoDynamicTop"
    val io = IO(Flipped(new AlveoStaticIO(
        VIVADO_VERSION = "202101", 
		QDMA_PCIE_WIDTH = 16, 
		QDMA_SLAVE_BRIDGE = false, 
		QDMA_AXI_BRIDGE = true,
		ENABLE_CMAC_1 = true,
		ENABLE_CMAC_2 		= true,
		ENABLE_DDR_1		= false,
		ENABLE_DDR_2		= true,		
    )))

	val dbgBridgeInst = DebugBridge(clk=clock)
	dbgBridgeInst.getTCL()

	dontTouch(io)
	io.cmacPin.get <> DontCare
	io.cmacPin2.get <> DontCare

	io.serClk <> DontCare

	io.ddrPort2.get.axi.qdma_init()

	val hbmDriver = withClockAndReset(io.sysClk, false.B) {Module(new HBM_DRIVER(WITH_RAMA=false, IP_CORE_NAME="HBMBlackBox"))}
	hbmDriver.getTCL()
	val hbmClk 	    	= hbmDriver.io.hbm_clk
	val hbmRstn     	= withClockAndReset(hbmClk,false.B) {RegNext(hbmDriver.io.hbm_rstn.asBool)}

	for (i <- 0 until 32) {
		hbmDriver.io.axi_hbm(i).hbm_init()	// Read hbm_init function if you're not familiar with AXI.
	}   
	dontTouch(hbmClk)
	dontTouch(hbmRstn)


	val userClk  	= Wire(Clock())
	val userRstn 	= Wire(Bool())
                                                                                                                                                   
	val ddrClk 		= io.ddrPort2.get.clk
	val ddrRst 		= io.ddrPort2.get.rst
	

	val qdma = Module(new QDMADynamic(
		VIVADO_VERSION		= "202002",
		PCIE_WIDTH			= 16,
		SLAVE_BRIDGE		= false,
		BRIDGE_BAR_SCALE	= "Megabytes",
		BRIDGE_BAR_SIZE 	= 4
	))



	val controlReg  = qdma.io.reg_control
	val statusReg   = qdma.io.reg_status
	ToZero(statusReg)

	userClk		:= clock
	userRstn	:= ((~reset.asBool & ~controlReg(0)(0)).asClock).asBool

	qdma.io.qdma_port	<> io.qdma
	qdma.io.user_clk	:= userClk
	qdma.io.user_arstn	:= ~reset.asBool



	// qdma.io.h2c_data.ready	:= 0.U
	qdma.io.c2h_data.valid	:= 0.U
	qdma.io.c2h_data.bits	:= 0.U.asTypeOf(new C2H_DATA)

	// qdma.io.h2c_cmd.valid	:= 0.U
	qdma.io.h2c_cmd.bits	:= 0.U.asTypeOf(new H2C_CMD)
	qdma.io.c2h_cmd.valid	:= 0.U
	qdma.io.c2h_cmd.bits	:= 0.U.asTypeOf(new C2H_CMD)

    
	withClockAndReset(clock,!userRstn) {


    val ser = Module(new Serializerhw())
    val meta_table = Module(new ClassMetaTable())


	val control = Module(new Control())



		control.io.axi 				<> qdma.io.axib	
		control.io.free_index.ready		:= 1.U
		control.io.metadata_init 	<> meta_table.io.class_meta_init
		control.io.ser_cmd    	 	<> ser.io.meta_in
		control.io.eng_cmd.ready		:= 1.U


    	ser.io.done.ready             	:= 1.U

    	ser.io.class_meta_req <> meta_table.io.s_class_meta_req
    	ser.io.class_meta_rsp <> meta_table.io.s_class_meta_rsp

		ToZero(meta_table.io.d_class_meta_req.valid)
		ToZero(meta_table.io.d_class_meta_req.bits)
		ToZero(meta_table.io.d_class_meta_rsp.ready)


        qdma.io.h2c_cmd.valid                       <> ser.io.host_data_cmd.valid
        qdma.io.h2c_cmd.ready                       <> ser.io.host_data_cmd.ready
        qdma.io.h2c_cmd.bits.addr                   <> ser.io.host_data_cmd.bits.vaddr		
        qdma.io.h2c_cmd.bits.len 		            <> ser.io.host_data_cmd.bits.length
        qdma.io.h2c_cmd.bits.eop					:= 1.U
        qdma.io.h2c_cmd.bits.sop					:= 1.U


		

        qdma.io.h2c_data.valid                      <> ser.io.host_data_in.valid
        qdma.io.h2c_data.ready                      <> ser.io.host_data_in.ready
        qdma.io.h2c_data.bits.data				    <> ser.io.host_data_in.bits              

		

		val timer_en = RegInit(false.B)
		val done_en = RegInit(false.B)
		val timer_cnt = RegInit(UInt(32.W), 0.U)

		when (control.io.ser_cmd.fire()) {
			timer_en 	:= true.B
		}.elsewhen(ser.io.done.fire()) {
			timer_en 	:= false.B
		}.otherwise{
			timer_en	:= timer_en
		}

		when (control.io.ser_cmd.fire()) {
			timer_cnt 	:= 0.U
		}.elsewhen(timer_en) {
			timer_cnt 	:= timer_cnt + 1.U
		}.otherwise{
			timer_cnt	:= timer_cnt
		}

		class ila_debug(seq:Seq[Data]) extends BaseILA(seq)
		val instIlaDbg = Module(new ila_debug(Seq(	
			timer_cnt,
			timer_en
		)))
		instIlaDbg.connect(clock)		

		when (control.io.ser_cmd.fire()) {
			done_en 	:= false.B
		}.elsewhen(ser.io.done.fire()) {
			done_en 	:= true.B
		}.otherwise{
			done_en	:= done_en
		}

		statusReg(300)			:= done_en


	

	}

	// Connect DDR's ports



	Collector.connect_to_status_reg(statusReg, 400)


	
}