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

class cloudfpgaServerSim() extends Module{
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

	val split_deser = (Module(new SplitDe()))

    val mem_to_net = (Module(new MemToNet()))

    // val ddr_sim = (Module(new DDRSimBlackbox()))
    // val ddr1_sim = (Module(new DDRSimBlackbox()))
    val hbm_sim = (Module(new DDRSimBlackbox()))

    val hbm_sim1 = (Module(new DDRSimBlackbox()))
    val hbm_sim2 = (Module(new DDRSimBlackbox()))
    
    // val hbmctrl = (Module(new AXISToHbm()))

    val ser = (Module(new SerializerSimple()))
    // val write_ser = (Module(new WriteSer()))
    val deser = (Module(new DeserializerSimple()))
    // val write_deser = (Module(new WriteDeser()))
    val meta_table = (Module(new ClassMetaTable()))


    val der_to_mem = (Module(new DerToMem()))


	val ser_hbm = (Module(new AXISToHbm()))

	val eng_hbm = (Module(new AXISToHbm()))

	// val control = (Module(new Control()))

	val read_host = (Module(new ReadHost()))

	val eng_sim = (Module(new EngineSim()))

	val arbiter	= (CompositeArbiter(new C2H_CMD,new C2H_DATA,2))

	val control = (Module(new Control()))



      



    	ip.io.s_mac_rx               <> io.s_mac_rx
		ip.io.m_mac_tx               <> io.m_mac_tx
    	roce.io.s_net_rx_data        <> ip.io.m_roce_rx
        roce.io.m_net_tx_data        <> ip.io.s_ip_tx

        ip.io.m_tcp_rx.ready         := 1.U
        ip.io.m_udp_rx.ready         := 1.U   
        ip.io.arp_req                <> io.arp_req 
        ip.io.arp_rsp                <> io.arp_rsp 

        mem_to_net.io.s_tx_meta      <> roce.io.s_tx_meta  	        
        io.qp_init                   <> roce.io.qp_init
        io.local_ip_address          <> roce.io.local_ip_address
        // io.m_mem_read_cmd            <> roce.io.m_mem_read_cmd 
        // io.s_mem_read_data           <> roce.io.s_mem_read_data 
        // io.m_mem_write_cmd           <> der_to_mem.io.m_mem_write_cmd 
        // io.m_mem_write_data          <> der_to_mem.io.m_mem_write_data  

        roce.io.m_mem_write_cmd.ready    := 1.U  
        roce.io.m_mem_write_data.ready    := 1.U 
        roce.io.m_mem_read_cmd.ready     := 1.U
        roce.io.s_mem_read_data.valid    := 0.U
        roce.io.s_mem_read_data.bits     := 0.U.asTypeOf(roce.io.s_mem_read_data.bits)
  
        net_to_mem.io.s_recv_meta    <> roce.io.m_recv_meta   
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


	control.io.axi 					<> io.axib	
	control.io.free_index			<> der_to_mem.io.free_index
    control.io.metadata_init 		<> meta_table.io.class_meta_init
    control.io.ser_cmd    	 		<> read_host.io.ser_cmd
	control.io.eng_cmd				<> read_host.io.eng_cmd



        io.m_mem_read_cmd            <> read_host.io.m_mem_read_cmd
        io.s_mem_read_data           <> read_host.io.s_mem_read_data




		roce.io.s_send_data				<> mem_to_net.io.m_send_data


		net_to_mem.io.s_recv_data				<> roce.io.m_recv_data
	        

        // net_to_mem.io.start               <> Delay(net_to_mem.io.done,200)

        net_to_mem.io.deser_meta_out     <> split_deser.io.meta_in
        net_to_mem.io.deser_data_out     <> split_deser.io.data_in                     
                     
        split_deser.io.de_idle         		<> deser.io.idle_out  
        split_deser.io.split_meta_out		<> deser.io.meta_in    
        split_deser.io.split_data_out    	<> deser.io.data_in


        mem_to_net.io.meta_in             <> ser.io.meta_out //write_ser
        mem_to_net.io.data_in             <> ser.io.data_out //write_ser
        mem_to_net.io.qpn                 := io.qpn                 

        // write_deser.io.writer_req          <> deser.io.writer_req
        deser.io.meta_out              <> der_to_mem.io.meta_in
        deser.io.host_data_out         <> der_to_mem.io.host_data_in
        deser.io.device_data_out       <> der_to_mem.io.device_data_in

		deser.io.total_thread_num    := 1.U
        deser.io.thread_num          := 0.U


    // ser.io.writer_req       <> write_ser.io.writer_req
    // ser.io.done             <> write_ser.io.done

    

    ser.io.class_meta_req <> meta_table.io.s_class_meta_req
    ser.io.class_meta_rsp <> meta_table.io.s_class_meta_rsp

    deser.io.class_meta_req <> meta_table.io.d_class_meta_req
    deser.io.class_meta_rsp <> meta_table.io.d_class_meta_rsp

    // deser.io.deser_done.ready:=1.U


		// ddr_sim.io.s_aresetn 					:= !(reset.asBool)
		// ddr_sim.io.s_aclk 					    := clock
		// ddr_sim.io.s_axi_awid              	    := net_to_mem.io.axi_ddr.aw.bits.id
		// ddr_sim.io.s_axi_awaddr              	:= net_to_mem.io.axi_ddr.aw.bits.addr
		// ddr_sim.io.s_axi_awlen              	    := net_to_mem.io.axi_ddr.aw.bits.len
		// ddr_sim.io.s_axi_awsize              	:= net_to_mem.io.axi_ddr.aw.bits.size
		// ddr_sim.io.s_axi_awburst              	:= net_to_mem.io.axi_ddr.aw.bits.burst
		// ddr_sim.io.s_axi_awvalid              	:= net_to_mem.io.axi_ddr.aw.valid
		// ddr_sim.io.s_axi_awready              	<> net_to_mem.io.axi_ddr.aw.ready
		// ddr_sim.io.s_axi_wdata              	    := net_to_mem.io.axi_ddr.w.bits.data(255,0)
		// ddr_sim.io.s_axi_wstrb              	    := net_to_mem.io.axi_ddr.w.bits.strb
		// ddr_sim.io.s_axi_wlast              	    := net_to_mem.io.axi_ddr.w.bits.last
		// ddr_sim.io.s_axi_wvalid              	:= net_to_mem.io.axi_ddr.w.valid
		// ddr_sim.io.s_axi_wready              	<> net_to_mem.io.axi_ddr.w.ready
		// ddr_sim.io.s_axi_bid              		<> net_to_mem.io.axi_ddr.b.bits.id
		// ddr_sim.io.s_axi_bresp              	    <> net_to_mem.io.axi_ddr.b.bits.resp
		// ddr_sim.io.s_axi_bvalid              	<> net_to_mem.io.axi_ddr.b.valid
		// ddr_sim.io.s_axi_bready              	<> net_to_mem.io.axi_ddr.b.ready
		// ddr_sim.io.s_axi_arid              	    <> net_to_mem.io.axi_ddr.ar.bits.id
		// ddr_sim.io.s_axi_araddr              	<> net_to_mem.io.axi_ddr.ar.bits.addr
		// ddr_sim.io.s_axi_arlen              	    <> net_to_mem.io.axi_ddr.ar.bits.len
		// ddr_sim.io.s_axi_arsize              	<> net_to_mem.io.axi_ddr.ar.bits.size
		// ddr_sim.io.s_axi_arburst              	<> net_to_mem.io.axi_ddr.ar.bits.burst
		// ddr_sim.io.s_axi_arvalid              	<> net_to_mem.io.axi_ddr.ar.valid
		// ddr_sim.io.s_axi_arready              	<> net_to_mem.io.axi_ddr.ar.ready
		// ddr_sim.io.s_axi_rid              		<> net_to_mem.io.axi_ddr.r.bits.id
		// // ddr_sim.io.s_axi_rdata              	    <> net_to_mem.io.axi_ddr.r.bits.data
		// ddr_sim.io.s_axi_rresp              	    <> net_to_mem.io.axi_ddr.r.bits.resp
		// ddr_sim.io.s_axi_rlast              	    <> net_to_mem.io.axi_ddr.r.bits.last
		// ddr_sim.io.s_axi_rvalid              	<> net_to_mem.io.axi_ddr.r.valid
		// ddr_sim.io.s_axi_rready              	<> net_to_mem.io.axi_ddr.r.ready

		// ddr1_sim.io.s_aresetn 					:= !(reset.asBool)
		// ddr1_sim.io.s_aclk 					    := clock
		// ddr1_sim.io.s_axi_awid              	    := net_to_mem.io.axi_ddr.aw.bits.id
		// ddr1_sim.io.s_axi_awaddr              	:= net_to_mem.io.axi_ddr.aw.bits.addr
		// ddr1_sim.io.s_axi_awlen              	:= net_to_mem.io.axi_ddr.aw.bits.len
		// ddr1_sim.io.s_axi_awsize              	:= net_to_mem.io.axi_ddr.aw.bits.size
		// ddr1_sim.io.s_axi_awburst              	:= net_to_mem.io.axi_ddr.aw.bits.burst
		// ddr1_sim.io.s_axi_awvalid              	:= net_to_mem.io.axi_ddr.aw.valid
		// // ddr1_sim.io.s_axi_awready              	<> net_to_mem.io.axi_ddr.aw.ready
		// ddr1_sim.io.s_axi_wdata              	:= net_to_mem.io.axi_ddr.w.bits.data(511,256)
		// ddr1_sim.io.s_axi_wstrb              	:= net_to_mem.io.axi_ddr.w.bits.strb
		// ddr1_sim.io.s_axi_wlast              	:= net_to_mem.io.axi_ddr.w.bits.last
		// ddr1_sim.io.s_axi_wvalid              	:= net_to_mem.io.axi_ddr.w.valid
		// // ddr1_sim.io.s_axi_wready              	<> net_to_mem.io.axi_ddr.w.ready
		// // ddr1_sim.io.s_axi_bid              		<> net_to_mem.io.axi_ddr.b.bits.id
		// // ddr1_sim.io.s_axi_bresp              	<> net_to_mem.io.axi_ddr.b.bits.resp
		// // ddr1_sim.io.s_axi_bvalid              	<> net_to_mem.io.axi_ddr.b.valid
		// ddr1_sim.io.s_axi_bready              	:= net_to_mem.io.axi_ddr.b.ready
		// ddr1_sim.io.s_axi_arid              	    := net_to_mem.io.axi_ddr.ar.bits.id
		// ddr1_sim.io.s_axi_araddr              	:= net_to_mem.io.axi_ddr.ar.bits.addr
		// ddr1_sim.io.s_axi_arlen              	:= net_to_mem.io.axi_ddr.ar.bits.len
		// ddr1_sim.io.s_axi_arsize              	:= net_to_mem.io.axi_ddr.ar.bits.size
		// ddr1_sim.io.s_axi_arburst              	:= net_to_mem.io.axi_ddr.ar.bits.burst
		// ddr1_sim.io.s_axi_arvalid              	:= net_to_mem.io.axi_ddr.ar.valid
		// // ddr1_sim.io.s_axi_arready              	<> net_to_mem.io.axi_ddr.ar.ready
        // net_to_mem.io.axi_ddr.r.bits.data        := Cat(ddr1_sim.io.s_axi_rdata,ddr_sim.io.s_axi_rdata)
		// ddr1_sim.io.s_axi_rready              	:= net_to_mem.io.axi_ddr.r.ready



		hbm_sim1.io.s_aresetn 					:= !(reset.asBool)
		hbm_sim1.io.s_aclk 					    := clock
		hbm_sim1.io.s_axi_awid              	    := ser_hbm.io.hbmAxi.aw.bits.id
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
		hbm_sim1.io.s_axi_arid              	    <> ser_hbm.io.hbmAxi.ar.bits.id
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
        ser_hbm.io.hbmCtrlAr   <> read_host.io.serhbmCtrlAr
        ser_hbm.io.hbmCtrlR    <> read_host.io.serhbmCtrlR
		ser_hbm.io.hbmCtrlAw	<> eng_sim.io.enghbmCtrlAw
		ser_hbm.io.hbmCtrlW		<> eng_sim.io.enghbmCtrlW

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
        eng_hbm.io.hbmCtrlAr   <> read_host.io.enghbmCtrlAr
        eng_hbm.io.hbmCtrlR    <> read_host.io.enghbmCtrlR
		eng_hbm.io.hbmCtrlAw	<> der_to_mem.io.hbmCtrlAw
		eng_hbm.io.hbmCtrlW		<> der_to_mem.io.hbmCtrlW

		eng_sim.io.delay_time		:= 100.U
		eng_sim.io.notice_addr		:= 0x3000.U

        der_to_mem.io.dma_base_addr  := 0x2000000.U
        der_to_mem.io.hbm_base_addr  := 0x10000.U

		der_to_mem.io.notice_addr		:= 0x70000000.U


        // net_to_mem.io.axi_ddr.r.bits.user        := 0.U
        // net_to_mem.io.axi_ddr.b.bits.user        := 0.U

        ser_hbm.io.hbmAxi.r.bits.user       := 0.U
        ser_hbm.io.hbmAxi.b.bits.user       := 0.U
        eng_hbm.io.hbmAxi.r.bits.user       := 0.U
        eng_hbm.io.hbmAxi.b.bits.user       := 0.U

    ip.io.ip_address                       := io.local_ip_address
    
}              



