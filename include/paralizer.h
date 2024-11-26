#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <ctime>
#include <queue>
#include <chrono>
#include <ratio>
#include <pthread.h>
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <time.h>
#include <netinet/in.h>
#include <bitset>
#include <QDMAController.hpp>
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/args.h>
#include <fmt/ostream.h>
#include <fmt/std.h>
#include <fmt/color.h>
#include <unistd.h>
#include <cmath>
#include <sstream>
#include <iomanip>

#include "encode.h"
#include "decode.h"

#define TAG_SIZE ((current_metadata.field_id[i] < 16) ? 1 : 2)

struct FPGA_Field{
    uint8_t field_type; 
    uint8_t reserve;
    uint16_t sub_class_id;
};

struct FPGA_Metadata{
    uint16_t class_id;
    uint16_t max_field_number;
    uint32_t class_length;
    FPGA_Field field[46];
};

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
#ifdef SIMPLETEST
#include "bench_header/e2e_testclass.h"
#endif
#ifdef DEATHSTARBENCH
#include "bench_header/deathstarbench_testclass.h"
#endif

void InitMessageSizeVec(size_t* messageSizeVec){
    for(int i = 0; i < 1000; ++i){
        messageSizeVec[i] = getMessageSize(i);
    }
}

size_t ByteSizeLong(M_base* message, bool skip_long_string_flag = false){
    // if(depth > max_depth) max_depth = depth;
    size_t current_field_size = 0;
    size_t output_size = 0;
    void* obj_addr = message;
    obj_addr += 8;  //skip the pointer to virtual function table
    Metadata** ptr_to_metadata_ptr = reinterpret_cast<Metadata**>(obj_addr);     
    Metadata &current_metadata = **ptr_to_metadata_ptr;
    obj_addr = ptr_to_metadata_ptr + 1;
    // //write the class_id of the object
    // current_field_size = 1 + Int32Size(current_metadata.class_id);
    // //if not overflow, write the field into the buffer
    // output_size += current_field_size;

    //write a loop to serialize all the fields of the object
    for(int i = 0; i < current_metadata.field_num; ++i){
        switch(current_metadata.wire_type[i]){
            case sw_int32_type:
                {
                    int32_t* ptr_to_int32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_int32;
                    obj_addr = ptr_to_int32 + 2;
                    current_field_size = TAG_SIZE + Int32Size(current_field);
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_int32_type:
                {
                    vector<int32_t>* ptr_to_int32_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
                    vector<int32_t>& current_field = *ptr_to_int32_vector;
                    obj_addr = ptr_to_int32_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        current_field_size += Int32Size(current_field[j]);
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;                
            case sw_int64_type:
                {
                    int64_t* ptr_to_int64 = reinterpret_cast<int64_t*>(obj_addr);
                    int64_t& current_field = *ptr_to_int64;
                    obj_addr = ptr_to_int64 + 1;
                    current_field_size = TAG_SIZE + Int64Size(current_field);
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_int64_type:
                {
                    vector<int64_t>* ptr_to_int64_vector = reinterpret_cast<vector<int64_t>*>(obj_addr);
                    vector<int64_t>& current_field = *ptr_to_int64_vector;
                    obj_addr = ptr_to_int64_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        current_field_size += Int64Size(current_field[j]);
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            case sw_uint64_type:
                {
                    uint64_t* ptr_to_uint64 = reinterpret_cast<uint64_t*>(obj_addr);
                    uint64_t& current_field = *ptr_to_uint64;
                    obj_addr = ptr_to_uint64 + 1;
                    current_field_size = TAG_SIZE + UInt64Size(current_field);
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_uint64_type:
                {
                    vector<uint64_t>* ptr_to_uint64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
                    vector<uint64_t>& current_field = *ptr_to_uint64_vector;
                    obj_addr = ptr_to_uint64_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        current_field_size += UInt64Size(current_field[j]);
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            case sw_uint32_type:
                {
                    uint32_t* ptr_to_uint32 = reinterpret_cast<uint32_t*>(obj_addr);
                    uint32_t& current_field = *ptr_to_uint32;
                    obj_addr = ptr_to_uint32 + 2;
                    current_field_size = TAG_SIZE + UInt32Size(current_field);
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_uint32_type:
                {
                    vector<uint32_t>* ptr_to_uint32_vector = reinterpret_cast<vector<uint32_t>*>(obj_addr);
                    vector<uint32_t>& current_field = *ptr_to_uint32_vector;
                    obj_addr = ptr_to_uint32_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); j++){
                        current_field_size += UInt32Size(current_field[j]);
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            case sw_bool_type:
                {
                    bool* ptr_to_bool = reinterpret_cast<bool*>(obj_addr);
                    bool& current_field = *ptr_to_bool;
                    obj_addr = ptr_to_bool + 8;
                    current_field_size = TAG_SIZE + 1;
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_bool_type:
                {
                    vector<bool>* ptr_to_bool_vector = reinterpret_cast<vector<bool>*>(obj_addr);
                    vector<bool>& current_field = *ptr_to_bool_vector;
                    obj_addr = ptr_to_bool_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        current_field_size += 1;
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            case sw_sint32_type: //当作int32处理，不做zigzag编码
                {
                    int32_t* ptr_to_sint32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_sint32;
                    obj_addr = ptr_to_sint32 + 2;
                    current_field_size = TAG_SIZE + Int32Size(current_field);
                    output_size += current_field_size;
                }
                break;
            case sw_double_type:
                {
                    double* ptr_to_double = reinterpret_cast<double*>(obj_addr);
                    double& current_field = *ptr_to_double;
                    obj_addr = ptr_to_double + 1;
                    current_field_size = TAG_SIZE + 8;
                    output_size += current_field_size;
                }
                break;
            case sw_float_type:
                {
                    float* ptr_to_float = reinterpret_cast<float*>(obj_addr);
                    float& current_field = *ptr_to_float;
                    obj_addr = ptr_to_float + 2;
                    current_field_size = TAG_SIZE + 4;
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_float_type:
                {
                    vector<float>* ptr_to_float_vector = reinterpret_cast<vector<float>*>(obj_addr);
                    vector<float>& current_field = *ptr_to_float_vector;
                    obj_addr = ptr_to_float_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        current_field_size += 4;
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            case sw_fix32_type:
                {
                    int32_t* ptr_to_fix32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_fix32;
                    obj_addr = ptr_to_fix32 + 2;
                    current_field_size = TAG_SIZE + 4;
                    output_size += current_field_size;
                }
                break;
            case sw_fix64_type:
                {
                    uint64_t* ptr_to_fix64 = reinterpret_cast<uint64_t*>(obj_addr);
                    uint64_t& current_field = *ptr_to_fix64;
                    obj_addr = ptr_to_fix64 + 1;
                    current_field_size = TAG_SIZE + 8;
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_fix64_type:
                {
                    vector<uint64_t>* ptr_to_fix64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
                    vector<uint64_t>& current_field = *ptr_to_fix64_vector;
                    obj_addr = ptr_to_fix64_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        current_field_size += 8;
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            case sw_enum_type:
                {
                    int32_t* ptr_to_enum = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_enum;
                    obj_addr = ptr_to_enum + 2;
                    current_field_size = TAG_SIZE + EnumSize(current_field);
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_enum_type:
                {
                    vector<int32_t>* ptr_to_enum_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
                    vector<int32_t>& current_field = *ptr_to_enum_vector;
                    obj_addr = ptr_to_enum_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        current_field_size += EnumSize(current_field[j]);
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            case sw_string_type:
                {
                    std::string* ptr_to_string = reinterpret_cast<std::string*>(obj_addr);
                    std::string& current_field = *ptr_to_string;
                    std::string skip_field = "";
                    obj_addr = ptr_to_string + 1;
                    if((current_field.size() > 1024) && skip_long_string_flag){
                        current_field_size = 0;
                    }
                    else{
                        current_field_size = TAG_SIZE + StringSize(current_field);
                    }
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_string_type:
                {
                    vector<std::string>* ptr_to_string_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
                    vector<std::string>& current_field = *ptr_to_string_vector;
                    std::string skip_field = "";
                    bool hasbigstr = false;
                    obj_addr = ptr_to_string_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        if((current_field[j].size() > 1024) && skip_long_string_flag){
                            hasbigstr = true;
                            break;
                        }
                        else{
                            current_field_size += StringSize(current_field[j]);
                        }                            
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    if(hasbigstr){
                        current_field_size = 0;
                    }
                    output_size += current_field_size;
                }
                break;
            case sw_bytes_type:
                {
                    std::string* ptr_to_bytes = reinterpret_cast<std::string*>(obj_addr);
                    std::string& current_field = *ptr_to_bytes;
                    std::string skip_field = "";
                    obj_addr = ptr_to_bytes + 1;
                    if((current_field.size() > 1024) && skip_long_string_flag){
                        current_field_size = 0;
                    }
                    else{
                        current_field_size = TAG_SIZE + StringSize(current_field);
                    }                        
                    output_size += current_field_size;
                }
                break;
            case sw_repeated_bytes_type: 
                {
                    vector<std::string>* ptr_to_bytes_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
                    vector<std::string>& current_field = *ptr_to_bytes_vector;
                    std::string skip_field = "";
                    bool hasbigstr = false;
                    obj_addr = ptr_to_bytes_vector + 1;
                    current_field_size = 0;
                    for(int j = 0; j < current_field.size(); ++j){
                        if((current_field[j].size() > 1024) && skip_long_string_flag){
                            hasbigstr = true;
                            break;
                        }
                        else{
                            current_field_size += StringSize(current_field[j]);
                        }
                    }
                    current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    if(hasbigstr){
                        current_field_size = 0;
                    }
                    output_size += current_field_size;
                }
                break;
            case sw_ptr_type:
                {
                    void** ptr_to_ptr = reinterpret_cast<void**>(obj_addr);
                    void*& current_field = *ptr_to_ptr;
                    obj_addr = ptr_to_ptr + 1;                        
                    current_field_size = ByteSizeLong(reinterpret_cast<M_base*>(current_field), skip_long_string_flag);
					current_field_size += TAG_SIZE + VarintSize32(static_cast<uint32_t>(current_field_size));
                    output_size += current_field_size;
                }
                break;
            default:
                std::cout << "Error: current_metadata.class_id = " << current_metadata.class_id << std::endl;
                std::cout << "Error: current_metadata.wire_type[" << i << "] = " << (int)(current_metadata.wire_type[i]) << std::endl;
                break;
        }      
        // std::cout <<"class_id: "<< current_metadata.class_id <<" outputsize: " << output_size <<std::endl;  
    }
    return output_size;
}

uint8_t* SerializeToString_DFS(M_base* message, uint8_t* current_buffer_addr, bool skip_long_string_flag = false){
    void* obj_addr = message;
    obj_addr += 8;  //skip the pointer to virtual function table
    Metadata** ptr_to_metadata_ptr = reinterpret_cast<Metadata**>(obj_addr);     
    Metadata &current_metadata = **ptr_to_metadata_ptr;
    obj_addr = ptr_to_metadata_ptr + 1;
    // //write the class_id of the object
    // current_buffer_addr = WriteClassIdToArray(0, current_metadata.class_id, current_buffer_addr);
    //write a loop to serialize all the fields of the object
    for(int i = 0; i < current_metadata.field_num; ++i){
        uint32_t current_field_id = current_metadata.field_id[i];

        std::cout  << (int)current_metadata.wire_type[i] << std::endl;

      
        switch(current_metadata.wire_type[i]){
            case sw_int32_type:
                {
                    int32_t* ptr_to_int32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_int32;
                    obj_addr = ptr_to_int32 + 2;
                    current_buffer_addr = WriteInt32ToArray(current_field_id, current_field, current_buffer_addr);                     
                }
                break;
            case sw_repeated_int32_type:
                {
                    vector<int32_t>* ptr_to_int32_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
                    vector<int32_t>& current_field = *ptr_to_int32_vector;
                    obj_addr = ptr_to_int32_vector + 1;
                    current_buffer_addr = WriteRepeatedInt32ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;                
            case sw_int64_type:
                {
                    int64_t* ptr_to_int64 = reinterpret_cast<int64_t*>(obj_addr);
                    int64_t& current_field = *ptr_to_int64;
                    obj_addr = ptr_to_int64 + 1;
                    current_buffer_addr = WriteInt64ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_repeated_int64_type:
                {
                    vector<int64_t>* ptr_to_int64_vector = reinterpret_cast<vector<int64_t>*>(obj_addr);
                    vector<int64_t>& current_field = *ptr_to_int64_vector;
                    obj_addr = ptr_to_int64_vector + 1;
                    current_buffer_addr = WriteRepeatedInt64ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_uint64_type:
                {
                    uint64_t* ptr_to_uint64 = reinterpret_cast<uint64_t*>(obj_addr);
                    uint64_t& current_field = *ptr_to_uint64;
                    obj_addr = ptr_to_uint64 + 1;
                    current_buffer_addr = WriteUInt64ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_repeated_uint64_type:
                {
                    vector<uint64_t>* ptr_to_uint64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
                    vector<uint64_t>& current_field = *ptr_to_uint64_vector;
                    obj_addr = ptr_to_uint64_vector + 1;
                    current_buffer_addr = WriteRepeatedUInt64ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_uint32_type:
                {
                    uint32_t* ptr_to_uint32 = reinterpret_cast<uint32_t*>(obj_addr);
                    uint32_t& current_field = *ptr_to_uint32;
                    obj_addr = ptr_to_uint32 + 2;
                    current_buffer_addr = WriteUInt32ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_repeated_uint32_type:
                {
                    vector<uint32_t>* ptr_to_uint32_vector = reinterpret_cast<vector<uint32_t>*>(obj_addr);
                    vector<uint32_t>& current_field = *ptr_to_uint32_vector;
                    obj_addr = ptr_to_uint32_vector + 1;
                    current_buffer_addr = WriteRepeatedUInt32ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_bool_type:
                {
                    bool* ptr_to_bool = reinterpret_cast<bool*>(obj_addr);
                    bool& current_field = *ptr_to_bool;
                    obj_addr = ptr_to_bool + 8;
                    current_buffer_addr = WriteBoolToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_repeated_bool_type:
                {
                    vector<bool>* ptr_to_bool_vector = reinterpret_cast<vector<bool>*>(obj_addr);
                    vector<bool>& current_field = *ptr_to_bool_vector;
                    obj_addr = ptr_to_bool_vector + 1;
                    current_buffer_addr = WriteRepeatedBoolToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_sint32_type:
                {
                    int32_t* ptr_to_sint32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_sint32;
                    obj_addr = ptr_to_sint32 + 2;
                    current_buffer_addr = WriteInt32ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_double_type:
                {
                    double* ptr_to_double = reinterpret_cast<double*>(obj_addr);
                    double& current_field = *ptr_to_double;
                    obj_addr = ptr_to_double + 1;
                    current_buffer_addr = WriteDoubleToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_float_type:
                {
                    float* ptr_to_float = reinterpret_cast<float*>(obj_addr);
                    float& current_field = *ptr_to_float;
                    obj_addr = ptr_to_float + 2;
                    current_buffer_addr = WriteFloatToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_repeated_float_type:
                {
                    vector<float>* ptr_to_float_vector = reinterpret_cast<vector<float>*>(obj_addr);
                    vector<float>& current_field = *ptr_to_float_vector;
                    obj_addr = ptr_to_float_vector + 1;
                    current_buffer_addr = WriteRepeatedFloatToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_fix32_type:
                {
                    int32_t* ptr_to_fix32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_fix32;
                    obj_addr = ptr_to_fix32 + 2;
                    current_buffer_addr = WriteFixed32ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_fix64_type:
                {
                    uint64_t* ptr_to_fix64 = reinterpret_cast<uint64_t*>(obj_addr);
                    uint64_t& current_field = *ptr_to_fix64;
                    obj_addr = ptr_to_fix64 + 1;
                    current_buffer_addr = WriteFixed64ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_repeated_fix64_type:
                {
                    vector<uint64_t>* ptr_to_fix64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
                    vector<uint64_t>& current_field = *ptr_to_fix64_vector;
                    obj_addr = ptr_to_fix64_vector + 1;
                    current_buffer_addr = WriteRepeatedFixed64ToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_enum_type:
                {
                    int32_t* ptr_to_enum = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_enum;
                    obj_addr = ptr_to_enum + 2;
                    current_buffer_addr = WriteEnumToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_repeated_enum_type:
                {
                    vector<int32_t>* ptr_to_enum_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
                    vector<int32_t>& current_field = *ptr_to_enum_vector;
                    obj_addr = ptr_to_enum_vector + 1;
                    current_buffer_addr = WriteRepeatedEnumToArray(current_field_id, current_field, current_buffer_addr);
                }
                break;
            case sw_string_type:
                {
                    std::string* ptr_to_string = reinterpret_cast<std::string*>(obj_addr);
                    std::string& current_field = *ptr_to_string;
                    std::string skip_field = "";
                    obj_addr = ptr_to_string + 1;
                    if((current_field.size() > 1024) && skip_long_string_flag){
                        ;                                                      
                    }
                    else{
                        current_buffer_addr = WriteStringToArray(current_field_id, current_field, current_buffer_addr);                       
                    }
                }
                break;
            case sw_repeated_string_type:
                {
                    vector<std::string>* ptr_to_string_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
                    vector<std::string>& current_field = *ptr_to_string_vector;
                    std::string skip_field = "";
                    bool hasbigstr = false;
                    obj_addr = ptr_to_string_vector + 1;
                    for(int j = 0; j < current_field.size(); ++j){
                        if((current_field[j].size() > 1024) && skip_long_string_flag){
                            hasbigstr = true;
                            break;
                        }                           
                    }
                    if(!hasbigstr){
                        current_buffer_addr = WriteRepeatedStringToArray(current_field_id, current_field, current_buffer_addr);
                    }
                }
                break;
            case sw_bytes_type:
                {
                    std::string* ptr_to_bytes = reinterpret_cast<std::string*>(obj_addr);
                    std::string& current_field = *ptr_to_bytes;
                    std::string skip_field = "";
                    obj_addr = ptr_to_bytes + 1;
                    if((current_field.size() > 1024) && skip_long_string_flag){
                        ;                                                      
                    }
                    else{
                        current_buffer_addr = WriteBytesToArray(current_field_id, current_field, current_buffer_addr);                       
                    }                        
                }
                break;
            case sw_repeated_bytes_type: 
                {
                    vector<std::string>* ptr_to_bytes_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
                    vector<std::string>& current_field = *ptr_to_bytes_vector;
                    std::string skip_field = "";
                    bool hasbigstr = false;
                    obj_addr = ptr_to_bytes_vector + 1;
                    for(int j = 0; j < current_field.size(); ++j){
                        if((current_field[j].size() > 1024) && skip_long_string_flag){
                            hasbigstr = true;
                            break;
                        }                           
                    }
                    if(!hasbigstr){
                        current_buffer_addr = WriteRepeatedStringToArray(current_field_id, current_field, current_buffer_addr);
                    }                    
                }
                break;
            case sw_ptr_type:
                {
                    void** ptr_to_ptr = reinterpret_cast<void**>(obj_addr);
                    void*& current_field = *ptr_to_ptr;
                    obj_addr = ptr_to_ptr + 1;     
					current_buffer_addr = WriteTagToArray(current_field_id, PROTOBUF_LENGTH_DELIMITED_TYPE, current_buffer_addr);
					current_buffer_addr = WriteVarint32ToArray(ByteSizeLong(reinterpret_cast<M_base*>(current_field), false), current_buffer_addr);
                    current_buffer_addr = SerializeToString_DFS(reinterpret_cast<M_base*>(current_field), current_buffer_addr, skip_long_string_flag);                                        
                }
                break;
            default:
                break;
        }        
    }
    return current_buffer_addr;
}

void SerializeToString(M_base* message, size_t* output, bool skip_long_string_flag = false){
    SerializeToString_DFS(message, reinterpret_cast<uint8_t*> (output), skip_long_string_flag);
}

const char * ParseFromString_DFS(const char* current_buffer_addr, uint32_t current_metadata_idx, void* current_obj_addr, Metadata* metadataVec, size_t* messageSizeVec, FPGA_Metadata* FPGA_metadataVec){
    uint32_t tag, wire_type;
    uint16_t field_length;
    size_t message_size = messageSizeVec[current_metadata_idx];
    //jump to the end of the object
    current_obj_addr = current_obj_addr + message_size;
    for(int i = metadataVec[current_metadata_idx].field_num - 1; i >= 0; --i){
        wire_type = metadataVec[current_metadata_idx].wire_type[i];
        bool skip_flag = false;
        uint32_t current_field_id = metadataVec[current_metadata_idx].field_id[i];
        if((FPGA_metadataVec[current_metadata_idx].field[current_field_id].field_type & 0x1) == 0){
            skip_flag = true;
            // cout << "skip field " << current_field_id << endl;
        }
        if(wire_type != sw_ptr_type && !skip_flag){
            field_length = ReadFieldLength(&current_buffer_addr);
            tag = ReadVarint32(&current_buffer_addr);            
        }
        switch (wire_type)
        {
            case sw_int32_type:
            {
                current_obj_addr -= 8;
                int32_t* ptr_to_int32 = reinterpret_cast<int32_t*>(current_obj_addr);
                *ptr_to_int32 = ReadVarint32(&current_buffer_addr);
            }
                break;
            case sw_repeated_int32_type:
            {
                current_obj_addr -= 24;
                vector<int32_t>* ptr_to_int32_vector = reinterpret_cast<vector<int32_t>*>(current_obj_addr);
                uint32_t int32_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < int32_vector_size){
                    int32_t temp_int32 = ReadVarint32(&current_buffer_addr);
                    ptr_to_int32_vector->emplace_back(temp_int32);
                }
            }
                break;
            case sw_int64_type:
            {
                current_obj_addr -= 8;
                int64_t* ptr_to_int64 = reinterpret_cast<int64_t*>(current_obj_addr);
                *ptr_to_int64 = ReadVarint64(&current_buffer_addr);;
            }
                break;
            case sw_repeated_int64_type:
            {
                current_obj_addr -= 24;
                vector<int64_t>* ptr_to_int64_vector = reinterpret_cast<vector<int64_t>*>(current_obj_addr);
                uint32_t int64_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < int64_vector_size){
                    int64_t temp_int64 = ReadVarint64(&current_buffer_addr);
                    ptr_to_int64_vector->emplace_back(temp_int64);
                }
            }
                break;
            case sw_uint64_type:
            {
                current_obj_addr -= 8;
                uint64_t* ptr_to_uint64 = reinterpret_cast<uint64_t*>(current_obj_addr);
                *ptr_to_uint64 = ReadVarint64(&current_buffer_addr);
            }
                break;
            case sw_repeated_uint64_type:
            {
                current_obj_addr -= 24;
                vector<uint64_t>* ptr_to_uint64_vector = reinterpret_cast<vector<uint64_t>*>(current_obj_addr);
                uint32_t uint64_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < uint64_vector_size){
                    uint64_t temp_uint64 = ReadVarint64(&current_buffer_addr);
                    ptr_to_uint64_vector->emplace_back(temp_uint64);
                }
            }
                break;
            case sw_uint32_type:
            {
                current_obj_addr -= 8;
                uint32_t* ptr_to_uint32 = reinterpret_cast<uint32_t*>(current_obj_addr);
                *ptr_to_uint32 = ReadVarint32(&current_buffer_addr);
            }
                break;
            case sw_repeated_uint32_type:
            {
                current_obj_addr -= 24;
                vector<uint32_t>* ptr_to_uint32_vector = reinterpret_cast<vector<uint32_t>*>(current_obj_addr);
                uint32_t uint32_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < uint32_vector_size){
                    uint32_t temp_uint32 = ReadVarint32(&current_buffer_addr);
                    ptr_to_uint32_vector->emplace_back(temp_uint32);
                }
            }
                break;
            case sw_bool_type:
            {
                current_obj_addr -= 8;
                bool* ptr_to_bool = reinterpret_cast<bool*>(current_obj_addr);
                *ptr_to_bool = ReadVarint32(&current_buffer_addr);
            }
                break;
            case sw_repeated_bool_type:
            {
                current_obj_addr -= 24;
                vector<uint8_t>* ptr_to_bool_vector = reinterpret_cast<vector<uint8_t>*>(current_obj_addr);
                uint32_t bool_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < bool_vector_size){
                    uint8_t temp_bool = ReadVarint32(&current_buffer_addr);
                    ptr_to_bool_vector->emplace_back(temp_bool);
                }
            }
                break;
            case sw_sint32_type:
            {
                current_obj_addr -= 8;
                int32_t* ptr_to_sint32 = reinterpret_cast<int32_t*>(current_obj_addr);
                *ptr_to_sint32 = ReadVarint32(&current_buffer_addr);
            }
                break;
            case sw_double_type:
            {
                current_obj_addr -= 8;
                double* ptr_to_double = reinterpret_cast<double*>(current_obj_addr);
                *ptr_to_double = ReadDouble(&current_buffer_addr);
            }
                break;
            case sw_float_type:
            {
                current_obj_addr -= 8;
                float* ptr_to_float = reinterpret_cast<float*>(current_obj_addr);
                *ptr_to_float = ReadFloat(&current_buffer_addr);
            }
                break;
            case sw_repeated_float_type:
            {
                current_obj_addr -= 24;
                vector<float>* ptr_to_float_vector = reinterpret_cast<vector<float>*>(current_obj_addr);
                uint32_t float_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < float_vector_size){
                    float temp_float = ReadFloat(&current_buffer_addr);
                    ptr_to_float_vector->emplace_back(temp_float);
                }
            }
                break;
            case sw_fix32_type:
            {
                current_obj_addr -= 8;
                int32_t* ptr_to_fix32 = reinterpret_cast<int32_t*>(current_obj_addr);
                *ptr_to_fix32 = ReadFixed32(&current_buffer_addr);
            }
                break;
            case sw_fix64_type:
            {
                current_obj_addr -= 8;
                int64_t* ptr_to_fix64 = reinterpret_cast<int64_t*>(current_obj_addr);
                *ptr_to_fix64 = ReadFixed64(&current_buffer_addr);
            }
                break;
            case sw_repeated_fix64_type:
            {
                current_obj_addr -= 24;
                vector<uint64_t>* ptr_to_fix64_vector = reinterpret_cast<vector<uint64_t>*>(current_obj_addr);
                uint32_t fix64_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < fix64_vector_size){
                    uint64_t temp_fix64 = ReadFixed64(&current_buffer_addr);
                    ptr_to_fix64_vector->emplace_back(temp_fix64);
                }
            }
                break;
            case sw_enum_type:
            {
                current_obj_addr -= 8;
                int32_t* ptr_to_enum = reinterpret_cast<int32_t*>(current_obj_addr);
                *ptr_to_enum = ReadVarint32(&current_buffer_addr);
            }
                break;
            case sw_repeated_enum_type:
            {
                current_obj_addr -= 24;
                vector<int32_t>* ptr_to_enum_vector = reinterpret_cast<vector<int32_t>*>(current_obj_addr);
                uint32_t enum_vector_size = ReadVarint32(&current_buffer_addr);
                const char* before_parse_current_buffer_addr = current_buffer_addr;
                while(current_buffer_addr - before_parse_current_buffer_addr < enum_vector_size){
                    int32_t temp_enum = ReadVarint32(&current_buffer_addr);
                    ptr_to_enum_vector->emplace_back(temp_enum);
                }
            }
                break;
            case sw_string_type:
            {
                current_obj_addr -= 32;
                if(!skip_flag){
                    int string_length = ReadVarint32(&current_buffer_addr);
                    std::string* ptr_to_string = reinterpret_cast<std::string*>(current_obj_addr);
                    current_buffer_addr = ReadString(current_buffer_addr, string_length, ptr_to_string);                    
                }
            }
                break;
            case sw_repeated_string_type:
            {
                current_obj_addr -= 24;
                if(!skip_flag){
                    vector<std::string>* ptr_to_string_vector = reinterpret_cast<vector<std::string>*>(current_obj_addr);
                    uint32_t string_vector_size = ReadVarint32(&current_buffer_addr);
                    const char* before_parse_current_buffer_addr = current_buffer_addr;
                    while(current_buffer_addr - before_parse_current_buffer_addr < string_vector_size){
                        int string_length = ReadVarint32(&current_buffer_addr);
                        std::string temp_string;
                        current_buffer_addr = ReadString(current_buffer_addr, string_length, &temp_string);
                        ptr_to_string_vector->emplace_back(temp_string);
                    }
                }
            }
                break;
            case sw_bytes_type:
            {
                current_obj_addr -= 32;
                if(!skip_flag){
                    int bytes_length = ReadVarint32(&current_buffer_addr);
                    std::string* ptr_to_bytes = reinterpret_cast<std::string*>(current_obj_addr);
                    current_buffer_addr = ReadString(current_buffer_addr, bytes_length, ptr_to_bytes);
                }
            }
                break;
            case sw_repeated_bytes_type:
            {
                current_obj_addr -= 24;
                if(!skip_flag){
                    vector<std::string>* ptr_to_bytes_vector = reinterpret_cast<vector<std::string>*>(current_obj_addr);
                    uint32_t bytes_vector_size = ReadVarint32(&current_buffer_addr);
                    const char* before_parse_current_buffer_addr = current_buffer_addr;
                    while(current_buffer_addr - before_parse_current_buffer_addr < bytes_vector_size){
                        int bytes_length = ReadVarint32(&current_buffer_addr);
                        std::string temp_bytes;
                        current_buffer_addr = ReadString(current_buffer_addr, bytes_length, &temp_bytes);
                        ptr_to_bytes_vector->emplace_back(temp_bytes);
                    }
                }
            }
                break;
            case sw_ptr_type:
            {
                current_obj_addr -= 8;
                void** ptr_to_ptr = reinterpret_cast<void**>(current_obj_addr);
                uint32_t current_field_id = metadataVec[current_metadata_idx].field_id[i];
                uint32_t next_metadata_idx = FPGA_metadataVec[current_metadata_idx].field[current_field_id].sub_class_id; 
                void* next_obj_addr = createMessage(next_metadata_idx);
                void* next_obj_addr_base = next_obj_addr;
                //将子对象指针写入父对象中
                *ptr_to_ptr = next_obj_addr;
                next_obj_addr += 8;  //skip the pointer to virtual function table	
                //将metadata指针写入对象中
                Metadata** ptr_to_metadata_ptr = reinterpret_cast<Metadata**>(next_obj_addr);
                *ptr_to_metadata_ptr = &metadataVec[next_metadata_idx];
                next_obj_addr = ptr_to_metadata_ptr + 1;
                current_buffer_addr = ParseFromString_DFS(current_buffer_addr, next_metadata_idx, next_obj_addr_base, metadataVec, messageSizeVec, FPGA_metadataVec);
            }
                break;
            default:
                std::cout << "Error: wire_type = " << wire_type << std::endl;
                break;
        }
    }    
    return current_buffer_addr;
}

void ParseFromString(string& data, M_base* message, uint16_t current_metadata_idx, Metadata* metadataVec, size_t *messageSizeVec, FPGA_Metadata *FPGA_metadataVec){
    const char* current_buffer_addr = reinterpret_cast<const char*>(&data[0]);
    uint32_t tag, wire_type;
    uint16_t field_length;
    void* current_obj_addr = nullptr;
    void* message_addr_base = message;
    current_obj_addr = message;
    current_obj_addr += 8;  //skip the pointer to virtual function table	
    //将metadata指针写入对象中
    Metadata** ptr_to_metadata_ptr = reinterpret_cast<Metadata**>(current_obj_addr);
    *ptr_to_metadata_ptr = &metadataVec[current_metadata_idx];
    current_obj_addr = ptr_to_metadata_ptr + 1;

    ParseFromString_DFS(current_buffer_addr, current_metadata_idx, message_addr_base, metadataVec, messageSizeVec, FPGA_metadataVec);
}

uint8_t* SendMetadataToFPGA(M_base* message, size_t* p_c2h, size_t* messageSizeVec, FPGA_Metadata* FPGA_metadataVec, size_t& p_c2h_buffer_size, size_t& min_class_id, size_t& max_class_id){
    uint8_t* uint8_p_c2h = reinterpret_cast<uint8_t*>(p_c2h);
    void* obj_addr = message;
    void* obj_addr_base = obj_addr;   
    obj_addr += 8;  //skip the pointer to virtual function table
    Metadata** ptr_to_metadata_ptr = reinterpret_cast<Metadata**>(obj_addr);     
    Metadata &current_metadata = **ptr_to_metadata_ptr;
    obj_addr = ptr_to_metadata_ptr + 1;

    uint16_t current_class_id = current_metadata.class_id;
    if(current_class_id > max_class_id){
        max_class_id = current_class_id;
    }
    if(current_class_id < min_class_id){
        min_class_id = current_class_id;
    }
    uint16_t current_max_field_number = 0;
    uint32_t current_class_length = 0;
    FPGA_metadataVec[current_class_id].class_id = current_class_id;
    size_t message_size = messageSizeVec[current_class_id];
    //jump to the end of the object
    obj_addr = obj_addr_base + message_size;
    //write a loop to serialize all the fields of the object
    for(int i = current_metadata.field_num - 1; i >= 0; --i){
        uint16_t current_field_id = current_metadata.field_id[i];
        if(current_field_id > current_max_field_number){
            current_max_field_number = current_field_id;
        }
        switch(current_metadata.wire_type[i]){
            case sw_int32_type:
                {
                    obj_addr -= 8;
                    int32_t* ptr_to_int32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_int32;
                    current_class_length += 4;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_INT32 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_int32_type:
                {
                    obj_addr -= 24;
                    vector<int32_t>* ptr_to_int32_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
                    vector<int32_t>& current_field = *ptr_to_int32_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_INT32 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;                
            case sw_int64_type:
                {
                    obj_addr -= 8;
                    int64_t* ptr_to_int64 = reinterpret_cast<int64_t*>(obj_addr);
                    int64_t& current_field = *ptr_to_int64;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_INT64 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_int64_type:
                {
                    obj_addr -= 24;
                    vector<int64_t>* ptr_to_int64_vector = reinterpret_cast<vector<int64_t>*>(obj_addr);
                    vector<int64_t>& current_field = *ptr_to_int64_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_INT64 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_uint64_type:
                {
                    obj_addr -= 8;
                    uint64_t* ptr_to_uint64 = reinterpret_cast<uint64_t*>(obj_addr);
                    uint64_t& current_field = *ptr_to_uint64;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_UINT64 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_uint64_type:
                {
                    obj_addr -= 24;
                    vector<uint64_t>* ptr_to_uint64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
                    vector<uint64_t>& current_field = *ptr_to_uint64_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_UINT64 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_uint32_type:
                {
                    obj_addr -= 8;
                    uint32_t* ptr_to_uint32 = reinterpret_cast<uint32_t*>(obj_addr);
                    uint32_t& current_field = *ptr_to_uint32;
                    current_class_length += 4;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_UINT32 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_uint32_type:
                {
                    obj_addr -= 24;
                    vector<uint32_t>* ptr_to_uint32_vector = reinterpret_cast<vector<uint32_t>*>(obj_addr);
                    vector<uint32_t>& current_field = *ptr_to_uint32_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_UINT32 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_bool_type:
                {
                    obj_addr -= 8;
                    bool* ptr_to_bool = reinterpret_cast<bool*>(obj_addr);
                    bool& current_field = *ptr_to_bool;
                    current_class_length += 4;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_BOOL << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_bool_type:
                {
                    obj_addr -= 24;
                    vector<uint8_t>* ptr_to_bool_vector = reinterpret_cast<vector<uint8_t>*>(obj_addr);
                    vector<uint8_t>& current_field = *ptr_to_bool_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_BOOL << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_sint32_type:
                {
                    obj_addr -= 8;
                    int32_t* ptr_to_sint32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_sint32;
                    current_class_length += 4;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_SINT32 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_double_type:
                {
                    obj_addr -= 8;
                    double* ptr_to_double = reinterpret_cast<double*>(obj_addr);
                    double& current_field = *ptr_to_double;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_DOUBLE << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_float_type:
                {
                    obj_addr -= 8;
                    float* ptr_to_float = reinterpret_cast<float*>(obj_addr);
                    float& current_field = *ptr_to_float;
                    current_class_length += 4;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_FLOAT << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_float_type:
                {
                    obj_addr -= 24;
                    vector<float>* ptr_to_float_vector = reinterpret_cast<vector<float>*>(obj_addr);
                    vector<float>& current_field = *ptr_to_float_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_FLOAT << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_fix32_type:
                {
                    obj_addr -= 8;
                    int32_t* ptr_to_fix32 = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_fix32;
                    current_class_length += 4;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_SFIXED32 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_fix64_type:
                {
                    obj_addr -= 8;
                    uint64_t* ptr_to_fix64 = reinterpret_cast<uint64_t*>(obj_addr);
                    uint64_t& current_field = *ptr_to_fix64;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_SFIXED64 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_fix64_type:
                {
                    obj_addr -= 24;
                    vector<uint64_t>* ptr_to_fix64_vector = reinterpret_cast<vector<uint64_t>*>(obj_addr);
                    vector<uint64_t>& current_field = *ptr_to_fix64_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_SFIXED64 << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_enum_type:
                {
                    obj_addr -= 8;
                    int32_t* ptr_to_enum = reinterpret_cast<int32_t*>(obj_addr);
                    int32_t& current_field = *ptr_to_enum;
                    current_class_length += 4;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_ENUM << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_enum_type:
                {
                    obj_addr -= 24;
                    vector<int32_t>* ptr_to_enum_vector = reinterpret_cast<vector<int32_t>*>(obj_addr);
                    vector<int32_t>& current_field = *ptr_to_enum_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_ENUM << 2);
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_string_type:
                {
                    obj_addr -= 32;
                    std::string* ptr_to_string = reinterpret_cast<std::string*>(obj_addr);
                    std::string& current_field = *ptr_to_string;
                    current_class_length += 8;
                    size_t s_size = current_field.size();
                    // 将s_size向上对齐到64字节边界
                    size_t alignment = 64; // 指定的对齐边界
                    size_t aligned_size = ((s_size + alignment - 1) / alignment) * alignment;
                    if(current_field.size() > 1024){
                        FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 0 | (FPGA_TYPE_STRING << 2);
                        memcpy(uint8_p_c2h, &aligned_size, sizeof(size_t));
                        uint8_p_c2h += sizeof(size_t);
                        memset(uint8_p_c2h, 0, 7 * sizeof(size_t));
                        uint8_p_c2h += 7 * sizeof(size_t);
                        memcpy(uint8_p_c2h, current_field.data(), s_size);
                        uint8_p_c2h += s_size;
                        memset(uint8_p_c2h, 0, aligned_size - s_size);
                        uint8_p_c2h += (aligned_size - s_size);
                        p_c2h_buffer_size += (64 + aligned_size);
                    }
                    else{
                        FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_STRING << 2);
                    }
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_repeated_string_type:
                {
                    obj_addr -= 24;
                    vector<std::string>* ptr_to_string_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
                    vector<std::string>& current_field = *ptr_to_string_vector;
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_STRING << 2);
                    bool skip_flag = false;
                    size_t repeated_num = current_field.size();
                    for(int j = 0; j < repeated_num; ++j){
                        if(current_field[j].size() > 1024){
                            FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 2 | (FPGA_TYPE_STRING << 2);
                            skip_flag = true;
                            break;
                        }                         
                    }
                    if(skip_flag){
                        for(int j = repeated_num - 1; j >= 0; --j){
                            size_t s_size = current_field[j].size();
                            if(j == (repeated_num - 1)){
                                memcpy(uint8_p_c2h, &repeated_num, sizeof(size_t));
                                uint8_p_c2h += sizeof(size_t);   
                                memset(uint8_p_c2h, 0, 7 * sizeof(size_t));
                                uint8_p_c2h += 7 * sizeof(size_t);  
                                p_c2h_buffer_size += 64;                                                           
                            }
                            // 将s_size向上对齐到64字节边界
                            size_t alignment = 64; // 指定的对齐边界
                            size_t aligned_size = ((s_size + alignment - 1) / alignment) * alignment;
                            p_c2h_buffer_size += (64 + aligned_size);
                            memcpy(uint8_p_c2h, &aligned_size, sizeof(size_t));
                            uint8_p_c2h += sizeof(size_t);
                            memset(uint8_p_c2h, 0, 7 * sizeof(size_t));
                            uint8_p_c2h += 7 * sizeof(size_t);
                            memcpy(uint8_p_c2h, current_field[j].data(), s_size);
                            uint8_p_c2h += s_size;
                            memset(uint8_p_c2h, 0, aligned_size - s_size);
                            uint8_p_c2h += (aligned_size - s_size);
                        }
                    }
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_bytes_type:
                {
                    obj_addr -= 32;
                    std::string* ptr_to_bytes = reinterpret_cast<std::string*>(obj_addr);
                    std::string& current_field = *ptr_to_bytes;
                    current_class_length += 8;
                    size_t s_size = current_field.size();
                    // 将s_size向上对齐到64字节边界
                    size_t alignment = 64; // 指定的对齐边界
                    size_t aligned_size = ((s_size + alignment - 1) / alignment) * alignment;
                    if(current_field.size() > 1024){
                        FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 0 | (FPGA_TYPE_BYTES << 2);
                        memcpy(uint8_p_c2h, &aligned_size, sizeof(size_t));
                        uint8_p_c2h += sizeof(size_t);
                        memset(uint8_p_c2h, 0, 7 * sizeof(size_t));
                        uint8_p_c2h += 7 * sizeof(size_t);
                        memcpy(uint8_p_c2h, current_field.data(), s_size);
                        uint8_p_c2h += s_size;
                        memset(uint8_p_c2h, 0, aligned_size - s_size);
                        uint8_p_c2h += (aligned_size - s_size);
                        p_c2h_buffer_size += (64 + aligned_size);
                    }
                    else{
                        FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_BYTES << 2);
                    }
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;                       
                }
                break;
            case sw_repeated_bytes_type: 
                {
                    obj_addr -= 24;
                    vector<std::string>* ptr_to_bytes_vector = reinterpret_cast<vector<std::string>*>(obj_addr);
                    vector<std::string>& current_field = *ptr_to_bytes_vector;
                    current_class_length += 8;
                    bool skip_flag = false;
                    size_t repeated_num = current_field.size();
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 3 | (FPGA_TYPE_BYTES << 2);
                    for(int j = 0; j < repeated_num; ++j){
                        if(current_field[j].size() > 1024){
                            FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 2 | (FPGA_TYPE_BYTES << 2);
                            skip_flag = true;
                            break;
                        }                         
                    }
                    if(skip_flag){
                        for(int j = repeated_num - 1; j >= 0; --j){
                            size_t s_size = current_field[j].size();
                            if(j == (repeated_num - 1)){
                                memcpy(uint8_p_c2h, &repeated_num, sizeof(size_t));
                                uint8_p_c2h += sizeof(size_t);   
                                memset(uint8_p_c2h, 0, 7 * sizeof(size_t));
                                uint8_p_c2h += 7 * sizeof(size_t);  
                                p_c2h_buffer_size += 64;                                                           
                            }                            
                            // 将s_size向上对齐到64字节边界
                            size_t alignment = 64; // 指定的对齐边界
                            size_t aligned_size = ((s_size + alignment - 1) / alignment) * alignment;
                            p_c2h_buffer_size += (64 + aligned_size);
                            memcpy(uint8_p_c2h, &aligned_size, sizeof(size_t));
                            uint8_p_c2h += sizeof(size_t);
                            memset(uint8_p_c2h, 0, 7 * sizeof(size_t));
                            uint8_p_c2h += 7 * sizeof(size_t);

                            memcpy(uint8_p_c2h, current_field[j].data(), s_size);
                            uint8_p_c2h += s_size;
                            memset(uint8_p_c2h, 0, aligned_size - s_size);
                            uint8_p_c2h += (aligned_size - s_size);
                        }
                    }
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = 0;
                }
                break;
            case sw_ptr_type:
                {
                    obj_addr -= 8;
                    void** ptr_to_ptr = reinterpret_cast<void**>(obj_addr);
                    void*& current_field = *ptr_to_ptr;   
                    current_class_length += 8;
                    FPGA_metadataVec[current_class_id].field[current_field_id].field_type = 1 | (FPGA_TYPE_MESSAGE << 2);
                    void* new_obj_addr = current_field;
                    new_obj_addr += 8;  //skip the pointer to virtual function table
                    Metadata** new_ptr_to_metadata_ptr = reinterpret_cast<Metadata**>(new_obj_addr);     
                    Metadata &new_obj_metadata = **new_ptr_to_metadata_ptr;
                    FPGA_metadataVec[current_class_id].field[current_field_id].reserve = 0;
                    FPGA_metadataVec[current_class_id].field[current_field_id].sub_class_id = new_obj_metadata.class_id;
                    uint8_p_c2h = SendMetadataToFPGA(reinterpret_cast<M_base*>(current_field), reinterpret_cast<size_t*>(uint8_p_c2h), messageSizeVec, FPGA_metadataVec, p_c2h_buffer_size, min_class_id, max_class_id);
                }
                break;
            default:
                break;
        }        
    }    
    FPGA_metadataVec[current_class_id].max_field_number = current_max_field_number;
    FPGA_metadataVec[current_class_id].class_length = current_class_length;
    return uint8_p_c2h;
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
#ifdef SIMPLETEST
#include "bench_header/e2e_target.inc"
#endif