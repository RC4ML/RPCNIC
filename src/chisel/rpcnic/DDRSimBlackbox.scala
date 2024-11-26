package cloud_fpga

import chisel3._
import chisel3.util._

class DDRSimBlackbox() extends BlackBox{
	val io = IO(new Bundle{
		val s_aresetn 					= Input(Bool())
		val s_aclk 						= Input(Clock())

		val s_axi_awid              	= Input(UInt(4.W))
		val s_axi_awaddr              	= Input(UInt(32.W))
		val s_axi_awlen              	= Input(UInt(8.W))
		val s_axi_awsize              	= Input(UInt(3.W))
		val s_axi_awburst              	= Input(UInt(2.W))
		val s_axi_awvalid              	= Input(UInt(1.W))
		val s_axi_awready              	= Output(UInt(1.W))
		val s_axi_wdata              	= Input(UInt(256.W))
		val s_axi_wstrb              	= Input(UInt(32.W))
		val s_axi_wlast              	= Input(UInt(1.W))
		val s_axi_wvalid              	= Input(UInt(1.W))
		val s_axi_wready              	= Output(UInt(1.W))
		val s_axi_bid              		= Output(UInt(4.W))
		val s_axi_bresp              	= Output(UInt(2.W))
		val s_axi_bvalid              	= Output(UInt(1.W))
		val s_axi_bready              	= Input(UInt(1.W))
		val s_axi_arid              	= Input(UInt(4.W))
		val s_axi_araddr              	= Input(UInt(32.W))
		val s_axi_arlen              	= Input(UInt(8.W))
		val s_axi_arsize              	= Input(UInt(3.W))
		val s_axi_arburst              	= Input(UInt(2.W))
		val s_axi_arvalid              	= Input(UInt(1.W))
		val s_axi_arready              	= Output(UInt(1.W))
		val s_axi_rid              		= Output(UInt(4.W))
		val s_axi_rdata              	= Output(UInt(256.W))
		val s_axi_rresp              	= Output(UInt(2.W))
		val s_axi_rlast              	= Output(UInt(1.W))
		val s_axi_rvalid              	= Output(UInt(1.W))
		val s_axi_rready              	= Input(UInt(1.W))

	})
}



