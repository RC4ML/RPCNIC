package cloud_fpga

import common.storage._
import common.Delay
import common.connection._
import common.axi._
import common._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import network.roce.util._
import network.roce._
import common.Collector
import common.ToZero
import serialization._
import qdma._



class ControlMul(Thread: Int = 2) extends Module{
	val io = IO(new Bundle{
		val axi = Flipped(new AXIB)	
		val free_index 		= Vec(Thread,(Decoupled(UInt(32.W))))
        val metadata_init 	= Vec(Thread,(Decoupled(new ClassMetaInit)))
        val ser_cmd     	= Vec(Thread,(Decoupled(new SerMeta)))
		val eng_cmd 		= Vec(Thread,(Decoupled(new EngMeta)))
	})

	


	ToZero(io.axi.b.bits)
	io.axi.b.valid := 1.U

	val sIDLE :: sWORK :: sFree_list :: sMetaData0 :: sMetaData1 :: sMetaData2 :: sSerCmd :: sEngCmd :: Nil = Enum(8)
	val s_wr = RegInit(sIDLE)

    val w_addr = RegInit(UInt(16.W),0.U)

	val free_index_R = SimpleRouter(UInt(32.W),Thread)
	val metadata_R = SimpleRouter(new ClassMetaInit,Thread)
	val sercmd_R = SimpleRouter(new SerMeta,Thread)
	val engcmd_R = SimpleRouter(new EngMeta,Thread)

	for(i<- 0 until Thread){
		free_index_R.io.out(i)	<> io.free_index(i)
		metadata_R.io.out(i)	<> io.metadata_init(i)
		sercmd_R.io.out(i)		<> io.ser_cmd(i)
		engcmd_R.io.out(i)		<> io.eng_cmd(i)
	}
	ToZero(free_index_R.io.in.valid)
	ToZero(free_index_R.io.in.bits)
	ToZero(free_index_R.io.idx)
	ToZero(metadata_R.io.in.valid)
	ToZero(metadata_R.io.in.bits)
	ToZero(metadata_R.io.idx)
	ToZero(sercmd_R.io.in.valid)
	ToZero(sercmd_R.io.in.bits)
	ToZero(sercmd_R.io.idx)
	ToZero(engcmd_R.io.in.valid)
	ToZero(engcmd_R.io.in.bits)
	ToZero(engcmd_R.io.idx)		

	val r = io.axi.r
	val ar = io.axi.ar
	val w = io.axi.w
	val aw = io.axi.aw

	//r and ar
	ToZero(r.bits)
	r.bits.last	:= 1.U

	val cur_data = RegInit(0.U(32.W))
 	val classmeta_reg = RegInit(0.U.asTypeOf(new ClassMetaInit()))
	when(r.fire()){
		cur_data := cur_data + 1.U
	}

	ar.ready := 1.U

	r.valid		:= 1.U
	r.bits.data	:= cur_data

    //write

	aw.ready	:= (s_wr === sIDLE)
	w.ready		:= (s_wr === sWORK) || ((s_wr === sFree_list) & (free_index_R.io.in.ready)) || (s_wr === sMetaData0) || (s_wr === sMetaData1)|| ((s_wr === sMetaData2) & (metadata_R.io.in.ready)) || ((s_wr === sSerCmd) & (sercmd_R.io.in.ready)) || ((s_wr === sEngCmd) & (engcmd_R.io.in.ready))

	switch(s_wr){
		is(sIDLE){
			when(aw.fire()){
				w_addr			:= aw.bits.addr >> 6.U
				when((aw.bits.addr >> 6.U) === CLREG.FREE_LIST_NUM){
                    s_wr        := sFree_list
                }.elsewhen((aw.bits.addr >> 6.U) === CLREG.META_INIT0){
					s_wr        := sMetaData0
				}.elsewhen((aw.bits.addr >> 6.U) === CLREG.META_INIT1){
					s_wr        := sMetaData1
				}.elsewhen((aw.bits.addr >> 6.U) === CLREG.META_INIT2){
					s_wr        := sMetaData2
				}.elsewhen((aw.bits.addr >> 6.U) === CLREG.SER_CMD){
					s_wr        := sSerCmd
				}.elsewhen((aw.bits.addr >> 6.U) === CLREG.ENG_CMD){
					s_wr        := sEngCmd
				}.otherwise{
                    s_wr        := sWORK
                }
			}
		}
		is(sFree_list){
			when(w.fire()){
                free_index_R.io.in.valid := 1.U
                free_index_R.io.in.bits  := w.bits.data(31,0)
				free_index_R.io.idx		 := w.bits.data(70,64) 
				s_wr			:= sIDLE
			}
		}
		is(sMetaData0){
			when(w.fire()){
                classmeta_reg.class_id      := w.bits.data(10,0)
                classmeta_reg.desc_state.max_field_num := w.bits.data(31,16)
				classmeta_reg.desc_state.class_length	:= w.bits.data(63,32)
                for(i<- 2 until 16){
                    classmeta_reg.desc_state.field_type(i-2).is_host      := w.bits.data(i*32).asBool
                    classmeta_reg.desc_state.field_type(i-2).is_repeated  := w.bits.data(i*32+1).asBool
                    classmeta_reg.desc_state.field_type(i-2).field_type   := w.bits.data(i*32+6,i*32+2)
                    classmeta_reg.desc_state.field_type(i-2).sub_class_id := w.bits.data(i*32+31,i*32+16)
                }                 
				s_wr			:= sIDLE
			}
		}
		is(sMetaData1){
			when(w.fire()){
                for(i<- 0 until 16){
                    classmeta_reg.desc_state.field_type(i+14).is_host      := w.bits.data(i*32).asBool
                    classmeta_reg.desc_state.field_type(i+14).is_repeated  := w.bits.data(i*32+1).asBool
                    classmeta_reg.desc_state.field_type(i+14).field_type   := w.bits.data(i*32+6,i*32+2)
                    classmeta_reg.desc_state.field_type(i+14).sub_class_id := w.bits.data(i*32+31,i*32+16)
                }                 
				s_wr			:= sIDLE
			}
		}
		is(sMetaData2){
			when(w.fire()){
                metadata_R.io.in.valid              := 1.U
                metadata_R.io.in.bits      			:= classmeta_reg
				metadata_R.io.idx					:= w.bits.data(458,448)
				classmeta_reg						:= 0.U.asTypeOf(classmeta_reg)
                for(i<- 0 until 3){
                    metadata_R.io.in.bits.desc_state.field_type(i+30).is_host      := w.bits.data(i*32).asBool
                    metadata_R.io.in.bits.desc_state.field_type(i+30).is_repeated  := w.bits.data(i*32+1).asBool
                    metadata_R.io.in.bits.desc_state.field_type(i+30).field_type   := w.bits.data(i*32+6,i*32+2)
                    metadata_R.io.in.bits.desc_state.field_type(i+30).sub_class_id := w.bits.data(i*32+31,i*32+16)
                }                 
				s_wr			:= sIDLE
			}
		}
		is(sSerCmd){
			when(w.fire()){
                sercmd_R.io.in.valid                    := 1.U
                sercmd_R.io.in.bits.class_id            := w.bits.data(10,0)
                sercmd_R.io.in.bits.host_base_addr      := w.bits.data(127,64)
                sercmd_R.io.in.bits.device_base_addr    := w.bits.data(191,128)
                sercmd_R.io.in.bits.host_length         := w.bits.data(223,192)
                sercmd_R.io.in.bits.device_length       := w.bits.data(255,224)				
                sercmd_R.io.in.bits.result_base_addr    := w.bits.data(287,256)
				sercmd_R.io.idx							:= w.bits.data(330,320)
				s_wr			:= sIDLE
			}
		}     
		is(sEngCmd){
			when(w.fire()){
                engcmd_R.io.in.valid                    := 1.U
                engcmd_R.io.in.bits.engine_num          := w.bits.data(7,0)
                engcmd_R.io.in.bits.src_addr         	:= w.bits.data(127,64)
                engcmd_R.io.in.bits.src_length       	:= w.bits.data(63,32)
                engcmd_R.io.in.bits.src_device      	:= w.bits.data(192).asBool //0 host 1 device
                engcmd_R.io.in.bits.dest_addr    		:= w.bits.data(191,128)
                engcmd_R.io.in.bits.dest_device    		:= w.bits.data(193).asBool //0 host 1 device
				engcmd_R.io.idx							:= w.bits.data(7,0)
				engcmd_R.io.in.bits.dest_length       	:= w.bits.data(287,256)
				s_wr			:= sIDLE
			}
		} 		
		is(sWORK){
			when(w.fire()){
				s_wr			:= sIDLE
			}
		}
	}

    // class ila_control(seq:Seq[Data]) extends BaseILA(seq)	  
  	// val control = Module(new ila_control(Seq(	
	// 	s_wr,aw,w,free_index_R.io.in
  	// )))
  	// control.connect(clock)


}