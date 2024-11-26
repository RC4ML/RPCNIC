package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._


class SerializerTop() extends Module{
	val io = IO(new Bundle{
        val meta_in             = Flipped(Decoupled(new SerMeta))
        val host_data_in        = Flipped(Decoupled(UInt(512.W)))
        val device_data_in      = Flipped(Decoupled(UInt(512.W)))	
        val class_meta_init     = Flipped(Decoupled(new ClassMetaInit))
        val writer_req	        = (Decoupled(new SerWriteReq))
	})

    val ser = Module(new Serializer())
    val write_ser = Module(new WriteSer())
    val deser = Module(new Deserializer())
    val meta_table = Module(new ClassMetaTable())

    // io.meta_in              <> deser.io.meta_in
    // io.data_in              <> deser.io.data_in
    io.writer_req           <> deser.io.writer_req
    // io.class_meta_init      <> meta_table.io.class_meta_init


    io.meta_in              <> ser.io.meta_in
    io.host_data_in         <> ser.io.host_data_in
    io.device_data_in       <> ser.io.device_data_in
    ser.io.writer_req       <> write_ser.io.writer_req
    ser.io.done             <> write_ser.io.done
    io.class_meta_init      <> meta_table.io.class_meta_init


    deser.io.meta_in.valid                  := write_ser.io.meta_out.valid
    write_ser.io.meta_out.ready             := deser.io.meta_in.ready  
    deser.io.meta_in.bits.class_id          := write_ser.io.meta_out.bits.class_id
    deser.io.meta_in.bits.length            := write_ser.io.meta_out.bits.length
    deser.io.meta_in.bits.result_base_addr  := 65536.U


    deser.io.data_in.valid                  := write_ser.io.data_out.valid
    write_ser.io.data_out.ready             := deser.io.data_in.ready  
    deser.io.data_in.bits                   := write_ser.io.data_out.bits.data

    

    ser.io.class_meta_req <> meta_table.io.s_class_meta_req
    ser.io.class_meta_rsp <> meta_table.io.s_class_meta_rsp

    deser.io.class_meta_req <> meta_table.io.d_class_meta_req
    deser.io.class_meta_rsp <> meta_table.io.d_class_meta_rsp

}

