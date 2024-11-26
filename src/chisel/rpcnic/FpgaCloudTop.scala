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


class FpgaCloudTop extends MultiIOModule {
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

	val dbgBridgeInst = DebugBridge(IP_CORE_NAME="DebugBridge",clk=clock)
	dbgBridgeInst.getTCL()

	dontTouch(io)
	// io.cmacPin.get <> DontCare

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
	// qdmaInst.io.c2h_data.valid	:= 0.U
	qdmaInst.io.c2h_data.bits	:= 0.U.asTypeOf(new C2H_DATA)

	// qdmaInst.io.h2c_cmd.valid	:= 0.U
	qdmaInst.io.h2c_cmd.bits	:= 0.U.asTypeOf(new H2C_CMD)
	// qdmaInst.io.c2h_cmd.valid	:= 0.U
	qdmaInst.io.c2h_cmd.bits	:= 0.U.asTypeOf(new C2H_CMD)


	val cmacInst = Module(new XCMAC(BOARD="u280", PORT=0, IP_CORE_NAME="CMACBlackBox2"))
	cmacInst.getTCL()
	// Connect CMAC's pins
	cmacInst.io.pin			<> io.cmacPin.get
	cmacInst.io.drp_clk		:= io.cmacClk.get
	cmacInst.io.user_clk	:= userClk
	cmacInst.io.user_arstn	:= ~reset.asBool
	cmacInst.io.sys_reset	:= reset
	cmacInst.io.m_net_rx.ready  := 1.U
	ToZero(cmacInst.io.s_net_tx.bits)
	cmacInst.io.s_net_tx.valid  := 0.U



    //network
	val roce								= Module(new NetworkStack(PART_ID=1,IP_CORE_NAME="CMACBlackBox"))
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
	val split_deser = (Module(new SplitDe()))
    val mem_to_net = Module(new MemToNet())
    

    // val ser = Module(new Serializer())
    // val write_ser = Module(new WriteSer())
	val ser = (Module(new SerializerSimple()))
    val deser = Module(new DeserializerSimple())
    // val write_deser = Module(new WriteDeser())
    val meta_table = Module(new ClassMetaTable())


    val der_to_mem = Module(new DerToMem())

	val ser_hbm = Module(new AXISToHbm())

	val eng_hbm = Module(new AXISToHbm())

	val control = Module(new Control())

	val read_host = Module(new ReadHost())

	val eng_sim = Module(new EngineSim())





	val arbiter	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)

	(qdmaInst.io.c2h_cmd)	<> RegSlice(arbiter.io.out_meta) 
	(qdmaInst.io.c2h_data)	<> RegSlice(arbiter.io.out_data)
	arbiter.io.in_meta(0)	<> der_to_mem.io.m_mem_write_cmd
	arbiter.io.in_data(0)	<> der_to_mem.io.m_mem_write_data
	arbiter.io.in_meta(1)	<> eng_sim.io.host_write_cmd
	arbiter.io.in_data(1)	<> eng_sim.io.host_write_data


    read_host.io.eng_cmd_out         <> eng_sim.io.meta_in
    read_host.io.eng_host_data_out   <> eng_sim.io.host_data_in
    read_host.io.eng_device_data_out <> eng_sim.io.device_data_in
    


    read_host.io.ser_cmd_out         <> ser.io.meta_in
    read_host.io.ser_host_data_out   <> ser.io.host_data_in
    read_host.io.ser_device_data_out <> ser.io.device_data_in


	control.io.axi 				<> qdmaInst.io.axib	
	control.io.free_index 		<> der_to_mem.io.free_index
    control.io.metadata_init 	<> meta_table.io.class_meta_init
    control.io.ser_cmd    	 	<> read_host.io.ser_cmd
	control.io.eng_cmd			<> read_host.io.eng_cmd



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

		roce.io.s_send_data							<> mem_to_net.io.m_send_data

		net_to_mem.io.s_recv_data					<> roce.io.m_recv_data



        mem_to_net.io.s_tx_meta      <> roce.io.s_tx_meta  	        



        net_to_mem.io.s_recv_meta    <> roce.io.m_recv_meta   

        // net_to_mem.io.start               <> Delay(net_to_mem.io.done, 200)

        net_to_mem.io.deser_meta_out     <> split_deser.io.meta_in
        net_to_mem.io.deser_data_out     <> split_deser.io.data_in                     
                     
        split_deser.io.de_idle         		<> deser.io.idle_out  
        split_deser.io.split_meta_out		<> deser.io.meta_in    
        split_deser.io.split_data_out    	<> deser.io.data_in


        mem_to_net.io.meta_in             <> ser.io.meta_out//write_ser
        mem_to_net.io.data_in             <> ser.io.data_out//write_ser  
        mem_to_net.io.qpn                 := 1.U                 




        // write_deser.io.writer_req          <> deser.io.writer_req
        deser.io.meta_out              <> der_to_mem.io.meta_in
        deser.io.host_data_out         <> der_to_mem.io.host_data_in
        deser.io.device_data_out       <> der_to_mem.io.device_data_in

		deser.io.thread_num				:= 0.U
		deser.io.total_thread_num		:= 1.U
    	// ser.io.writer_req       <> write_ser.io.writer_req
    	// ser.io.done             <> write_ser.io.done

    

    	ser.io.class_meta_req <> meta_table.io.s_class_meta_req
    	ser.io.class_meta_rsp <> meta_table.io.s_class_meta_rsp

    	deser.io.class_meta_req <> meta_table.io.d_class_meta_req
    	deser.io.class_meta_rsp <> meta_table.io.d_class_meta_rsp


        ser_hbm.io.userClk     := clock
        ser_hbm.io.userRstn    := !(reset.asBool)
        ser_hbm.io.hbmClk      := hbmClk
        ser_hbm.io.hbmRstn     := hbmRstn
        ser_hbm.io.hbmCtrlAr   <> read_host.io.serhbmCtrlAr
        ser_hbm.io.hbmCtrlR    <> read_host.io.serhbmCtrlR
		ser_hbm.io.hbmCtrlAw	<> eng_sim.io.enghbmCtrlAw
		ser_hbm.io.hbmCtrlW		<> eng_sim.io.enghbmCtrlW


        eng_hbm.io.userClk     := clock
        eng_hbm.io.userRstn    := !(reset.asBool)
        eng_hbm.io.hbmClk      := hbmClk
        eng_hbm.io.hbmRstn     := hbmRstn
        eng_hbm.io.hbmCtrlAr   <> read_host.io.enghbmCtrlAr
        eng_hbm.io.hbmCtrlR    <> read_host.io.enghbmCtrlR
		eng_hbm.io.hbmCtrlAw	<> der_to_mem.io.hbmCtrlAw
		eng_hbm.io.hbmCtrlW		<> der_to_mem.io.hbmCtrlW


        der_to_mem.io.dma_base_addr  := Cat(controlReg(111), controlReg(110))
        der_to_mem.io.hbm_base_addr  := Cat(controlReg(113), controlReg(112))

		eng_sim.io.delay_time		:= controlReg(116)
		eng_sim.io.notice_addr		:= Cat(controlReg(115), controlReg(114))
		der_to_mem.io.notice_addr	:= Cat(controlReg(118), controlReg(117))

	// Connect DDR's ports
	// io.ddrPort2.get.axi		<> withClockAndReset(ddrClk,ddrRst){ AXIRegSlice(2)(XAXIConverter(net_to_mem.io.axi_ddr, userClk, userRstn, ddrClk, !ddrRst))}

	io.ddrPort2.get.axi.qdma_init()

	hbmDriver.io.axi_hbm(9) <>  withClockAndReset(hbmClk,!hbmRstn){AXIRegSlice(2)(ser_hbm.io.hbmAxi)}

	hbmDriver.io.axi_hbm(10) <>  withClockAndReset(hbmClk,!hbmRstn){AXIRegSlice(2)(eng_hbm.io.hbmAxi)}

	val time_cnt = RegInit(UInt(32.W), 0.U) 
	time_cnt := time_cnt + 1.U

		val ser_meta_ready = RegNext(ser.io.meta_in.ready)
		val ser_meta_valid = RegNext(ser.io.meta_in.valid)

		// class ila_net(seq:Seq[Data]) extends BaseILA(seq)
		// val instila_net = Module(new ila_net(Seq(	
		// 	time_cnt,
		// 	roce.io.s_tx_meta.valid,
		// 	roce.io.s_tx_meta.ready,
		// 	roce.io.m_recv_meta.valid,
		// 	roce.io.m_recv_meta.ready,			
		// 	der_to_mem.io.m_mem_write_cmd.ready,
		// 	der_to_mem.io.m_mem_write_cmd.valid,
		// 	eng_sim.io.meta_in.ready,
		// 	eng_sim.io.meta_in.valid,
		// 	ser_meta_ready,
		// 	ser_meta_valid,
		// )))
		// instila_net.connect(clock)


	val n2m_timer = Timer(net_to_mem.io.s_recv_meta.fire(),net_to_mem.io.deser_meta_out.fire())
	val n2m_latency = n2m_timer.latency
	val n2m_start_cnt = n2m_timer.cnt_start
	val n2m_end_cnt = n2m_timer.cnt_end

	val de_timer = Timer(deser.io.meta_in.fire(),deser.io.meta_out.fire())
	val de_latency = de_timer.latency
	val de_start_cnt = de_timer.cnt_start
	val de_end_cnt = de_timer.cnt_end	

	val d2m_timer = Timer(der_to_mem.io.meta_in.fire(),read_host.io.eng_cmd.fire())
	val d2m_latency = d2m_timer.latency
	val d2m_start_cnt = d2m_timer.cnt_start
	val d2m_end_cnt = d2m_timer.cnt_end	

	val eng_timer = Timer(read_host.io.eng_cmd.fire(),read_host.io.ser_cmd.fire())
	val eng_latency = eng_timer.latency
	val eng_start_cnt = eng_timer.cnt_start
	val eng_end_cnt = eng_timer.cnt_end

	val ser_timer = Timer(read_host.io.ser_cmd.fire(),ser.io.meta_out.fire())
	val ser_latency = ser_timer.latency
	val ser_start_cnt = ser_timer.cnt_start
	val ser_end_cnt = ser_timer.cnt_end

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


	}
	Collector.connect_to_status_reg(statusReg, 300)




}