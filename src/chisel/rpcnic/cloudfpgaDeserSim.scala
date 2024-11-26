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

class cloudfpgaDeserSim() extends Module{
	val io = IO(new Bundle{

		val axib 				= Flipped(new AXIB)    


        val m_mem_read_cmd      = (Decoupled(new MEM_CMD()))
        val s_mem_read_data	    = Flipped(Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
        val m_mem_write_cmd     = (Decoupled(new MEM_CMD()))
        val m_mem_write_data	= (Decoupled(new AXIS(CONFIG.DATA_WIDTH)))
   

        val status              = Output(Vec(512,UInt(32.W)))
	})



		val read_host = (Module(new ReadHostDeser()))

		val control = (Module(new ControlMul(Thread=8)))	

		val split_L1 = (Module(new SplitDeMul()))
		val split_L2 = Seq.fill(2)(Module(new SplitDeMul()))
		val split_L3 = Seq.fill(4)(Module(new SplitDeMul()))

		val deser = Seq.fill(8)(Module(new Deserializer128()))
		val meta_table = Seq.fill(8)(Module(new ClassMetaTable()))
		val write_deser = Seq.fill(8)(Module(new WriteDeserSimple()))


		val arbiter	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)

		val Arb_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)
		val Arb_L2	= Seq.fill(2)(CompositeArbiter(new C2H_CMD,new C2H_DATA,2))
		val Ard_L1	= CompositeArbiter(new C2H_CMD,new C2H_DATA,2)
		val Ard_L2	= Seq.fill(2)(CompositeArbiter(new C2H_CMD,new C2H_DATA,2))


		io.m_mem_write_cmd.valid          := arbiter.io.out_meta.valid
		io.m_mem_write_cmd.bits.vaddr     := arbiter.io.out_meta.bits.addr
		io.m_mem_write_cmd.bits.length    := arbiter.io.out_meta.bits.len
		arbiter.io.out_meta.ready         := io.m_mem_write_cmd.ready

		io.m_mem_write_data.valid        := arbiter.io.out_data.valid
		io.m_mem_write_data.bits.data    := arbiter.io.out_data.bits.data
		io.m_mem_write_data.bits.keep    := -1.S(64.W).asTypeOf(UInt(64.W)) 
		io.m_mem_write_data.bits.last    := arbiter.io.out_data.bits.last
		arbiter.io.out_data.ready        := io.m_mem_write_data.ready


		arbiter.io.in_meta(0)	<> Ard_L1.io.out_meta
		arbiter.io.in_data(0)	<> Ard_L1.io.out_data
		arbiter.io.in_meta(1)	<> Arb_L1.io.out_meta
		arbiter.io.in_data(1)	<> Arb_L1.io.out_data

		for(i<- 0 until 2){
			Arb_L1.io.in_meta(i)	<> Arb_L2(i).io.out_meta    
			Arb_L1.io.in_data(i)   	<> Arb_L2(i).io.out_data	
			for(j<- 0 until 2){
				Arb_L2(i).io.in_meta(j)		<> write_deser(i*2+j).io.m_mem_write_cmd   
				Arb_L2(i).io.in_data(j)   	<> write_deser(i*2+j).io.m_mem_write_data
			}					
		}     

		for(i<- 0 until 2){
			Ard_L1.io.in_meta(i)	<> Ard_L2(i).io.out_meta    
			Ard_L1.io.in_data(i)   	<> Ard_L2(i).io.out_data	
			for(j<- 0 until 2){
				Ard_L2(i).io.in_meta(j)		<> write_deser(i*2+j+4).io.m_mem_write_cmd   
				Ard_L2(i).io.in_data(j)   	<> write_deser(i*2+j+4).io.m_mem_write_data
			}				
		}




        read_host.io.ser_cmd_out     		<> split_L1.io.meta_in
        read_host.io.ser_host_data_out     		<> split_L1.io.data_in     
	    read_host.io.idle				:= deser(0).io.idle_out | deser(1).io.idle_out | deser(2).io.idle_out | deser(3).io.idle_out

		split_L1.io.de_idle         	:= Cat((deser(4).io.idle_out | deser(5).io.idle_out | deser(6).io.idle_out | deser(7).io.idle_out),(deser(0).io.idle_out | deser(1).io.idle_out | deser(2).io.idle_out | deser(3).io.idle_out))
		for(i<- 0 until 2){
			split_L2(i).io.de_idle         	:= Cat((deser(i*4+2).io.idle_out | deser(i*4+3).io.idle_out),(deser(i*4).io.idle_out | deser(i*4+1).io.idle_out))
			split_L1.io.split_meta_out(i)	<> split_L2(i).io.meta_in    
			split_L1.io.split_data_out(i)   <> split_L2(i).io.data_in
			for(j<- 0 until 2){
				split_L3(i*2+j).io.de_idle         	:= Cat(deser(i*4+j*2+1).io.idle_out,deser(i*4+j*2).io.idle_out)
				split_L2(i).io.split_meta_out(j)	<> split_L3(i*2+j).io.meta_in    
				split_L2(i).io.split_data_out(j)   	<> split_L3(i*2+j).io.data_in	
				for(k<- 0 until 2){
					split_L3(i*2+j).io.split_meta_out(k)	<> deser(i*4+j*2+k).io.meta_in    
					split_L3(i*2+j).io.split_data_out(k)   	<> deser(i*4+j*2+k).io.data_in					
				}										
			}			
		} 


	for(i<- 0 until 8){	
		deser(i).io.writer_req		<> write_deser(i).io.writer_req
		deser(i).io.busy			<> write_deser(i).io.busy


    	deser(i).io.class_meta_req <> meta_table(i).io.d_class_meta_req
    	deser(i).io.class_meta_rsp <> meta_table(i).io.d_class_meta_rsp



		write_deser(i).io.done.ready	:= 1.U

		write_deser(i).io.dma_addr_base	:= 0x1234.U

		ToZero(meta_table(i).io.s_class_meta_req.valid)
		ToZero(meta_table(i).io.s_class_meta_req.bits)
		ToZero(meta_table(i).io.s_class_meta_rsp.ready)

		control.io.free_index(i).ready		:= 1.U
		control.io.metadata_init(i) 		<> meta_table(i).io.class_meta_init
		control.io.ser_cmd(i).ready    	 	:= 1.U
		control.io.eng_cmd(i).ready		:= 1.U

	}

		control.io.axi 				<> io.axib	
		control.io.ser_cmd(0)    	 	<> read_host.io.ser_cmd


		io.m_mem_read_cmd					<> read_host.io.m_mem_read_cmd

		io.s_mem_read_data					<> read_host.io.s_mem_read_data


        read_host.io.recv_meta_fire      	:= write_deser(0).io.done.fire | write_deser(1).io.done.fire |write_deser(2).io.done.fire |write_deser(3).io.done.fire |write_deser(4).io.done.fire | write_deser(5).io.done.fire |write_deser(6).io.done.fire |write_deser(7).io.done.fire   //fix it
        read_host.io.total_send_num      	:= 100.U
        read_host.io.idle_cycle          	:= 0.U
        read_host.io.outstanding_cmd     	:= 16.U





    ToZero(io.status)

    Collector.connect_to_status_reg(io.status,0)
    
}              

