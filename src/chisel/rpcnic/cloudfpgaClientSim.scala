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

class cloudfpgaClientSim() extends Module{
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
	// val aes = (Module(new aes_cipher_512()))

    val mem_to_net = (Module(new MemToNet()))

	val read_host = (Module(new ReadHostClient()))

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


        roce.io.m_mem_write_cmd.ready    := 1.U  
        roce.io.m_mem_write_data.ready    := 1.U 
        roce.io.m_mem_read_cmd.ready     := 1.U
        roce.io.s_mem_read_data.valid    := 0.U
        roce.io.s_mem_read_data.bits     := 0.U.asTypeOf(roce.io.s_mem_read_data.bits)
  
        roce.io.m_recv_meta.ready		:= 1.U   
        roce.io.m_cmpt_meta.ready        := 1.U

    ToZero(io.m_mem_write_cmd.valid)          
    ToZero(io.m_mem_write_cmd.bits) 
    
    ToZero(io.m_mem_write_data.valid)
    ToZero(io.m_mem_write_data.bits)

        


        read_host.io.recv_meta_fire      := roce.io.m_recv_meta.fire
        read_host.io.total_send_num      := 1000000.U
        read_host.io.idle_cycle          := 30.U
        read_host.io.outstanding_cmd     := 1000000.U
    

    

    read_host.io.ser_cmd_out			<> mem_to_net.io.meta_in
    read_host.io.ser_host_data_out   <> mem_to_net.io.data_in

	mem_to_net.io.qpn                 := io.qpn	


	control.io.axi 					<> io.axib	
	control.io.free_index.ready		:= 1.U
    control.io.metadata_init.ready	:= 1.U
    control.io.ser_cmd    	 		<> read_host.io.ser_cmd
	control.io.eng_cmd.ready		:= 1.U


        io.m_mem_read_cmd            <> read_host.io.m_mem_read_cmd
        io.s_mem_read_data           <> read_host.io.s_mem_read_data
	




		roce.io.s_send_data             <> mem_to_net.io.m_send_data


		roce.io.m_recv_data.ready		:= 1.U





    ip.io.ip_address                       := io.local_ip_address
    
}              

