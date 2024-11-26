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


class StaticFpgaCloudTop extends RawModule {
	val qdma_pin		= IO(new QDMAPin())
	val cmac_pin		= IO(new CMACPin)
	val cmac_pin1		= IO(new CMACPin)
	// val cmac_pin2		= IO(new CMACPin)
	// val cmac_pin3		= IO(new CMACPin)
	val sysClkP			= IO(Input(Clock()))
	val sysClkN			= IO(Input(Clock()))
	val led		        = IO(Output(UInt(1.W)))

	led         		:= 0.U

	def TODO_32			= 32
	
	val mmcmTop	= Module(new MMCME4_ADV_Wrapper(
		CLKFBOUT_MULT_F 		= 12,
		MMCM_DIVCLK_DIVIDE		= 1,
		MMCM_CLKOUT0_DIVIDE_F	= 12,
		MMCM_CLKOUT1_DIVIDE_F	= 5,
		MMCM_CLKOUT2_DIVIDE_F	= 12,
		MMCM_CLKOUT3_DIVIDE_F	= 5,
		MMCM_CLKIN1_PERIOD 		= 10
	))

	mmcmTop.io.CLKIN1	:= IBUFDS(sysClkP,sysClkN)
	mmcmTop.io.RST		:= 0.U

	val clk_hbm_driver	= mmcmTop.io.CLKOUT0 //100M
	val userClk			= mmcmTop.io.CLKOUT1 //240M
	val cmacClk			= mmcmTop.io.CLKOUT2 //100M

	//HBM
    val hbmDriver 		= withClockAndReset(clk_hbm_driver, false.B) {Module(new HBM_DRIVER(WITH_RAMA=false))}
	hbmDriver.getTCL()
	val hbmClk 	    	= hbmDriver.io.hbm_clk
	val hbmRstn     	= withClockAndReset(hbmClk,false.B) {RegNext(hbmDriver.io.hbm_rstn.asBool)}
    
	val userRstn		= withClockAndReset(userClk,false.B) {ShiftRegister(hbmRstn,4)}

	for (i <- 0 until 32) {
		hbmDriver.io.axi_hbm(i).hbm_init()	// Read hbm_init function if you're not familiar with AXI.
	}

	dontTouch(hbmClk)
	dontTouch(hbmRstn)
	//QDMA
	val qdma 			= Module(new QDMA("202101"))
	qdma.getTCL()
	ToZero(qdma.io.reg_status)
	ToZero(qdma.io.c2h_data.bits)
	ToZero(qdma.io.h2c_cmd.bits)
	ToZero(qdma.io.c2h_cmd.bits)
	qdma.io.h2c_data.ready	:= 0.U
	qdma.io.c2h_data.valid	:= 0.U
	qdma.io.h2c_cmd.valid	:= 0.U
	qdma.io.c2h_cmd.valid	:= 0.U

	qdma.io.pin <> qdma_pin
	qdma.io.user_clk	:= userClk
	qdma.io.user_arstn	:= userRstn

	val controlReg = qdma.io.reg_control
	val statusReg = qdma.io.reg_status
	ToZero(statusReg)

	val sw_resetn	= withClockAndReset(userClk,false.B){RegNext(((userRstn & ~controlReg(0)(0)).asClock).asBool)}




	val cmacInst = Module(new XCMAC(BOARD="u280", PORT=0, IP_CORE_NAME="CMACBlackBox2"))
	cmacInst.getTCL()
	// Connect CMAC's pins
	cmacInst.io.pin			<> cmac_pin
	cmacInst.io.drp_clk		:= cmacClk
	cmacInst.io.user_clk	:= userClk
	cmacInst.io.user_arstn	:= sw_resetn
	cmacInst.io.sys_reset	:= !userRstn
	cmacInst.io.m_net_rx.ready  := 1.U
	ToZero(cmacInst.io.s_net_tx.bits)
	cmacInst.io.s_net_tx.valid  := 0.U



    //network
	val roce								= Module(new NetworkStack(PART_ID=1,IP_CORE_NAME="CMACBlackBox"))
	roce.io.pin								<> cmac_pin1
	roce.io.user_clk						:= userClk
	roce.io.user_arstn						:= sw_resetn
	roce.io.sys_reset						:= !userRstn
	roce.io.drp_clk							:= cmacClk
	roce.io.m_mem_read_cmd.ready			:= 1.U
	roce.io.m_mem_write_cmd.ready			:= 1.U
	roce.io.m_mem_write_data.ready			:= 1.U
	roce.io.s_mem_read_data.valid			:= 0.U
	roce.io.m_cmpt_meta.ready				:= 1.U
	roce.io.arp_rsp.ready					:= 1.U
	roce.io.arp_req.valid					:= 0.U
	roce.io.sw_reset						:= !sw_resetn
	ToZero(roce.io.s_mem_read_data.bits)
	ToZero(roce.io.qp_init.bits)

    roce.io.qp_init.bits.remote_udp_port	:= 17.U	

    //roce init
	withClockAndReset(userClk,!sw_resetn) {
		val start 							= RegNext(controlReg(101) === 1.U)
		val risingStartInit					= start && RegNext(!start)
		val valid 							= RegInit(UInt(1.W),0.U)
		when(risingStartInit === 1.U){
			valid							:= 1.U
		}.elsewhen(roce.io.qp_init.fire()){
			valid							:= 0.U
		}
		roce.io.qp_init.valid				:= valid
		roce.io.qp_init.bits.remote_ip		:= 0x52bda8c0.U
		roce.io.ip_address					:= 0x51bda8c0.U//0x01bda8c0 01/189/168/192
		roce.io.qp_init.bits.credit			:= controlReg(103)

		val cur_qp							= RegInit(UInt(1.W),0.U)
		when(roce.io.qp_init.fire()){
			cur_qp							:= cur_qp + 1.U
		}

		when(cur_qp === 0.U){
			roce.io.qp_init.bits.qpn			:= 1.U
			roce.io.qp_init.bits.remote_qpn		:= 1.U
			roce.io.qp_init.bits.local_psn		:= 0x1001.U
			roce.io.qp_init.bits.remote_psn		:= 0x2001.U
		}.otherwise{
			roce.io.qp_init.bits.qpn			:= 2.U
			roce.io.qp_init.bits.remote_qpn		:= 2.U
			roce.io.qp_init.bits.local_psn		:= 0x1002.U
			roce.io.qp_init.bits.remote_psn		:= 0x2002.U
		}

		val valid_arp						= RegInit(UInt(1.W),0.U)
		when(risingStartInit === 1.U){
			valid_arp						:= 1.U
		}.elsewhen(roce.io.arp_req.fire()){
			valid_arp						:= 0.U
		}
		roce.io.arp_req.valid				:= valid_arp
		roce.io.arp_req.bits				:= 0x52bda8c0.U


    val net_to_mem = Module(new NetToMem())
	
    val mem_to_net = Module(new MemToNet())
    
	val split_L1 = (Module(new SplitDeMul()))


	val ser = Seq.fill(2)(Module(new SerializerSimple()))
    // val deser = Seq.fill(8)(Module(new Deserializer()))
    // val write_deser = Seq.fill(8)(Module(new WriteDeser()))
	val deser = Seq.fill(2)(Module(new DeserializerSimple()))
    val meta_table = Seq.fill(2)(Module(new ClassMetaTable()))


    val der_to_mem = Seq.fill(2)(Module(new DerToMem()))

	val ser_hbm = Seq.fill(2)(Module(new AXISToHbm()))
	val eng_hbm = Seq.fill(2)(Module(new AXISToHbm()))

	val control = Module(new ControlMul())

	val read_host = Seq.fill(2)(Module(new ReadHost()))

	val eng_sim = Seq.fill(2)(Module(new EngineSim()))


	val arbiter	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)

	val Arb_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)
	val Ard_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)



	(qdma.io.c2h_cmd)	<> RegSlice(arbiter.io.out_meta) 
	(qdma.io.c2h_data)	<> RegSlice(arbiter.io.out_data)
	arbiter.io.in_meta(0)	<> Ard_L1.io.out_meta
	arbiter.io.in_data(0)	<> Ard_L1.io.out_data
	arbiter.io.in_meta(1)	<> Arb_L1.io.out_meta
	arbiter.io.in_data(1)	<> Arb_L1.io.out_data


	for(i<- 0 until 2){
		Arb_L1.io.in_meta(i)	<> eng_sim(i).io.host_write_cmd    
		Arb_L1.io.in_data(i)   	<> eng_sim(i).io.host_write_data			
	}     

	for(i<- 0 until 2){
		Ard_L1.io.in_meta(i)	<> der_to_mem(i).io.m_mem_write_cmd    
		Ard_L1.io.in_data(i)   	<> der_to_mem(i).io.m_mem_write_data		
	}	



	val Router_L1	= SerialRouter(new H2C_DATA(),2)
	val Arb_DMA	= XArbiter(new H2C_CMD(),2)
	val q_fifo = XQueue(UInt(8.W),4096)

	qdma.io.h2c_data			<> Router_L1.io.in

	Router_L1.io.in.bits.tuser_qid	:= q_fifo.io.out.bits
	q_fifo.io.out.ready				:= qdma.io.h2c_data.fire()

	Router_L1.io.idx 				<> Router_L1.io.in.bits.tuser_qid(0)
	for(i<- 0 until 2){ 
		Router_L1.io.out(i).valid 		<> read_host(i).io.s_mem_read_data.valid
		Router_L1.io.out(i).ready 		<> read_host(i).io.s_mem_read_data.ready
		Router_L1.io.out(i).bits.data 	<> read_host(i).io.s_mem_read_data.bits.data
		Router_L1.io.out(i).bits.last 	<> read_host(i).io.s_mem_read_data.bits.last
		read_host(i).io.s_mem_read_data.bits.keep		:= -1.S(64.W).asTypeOf(UInt(64.W))		
	} 



	Arb_DMA.io.out							<> qdma.io.h2c_cmd
	q_fifo.io.in.valid						:= Arb_DMA.io.out.fire()
	q_fifo.io.in.bits						:= Arb_DMA.io.out.bits.qid
	qdma.io.h2c_cmd.bits.qid			:= 0.U

	for(i<- 0 until 2){ 
		ToZero(Arb_DMA.io.in(i).bits)				
		Arb_DMA.io.in(i).valid				<> read_host(i).io.m_mem_read_cmd.valid
		Arb_DMA.io.in(i).ready				<> read_host(i).io.m_mem_read_cmd.ready
		Arb_DMA.io.in(i).bits.addr			<> read_host(i).io.m_mem_read_cmd.bits.vaddr
		Arb_DMA.io.in(i).bits.len			<> read_host(i).io.m_mem_read_cmd.bits.length
		Arb_DMA.io.in(i).bits.eop			<> 1.U
		Arb_DMA.io.in(i).bits.sop			<> 1.U
		Arb_DMA.io.in(i).bits.qid			<> i.U
	}

		control.io.axi 								<> qdma.io.axib
		roce.io.s_send_data							<> mem_to_net.io.m_send_data
		net_to_mem.io.s_recv_data					<> roce.io.m_recv_data
        mem_to_net.io.s_tx_meta      				<> roce.io.s_tx_meta  	        

        net_to_mem.io.s_recv_meta    				<> roce.io.m_recv_meta  
        net_to_mem.io.deser_meta_out     		<> split_L1.io.meta_in
        net_to_mem.io.deser_data_out     		<> split_L1.io.data_in     

	val A_Ser_L1	= CompositeArbiter(new SerOutMeta,new AXIS(512),2)


	for(i<- 0 until 2){
		A_Ser_L1.io.in_meta(i)		<> ser(i).io.meta_out    
		A_Ser_L1.io.in_data(i)   	<> ser(i).io.data_out		
	} 

    mem_to_net.io.meta_in             <> A_Ser_L1.io.out_meta
    mem_to_net.io.data_in             <> A_Ser_L1.io.out_data   
    mem_to_net.io.qpn                 := 1.U


		split_L1.io.de_idle         	:= Cat(deser(1).io.idle_out,deser(0).io.idle_out)
		for(i<- 0 until 2){
			split_L1.io.split_meta_out(i)	<> deser(i).io.meta_in    
			split_L1.io.split_data_out(i)   <> deser(i).io.data_in			
		}                

			

	for(i<- 0 until 2){

		control.io.free_index(i) 		<> der_to_mem(i).io.free_index
		control.io.metadata_init(i) 	<> meta_table(i).io.class_meta_init
		control.io.ser_cmd(i)    	 	<> read_host(i).io.ser_cmd
		control.io.eng_cmd(i)			<> read_host(i).io.eng_cmd

		read_host(i).io.eng_cmd_out         <> eng_sim(i).io.meta_in
		read_host(i).io.eng_host_data_out   <> eng_sim(i).io.host_data_in
		read_host(i).io.eng_device_data_out <> eng_sim(i).io.device_data_in

		read_host(i).io.ser_cmd_out         <> ser(i).io.meta_in
		read_host(i).io.ser_host_data_out   <> ser(i).io.host_data_in
		read_host(i).io.ser_device_data_out <> ser(i).io.device_data_in

		deser(i).io.total_thread_num		:= controlReg(200)
		deser(i).io.thread_num				:= i.U
		// write_deser(i).io.writer_req          	<> deser(i).io.writer_req
		deser(i).io.meta_out              <> der_to_mem(i).io.meta_in
		deser(i).io.host_data_out         <> der_to_mem(i).io.host_data_in
		deser(i).io.device_data_out       <> der_to_mem(i).io.device_data_in



		deser(i).io.class_meta_req <> meta_table(i).io.d_class_meta_req
		deser(i).io.class_meta_rsp <> meta_table(i).io.d_class_meta_rsp

		ser(i).io.class_meta_req <> meta_table(i).io.s_class_meta_req
		ser(i).io.class_meta_rsp <> meta_table(i).io.s_class_meta_rsp

		der_to_mem(i).io.dma_base_addr  := Cat(controlReg(i*11+111), controlReg(i*11+110))
		der_to_mem(i).io.hbm_base_addr  := Cat(controlReg(i*11+113), controlReg(i*11+112))
		der_to_mem(i).io.notice_addr	:= Cat(controlReg(i*11+118), controlReg(i*11+117))
		der_to_mem(i).io.thread_num		:= controlReg(i*11+119)
		eng_sim(i).io.delay_time		:= controlReg(i*11+116)
		eng_sim(i).io.notice_addr		:= Cat(controlReg(i*11+115), controlReg(i*11+114))
		eng_sim(i).io.thread_num		:= controlReg(i*11+120)
		
		

        ser_hbm(i).io.userClk     	:= userClk
        ser_hbm(i).io.userRstn    	:= sw_resetn
        ser_hbm(i).io.hbmClk      	:= hbmClk
        ser_hbm(i).io.hbmRstn     	:= hbmRstn
        ser_hbm(i).io.hbmCtrlAr   	<> read_host(i).io.serhbmCtrlAr
        ser_hbm(i).io.hbmCtrlR    	<> read_host(i).io.serhbmCtrlR
		ser_hbm(i).io.hbmCtrlAw		<> eng_sim(i).io.enghbmCtrlAw
		ser_hbm(i).io.hbmCtrlW		<> eng_sim(i).io.enghbmCtrlW


        eng_hbm(i).io.userClk     	:= userClk
        eng_hbm(i).io.userRstn    	:= sw_resetn
        eng_hbm(i).io.hbmClk      	:= hbmClk
        eng_hbm(i).io.hbmRstn     	:= hbmRstn
        eng_hbm(i).io.hbmCtrlAr   	<> read_host(i).io.enghbmCtrlAr
        eng_hbm(i).io.hbmCtrlR    	<> read_host(i).io.enghbmCtrlR
		eng_hbm(i).io.hbmCtrlAw		<> der_to_mem(i).io.hbmCtrlAw
		eng_hbm(i).io.hbmCtrlW		<> der_to_mem(i).io.hbmCtrlW

		
		
		hbmDriver.io.axi_hbm(i*8) <>  withClockAndReset(hbmClk,!hbmRstn){AXIRegSlice(1)(ser_hbm(i).io.hbmAxi)}
		hbmDriver.io.axi_hbm(i*8+1) <>  withClockAndReset(hbmClk,!hbmRstn){AXIRegSlice(1)(eng_hbm(i).io.hbmAxi)}
	}
		

	val n2m_timer = Timer(net_to_mem.io.s_recv_meta.fire(),net_to_mem.io.deser_meta_out.fire())
	val n2m_latency = n2m_timer.latency
	val n2m_start_cnt = n2m_timer.cnt_start
	val n2m_end_cnt = n2m_timer.cnt_end

	val de_timer = Timer(deser(0).io.meta_in.fire(),deser(0).io.meta_out.fire())
	val de_latency = de_timer.latency
	val de_start_cnt = de_timer.cnt_start
	val de_end_cnt = de_timer.cnt_end	

	val d2m_timer = Timer(der_to_mem(0).io.meta_in.fire(),read_host(0).io.eng_cmd.fire())
	val d2m_latency = d2m_timer.latency
	val d2m_start_cnt = d2m_timer.cnt_start
	val d2m_end_cnt = d2m_timer.cnt_end	

	val eng_timer = Timer(read_host(0).io.eng_cmd.fire(),read_host(0).io.ser_cmd.fire())
	val eng_latency = eng_timer.latency
	val eng_start_cnt = eng_timer.cnt_start
	val eng_end_cnt = eng_timer.cnt_end

	val ser_timer = Timer(read_host(0).io.ser_cmd.fire(),ser(0).io.meta_out.fire())
	val ser_latency = ser_timer.latency
	val ser_start_cnt = ser_timer.cnt_start
	val ser_end_cnt = ser_timer.cnt_end

	val de_timer1 = Timer(deser(1).io.meta_in.fire(),deser(1).io.meta_out.fire())
	val de_latency1 = de_timer1.latency
	val de_start_cnt1 = de_timer1.cnt_start
	val de_end_cnt1 = de_timer1.cnt_end	

	val d2m_timer1 = Timer(der_to_mem(1).io.meta_in.fire(),read_host(1).io.eng_cmd.fire())
	val d2m_latency1 = d2m_timer1.latency
	val d2m_start_cnt1 = d2m_timer1.cnt_start
	val d2m_end_cnt1 = d2m_timer1.cnt_end	

	val eng_timer1 = Timer(read_host(1).io.eng_cmd.fire(),read_host(1).io.ser_cmd.fire())
	val eng_latency1 = eng_timer1.latency
	val eng_start_cnt1 = eng_timer1.cnt_start
	val eng_end_cnt1 = eng_timer1.cnt_end

	val ser_timer1 = Timer(read_host(1).io.ser_cmd.fire(),ser(1).io.meta_out.fire())
	val ser_latency1 = ser_timer1.latency
	val ser_start_cnt1 = ser_timer1.cnt_start
	val ser_end_cnt1 = ser_timer1.cnt_end



	val m2n_timer = Timer(mem_to_net.io.meta_in.fire(),mem_to_net.io.s_tx_meta.fire())
	val m2n_latency = m2n_timer.latency
	val m2n_start_cnt = m2n_timer.cnt_start
	val m2n_end_cnt = m2n_timer.cnt_end	

	statusReg(403) := n2m_latency
	statusReg(404) := n2m_start_cnt
	statusReg(405) := n2m_end_cnt
	statusReg(406) := de_latency
	statusReg(407) := de_start_cnt
	statusReg(408) := de_end_cnt
	statusReg(409) := d2m_latency
	statusReg(410) := d2m_start_cnt
	statusReg(411) := d2m_end_cnt
	statusReg(412) := eng_latency
	statusReg(413) := eng_start_cnt
	statusReg(414) := eng_end_cnt
	statusReg(415) := ser_latency
	statusReg(416) := ser_start_cnt
	statusReg(417) := ser_end_cnt
	statusReg(418) := m2n_latency
	statusReg(419) := m2n_start_cnt
	statusReg(420) := m2n_end_cnt

	statusReg(421) := de_latency1
	statusReg(422) := de_start_cnt1
	statusReg(423) := de_end_cnt1
	statusReg(424) := d2m_latency1
	statusReg(425) := d2m_start_cnt1
	statusReg(426) := d2m_end_cnt1
	statusReg(427) := eng_latency1
	statusReg(428) := eng_start_cnt1
	statusReg(429) := eng_end_cnt1
	statusReg(430) := ser_latency1
	statusReg(431) := ser_start_cnt1
	statusReg(432) := ser_end_cnt1

	



	}
	Collector.connect_to_status_reg(statusReg, 100)

		// val qdmaInst_c2h_data = WireInit(0.U(64.W))
		// qdmaInst_c2h_data 	:= qdma.io.h2c_data.bits.data(63,0)
		// class ila_net(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_net = Module(new ila_net(Seq(	
		// 	qdma.io.h2c_cmd,
		// 	qdma.io.h2c_data.valid,
		// 	qdma.io.h2c_data.ready,
		// 	qdmaInst_c2h_data

		// )))
		// instila_net.connect(clock)

}