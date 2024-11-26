#pragma once
#include <bits/stdc++.h>

#include "bf_no_encode.h"

#ifdef BENCH0
#include "bench_header/bench0_testclass.h"
#endif
#ifdef BENCH1
#include "bench_header/bench1_testclass.h"
#endif
#ifdef BENCH2
#include "bench_header/bench2_testclass.h"
#endif
#ifdef BENCH3
#include "bench_header/bench3_testclass.h"
#endif
#ifdef BENCH4
#include "bench_header/bench4_testclass.h"
#endif
#ifdef BENCH5
#include "bench_header/bench5_testclass.h"
#endif
#ifdef DEATHSTARBENCH
#include "bench_header/deathstarbench_testclass.h"
#endif
#ifdef MICROBENCH_1INT
#include "bench_header/1int_microbench_testclass.h"
#endif
#ifdef MICROBENCH_2INT
#include "bench_header/2int_microbench_testclass.h"
#endif
#ifdef MICROBENCH_4INT
#include "bench_header/4int_microbench_testclass.h"
#endif
#ifdef MICROBENCH_8INT
#include "bench_header/8int_microbench_testclass.h"
#endif
#ifdef MICROBENCH_16INT
#include "bench_header/16int_microbench_testclass.h"
#endif
#ifdef MICROBENCH_32INT
#include "bench_header/32int_microbench_testclass.h"
#endif
#ifdef MICROBENCH_64INT
#include "bench_header/64int_microbench_testclass.h"
#endif

#define TAG_SIZE 4
#define TAG_SIZE_PLUS_2 TAG_SIZE + 2

void InitMessageSizeVec(size_t *messageSizeVec) {
    for (int i = 0; i < 1000; ++i) {
        messageSizeVec[i] = getMessageSize(i);
    }
}

size_t ByteSizeLong(M_base *message, bool skip_long_string_flag = false) {
    size_t current_field_size = 0;
    size_t output_size = 0;
    void *obj_addr = message;
    obj_addr += 8;  //skip the pointer to virtual function table
    Metadata **ptr_to_metadata_ptr = reinterpret_cast<Metadata **>(obj_addr);
    Metadata &current_metadata = **ptr_to_metadata_ptr;
    obj_addr = ptr_to_metadata_ptr + 1;

    //write a loop to serialize all the fields of the object
    for (int i = 0; i < current_metadata.field_num; ++i) {
        switch (current_metadata.wire_type[i]) {
        case sw_int32_type:
        {
            int32_t *ptr_to_int32 = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_int32;
            obj_addr = ptr_to_int32 + 2;
            current_field_size = TAG_SIZE_PLUS_2 + Int32Size(current_field);
            output_size += current_field_size;
        }
        break;
        case sw_repeated_int32_type:
        {
            vector<int32_t> *ptr_to_int32_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
            vector<int32_t> &current_field = *ptr_to_int32_vector;
            obj_addr = ptr_to_int32_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += Int32Size(current_field[j]);
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_int64_type:
        {
            int64_t *ptr_to_int64 = reinterpret_cast<int64_t *>(obj_addr);
            int64_t &current_field = *ptr_to_int64;
            obj_addr = ptr_to_int64 + 1;
            current_field_size = TAG_SIZE_PLUS_2 + Int64Size(current_field);
            output_size += current_field_size;
        }
        break;
        case sw_repeated_int64_type:
        {
            vector<int64_t> *ptr_to_int64_vector = reinterpret_cast<vector<int64_t>*>(obj_addr);
            vector<int64_t> &current_field = *ptr_to_int64_vector;
            obj_addr = ptr_to_int64_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += Int64Size(current_field[j]);
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_uint64_type:
        {
            uint64_t *ptr_to_uint64 = reinterpret_cast<uint64_t *>(obj_addr);
            uint64_t &current_field = *ptr_to_uint64;
            obj_addr = ptr_to_uint64 + 1;
            current_field_size = TAG_SIZE_PLUS_2 + UInt64Size(current_field);
            output_size += current_field_size;
        }
        break;
        case sw_repeated_uint64_type:
        {
            vector<uint64_t> *ptr_to_uint64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
            vector<uint64_t> &current_field = *ptr_to_uint64_vector;
            obj_addr = ptr_to_uint64_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += UInt64Size(current_field[j]);
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_uint32_type:
        {
            uint32_t *ptr_to_uint32 = reinterpret_cast<uint32_t *>(obj_addr);
            uint32_t &current_field = *ptr_to_uint32;
            obj_addr = ptr_to_uint32 + 2;
            current_field_size = TAG_SIZE_PLUS_2 + UInt32Size(current_field);
            output_size += current_field_size;
        }
        break;
        case sw_repeated_uint32_type:
        {
            vector<uint32_t> *ptr_to_uint32_vector = reinterpret_cast<vector<uint32_t>*>(obj_addr);
            vector<uint32_t> &current_field = *ptr_to_uint32_vector;
            obj_addr = ptr_to_uint32_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); j++) {
                current_field_size += UInt32Size(current_field[j]);
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_bool_type:
        {
            bool *ptr_to_bool = reinterpret_cast<bool *>(obj_addr);
            bool &current_field = *ptr_to_bool;
            obj_addr = ptr_to_bool + 8;
            current_field_size = TAG_SIZE_PLUS_2 + 4;
            output_size += current_field_size;
        }
        break;
        case sw_repeated_bool_type:
        {
            vector<uint8_t> *ptr_to_bool_vector = reinterpret_cast<vector<uint8_t>*>(obj_addr);
            vector<uint8_t> &current_field = *ptr_to_bool_vector;
            obj_addr = ptr_to_bool_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += 4;
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_sint32_type: //当作int32处理，不做zigzag编码
        {
            int32_t *ptr_to_sint32 = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_sint32;
            obj_addr = ptr_to_sint32 + 2;
            current_field_size = TAG_SIZE_PLUS_2 + Int32Size(current_field);
            output_size += current_field_size;
        }
        break;
        case sw_double_type:
        {
            double *ptr_to_double = reinterpret_cast<double *>(obj_addr);
            double &current_field = *ptr_to_double;
            obj_addr = ptr_to_double + 1;
            current_field_size = TAG_SIZE_PLUS_2 + 8;
            output_size += current_field_size;
        }
        break;
        case sw_float_type:
        {
            float *ptr_to_float = reinterpret_cast<float *>(obj_addr);
            float &current_field = *ptr_to_float;
            obj_addr = ptr_to_float + 2;
            current_field_size = TAG_SIZE_PLUS_2 + 4;
            output_size += current_field_size;
        }
        break;
        case sw_repeated_float_type:
        {
            vector<float> *ptr_to_float_vector = reinterpret_cast<vector<float>*>(obj_addr);
            vector<float> &current_field = *ptr_to_float_vector;
            obj_addr = ptr_to_float_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += 4;
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_fix32_type:
        {
            int32_t *ptr_to_fix32 = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_fix32;
            obj_addr = ptr_to_fix32 + 2;
            current_field_size = TAG_SIZE_PLUS_2 + 4;
            output_size += current_field_size;
        }
        break;
        case sw_fix64_type:
        {
            uint64_t *ptr_to_fix64 = reinterpret_cast<uint64_t *>(obj_addr);
            uint64_t &current_field = *ptr_to_fix64;
            obj_addr = ptr_to_fix64 + 1;
            current_field_size = TAG_SIZE_PLUS_2 + 8;
            output_size += current_field_size;
        }
        break;
        case sw_repeated_fix64_type:
        {
            vector<uint64_t> *ptr_to_fix64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
            vector<uint64_t> &current_field = *ptr_to_fix64_vector;
            obj_addr = ptr_to_fix64_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += 8;
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_enum_type:
        {
            int32_t *ptr_to_enum = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_enum;
            obj_addr = ptr_to_enum + 2;
            current_field_size = TAG_SIZE_PLUS_2 + EnumSize(current_field);
            output_size += current_field_size;
        }
        break;
        case sw_repeated_enum_type:
        {
            vector<int32_t> *ptr_to_enum_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
            vector<int32_t> &current_field = *ptr_to_enum_vector;
            obj_addr = ptr_to_enum_vector + 1;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += EnumSize(current_field[j]);
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            output_size += current_field_size;
        }
        break;
        case sw_string_type:
        {
            std::string *ptr_to_string = reinterpret_cast<std::string *>(obj_addr);
            std::string &current_field = *ptr_to_string;
            obj_addr = ptr_to_string + 1;
            if (skip_long_string_flag && (current_field.size() > 1024)) {
                current_field_size = 0;
            } else {
                current_field_size = TAG_SIZE_PLUS_2 + StringSize(current_field);
            }
            output_size += current_field_size;
        }
        break;
        case sw_repeated_string_type:
        {
            vector<std::string> *ptr_to_string_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
            vector<std::string> &current_field = *ptr_to_string_vector;
            obj_addr = ptr_to_string_vector + 1;
            current_field_size = 0;
            bool skip_flag = false;
            for (int j = 0; j < current_field.size(); ++j) {
                if (skip_long_string_flag && (current_field[j].size() > 1024)) {
                    skip_flag = true;
                    break;
                } else {
                    current_field_size += StringSize(current_field[j]);
                }
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            if (skip_flag) {
                current_field_size = 0;
            }
            output_size += current_field_size;
        }
        break;
        case sw_bytes_type:
        {
            std::string *ptr_to_bytes = reinterpret_cast<std::string *>(obj_addr);
            std::string &current_field = *ptr_to_bytes;
            obj_addr = ptr_to_bytes + 1;
            if (skip_long_string_flag && (current_field.size() > 1024)) {
                current_field_size = 0;
            } else {
                current_field_size = TAG_SIZE_PLUS_2 + StringSize(current_field);
            }
            output_size += current_field_size;
        }
        break;
        case sw_repeated_bytes_type:
        {
            vector<std::string> *ptr_to_bytes_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
            vector<std::string> &current_field = *ptr_to_bytes_vector;
            obj_addr = ptr_to_bytes_vector + 1;
            current_field_size = 0;
            bool skip_flag = false;
            for (int j = 0; j < current_field.size(); ++j) {
                if (skip_long_string_flag && (current_field[j].size() > 1024)) {
                    skip_flag = true;
                    break;
                } else {
                    current_field_size += StringSize(current_field[j]);
                }
            }
            current_field_size += TAG_SIZE_PLUS_2 + VarintSize32(static_cast<uint32_t>(current_field_size));
            if (skip_flag) {
                current_field_size = 0;
            }
            output_size += current_field_size;
        }
        break;
        case sw_ptr_type:
        {
            void **ptr_to_ptr = reinterpret_cast<void **>(obj_addr);
            void *&current_field = *ptr_to_ptr;
            obj_addr = ptr_to_ptr + 1;
            current_field_size = ByteSizeLong(reinterpret_cast<M_base *>(current_field), skip_long_string_flag);
            output_size += current_field_size;
        }
        break;
        default:
            std::cout << "Error: current_metadata.class_id = " << current_metadata.class_id << std::endl;
            std::cout << "Error: current_metadata.wire_type[" << i << "] = " << (int)(current_metadata.wire_type[i]) << std::endl;
            break;
        }
    }
    return output_size;
}


uint8_t *SerializeToString_DFS(M_base *message, uint8_t *current_buffer_addr, bool skip_long_string_flag, size_t *messageSizeVec) {
    uint16_t current_field_size = 0;
    void *obj_addr = message;
    void *obj_addr_base = obj_addr;
    obj_addr += 8;  //skip the pointer to virtual function table
    Metadata **ptr_to_metadata_ptr = reinterpret_cast<Metadata **>(obj_addr);
    Metadata &current_metadata = **ptr_to_metadata_ptr;
    obj_addr = ptr_to_metadata_ptr + 1;
    size_t message_size = messageSizeVec[current_metadata.class_id];
    //jump to the end of the object
    obj_addr = obj_addr_base + message_size;

    //write a loop to serialize all the fields of the object
    for (int i = current_metadata.field_num - 1; i >= 0; --i) {
        uint32_t current_field_id = current_metadata.field_id[i];
        switch (current_metadata.wire_type[i]) {
        case sw_int32_type:
        {
            obj_addr -= 8;
            int32_t *ptr_to_int32 = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_int32;
            current_field_size = TAG_SIZE + Int32Size(current_field);
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteInt32ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_int32_type:
        {
            obj_addr -= 24;
            vector<int32_t> *ptr_to_int32_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
            vector<int32_t> &current_field = *ptr_to_int32_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += Int32Size(current_field[j]);
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedInt32ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_int64_type:
        {
            obj_addr -= 8;
            int64_t *ptr_to_int64 = reinterpret_cast<int64_t *>(obj_addr);
            int64_t &current_field = *ptr_to_int64;
            current_field_size = TAG_SIZE + Int64Size(current_field);
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteInt64ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_int64_type:
        {
            obj_addr -= 24;
            vector<int64_t> *ptr_to_int64_vector = reinterpret_cast<vector<int64_t>*>(obj_addr);
            vector<int64_t> &current_field = *ptr_to_int64_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += Int64Size(current_field[j]);
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedInt64ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_uint64_type:
        {
            obj_addr -= 8;
            uint64_t *ptr_to_uint64 = reinterpret_cast<uint64_t *>(obj_addr);
            uint64_t &current_field = *ptr_to_uint64;
            current_field_size = TAG_SIZE + UInt64Size(current_field);
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteUInt64ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_uint64_type:
        {
            obj_addr -= 24;
            vector<uint64_t> *ptr_to_uint64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
            vector<uint64_t> &current_field = *ptr_to_uint64_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += UInt64Size(current_field[j]);
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedUInt64ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_uint32_type:
        {
            obj_addr -= 8;
            uint32_t *ptr_to_uint32 = reinterpret_cast<uint32_t *>(obj_addr);
            uint32_t &current_field = *ptr_to_uint32;
            current_field_size = TAG_SIZE + UInt32Size(current_field);
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteUInt32ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_uint32_type:
        {
            obj_addr -= 24;
            vector<uint32_t> *ptr_to_uint32_vector = reinterpret_cast<vector<uint32_t>*>(obj_addr);
            vector<uint32_t> &current_field = *ptr_to_uint32_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); j++) {
                current_field_size += UInt32Size(current_field[j]);
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedUInt32ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_bool_type:
        {
            obj_addr -= 8;
            bool *ptr_to_bool = reinterpret_cast<bool *>(obj_addr);
            bool &current_field = *ptr_to_bool;
            current_field_size = TAG_SIZE + 1;
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteBoolToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_bool_type:
        {
            obj_addr -= 24;
            vector<uint8_t> *ptr_to_bool_vector = reinterpret_cast<vector<uint8_t>*>(obj_addr);
            vector<uint8_t> &current_field = *ptr_to_bool_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += 1;
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedBoolToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_sint32_type:
        {
            obj_addr -= 8;
            int32_t *ptr_to_sint32 = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_sint32;
            current_field_size = TAG_SIZE + Int32Size(current_field);
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteInt32ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_double_type:
        {
            obj_addr -= 8;
            double *ptr_to_double = reinterpret_cast<double *>(obj_addr);
            double &current_field = *ptr_to_double;
            current_field_size = TAG_SIZE + 8;
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteDoubleToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_float_type:
        {
            obj_addr -= 8;
            float *ptr_to_float = reinterpret_cast<float *>(obj_addr);
            float &current_field = *ptr_to_float;
            current_field_size = TAG_SIZE + 4;
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteFloatToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_float_type:
        {
            obj_addr -= 24;
            vector<float> *ptr_to_float_vector = reinterpret_cast<vector<float>*>(obj_addr);
            vector<float> &current_field = *ptr_to_float_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += 4;
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedFloatToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_fix32_type:
        {
            obj_addr -= 8;
            int32_t *ptr_to_fix32 = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_fix32;
            current_field_size = TAG_SIZE + 4;
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteFixed32ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_fix64_type:
        {
            obj_addr -= 8;
            uint64_t *ptr_to_fix64 = reinterpret_cast<uint64_t *>(obj_addr);
            uint64_t &current_field = *ptr_to_fix64;
            current_field_size = TAG_SIZE + 8;
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteFixed64ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_fix64_type:
        {
            obj_addr -= 24;
            vector<uint64_t> *ptr_to_fix64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
            vector<uint64_t> &current_field = *ptr_to_fix64_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += 8;
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedFixed64ToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_enum_type:
        {
            obj_addr -= 8;
            int32_t *ptr_to_enum = reinterpret_cast<int32_t *>(obj_addr);
            int32_t &current_field = *ptr_to_enum;
            current_field_size = TAG_SIZE + EnumSize(current_field);
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteEnumToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_repeated_enum_type:
        {
            obj_addr -= 24;
            vector<int32_t> *ptr_to_enum_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
            vector<int32_t> &current_field = *ptr_to_enum_vector;
            current_field_size = 0;
            for (int j = 0; j < current_field.size(); ++j) {
                current_field_size += EnumSize(current_field[j]);
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
            current_buffer_addr = WriteRepeatedEnumToArray(current_field_id, current_field, current_buffer_addr);
        }
        break;
        case sw_string_type:
        {
            obj_addr -= 32;
            std::string *ptr_to_string = reinterpret_cast<std::string *>(obj_addr);
            std::string &current_field = *ptr_to_string;
            if (skip_long_string_flag && (current_field.size() > 1024)) {
                current_field_size = 0;
            } else {
                current_field_size = TAG_SIZE + StringSize(current_field);
                current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
                current_buffer_addr = WriteStringToArray(current_field_id, current_field, current_buffer_addr);
            }
        }
        break;
        case sw_repeated_string_type:
        {
            obj_addr -= 24;
            vector<std::string> *ptr_to_string_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
            vector<std::string> &current_field = *ptr_to_string_vector;
            current_field_size = 0;
            bool skip_flag = false;
            for (int j = 0; j < current_field.size(); ++j) {
                if (skip_long_string_flag && (current_field[j].size() > 1024)) {
                    skip_flag = true;
                    break;
                } else {
                    current_field_size += StringSize(current_field[j]);
                }
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            if (skip_flag) {
                current_field_size = 0;
            } else {
                current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
                current_buffer_addr = WriteRepeatedStringToArray(current_field_id, current_field, current_buffer_addr);
            }
        }
        break;
        case sw_bytes_type:
        {
            obj_addr -= 32;
            std::string *ptr_to_bytes = reinterpret_cast<std::string *>(obj_addr);
            std::string &current_field = *ptr_to_bytes;
            if (skip_long_string_flag && (current_field.size() > 1024)) {
                current_field_size = 0;
            } else {
                current_field_size = TAG_SIZE + StringSize(current_field);
                current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
                current_buffer_addr = WriteBytesToArray(current_field_id, current_field, current_buffer_addr);
            }
        }
        break;
        case sw_repeated_bytes_type:
        {
            obj_addr -= 24;
            vector<std::string> *ptr_to_bytes_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
            vector<std::string> &current_field = *ptr_to_bytes_vector;
            current_field_size = 0;
            bool skip_flag = false;
            for (int j = 0; j < current_field.size(); ++j) {
                if (skip_long_string_flag && (current_field[j].size() > 1024)) {
                    skip_flag = true;
                    break;
                } else {
                    current_field_size += StringSize(current_field[j]);
                }
            }
            current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
            if (skip_flag) {
                current_field_size = 0;
            } else {
                current_buffer_addr = WriteLengthToArray(current_field_size, current_buffer_addr);
                current_buffer_addr = WriteRepeatedBytesToArray(current_field_id, current_field, current_buffer_addr);
            }
        }
        break;
        case sw_ptr_type:
        {
            obj_addr -= 8;
            void **ptr_to_ptr = reinterpret_cast<void **>(obj_addr);
            void *&current_field = *ptr_to_ptr;
            current_buffer_addr = SerializeToString_DFS(reinterpret_cast<M_base *>(current_field), current_buffer_addr, skip_long_string_flag, messageSizeVec);
        }
        break;
        default:
            break;
        }
    }
    return current_buffer_addr;
}

uint8_t *SerializeToString(M_base *message, string *output, bool skip_long_string_flag, size_t *messageSizeVec) {
    uint8_t *temp_p_h2c = (uint8_t *)output;
    SerializeToString_DFS(message, reinterpret_cast<uint8_t *>(output), skip_long_string_flag, messageSizeVec);
    return temp_p_h2c;
}


#ifdef BENCH0
#include "bench_header/bench0_target.inc"
#endif
#ifdef BENCH1
#include "bench_header/bench1_target.inc"
#endif
#ifdef BENCH2
#include "bench_header/bench2_target.inc"
#endif
#ifdef BENCH3
#include "bench_header/bench3_target.inc"
#endif
#ifdef BENCH4
#include "bench_header/bench4_target.inc"
#endif
#ifdef BENCH5
#include "bench_header/bench5_target.inc"
#endif
#ifdef DEATHSTARBENCH
#include "bench_header/deathstarbench_target.inc"
#endif
#ifdef MICROBENCH_1INT
#include "bench_header/1int_microbench_target.inc"
#endif
#ifdef MICROBENCH_2INT
#include "bench_header/2int_microbench_target.inc"
#endif
#ifdef MICROBENCH_4INT
#include "bench_header/4int_microbench_target.inc"
#endif
#ifdef MICROBENCH_8INT
#include "bench_header/8int_microbench_target.inc"
#endif
#ifdef MICROBENCH_16INT
#include "bench_header/16int_microbench_target.inc"
#endif
#ifdef MICROBENCH_32INT
#include "bench_header/32int_microbench_target.inc"
#endif
#ifdef MICROBENCH_64INT
#include "bench_header/64int_microbench_target.inc"
#endif