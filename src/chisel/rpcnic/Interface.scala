package cloud_fpga

import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum

object CLCONFIG{
    def DDR_BUFFER_NUM = 256
    def RPC_HEAD_LEN = 8
}

object CLREG{
    def FREE_LIST_NUM = 10.U
    def META_INIT0 = 20.U
    def META_INIT1 = 21.U
    def META_INIT2 = 22.U
    def SER_CMD = 12.U
    def ENG_CMD = 13.U
}

class HASH_STATE()extends Bundle{
    val qpn         = UInt(16.W)
    val msg_num      = UInt(24.W)  
    val valid      = UInt(1.W)
    val addr      = UInt(34.W) 
}

class RoceSend()extends Bundle{
	val qpn = UInt(24.W)
    val addr = UInt(34.W)
    val length = UInt(32.W)
}

class EngMeta()extends Bundle{
	val engine_num = UInt(8.W)
    val src_addr = UInt(64.W)
    val src_length = UInt(32.W)
    val dest_length = UInt(32.W)
    val src_device = Bool() //0 host 1 device
    val dest_addr = UInt(64.W)
    val dest_device = Bool() //0 host 1 device
}