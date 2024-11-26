package cloud_fpga

import common.storage._
import common.Delay
import common.connection._
import common.axi._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.ToZero


class SimpleHash() extends Module{
	val io = IO(new Bundle{
        val in         	= Input(UInt(40.W))
        val out			= Output(UInt(10.W))
	})

	io.out			:= io.in(9,0) + io.in(19,10) + io.in(29,20) + io.in(39,30)
    
}