#pragma once

struct alignas(64) Metadata{
    size_t field_num;
    int32_t class_id;
    char wire_type[52];
    char field_id[64];
};

// wire_type of protobuf
#define PROTOBUF_VARINT_TYPE 0
#define PROTOBUF_64BIT_TYPE 1
#define PROTOBUF_LENGTH_DELIMITED_TYPE 2
#define PROTOBUF_START_GROUP_TYPE 3 // deprecated
#define PROTOBUF_END_GROUP_TYPE 4   // deprecated
#define PROTOBUF_32BIT_TYPE 5

// wire_type of hardware
#define FPGA_TYPE_DOUBLE  1
#define FPGA_TYPE_FLOAT  2
#define FPGA_TYPE_INT64  3
#define FPGA_TYPE_UINT64  4
#define FPGA_TYPE_INT32  5
#define FPGA_TYPE_FIXED64  6
#define FPGA_TYPE_FIXED32  7
#define FPGA_TYPE_BOOL  8
#define FPGA_TYPE_STRING  9
#define FPGA_TYPE_GROUP  10
#define FPGA_TYPE_MESSAGE  11
#define FPGA_TYPE_BYTES  12
#define FPGA_TYPE_UINT32  13
#define FPGA_TYPE_ENUM  14
#define FPGA_TYPE_SFIXED32  15
#define FPGA_TYPE_SFIXED64  16
#define FPGA_TYPE_SINT32  17
#define FPGA_TYPE_SINT64  18

// wire_type of software
#define sw_int32_type 1
#define sw_int64_type 2
#define sw_fix32_type 3
#define sw_fix64_type 4
#define sw_float_type 5
#define sw_double_type 6
#define sw_bool_type 7
#define sw_enum_type 8
#define sw_string_type 9
#define sw_bytes_type 10
#define sw_ptr_type 11
#define sw_class_id_type 12
#define sw_done_flag_type 13
#define sw_uint32_type 14
#define sw_uint64_type 15
#define sw_sint32_type 16
#define sw_sint64_type 17
#define sw_sfix32_type 18
#define sw_sfix64_type 19

#define sw_repeated_int32_type 20
#define sw_repeated_int64_type 21
#define sw_repeated_fix32_type 22
#define sw_repeated_fix64_type 23
#define sw_repeated_float_type 24
#define sw_repeated_double_type 25
#define sw_repeated_bool_type 26
#define sw_repeated_enum_type 27
#define sw_repeated_string_type 28
#define sw_repeated_bytes_type 29
#define sw_repeated_ptr_type 30
#define sw_repeated_class_id_type 31
#define sw_repeated_done_flag_type 32
#define sw_repeated_uint32_type 33
#define sw_repeated_uint64_type 34
#define sw_repeated_sint32_type 35
#define sw_repeated_sint64_type 36
#define sw_repeated_sfix32_type 37
#define sw_repeated_sfix64_type 38


