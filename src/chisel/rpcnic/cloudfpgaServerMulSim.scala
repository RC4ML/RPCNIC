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

class cloudfpgaServerMulSim() extends Module{
	val io = IO(new Bundle{

        val qpn                 = Input(UInt(16.W)) 

		val axib 				= Flipped(new AXIB)      

        val m_mem_read_cmd      = (Decoupled(new MEM_CMD()))
        val s_mem_read_data	    = Flipped(Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
        val m_mem_write_cmd     = (Decoupled(new MEM_CMD()))
        val m_mem_write_data	= (Decoupled(new AXIS(CONFIG.DATA_WIDTH)))

		val s_mac_rx			= Flipped(Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
		val m_mac_tx			= (Decoupled(new AXIS(CONFIG.DATA_WIDTH)))

        val qp_init	            = Flipped(Decoupled(new QP_INIT()))
        val local_ip_address    = Input(UInt(32.W))

        val arp_req             =   Flipped(Decoupled(UInt(32.W)))
        val arp_rsp             =   Decoupled(new mac_out)     
	})

    val roce = (Module(new ROCE_IP()))


    val ip = (Module(new IPTest()))

    val net_to_mem = (Module(new NetToMem()))

    val mem_to_net = (Module(new MemToNet()))

    // val ddr_sim = (Module(new DDRSimBlackbox()))
    // val ddr1_sim = (Module(new DDRSimBlackbox()))
    // val hbm_sim1 = Seq.fill(8)(Module(new DDRSimBlackbox()))
    // val hbm_sim2 = Seq.fill(8)(Module(new DDRSimBlackbox()))
    
    // val hbmctrl = (Module(new AXISToHbm()))
	val split_L1 = (Module(new SplitDeMul()))

    val ser = Seq.fill(2)(Module(new SerializerSimple()))
    // val write_ser = (Module(new WriteSer()))
    val deser = Seq.fill(2)(Module(new DeserializerBase()))
    // val write_deser = (Module(new WriteDeser()))
    val meta_table = Seq.fill(2)(Module(new ClassMetaTable()))


    val der_to_mem = Seq.fill(2)(Module(new DerToMem()))


	val ser_hbm = Seq.fill(2)(Module(new AXISToHbmSim()))

	val eng_hbm = Seq.fill(2)(Module(new AXISToHbmSim()))

	// val control = (Module(new Control()))

	val read_host = Seq.fill(2)(Module(new ReadHost()))

	val eng_sim = Seq.fill(2)(Module(new EngineSim()))

	val arbiter	= (CompositeArbiter(new C2H_CMD,new C2H_DATA,2))

	val control = (Module(new ControlMul()))

	val Arb_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)

	val Ard_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)
    	ip.io.s_mac_rx               <> io.s_mac_rx
		ip.io.m_mac_tx               <> io.m_mac_tx
    	roce.io.s_net_rx_data        <> ip.io.m_roce_rx
        roce.io.m_net_tx_data        <> ip.io.s_ip_tx

        ip.io.m_tcp_rx.ready         := 1.U
        ip.io.m_udp_rx.ready         := 1.U   
        ip.io.arp_req                <> io.arp_req 
        ip.io.arp_rsp                <> io.arp_rsp 
	        
        io.qp_init                   <> roce.io.qp_init
        io.local_ip_address          <> roce.io.local_ip_address 

        roce.io.m_mem_write_cmd.ready    := 1.U  
        roce.io.m_mem_write_data.ready    := 1.U 
        roce.io.m_mem_read_cmd.ready     := 1.U
        roce.io.s_mem_read_data.valid    := 0.U
        roce.io.s_mem_read_data.bits     := 0.U.asTypeOf(roce.io.s_mem_read_data.bits)
  
           
        roce.io.m_cmpt_meta.ready        := 1.U

    io.m_mem_write_cmd.valid          := arbiter.io.out_meta.valid
    io.m_mem_write_cmd.bits.vaddr     := arbiter.io.out_meta.bits.addr
    io.m_mem_write_cmd.bits.length    := arbiter.io.out_meta.bits.len
    arbiter.io.out_meta.ready         := io.m_mem_write_cmd.ready

    io.m_mem_write_data.valid        := arbiter.io.out_data.valid
    io.m_mem_write_data.bits.data    := arbiter.io.out_data.bits.data
    io.m_mem_write_data.bits.keep    := -1.S(64.W).asTypeOf(UInt(64.W)) 
    io.m_mem_write_data.bits.last    := arbiter.io.out_data.bits.last
    arbiter.io.out_data.ready        := io.m_mem_write_data.ready


	control.io.axi 								<> io.axib





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

	ToZero(Router_L1.io.in.bits)


	io.s_mem_read_data.ready			<> Router_L1.io.in.ready
	io.s_mem_read_data.valid			<> Router_L1.io.in.valid
	io.s_mem_read_data.bits.data		<> Router_L1.io.in.bits.data
	io.s_mem_read_data.bits.last		<> Router_L1.io.in.bits.last

	Router_L1.io.in.bits.tuser_qid	:= q_fifo.io.out.bits
	q_fifo.io.out.ready				:= io.s_mem_read_data.fire()

	Router_L1.io.idx 				<> Router_L1.io.in.bits.tuser_qid(0)
	for(i<- 0 until 2){ 
		Router_L1.io.out(i).valid 		<> read_host(i).io.s_mem_read_data.valid
		Router_L1.io.out(i).ready 		<> read_host(i).io.s_mem_read_data.ready
		Router_L1.io.out(i).bits.data 	<> read_host(i).io.s_mem_read_data.bits.data
		Router_L1.io.out(i).bits.last 	<> read_host(i).io.s_mem_read_data.bits.last
		read_host(i).io.s_mem_read_data.bits.keep		:= -1.S(64.W).asTypeOf(UInt(64.W))		
	} 





	Arb_DMA.io.out.ready					<> io.m_mem_read_cmd.ready
	Arb_DMA.io.out.valid					<> io.m_mem_read_cmd.valid
	Arb_DMA.io.out.bits.addr				<> io.m_mem_read_cmd.bits.vaddr
	Arb_DMA.io.out.bits.len					<> io.m_mem_read_cmd.bits.length


	q_fifo.io.in.valid						:= Arb_DMA.io.out.fire()
	q_fifo.io.in.bits						:= Arb_DMA.io.out.bits.qid


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


		
		roce.io.s_send_data							<> mem_to_net.io.m_send_data
		net_to_mem.io.s_recv_data					<> roce.io.m_recv_data

        mem_to_net.io.s_tx_meta      				<> roce.io.s_tx_meta 
		net_to_mem.io.s_recv_meta    				<> roce.io.m_recv_meta 	        

  
     

	val A_Ser_L1	= CompositeArbiter(new SerOutMeta,new AXIS(512),2)

    mem_to_net.io.meta_in             <> A_Ser_L1.io.out_meta
    mem_to_net.io.data_in             <> A_Ser_L1.io.out_data   
    mem_to_net.io.qpn                 := 1.U

	for(i<- 0 until 2){
		A_Ser_L1.io.in_meta(i)		<> ser(i).io.meta_out    
		A_Ser_L1.io.in_data(i)   	<> ser(i).io.data_out		
	} 





        net_to_mem.io.deser_meta_out     		<> split_L1.io.meta_in
        net_to_mem.io.deser_data_out     		<> split_L1.io.data_in     


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

		deser(i).io.meta_out              <> der_to_mem(i).io.meta_in
		deser(i).io.host_data_out         <> der_to_mem(i).io.host_data_in
		deser(i).io.device_data_out       <> der_to_mem(i).io.device_data_in
		
		deser(i).io.total_thread_num		:= 1.U
		deser(i).io.thread_num				:= i.U

		deser(i).io.class_meta_req <> meta_table(i).io.d_class_meta_req
		deser(i).io.class_meta_rsp <> meta_table(i).io.d_class_meta_rsp

		ser(i).io.class_meta_req <> meta_table(i).io.s_class_meta_req
		ser(i).io.class_meta_rsp <> meta_table(i).io.s_class_meta_rsp

    // deser.io.deser_done.ready:=1.U



		// hbm_sim1(i).io.s_aresetn 					:= !(reset.asBool)
		// hbm_sim1(i).io.s_aclk 					    := clock
		// hbm_sim1(i).io.s_axi_awid              	    := ser_hbm(i).io.hbmAxi.aw.bits.id
		// hbm_sim1(i).io.s_axi_awaddr              	:= ser_hbm(i).io.hbmAxi.aw.bits.addr
		// hbm_sim1(i).io.s_axi_awlen              	:= ser_hbm(i).io.hbmAxi.aw.bits.len
		// hbm_sim1(i).io.s_axi_awsize              	:= ser_hbm(i).io.hbmAxi.aw.bits.size
		// hbm_sim1(i).io.s_axi_awburst              	:= ser_hbm(i).io.hbmAxi.aw.bits.burst
		// hbm_sim1(i).io.s_axi_awvalid              	:= ser_hbm(i).io.hbmAxi.aw.valid
		// hbm_sim1(i).io.s_axi_awready              	<> ser_hbm(i).io.hbmAxi.aw.ready
		// hbm_sim1(i).io.s_axi_wdata              	:= ser_hbm(i).io.hbmAxi.w.bits.data(255,0)
		// hbm_sim1(i).io.s_axi_wstrb              	:= ser_hbm(i).io.hbmAxi.w.bits.strb
		// hbm_sim1(i).io.s_axi_wlast              	:= ser_hbm(i).io.hbmAxi.w.bits.last
		// hbm_sim1(i).io.s_axi_wvalid              	:= ser_hbm(i).io.hbmAxi.w.valid
		// hbm_sim1(i).io.s_axi_wready              	<> ser_hbm(i).io.hbmAxi.w.ready
		// hbm_sim1(i).io.s_axi_bid              		<> ser_hbm(i).io.hbmAxi.b.bits.id
		// hbm_sim1(i).io.s_axi_bresp              	<> ser_hbm(i).io.hbmAxi.b.bits.resp
		// hbm_sim1(i).io.s_axi_bvalid              	<> ser_hbm(i).io.hbmAxi.b.valid
		// hbm_sim1(i).io.s_axi_bready              	<> ser_hbm(i).io.hbmAxi.b.ready
		// hbm_sim1(i).io.s_axi_arid              	    <> ser_hbm(i).io.hbmAxi.ar.bits.id
		// hbm_sim1(i).io.s_axi_araddr              	<> ser_hbm(i).io.hbmAxi.ar.bits.addr
		// hbm_sim1(i).io.s_axi_arlen              	<> ser_hbm(i).io.hbmAxi.ar.bits.len
		// hbm_sim1(i).io.s_axi_arsize              	<> ser_hbm(i).io.hbmAxi.ar.bits.size
		// hbm_sim1(i).io.s_axi_arburst              	<> ser_hbm(i).io.hbmAxi.ar.bits.burst
		// hbm_sim1(i).io.s_axi_arvalid              	<> ser_hbm(i).io.hbmAxi.ar.valid
		// hbm_sim1(i).io.s_axi_arready              	<> ser_hbm(i).io.hbmAxi.ar.ready
		// hbm_sim1(i).io.s_axi_rid              		<> ser_hbm(i).io.hbmAxi.r.bits.id
		// hbm_sim1(i).io.s_axi_rdata              	<> ser_hbm(i).io.hbmAxi.r.bits.data
		// hbm_sim1(i).io.s_axi_rresp              	<> ser_hbm(i).io.hbmAxi.r.bits.resp
		// hbm_sim1(i).io.s_axi_rlast              	<> ser_hbm(i).io.hbmAxi.r.bits.last
		// hbm_sim1(i).io.s_axi_rvalid              	<> ser_hbm(i).io.hbmAxi.r.valid
		// hbm_sim1(i).io.s_axi_rready              	<> ser_hbm(i).io.hbmAxi.r.ready


        // ser_hbm(i).io.userClk     := clock
        // ser_hbm(i).io.userRstn    := !(reset.asBool)
        // ser_hbm(i).io.hbmClk      := clock
        // ser_hbm(i).io.hbmRstn     := !(reset.asBool)
        ser_hbm(i).io.hbmCtrlAr   	<> read_host(i).io.serhbmCtrlAr
        ser_hbm(i).io.hbmCtrlR    	<> read_host(i).io.serhbmCtrlR
		ser_hbm(i).io.hbmCtrlAw		<> eng_sim(i).io.enghbmCtrlAw
		ser_hbm(i).io.hbmCtrlW		<> eng_sim(i).io.enghbmCtrlW


		// hbm_sim2(i).io.s_aresetn 					:= !(reset.asBool)
		// hbm_sim2(i).io.s_aclk 					    := clock
		// hbm_sim2(i).io.s_axi_awid              	    := eng_hbm(i).io.hbmAxi.aw.bits.id
		// hbm_sim2(i).io.s_axi_awaddr              	:= eng_hbm(i).io.hbmAxi.aw.bits.addr
		// hbm_sim2(i).io.s_axi_awlen              	:= eng_hbm(i).io.hbmAxi.aw.bits.len
		// hbm_sim2(i).io.s_axi_awsize              	:= eng_hbm(i).io.hbmAxi.aw.bits.size
		// hbm_sim2(i).io.s_axi_awburst              	:= eng_hbm(i).io.hbmAxi.aw.bits.burst
		// hbm_sim2(i).io.s_axi_awvalid              	:= eng_hbm(i).io.hbmAxi.aw.valid
		// hbm_sim2(i).io.s_axi_awready              	<> eng_hbm(i).io.hbmAxi.aw.ready
		// hbm_sim2(i).io.s_axi_wdata              	:= eng_hbm(i).io.hbmAxi.w.bits.data(255,0)
		// hbm_sim2(i).io.s_axi_wstrb              	:= eng_hbm(i).io.hbmAxi.w.bits.strb
		// hbm_sim2(i).io.s_axi_wlast              	:= eng_hbm(i).io.hbmAxi.w.bits.last
		// hbm_sim2(i).io.s_axi_wvalid              	:= eng_hbm(i).io.hbmAxi.w.valid
		// hbm_sim2(i).io.s_axi_wready              	<> eng_hbm(i).io.hbmAxi.w.ready
		// hbm_sim2(i).io.s_axi_bid              		<> eng_hbm(i).io.hbmAxi.b.bits.id
		// hbm_sim2(i).io.s_axi_bresp              	<> eng_hbm(i).io.hbmAxi.b.bits.resp
		// hbm_sim2(i).io.s_axi_bvalid              	<> eng_hbm(i).io.hbmAxi.b.valid
		// hbm_sim2(i).io.s_axi_bready              	<> eng_hbm(i).io.hbmAxi.b.ready
		// hbm_sim2(i).io.s_axi_arid              	    <> eng_hbm(i).io.hbmAxi.ar.bits.id
		// hbm_sim2(i).io.s_axi_araddr              	<> eng_hbm(i).io.hbmAxi.ar.bits.addr
		// hbm_sim2(i).io.s_axi_arlen              	<> eng_hbm(i).io.hbmAxi.ar.bits.len
		// hbm_sim2(i).io.s_axi_arsize              	<> eng_hbm(i).io.hbmAxi.ar.bits.size
		// hbm_sim2(i).io.s_axi_arburst              	<> eng_hbm(i).io.hbmAxi.ar.bits.burst
		// hbm_sim2(i).io.s_axi_arvalid              	<> eng_hbm(i).io.hbmAxi.ar.valid
		// hbm_sim2(i).io.s_axi_arready              	<> eng_hbm(i).io.hbmAxi.ar.ready
		// hbm_sim2(i).io.s_axi_rid              		<> eng_hbm(i).io.hbmAxi.r.bits.id
		// hbm_sim2(i).io.s_axi_rdata              	<> eng_hbm(i).io.hbmAxi.r.bits.data
		// hbm_sim2(i).io.s_axi_rresp              	<> eng_hbm(i).io.hbmAxi.r.bits.resp
		// hbm_sim2(i).io.s_axi_rlast              	<> eng_hbm(i).io.hbmAxi.r.bits.last
		// hbm_sim2(i).io.s_axi_rvalid              	<> eng_hbm(i).io.hbmAxi.r.valid
		// hbm_sim2(i).io.s_axi_rready              	<> eng_hbm(i).io.hbmAxi.r.ready


        // eng_hbm(i).io.userClk     := clock
        // eng_hbm(i).io.userRstn    := !(reset.asBool)
        // eng_hbm(i).io.hbmClk      := clock
        // eng_hbm(i).io.hbmRstn     := !(reset.asBool)
        eng_hbm(i).io.hbmCtrlAr   	<> read_host(i).io.enghbmCtrlAr
        eng_hbm(i).io.hbmCtrlR    	<> read_host(i).io.enghbmCtrlR
		eng_hbm(i).io.hbmCtrlAw		<> der_to_mem(i).io.hbmCtrlAw
		eng_hbm(i).io.hbmCtrlW		<> der_to_mem(i).io.hbmCtrlW



		eng_sim(i).io.delay_time		:= 100.U
		eng_sim(i).io.notice_addr		:= 0x3000.U+i.U*64.U
		eng_sim(i).io.thread_num		:= 1.U

        der_to_mem(i).io.dma_base_addr  := 0x2000000.U+i.U*0x10000.U
        der_to_mem(i).io.hbm_base_addr  := 0x10000.U+i.U*0x10000.U
		der_to_mem(i).io.notice_addr		:= 0x70000000.U+i.U*64.U

		der_to_mem(i).io.thread_num		:= 1.U


        // net_to_mem.io.axi_ddr.r.bits.user        := 0.U
        // net_to_mem.io.axi_ddr.b.bits.user        := 0.U

        // ser_hbm(i).io.hbmAxi.r.bits.user       := 0.U
        // ser_hbm(i).io.hbmAxi.b.bits.user       := 0.U
        // eng_hbm(i).io.hbmAxi.r.bits.user       := 0.U
        // eng_hbm(i).io.hbmAxi.b.bits.user       := 0.U

	}

    ip.io.ip_address                       := io.local_ip_address
    
}              