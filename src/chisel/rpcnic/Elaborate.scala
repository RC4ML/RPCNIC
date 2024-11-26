package cloud_fpga
import chisel3._
import chisel3.util._
import chisel3.stage.{ChiselGeneratorAnnotation, ChiselStage, ChiselOutputFileAnnotation}
import firrtl.options.{TargetDirAnnotation, OutputAnnotationFileAnnotation}
import firrtl.stage.OutputFileAnnotation
import firrtl.options.TargetDirAnnotation
import qdma._

object elaborate extends App {
	println("Generating a %s class".format(args(0)))
	val stage	= new chisel3.stage.ChiselStage
	val arr		= Array("-X", "sverilog", "--full-stacktrace")
	val dir 	= TargetDirAnnotation("Verilog")

	args(0) match{
		case "Foo" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new Foo()),dir))
		case "StaticFpgaCloudTop" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new StaticFpgaCloudTop()),dir))
		case "cloudfpgaSim" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new cloudfpgaSim()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "cloudfpgaSimMul" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new cloudfpgaSimMul()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "cloudfpgaSerSim" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new cloudfpgaSerSim()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "cloudfpgaSerhwSim" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new cloudfpgaSerhwSim()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "FpgaCloudTop" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new FpgaCloudTop()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "FpgaCloudMulTop" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new FpgaCloudMulTop()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "FpgaCloudBaseTop" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new FpgaCloudBaseTop()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "U280DynamicGreyBox" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new U280DynamicGreyBox()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "FpgaCloudClientTop" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new FpgaCloudClientTop()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "FpgaCloudSer" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new FpgaCloudSer()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "FpgaCloudSerHw" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new FpgaCloudSerHw()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "FpgaCloudDeser" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new FpgaCloudDeser()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case "cloudfpgaDeserSim" => stage.execute(arr,Seq(ChiselGeneratorAnnotation(() => new cloudfpgaDeserSim()),dir, OutputFileAnnotation(args(0)), OutputAnnotationFileAnnotation(args(0)), ChiselOutputFileAnnotation(args(0))))
		case _ => println("Module match failed!")
	}
}