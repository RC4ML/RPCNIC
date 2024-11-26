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


class FpgaCloudSer extends MultiIOModule {
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
	// qdma.io.c2h_data.valid	:= 0.U
	// qdma.io.c2h_data.bits	:= 0.U.asTypeOf(new C2H_DATA)

	// qdma.io.h2c_cmd.valid	:= 0.U
	qdma.io.h2c_cmd.bits	:= 0.U.asTypeOf(new H2C_CMD)
	// qdma.io.c2h_cmd.valid	:= 0.U
	qdma.io.c2h_cmd.bits	:= 0.U.asTypeOf(new C2H_CMD)


	val ser_hbm = Module(new AXISToHbm())

	val eng_hbm = Module(new AXISToHbm())
    
	withClockAndReset(clock,!userRstn) {
		val ser = Module(new Serializer())
		val write_ser = Module(new WriteSer())
		val meta_table = Module(new ClassMetaTable())



		val control = Module(new Control())

		val read_host = Module(new ReadHost())

		val eng_sim = Module(new EngineSim())


		eng_sim.io.host_write_cmd	<> qdma.io.c2h_cmd
		eng_sim.io.host_write_data	<> qdma.io.c2h_data


		read_host.io.eng_cmd_out         <> eng_sim.io.meta_in
		read_host.io.eng_host_data_out   <> eng_sim.io.host_data_in
		read_host.io.eng_device_data_out <> eng_sim.io.device_data_in
		


		read_host.io.ser_cmd_out         <> ser.io.meta_in
		read_host.io.ser_host_data_out   <> ser.io.host_data_in
		read_host.io.ser_device_data_out <> ser.io.device_data_in


		control.io.axi 				<> qdma.io.axib	
		control.io.free_index.ready		:= 1.U
		control.io.metadata_init 	<> meta_table.io.class_meta_init
		control.io.ser_cmd    	 	<> read_host.io.ser_cmd
		control.io.eng_cmd			<> read_host.io.eng_cmd



        qdma.io.h2c_cmd.valid                       <> read_host.io.m_mem_read_cmd.valid
        qdma.io.h2c_cmd.ready                       <> read_host.io.m_mem_read_cmd.ready
        qdma.io.h2c_cmd.bits.addr                   <> read_host.io.m_mem_read_cmd.bits.vaddr		
        qdma.io.h2c_cmd.bits.len 		            <> read_host.io.m_mem_read_cmd.bits.length
        qdma.io.h2c_cmd.bits.eop					:= 1.U
        qdma.io.h2c_cmd.bits.sop					:= 1.U


		

        qdma.io.h2c_data.valid                      <> read_host.io.s_mem_read_data.valid
        qdma.io.h2c_data.ready                      <> read_host.io.s_mem_read_data.ready
        qdma.io.h2c_data.bits.data				    <> read_host.io.s_mem_read_data.bits.data
        qdma.io.h2c_data.bits.last				    <> read_host.io.s_mem_read_data.bits.last
		read_host.io.s_mem_read_data.bits.keep		:= -1.S(64.W).asTypeOf(UInt(64.W))
		// qdma.io.h2c_data.bits.keep				    <> read_host.io.s_mem_read_data.bits.keep               

		
		write_ser.io.meta_out.ready			:= 1.U
		write_ser.io.data_out.ready			:= 1.U

		val timer_en = RegInit(false.B)
		val done_en = RegInit(false.B)
		val timer_cnt = RegInit(UInt(32.W), 0.U)

		when (control.io.ser_cmd.fire()) {
			timer_en 	:= true.B
		}.elsewhen(write_ser.io.meta_out.fire()) {
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

		when (control.io.eng_cmd.fire()) {
			done_en 	:= false.B
		}.elsewhen(write_ser.io.meta_out.fire()) {
			done_en 	:= true.B
		}.otherwise{
			done_en	:= done_en
		}

		statusReg(300)			:= done_en

    	ser.io.writer_req       <> write_ser.io.writer_req
    	ser.io.done             <> write_ser.io.done
    

    	ser.io.class_meta_req <> meta_table.io.s_class_meta_req
    	ser.io.class_meta_rsp <> meta_table.io.s_class_meta_rsp

		ToZero(meta_table.io.d_class_meta_req.valid)
		ToZero(meta_table.io.d_class_meta_req.bits)
		ToZero(meta_table.io.d_class_meta_rsp.ready)
	

        ser_hbm.io.userClk     := clock
        ser_hbm.io.userRstn    := !(reset.asBool)
        ser_hbm.io.hbmClk      := hbmClk
        ser_hbm.io.hbmRstn     := hbmRstn
        ser_hbm.io.hbmCtrlAr   <> read_host.io.serhbmCtrlAr
        ser_hbm.io.hbmCtrlR    <> read_host.io.serhbmCtrlR
		ser_hbm.io.hbmCtrlAw.ready	:= 1.U
		ser_hbm.io.hbmCtrlW.ready	:= 1.U 

        eng_hbm.io.userClk     := clock
        eng_hbm.io.userRstn    := !(reset.asBool)
        eng_hbm.io.hbmClk      := hbmClk
        eng_hbm.io.hbmRstn     := hbmRstn
        eng_hbm.io.hbmCtrlAr   <> read_host.io.enghbmCtrlAr
        eng_hbm.io.hbmCtrlR    <> read_host.io.enghbmCtrlR
		eng_hbm.io.hbmCtrlAw	<> eng_sim.io.enghbmCtrlAw
		eng_hbm.io.hbmCtrlW		<> eng_sim.io.enghbmCtrlW
	}

	// Connect DDR's ports

	hbmDriver.io.axi_hbm(9) <>  withClockAndReset(hbmClk,!hbmRstn){AXIRegSlice(2)(ser_hbm.io.hbmAxi)}

	hbmDriver.io.axi_hbm(10) <>  withClockAndReset(hbmClk,!hbmRstn){AXIRegSlice(2)(eng_hbm.io.hbmAxi)}

	Collector.connect_to_status_reg(statusReg, 400)


	
}


