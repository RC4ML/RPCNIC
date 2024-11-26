package serialization

import chisel3._
import chisel3.util._
import common.axi.HasLast



object WIRE_TYPES {
  val WIRE_TYPE_VARINT = 0.U
  val WIRE_TYPE_64bit = 1.U
  val WIRE_TYPE_LEN_DELIM = 2.U
  val WIRE_TYPE_START_GROUP = 3.U
  val WIRE_TYPE_END_GROUP = 4.U
  val WIRE_TYPE_32bit = 5.U
}

object PROTO_TYPES {
  val TYPE_DOUBLE = 1.U
  val TYPE_FLOAT = 2.U
  val TYPE_INT64 = 3.U
  val TYPE_UINT64 = 4.U
  val TYPE_INT32 = 5.U
  val TYPE_FIXED64 = 6.U
  val TYPE_FIXED32 = 7.U
  val TYPE_BOOL = 8.U
  val TYPE_STRING = 9.U
  val TYPE_GROUP = 10.U
  val TYPE_MESSAGE = 11.U

  val TYPE_BYTES = 12.U
  val TYPE_UINT32 = 13.U

  val TYPE_ENUM = 14.U
  val TYPE_SFIXED32 = 15.U
  val TYPE_SFIXED64 = 16.U
  val TYPE_SINT32 = 17.U
  val TYPE_SINT64 = 18.U

  val TYPE_fieldwidth = 5.W

  val Des_Table_Depth = 1024



  def detailedTypeToWireType(detailedType: UInt): UInt = {
    val wire_type_lookup = VecInit(
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_64bit,
      WIRE_TYPES.WIRE_TYPE_32bit,
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_64bit,
      WIRE_TYPES.WIRE_TYPE_32bit,
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_LEN_DELIM,
      WIRE_TYPES.WIRE_TYPE_START_GROUP,
      WIRE_TYPES.WIRE_TYPE_LEN_DELIM,
      WIRE_TYPES.WIRE_TYPE_LEN_DELIM,
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_32bit,
      WIRE_TYPES.WIRE_TYPE_64bit,
      WIRE_TYPES.WIRE_TYPE_VARINT,
      WIRE_TYPES.WIRE_TYPE_VARINT,
    )
    wire_type_lookup(detailedType)
  }

  def detailedTypeToCppSizeLog2(detailedType: UInt): UInt =  {
    val cpp_size = VecInit(
        0.U,
      3.U,
      2.U,
      3.U,
      3.U,
      2.U,
      3.U,
      2.U,
      2.U,
      3.U,
        0.U,
      3.U,
      3.U,
      2.U,
      2.U,
      2.U,
      3.U,
      2.U,
      3.U,
    )
    cpp_size(detailedType)
  }


  def detailedTypeIsVarintSigned(detailedType: UInt): Bool = {
    val varint_is_signed = VecInit(
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      false.B,
      true.B,
      true.B,
    )
    varint_is_signed(detailedType)
  }


  def detailedTypeIsPotentiallyScalar(detailedType: UInt): Bool = {
    val varint_is_signed = VecInit(
      false.B,
      true.B,
      true.B,
      true.B,
      true.B,
      true.B,
      true.B,
      true.B,
      true.B,
      false.B,
      false.B,
      false.B,
      false.B,
      true.B,
      true.B,
      true.B,
      true.B,
      true.B,
      true.B,
    )
    varint_is_signed(detailedType)
  }

 val _lookup = VecInit(

0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
0.U,
    )





}