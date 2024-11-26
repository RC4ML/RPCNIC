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
import network.cmac._
import network._
import common.Collector
import common.ToZero
import aes._
import serialization._
import hbm._
import qdma._


class FpgaCloudDeser extends MultiIOModule {
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

	io.ddrPort2.get.axi.qdma_init()
	

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




    //network

		val cmacInst2 = Module(new XCMAC(BOARD="u280", PORT=1, IP_CORE_NAME="CMACBlackBox"))
		cmacInst2.getTCL()

		// Connect CMAC's pins
		cmacInst2.io.pin			<> io.cmacPin2.get
		cmacInst2.io.drp_clk		:= io.cmacClk.get
		cmacInst2.io.user_clk		:= userClk
		cmacInst2.io.user_arstn		:= userRstn
		cmacInst2.io.sys_reset		:= reset

		cmacInst2.io.m_net_rx.ready  := 1.U
		ToZero(cmacInst2.io.s_net_tx.bits)
		cmacInst2.io.s_net_tx.valid  := 0.U
	///////////////////////////




	withClockAndReset(clock,!userRstn) {


		val read_host = (Module(new ReadHostDeser()))

		val control = (Module(new ControlMul(Thread=4)))	

		val split_L1 = (Module(new SplitDeMul()))
		val split_L2 = Seq.fill(2)(Module(new SplitDeMul()))
		// val split_L3 = Seq.fill(4)(Module(new SplitDeMul()))

		val deser = Seq.fill(4)(Module(new Deserializer128()))
		val meta_table = Seq.fill(4)(Module(new ClassMetaTable()))
		val write_deser = Seq.fill(4)(Module(new WriteDeserSimple()))
		// val write_deser = Seq.fill(4)(Module(new WriteDeserBase()))


		val arbiter	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)

		val Arb_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)
		// val Arb_L2	= Seq.fill(2)(CompositeArbiter(new C2H_CMD,new C2H_DATA,2))
		val Ard_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)
		// val Ard_L2	= Seq.fill(2)(CompositeArbiter(new C2H_CMD,new C2H_DATA,2))

		val Arb_done= XArbiter(UInt(1.W),4)

		(qdma.io.c2h_cmd)	<> RegSlice(arbiter.io.out_meta) 
		(qdma.io.c2h_data)	<> RegSlice(arbiter.io.out_data)
		arbiter.io.in_meta(0)	<> Ard_L1.io.out_meta
		arbiter.io.in_data(0)	<> Ard_L1.io.out_data
		arbiter.io.in_meta(1)	<> Arb_L1.io.out_meta
		arbiter.io.in_data(1)	<> Arb_L1.io.out_data

		for(i<- 0 until 2){
			Arb_L1.io.in_meta(i)	<> write_deser(i).io.m_mem_write_cmd     
			Arb_L1.io.in_data(i)   	<> write_deser(i).io.m_mem_write_data					
		}     

		for(i<- 0 until 2){
			Ard_L1.io.in_meta(i)	<> write_deser(i+2).io.m_mem_write_cmd     
			Ard_L1.io.in_data(i)   	<> write_deser(i+2).io.m_mem_write_data				
		}	




        read_host.io.ser_cmd_out     		<> split_L1.io.meta_in
        read_host.io.ser_host_data_out     		<> split_L1.io.data_in     
		read_host.io.idle				:= deser(0).io.idle_out | deser(1).io.idle_out | deser(2).io.idle_out | deser(3).io.idle_out

		split_L1.io.de_idle         	:= Cat((deser(2).io.idle_out | deser(3).io.idle_out),(deser(0).io.idle_out | deser(1).io.idle_out))
		for(i<- 0 until 2){
			split_L2(i).io.de_idle         	:= Cat((deser(i*2+1).io.idle_out),(deser(i*2).io.idle_out))
			split_L1.io.split_meta_out(i)	<> split_L2(i).io.meta_in    
			split_L1.io.split_data_out(i)   <> split_L2(i).io.data_in
			for(j<- 0 until 2){
				split_L2(i).io.split_meta_out(j)	<> deser(i*2+j).io.meta_in    
				split_L2(i).io.split_data_out(j)   	<> deser(i*2+j).io.data_in			
		} 
		} 


	for(i<- 0 until 4){	
		deser(i).io.writer_req		<> write_deser(i).io.writer_req
		deser(i).io.busy			<> write_deser(i).io.busy


    	deser(i).io.class_meta_req <> meta_table(i).io.d_class_meta_req
    	deser(i).io.class_meta_rsp <> meta_table(i).io.d_class_meta_rsp


		Arb_done.io.in(i)			<> write_deser(i).io.done
		Arb_done.io.out.ready		:= 1.U
		// write_deser(i).io.done.ready	:= 1.U

		write_deser(i).io.dma_addr_base	:= Cat(controlReg(111),controlReg(110))

		ToZero(meta_table(i).io.s_class_meta_req.valid)
		ToZero(meta_table(i).io.s_class_meta_req.bits)
		ToZero(meta_table(i).io.s_class_meta_rsp.ready)

		control.io.free_index(i).ready		:=  1.U
		control.io.metadata_init(i) 	<> meta_table(i).io.class_meta_init
		control.io.ser_cmd(i).ready		:= 1.U
		control.io.eng_cmd(i).ready		:= 1.U		


	}



		control.io.axi 					<> qdma.io.axib	
		control.io.ser_cmd(0)    	 	<> read_host.io.ser_cmd




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





        read_host.io.recv_meta_fire      	:= write_deser(0).io.done.fire | write_deser(1).io.done.fire |write_deser(2).io.done.fire |write_deser(3).io.done.fire    //fix it
        read_host.io.total_send_num      	:= controlReg(105)
        read_host.io.idle_cycle          	:= controlReg(106)
        read_host.io.outstanding_cmd     	:= controlReg(107)
 
               

		val timer_en = RegInit(false.B)
		val timer_end = RegInit(false.B)
		val done_en = RegInit(false.B)
		val timer_cnt = RegInit(UInt(32.W), 0.U)
		val data_cnt = RegInit(UInt(32.W), 1.U)
		val total_data = RegNext(controlReg(108))

		val time_cnt = RegInit(UInt(32.W), 0.U)

		when (read_host.io.ser_cmd_out.fire()) {
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

		when (read_host.io.ser_host_data_out.fire) {
			data_cnt 	:= data_cnt + 1.U
		}.otherwise{
			data_cnt	:= data_cnt
		}

		statusReg(300)			:= data_cnt
		statusReg(301)			:= timer_en
		statusReg(302)			:= timer_cnt




	val de_timer = Timer(deser(0).io.meta_in.fire(),write_deser(0).io.done.fire())
	val de_latency = de_timer.latency
	val de_start_cnt = de_timer.cnt_start
	val de_end_cnt = de_timer.cnt_end	

	val de1_timer = Timer(deser(1).io.meta_in.fire(),write_deser(1).io.done.fire())
	val de1_latency = de1_timer.latency
	val de1_start_cnt = de1_timer.cnt_start
	val de1_end_cnt = de1_timer.cnt_end

	val de2_timer = Timer(deser(2).io.meta_in.fire(),write_deser(2).io.done.fire())
	val de2_latency = de2_timer.latency
	val de2_start_cnt = de2_timer.cnt_start
	val de2_end_cnt = de2_timer.cnt_end

	val de3_timer = Timer(deser(3).io.meta_in.fire(),write_deser(3).io.done.fire())
	val de3_latency = de3_timer.latency
	val de3_start_cnt = de3_timer.cnt_start
	val de3_end_cnt = de3_timer.cnt_end		

	// val de4_timer = Timer(deser(4).io.meta_in.fire(),write_deser(4).io.done.fire())
	// val de4_latency = de4_timer.latency
	// val de4_start_cnt = de4_timer.cnt_start
	// val de4_end_cnt = de4_timer.cnt_end	

	// val de5_timer = Timer(deser(5).io.meta_in.fire(),write_deser(5).io.done.fire())
	// val de5_latency = de5_timer.latency
	// val de5_start_cnt = de5_timer.cnt_start
	// val de5_end_cnt = de5_timer.cnt_end

	// val de6_timer = Timer(deser(6).io.meta_in.fire(),write_deser(6).io.done.fire())
	// val de6_latency = de6_timer.latency
	// val de6_start_cnt = de6_timer.cnt_start
	// val de6_end_cnt = de6_timer.cnt_end

	// val de7_timer = Timer(deser(7).io.meta_in.fire(),write_deser(7).io.done.fire())
	// val de7_latency = de7_timer.latency
	// val de7_start_cnt = de7_timer.cnt_start
	// val de7_end_cnt = de7_timer.cnt_end	


	statusReg(403) := de_latency
	statusReg(404) := de_start_cnt
	statusReg(405) := de_end_cnt
	statusReg(406) := de1_latency
	statusReg(407) := de1_start_cnt
	statusReg(408) := de1_end_cnt
	statusReg(409) := de2_latency
	statusReg(410) := de2_start_cnt
	statusReg(411) := de2_end_cnt
	statusReg(412) := de3_latency
	statusReg(413) := de3_start_cnt
	statusReg(414) := de3_end_cnt
	// statusReg(415) := de4_latency
	// statusReg(416) := de4_start_cnt
	// statusReg(417) := de4_end_cnt
	// statusReg(418) := de5_latency
	// statusReg(419) := de5_start_cnt
	// statusReg(420) := de5_end_cnt
	// statusReg(421) := de6_latency
	// statusReg(422) := de6_start_cnt
	// statusReg(423) := de6_end_cnt
	// statusReg(424) := de7_latency
	// statusReg(425) := de7_start_cnt
	// statusReg(426) := de7_end_cnt






		//delay
		val latency_bucket = Module{new LatencyBucket(BUCKET_SIZE=1024,LATENCY_STRIDE=64)}

		latency_bucket.io.enable		:= controlReg(120)
		latency_bucket.io.start			:= read_host.io.ser_cmd_out.fire()
		latency_bucket.io.end			:= Arb_done.io.out.fire()
		latency_bucket.io.bucketRdId	:= controlReg(121)
		latency_bucket.io.resetBucket	:= reset




		Collector.report(latency_bucket.io.bucketValue, "REG_BUCKET_VALUE")



		class ila_probe(seq:Seq[Data]) extends BaseILA(seq)
		val instila_probe = Module(new ila_probe(Seq(	
			qdma.io.c2h_cmd.ready,
			qdma.io.c2h_cmd.valid,
		)))
		instila_probe.connect(clock)


	}

	// Connect DDR's ports

	Collector.connect_to_status_reg(statusReg, 200)
}