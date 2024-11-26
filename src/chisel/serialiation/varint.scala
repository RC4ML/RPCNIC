package serialization

import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum

class VarintEncode() extends Module {
  val io = IO(new Bundle {
    val inputData = Input(UInt(64.W))
    val outputData = Output(UInt((8*10).W))
    val outputBytes = Output(UInt(log2Up(10).W))
  })

  val chunk0 = io.inputData(6, 0)
  val chunk1 = io.inputData(13, 7)
  val chunk2 = io.inputData(20, 14)
  val chunk3 = io.inputData(27, 21)
  val chunk4 = io.inputData(34, 28)
  val chunk5 = io.inputData(41, 35)
  val chunk6 = io.inputData(48, 42)
  val chunk7 = io.inputData(55, 49)
  val chunk8 = io.inputData(62, 56)
  val chunk9 = io.inputData(63)


  val chunk8_includebit = (chunk9 =/= 0.U)
  val chunk7_includebit = (chunk8 =/= 0.U) || chunk8_includebit
  val chunk6_includebit = (chunk7 =/= 0.U) || chunk7_includebit
  val chunk5_includebit = (chunk6 =/= 0.U) || chunk6_includebit
  val chunk4_includebit = (chunk5 =/= 0.U) || chunk5_includebit
  val chunk3_includebit = (chunk4 =/= 0.U) || chunk4_includebit
  val chunk2_includebit = (chunk3 =/= 0.U) || chunk3_includebit
  val chunk1_includebit = (chunk2 =/= 0.U) || chunk2_includebit
  val chunk0_includebit = (chunk1 =/= 0.U) || chunk1_includebit

  io.outputData := Cat(
    chunk9,
    chunk8_includebit, chunk8,
    chunk7_includebit, chunk7,
    chunk6_includebit, chunk6,
    chunk5_includebit, chunk5,
    chunk4_includebit, chunk4,
    chunk3_includebit, chunk3,
    chunk2_includebit, chunk2,
    chunk1_includebit, chunk1,
    chunk0_includebit, chunk0
  )

  io.outputBytes := chunk0_includebit +& chunk1_includebit +& chunk2_includebit +& chunk3_includebit +& chunk4_includebit +& chunk5_includebit +& chunk6_includebit +& chunk7_includebit +& chunk8_includebit +& 1.U
}

class VarintDecode() extends Module {
  val MAX_ENCODED_VARINT_BYTES = 10
  val MAX_ENCODED_VARINT_BITS = MAX_ENCODED_VARINT_BYTES*8
  val MAX_DECODED_VARINT_BITS = 64
  val CONSUMED_LEN_BITS = log2Up(MAX_ENCODED_VARINT_BYTES)

  val io = IO(new Bundle {
    val inputRawData = Input(UInt(MAX_ENCODED_VARINT_BITS.W))
    val outputData = Output(UInt(MAX_DECODED_VARINT_BITS.W))
    val consumedLenBytes = Output(UInt(CONSUMED_LEN_BITS.W))
  })

  val chunk0 = io.inputRawData(6, 0)
  val include0 = io.inputRawData(7)
  val chunk1 = io.inputRawData(14, 8)
  val include1 = io.inputRawData(15)
  val chunk2 = io.inputRawData(22, 16)
  val include2 = io.inputRawData(23)
  val chunk3 = io.inputRawData(30, 24)
  val include3 = io.inputRawData(31)
  val chunk4 = io.inputRawData(38, 32)
  val include4 = io.inputRawData(39)
  val chunk5 = io.inputRawData(46, 40)
  val include5 = io.inputRawData(47)
  val chunk6 = io.inputRawData(54, 48)
  val include6 = io.inputRawData(55)
  val chunk7 = io.inputRawData(62, 56)
  val include7 = io.inputRawData(63)

  val chunk8 = io.inputRawData(70, 64)
  val include8 = io.inputRawData(71)
  val chunk9 = io.inputRawData(72)

  val outchunk0 = chunk0

  val mask1 = include0
  val outchunk1 = Mux(mask1, chunk1, (0.U(7.W)))

  val mask2 = include0 & include1
  val outchunk2 = Mux(mask2, chunk2, (0.U(7.W)))

  val mask3 = include0 & include1 & include2
  val outchunk3 = Mux(mask3, chunk3, (0.U(7.W)))

  val mask4 = include0 & include1 & include2 & include3
  val outchunk4 = Mux(mask4, chunk4, (0.U(7.W)))

  val mask5 = include0 & include1 & include2 & include3 & include4
  val outchunk5 = Mux(mask5, chunk5, (0.U(7.W)))

  val mask6 = include0 & include1 & include2 & include3 & include4 & include5
  val outchunk6 = Mux(mask6, chunk6, (0.U(7.W)))

  val mask7 = include0 & include1 & include2 & include3 & include4 & include5 & include6
  val outchunk7 = Mux(mask7, chunk7, (0.U(7.W)))

  val mask8 = include0 & include1 & include2 & include3 & include4 & include5 & include6 & include7
  val outchunk8 = Mux(mask8, chunk8, (0.U(7.W)))

  val mask9 = include0 & include1 & include2 & include3 & include4 & include5 & include6 & include7 & include8
  val outchunk9 = Mux(mask9, chunk9, (0.U(1.W)))

  io.consumedLenBytes := mask1.asUInt +& mask2.asUInt +& mask3.asUInt +& mask4.asUInt +& mask5.asUInt +& mask6.asUInt +& mask7.asUInt +& mask8.asUInt +& mask9.asUInt +& 1.U

  io.outputData := Cat(
    outchunk9,
    outchunk8,
    outchunk7,
    outchunk6,
    outchunk5,
    outchunk4,
    outchunk3,
    outchunk2,
    outchunk1,
    outchunk0
  )

}


