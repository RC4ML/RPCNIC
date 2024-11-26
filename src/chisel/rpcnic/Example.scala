package cloud_fpga
import chisel3._
import chisel3.util._

class Package extends Bundle{
	val data = UInt(32.W)
	val last = UInt(1.W)
}

class Foo extends Module{
	val io = IO(new Bundle{
		val in	= Flipped(Decoupled(new Package))
		val out = Decoupled(new Package)
	})
	io.out	<> io.in
}