package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common._



class ClassMetaReq extends Bundle {
    val class_id = UInt(10.W)
}

class ClassMetaRsp extends Bundle {
    val class_id = UInt(10.W)
    val class_meta = new ClassMetaState()
}

class SubMetaState extends Bundle {
    val is_repeated = Bool()
    val field_type = UInt(PROTO_TYPES.TYPE_fieldwidth)
    val sub_class_id = UInt(16.W)
    val is_host = Bool()
}

class ClassMetaState extends Bundle {
    val class_length    = UInt(16.W)
    val max_field_num   = UInt(8.W)
    val field_type      = Vec(33,new SubMetaState)
}

class ClassMetaInit extends Bundle {
    val class_id = UInt(10.W)
    val desc_state = new ClassMetaState()
}

class ClassMetaTable() extends Module{
	val io = IO(new Bundle{
        val class_meta_init     = Flipped(Decoupled(new ClassMetaInit))
		val s_class_meta_req	= Flipped(Decoupled(new ClassMetaReq))
		val s_class_meta_rsp	= (Decoupled(new ClassMetaRsp))

		val d_class_meta_req	= Flipped(Decoupled(new ClassMetaReq))
		val d_class_meta_rsp	= (Decoupled(new ClassMetaRsp))        
	})

    Collector.fire(io.class_meta_init)


    val s_class_meta_req_fifo = XQueue(new ClassMetaReq(), entries=8)
    val d_class_meta_req_fifo = XQueue(new ClassMetaReq(), entries=8)


    io.s_class_meta_req                       <> s_class_meta_req_fifo.io.in
    io.d_class_meta_req                       <> d_class_meta_req_fifo.io.in

    val meta_table = XRam(new ClassMetaState(), PROTO_TYPES.Des_Table_Depth, latency = 1)

    val class_meta_req = RegInit(0.U.asTypeOf(new ClassMetaReq()))

	


	val sIDLE :: sSRSP :: sDRSP :: Nil = Enum(3)
	val state                   = RegInit(sIDLE)
    // Collector.report(state===sIDLE, "meta_table===sIDLE")
    meta_table.io.addr_a                 := 0.U
    meta_table.io.addr_b                 := 0.U
    meta_table.io.wr_en_a                := 0.U
    meta_table.io.data_in_a              := 0.U.asTypeOf(meta_table.io.data_in_a)

    s_class_meta_req_fifo.io.out.ready           := (!io.class_meta_init.valid.asBool) & (state === sIDLE)
    d_class_meta_req_fifo.io.out.ready           := (!io.class_meta_init.valid.asBool) & (!s_class_meta_req_fifo.io.out.valid.asBool) &(state === sIDLE)
    io.class_meta_init.ready                   := 1.U


    ToZero(io.s_class_meta_rsp.valid)
    ToZero(io.s_class_meta_rsp.bits)
    ToZero(io.d_class_meta_rsp.valid)
    ToZero(io.d_class_meta_rsp.bits)

    //cycle1
    when(io.class_meta_init.fire()){
        meta_table.io.addr_a                    := io.class_meta_init.bits.class_id
        meta_table.io.wr_en_a                   := 1.U
        meta_table.io.data_in_a                 := io.class_meta_init.bits.desc_state
        state                                   := sIDLE        
    }.elsewhen(s_class_meta_req_fifo.io.out.fire()){
        meta_table.io.addr_b                    := s_class_meta_req_fifo.io.out.bits.class_id
        class_meta_req                          := s_class_meta_req_fifo.io.out.bits
        state                                   := sSRSP
    }.elsewhen(d_class_meta_req_fifo.io.out.fire()){
        meta_table.io.addr_b                    := d_class_meta_req_fifo.io.out.bits.class_id
        class_meta_req                          := d_class_meta_req_fifo.io.out.bits
        state                                   := sDRSP
    }.otherwise{
        state                                   := sIDLE
    }    

    //cycle2

    when(state === sSRSP){
        io.s_class_meta_rsp.valid                 := 1.U
        io.s_class_meta_rsp.bits.class_id         := class_meta_req.class_id
        io.s_class_meta_rsp.bits.class_meta       := meta_table.io.data_out_b
    }.elsewhen(state === sDRSP){
        io.d_class_meta_rsp.valid                 := 1.U
        io.d_class_meta_rsp.bits.class_id         := class_meta_req.class_id
        io.d_class_meta_rsp.bits.class_meta       := meta_table.io.data_out_b        
    } 

}