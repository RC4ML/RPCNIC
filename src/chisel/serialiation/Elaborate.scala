package serialization

import chisel3._
import chisel3.util._
import chisel3.stage.{ChiselGeneratorAnnotation, ChiselStage}
import firrtl.options.TargetDirAnnotation
import qdma._
import common.OffsetGenerator
import common.connection.CreditQ
import common.connection.ProducerConsumer

class TestPC extends Module{
	val io = IO(new Bundle{
		val in	= Flipped(Decoupled(UInt(4.W)))
		val out	= Vec(8,Decoupled(UInt(4.W)))
	})
	val pcTree = ProducerConsumer(Seq(2,4))(io.in,io.out)
}
object elaborate extends App {
	println("Generating a %s class".format(args(0)))
	val stage	= new chisel3.stage.ChiselStage
	val arr		= Array("-X", "sverilog", "--full-stacktrace")
	val dir 	= TargetDirAnnotation("Verilog")

	args(0) match{
		case "SerializerTop" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new SerializerTop()),dir))
		case _ => println("Module match failed!")
	}
}