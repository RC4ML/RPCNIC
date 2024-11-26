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

class cloudfpgaSim() extends Module{
	val io = IO(new Bundle{

        val qpn                 = Vec(2,Input(UInt(16.W)))  

		val axib 				= Vec(2,Flipped(new AXIB))       

        val m_mem_read_cmd      = Vec(2,(Decoupled(new MEM_CMD())))
        val s_mem_read_data	    = Vec(2,Flipped(Decoupled(new AXIS(CONFIG.DATA_WIDTH))))
        val m_mem_write_cmd     = Vec(2,(Decoupled(new MEM_CMD())))
        val m_mem_write_data	= Vec(2,(Decoupled(new AXIS(CONFIG.DATA_WIDTH))))


        val qp_init	            = Vec(2,Flipped(Decoupled(new QP_INIT())))
        val local_ip_address    = Vec(2,Input(UInt(32.W)))

        val arp_req             =   Vec(2,Flipped(Decoupled(UInt(32.W))))
        val arp_rsp             =   Vec(2,Decoupled(new mac_out))        

        val status              = Output(Vec(512,UInt(32.W)))
	})




    val q = XQueue(2)(new AXIS(CONFIG.DATA_WIDTH), 16)

	val server = Module(new cloudfpgaServerSim())
	val client = Module(new cloudfpgaClientSim())


        server.io.qpn        			<> io.qpn(0)
		server.io.axib        			<> io.axib(0)
		server.io.m_mem_read_cmd        <> io.m_mem_read_cmd(0)
		server.io.s_mem_read_data       <> io.s_mem_read_data(0)
		server.io.m_mem_write_cmd       <> io.m_mem_write_cmd(0)
		server.io.m_mem_write_data      <> io.m_mem_write_data(0)
		server.io.qp_init        		<> io.qp_init(0)
		server.io.local_ip_address      <> io.local_ip_address(0)
		server.io.arp_req       		<> io.arp_req(0)
		server.io.arp_rsp      			<> io.arp_rsp(0)


        client.io.qpn        			<> io.qpn(1)
		client.io.axib        			<> io.axib(1)
		client.io.m_mem_read_cmd        <> io.m_mem_read_cmd(1)
		client.io.s_mem_read_data       <> io.s_mem_read_data(1)
		client.io.m_mem_write_cmd       <> io.m_mem_write_cmd(1)
		client.io.m_mem_write_data      <> io.m_mem_write_data(1)
		client.io.qp_init        		<> io.qp_init(1)
		client.io.local_ip_address      <> io.local_ip_address(1)
		client.io.arp_req       		<> io.arp_req(1)
		client.io.arp_rsp      			<> io.arp_rsp(1)


    server.io.s_mac_rx                       <> Delay(q(1).io.out,1000)
    client.io.s_mac_rx                       <> Delay(q(0).io.out,1000)

	server.io.m_mac_tx					<> q(0).io.in
	client.io.m_mac_tx					<> q(1).io.in


    ToZero(io.status)

    Collector.connect_to_status_reg(io.status,0)
    
}              


