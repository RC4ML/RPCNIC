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
import network.cmac._
import network._
import common.Collector
import common.ToZero
import aes._
import serialization._
import hbm._
import qdma._


class U280DynamicGreyBox extends MultiIOModule {
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

	val dbgBridgeInst = DebugBridge(IP_CORE_NAME="DebugBridgeBase",clk=clock)
	dbgBridgeInst.getTCL()

	dontTouch(io)


	val hbmDriver = withClockAndReset(io.sysClk, false.B) {Module(new HBM_DRIVER(WITH_RAMA=false, IP_CORE_NAME="HBMBlackBoxBase"))}
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

	io.ddrPort2.get.axi.qdma_init()
	

	val qdmaInst = Module(new QDMADynamic(
		VIVADO_VERSION		= "202002",
		PCIE_WIDTH			= 16,
		SLAVE_BRIDGE		= false,
		BRIDGE_BAR_SCALE	= "Megabytes",
		BRIDGE_BAR_SIZE 	= 4
	))



	val controlReg  = qdmaInst.io.reg_control
	val statusReg   = qdmaInst.io.reg_status
	ToZero(statusReg)

	userClk		:= clock
	userRstn	:= ((~reset.asBool & ~controlReg(0)(0)).asClock).asBool

	qdmaInst.io.qdma_port	<> io.qdma
	qdmaInst.io.user_clk	:= userClk
	qdmaInst.io.user_arstn	:= ~reset.asBool



	// qdmaInst.io.h2c_data.ready	:= 0.U
	qdmaInst.io.c2h_data.valid	:= 0.U
	qdmaInst.io.c2h_data.bits	:= 0.U.asTypeOf(new C2H_DATA)

	// qdmaInst.io.h2c_cmd.valid	:= 0.U
	qdmaInst.io.h2c_cmd.bits	:= 0.U.asTypeOf(new H2C_CMD)
	qdmaInst.io.c2h_cmd.valid	:= 0.U
	qdmaInst.io.c2h_cmd.bits	:= 0.U.asTypeOf(new C2H_CMD)



		val cmacInst = Module(new XCMAC(BOARD="u280", PORT=0, IP_CORE_NAME="CMACBlackBoxBase"))
		cmacInst.getTCL()

		// Connect CMAC's pins
		cmacInst.io.pin			<> io.cmacPin.get
		cmacInst.io.drp_clk		:= io.cmacClk.get
		cmacInst.io.user_clk	:= userClk
		cmacInst.io.user_arstn	:= userRstn
		cmacInst.io.sys_reset	:= reset

		cmacInst.io.m_net_rx.ready  := 1.U
		ToZero(cmacInst.io.s_net_tx.bits)
		cmacInst.io.s_net_tx.valid  := 0.U


    //network
	val roce								= Module(new NetworkStack(PART_ID=1,IP_CORE_NAME="CMACBlackBoxBase2"))
	roce.io.pin								<> io.cmacPin2.get
	roce.io.user_clk						:= userClk
	roce.io.user_arstn						:= userRstn
	roce.io.sys_reset						:= reset
	roce.io.drp_clk							:= io.cmacClk.get
	roce.io.m_mem_read_cmd.ready			:= 1.U
	roce.io.m_mem_write_cmd.ready			:= 1.U
	roce.io.m_mem_write_data.ready			:= 1.U
	roce.io.s_mem_read_data.valid			:= 0.U
	roce.io.m_cmpt_meta.ready				:= 1.U
	roce.io.arp_rsp.ready					:= 1.U
	roce.io.arp_req.valid					:= 0.U
	roce.io.sw_reset						:= ~userRstn
	ToZero(roce.io.s_mem_read_data.bits)
	ToZero(roce.io.qp_init.bits)

    roce.io.qp_init.bits.remote_udp_port	:= 17.U	

    //roce init
	withClockAndReset(clock,!userRstn) {
		val start 							= RegNext(controlReg(101) === 1.U)
		val risingStartInit					= start && RegNext(!start)
		val valid 							= RegInit(UInt(1.W),0.U)
		when(risingStartInit === 1.U){
			valid							:= 1.U
		}.elsewhen(roce.io.qp_init.fire()){
			valid							:= 0.U
		}
		roce.io.qp_init.valid				:= valid
		roce.io.qp_init.bits.remote_ip		:= 0x51bda8c0.U
		roce.io.ip_address					:= 0x52bda8c0.U//0x01bda8c0 01/189/168/192
		roce.io.qp_init.bits.credit			:= controlReg(103)

		val cur_qp							= RegInit(UInt(1.W),0.U)
		when(roce.io.qp_init.fire()){
			cur_qp							:= cur_qp + 1.U
		}

		when(cur_qp === 0.U){
			roce.io.qp_init.bits.qpn			:= 1.U
			roce.io.qp_init.bits.remote_qpn		:= 1.U
			roce.io.qp_init.bits.local_psn		:= 0x2001.U
			roce.io.qp_init.bits.remote_psn		:= 0x1001.U
		}.otherwise{
			roce.io.qp_init.bits.qpn			:= 2.U
			roce.io.qp_init.bits.remote_qpn		:= 2.U
			roce.io.qp_init.bits.local_psn		:= 0x2002.U
			roce.io.qp_init.bits.remote_psn		:= 0x1002.U
		}

		val valid_arp						= RegInit(UInt(1.W),0.U)
		when(risingStartInit === 1.U){
			valid_arp						:= 1.U
		}.elsewhen(roce.io.arp_req.fire()){
			valid_arp						:= 0.U
		}
		roce.io.arp_req.valid				:= valid_arp
		roce.io.arp_req.bits				:= 0x51bda8c0.U


		val mem_to_net = (Module(new MemToNet()))

		val read_host = (Module(new ReadHostClient()))

		val control = (Module(new Control()))
    
		val tx_bd = (Module(new BandwidthProbe()))
		val rx_bd = (Module(new BandwidthProbe()))

		read_host.io.ser_cmd_out			<> mem_to_net.io.meta_in
		read_host.io.ser_host_data_out   <> mem_to_net.io.data_in



		control.io.axi 				<> qdmaInst.io.axib	
		control.io.free_index.ready		:= 1.U
		control.io.metadata_init.ready := 1.U
		control.io.ser_cmd    	 	<> read_host.io.ser_cmd
		control.io.eng_cmd.ready		:= 1.U



        qdmaInst.io.h2c_cmd.valid                       <> read_host.io.m_mem_read_cmd.valid
        qdmaInst.io.h2c_cmd.ready                       <> read_host.io.m_mem_read_cmd.ready
        qdmaInst.io.h2c_cmd.bits.addr                   <> read_host.io.m_mem_read_cmd.bits.vaddr		
        qdmaInst.io.h2c_cmd.bits.len 		            <> read_host.io.m_mem_read_cmd.bits.length
        qdmaInst.io.h2c_cmd.bits.eop					:= 1.U
        qdmaInst.io.h2c_cmd.bits.sop					:= 1.U


		

        qdmaInst.io.h2c_data.valid                      <> read_host.io.s_mem_read_data.valid
        qdmaInst.io.h2c_data.ready                      <> read_host.io.s_mem_read_data.ready
        qdmaInst.io.h2c_data.bits.data				    <> read_host.io.s_mem_read_data.bits.data
        qdmaInst.io.h2c_data.bits.last				    <> read_host.io.s_mem_read_data.bits.last
		read_host.io.s_mem_read_data.bits.keep		:= -1.S(64.W).asTypeOf(UInt(64.W))
		// qdmaInst.io.h2c_data.bits.keep				    <> read_host.io.s_mem_read_data.bits.keep


		mem_to_net.io.m_send_data					<> roce.io.s_send_data
		mem_to_net.io.s_tx_meta      <> roce.io.s_tx_meta


		roce.io.m_recv_data.ready			:= 1.U
		roce.io.m_recv_meta.ready			:= 1.U


        read_host.io.recv_meta_fire      	:= roce.io.m_recv_meta.fire & (roce.io.m_recv_meta.bits.pkg_num === roce.io.m_recv_meta.bits.pkg_total)
        read_host.io.total_send_num      	:= controlReg(105)
        read_host.io.idle_cycle          	:= controlReg(106)
        read_host.io.outstanding_cmd     	:= controlReg(107)
 
        mem_to_net.io.qpn                 	:= 1.U                 

		val timer_en = RegInit(false.B)
		val timer_end = RegInit(false.B)
		val done_en = RegInit(false.B)
		val timer_cnt = RegInit(UInt(32.W), 0.U)
		val data_cnt = RegInit(UInt(32.W), 1.U)
		val total_data = RegNext(controlReg(108))

		val time_cnt = RegInit(UInt(32.W), 0.U)

		when (roce.io.s_send_data.fire()) {
			timer_en 	:= true.B
		}.otherwise{
			timer_en	:= timer_en
		}

		when (data_cnt === total_data) {
			timer_end 	:= true.B
		}.otherwise{
			timer_end	:= timer_end
		}

		when (timer_en & (~timer_end)) {
			timer_cnt 	:= timer_cnt + 1.U
		}otherwise{
			timer_cnt	:= timer_cnt
		}		

		time_cnt := time_cnt + 1.U

		when (roce.io.s_send_data.fire) {
			data_cnt 	:= data_cnt + 1.U
		}.otherwise{
			data_cnt	:= data_cnt
		}

		statusReg(300)			:= data_cnt
		statusReg(301)			:= timer_en
		statusReg(302)			:= timer_cnt

        tx_bd.io.enable			:= controlReg(110)
        tx_bd.io.fire 			:= roce.io.s_send_data.fire
        tx_bd.io.count.ready	:= (controlReg(111)(0) === 1.U && RegNext(controlReg(111)(0)) =/= 1.U)
		statusReg(310)			:= Mux(tx_bd.io.count.valid, tx_bd.io.count.bits, -1.S(32.W).asUInt)


        rx_bd.io.enable			:= controlReg(112)
        rx_bd.io.fire 			:= roce.io.m_recv_data.fire
        rx_bd.io.count.ready	:= (controlReg(113)(0) === 1.U && RegNext(controlReg(113)(0)) =/= 1.U)
		statusReg(311)			:= Mux(rx_bd.io.count.valid, rx_bd.io.count.bits, -1.S(32.W).asUInt)


		//delay
		val latency_bucket = Module{new LatencyBucket(BUCKET_SIZE=1024,LATENCY_STRIDE=64)}

		latency_bucket.io.enable		:= controlReg(120)
		latency_bucket.io.start			:= roce.io.s_tx_meta.fire()
		latency_bucket.io.end			:= roce.io.m_recv_meta.fire() & (roce.io.m_recv_meta.bits.pkg_num === roce.io.m_recv_meta.bits.pkg_total)
		latency_bucket.io.bucketRdId	:= controlReg(121)
		latency_bucket.io.resetBucket	:= reset




		Collector.report(latency_bucket.io.bucketValue, "REG_BUCKET_VALUE")



		// class ila_probebase(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_probebase = Module(new ila_probebase(Seq(	
		// 	time_cnt,
		// 	roce.io.s_tx_meta.valid,
		// 	roce.io.s_tx_meta.ready,
		// 	roce.io.m_recv_meta.valid,
		// 	roce.io.m_recv_meta.ready


		// )))
		// instila_probebase.connect(clock)


	}

	// Connect DDR's ports

	Collector.connect_to_status_reg(statusReg, 400)
}