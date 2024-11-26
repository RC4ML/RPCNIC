void RegisterTestClass(Metadata* metadataVec) {
    metadataVec[2].class_id = 2;
    metadataVec[2].field_num = 3;
    metadataVec[2].wire_type[0] = sw_string_type;
    metadataVec[2].field_id[0] = 2;
    metadataVec[2].wire_type[1] = sw_string_type;
    metadataVec[2].field_id[1] = 3;
    metadataVec[2].wire_type[2] = sw_string_type;
    metadataVec[2].field_id[2] = 6;

    metadataVec[1].class_id = 1;
    metadataVec[1].field_num = 11;
    metadataVec[1].wire_type[0] = sw_bytes_type;
    metadataVec[1].field_id[0] = 3;
    metadataVec[1].wire_type[1] = sw_ptr_type;
    metadataVec[1].field_id[1] = 4;
    metadataVec[1].wire_type[2] = sw_bytes_type;
    metadataVec[1].field_id[2] = 5;
    metadataVec[1].wire_type[3] = sw_float_type;
    metadataVec[1].field_id[3] = 8;
    metadataVec[1].wire_type[4] = sw_float_type;
    metadataVec[1].field_id[4] = 9;
    metadataVec[1].wire_type[5] = sw_uint32_type;
    metadataVec[1].field_id[5] = 10;
    metadataVec[1].wire_type[6] = sw_int64_type;
    metadataVec[1].field_id[6] = 13;
    metadataVec[1].wire_type[7] = sw_int32_type;
    metadataVec[1].field_id[7] = 14;
    metadataVec[1].wire_type[8] = sw_int64_type;
    metadataVec[1].field_id[8] = 15;
    metadataVec[1].wire_type[9] = sw_bool_type;
    metadataVec[1].field_id[9] = 16;
    metadataVec[1].wire_type[10] = sw_int64_type;
    metadataVec[1].field_id[10] = 17;

    metadataVec[4].class_id = 4;
    metadataVec[4].field_num = 2;
    metadataVec[4].wire_type[0] = sw_float_type;
    metadataVec[4].field_id[0] = 1;
    metadataVec[4].wire_type[1] = sw_int32_type;
    metadataVec[4].field_id[1] = 2;

    metadataVec[3].class_id = 3;
    metadataVec[3].field_num = 11;
    metadataVec[3].wire_type[0] = sw_uint32_type;
    metadataVec[3].field_id[0] = 1;
    metadataVec[3].wire_type[1] = sw_int32_type;
    metadataVec[3].field_id[1] = 2;
    metadataVec[3].wire_type[2] = sw_string_type;
    metadataVec[3].field_id[2] = 3;
    metadataVec[3].wire_type[3] = sw_float_type;
    metadataVec[3].field_id[3] = 4;
    metadataVec[3].wire_type[4] = sw_float_type;
    metadataVec[3].field_id[4] = 5;
    metadataVec[3].wire_type[5] = sw_string_type;
    metadataVec[3].field_id[5] = 6;
    metadataVec[3].wire_type[6] = sw_string_type;
    metadataVec[3].field_id[6] = 7;
    metadataVec[3].wire_type[7] = sw_enum_type;
    metadataVec[3].field_id[7] = 11;
    metadataVec[3].wire_type[8] = sw_ptr_type;
    metadataVec[3].field_id[8] = 12;
    metadataVec[3].wire_type[9] = sw_float_type;
    metadataVec[3].field_id[9] = 14;
    metadataVec[3].wire_type[10] = sw_string_type;
    metadataVec[3].field_id[10] = 20;

    metadataVec[6].class_id = 6;
    metadataVec[6].field_num = 1;
    metadataVec[6].wire_type[0] = sw_int32_type;
    metadataVec[6].field_id[0] = 1;

    metadataVec[8].class_id = 8;
    metadataVec[8].field_num = 1;
    metadataVec[8].wire_type[0] = sw_bool_type;
    metadataVec[8].field_id[0] = 1;

    metadataVec[7].class_id = 7;
    metadataVec[7].field_num = 2;
    metadataVec[7].wire_type[0] = sw_ptr_type;
    metadataVec[7].field_id[0] = 1;
    metadataVec[7].wire_type[1] = sw_bytes_type;
    metadataVec[7].field_id[1] = 2;

    metadataVec[5].class_id = 5;
    metadataVec[5].field_num = 14;
    metadataVec[5].wire_type[0] = sw_int64_type;
    metadataVec[5].field_id[0] = 1;
    metadataVec[5].wire_type[1] = sw_int32_type;
    metadataVec[5].field_id[1] = 5;
    metadataVec[5].wire_type[2] = sw_float_type;
    metadataVec[5].field_id[2] = 6;
    metadataVec[5].wire_type[3] = sw_int32_type;
    metadataVec[5].field_id[3] = 7;
    metadataVec[5].wire_type[4] = sw_bool_type;
    metadataVec[5].field_id[4] = 8;
    metadataVec[5].wire_type[5] = sw_fix64_type;
    metadataVec[5].field_id[5] = 11;
    metadataVec[5].wire_type[6] = sw_int32_type;
    metadataVec[5].field_id[6] = 13;
    metadataVec[5].wire_type[7] = sw_int64_type;
    metadataVec[5].field_id[7] = 14;
    metadataVec[5].wire_type[8] = sw_int64_type;
    metadataVec[5].field_id[8] = 15;
    metadataVec[5].wire_type[9] = sw_float_type;
    metadataVec[5].field_id[9] = 17;
    metadataVec[5].wire_type[10] = sw_bool_type;
    metadataVec[5].field_id[10] = 18;
    metadataVec[5].wire_type[11] = sw_ptr_type;
    metadataVec[5].field_id[11] = 19;
    metadataVec[5].wire_type[12] = sw_int32_type;
    metadataVec[5].field_id[12] = 20;
    metadataVec[5].wire_type[13] = sw_ptr_type;
    metadataVec[5].field_id[13] = 21;

    metadataVec[11].class_id = 11;
    metadataVec[11].field_num = 7;
    metadataVec[11].wire_type[0] = sw_fix32_type;
    metadataVec[11].field_id[0] = 1;
    metadataVec[11].wire_type[1] = sw_float_type;
    metadataVec[11].field_id[1] = 2;
    metadataVec[11].wire_type[2] = sw_float_type;
    metadataVec[11].field_id[2] = 3;
    metadataVec[11].wire_type[3] = sw_int32_type;
    metadataVec[11].field_id[3] = 4;
    metadataVec[11].wire_type[4] = sw_int32_type;
    metadataVec[11].field_id[4] = 6;
    metadataVec[11].wire_type[5] = sw_float_type;
    metadataVec[11].field_id[5] = 7;
    metadataVec[11].wire_type[6] = sw_bool_type;
    metadataVec[11].field_id[6] = 9;

    metadataVec[10].class_id = 10;
    metadataVec[10].field_num = 2;
    metadataVec[10].wire_type[0] = sw_ptr_type;
    metadataVec[10].field_id[0] = 5;
    metadataVec[10].wire_type[1] = sw_uint64_type;
    metadataVec[10].field_id[1] = 6;

    metadataVec[12].class_id = 12;
    metadataVec[12].field_num = 7;
    metadataVec[12].wire_type[0] = sw_repeated_int32_type;
    metadataVec[12].field_id[0] = 2;
    metadataVec[12].wire_type[1] = sw_repeated_int32_type;
    metadataVec[12].field_id[1] = 7;
    metadataVec[12].wire_type[2] = sw_string_type;
    metadataVec[12].field_id[2] = 8;
    metadataVec[12].wire_type[3] = sw_int32_type;
    metadataVec[12].field_id[3] = 9;
    metadataVec[12].wire_type[4] = sw_float_type;
    metadataVec[12].field_id[4] = 14;
    metadataVec[12].wire_type[5] = sw_int32_type;
    metadataVec[12].field_id[5] = 15;
    metadataVec[12].wire_type[6] = sw_bool_type;
    metadataVec[12].field_id[6] = 16;

    metadataVec[9].class_id = 9;
    metadataVec[9].field_num = 14;
    metadataVec[9].wire_type[0] = sw_repeated_uint32_type;
    metadataVec[9].field_id[0] = 1;
    metadataVec[9].wire_type[1] = sw_ptr_type;
    metadataVec[9].field_id[1] = 2;
    metadataVec[9].wire_type[2] = sw_bytes_type;
    metadataVec[9].field_id[2] = 3;
    metadataVec[9].wire_type[3] = sw_float_type;
    metadataVec[9].field_id[3] = 5;
    metadataVec[9].wire_type[4] = sw_ptr_type;
    metadataVec[9].field_id[4] = 6;
    metadataVec[9].wire_type[5] = sw_int32_type;
    metadataVec[9].field_id[5] = 7;
    metadataVec[9].wire_type[6] = sw_bytes_type;
    metadataVec[9].field_id[6] = 8;
    metadataVec[9].wire_type[7] = sw_int32_type;
    metadataVec[9].field_id[7] = 9;
    metadataVec[9].wire_type[8] = sw_float_type;
    metadataVec[9].field_id[8] = 11;
    metadataVec[9].wire_type[9] = sw_bool_type;
    metadataVec[9].field_id[9] = 12;
    metadataVec[9].wire_type[10] = sw_float_type;
    metadataVec[9].field_id[10] = 14;
    metadataVec[9].wire_type[11] = sw_int64_type;
    metadataVec[9].field_id[11] = 17;
    metadataVec[9].wire_type[12] = sw_float_type;
    metadataVec[9].field_id[12] = 19;
    metadataVec[9].wire_type[13] = sw_int64_type;
    metadataVec[9].field_id[13] = 20;

    metadataVec[14].class_id = 14;
    metadataVec[14].field_num = 1;
    metadataVec[14].wire_type[0] = sw_int32_type;
    metadataVec[14].field_id[0] = 1;

    metadataVec[13].class_id = 13;
    metadataVec[13].field_num = 9;
    metadataVec[13].wire_type[0] = sw_float_type;
    metadataVec[13].field_id[0] = 2;
    metadataVec[13].wire_type[1] = sw_ptr_type;
    metadataVec[13].field_id[1] = 4;
    metadataVec[13].wire_type[2] = sw_int32_type;
    metadataVec[13].field_id[2] = 6;
    metadataVec[13].wire_type[3] = sw_bytes_type;
    metadataVec[13].field_id[3] = 7;
    metadataVec[13].wire_type[4] = sw_bytes_type;
    metadataVec[13].field_id[4] = 9;
    metadataVec[13].wire_type[5] = sw_string_type;
    metadataVec[13].field_id[5] = 10;
    metadataVec[13].wire_type[6] = sw_bool_type;
    metadataVec[13].field_id[6] = 11;
    metadataVec[13].wire_type[7] = sw_fix64_type;
    metadataVec[13].field_id[7] = 12;
    metadataVec[13].wire_type[8] = sw_int32_type;
    metadataVec[13].field_id[8] = 14;

    metadataVec[16].class_id = 16;
    metadataVec[16].field_num = 1;
    metadataVec[16].wire_type[0] = sw_int32_type;
    metadataVec[16].field_id[0] = 1;

    metadataVec[15].class_id = 15;
    metadataVec[15].field_num = 5;
    metadataVec[15].wire_type[0] = sw_int32_type;
    metadataVec[15].field_id[0] = 1;
    metadataVec[15].wire_type[1] = sw_ptr_type;
    metadataVec[15].field_id[1] = 2;
    metadataVec[15].wire_type[2] = sw_int32_type;
    metadataVec[15].field_id[2] = 3;
    metadataVec[15].wire_type[3] = sw_int32_type;
    metadataVec[15].field_id[3] = 4;
    metadataVec[15].wire_type[4] = sw_uint32_type;
    metadataVec[15].field_id[4] = 8;

    metadataVec[18].class_id = 18;
    metadataVec[18].field_num = 5;
    metadataVec[18].wire_type[0] = sw_int32_type;
    metadataVec[18].field_id[0] = 2;
    metadataVec[18].wire_type[1] = sw_fix32_type;
    metadataVec[18].field_id[1] = 3;
    metadataVec[18].wire_type[2] = sw_int32_type;
    metadataVec[18].field_id[2] = 4;
    metadataVec[18].wire_type[3] = sw_int32_type;
    metadataVec[18].field_id[3] = 7;
    metadataVec[18].wire_type[4] = sw_enum_type;
    metadataVec[18].field_id[4] = 8;

    metadataVec[17].class_id = 17;
    metadataVec[17].field_num = 8;
    metadataVec[17].wire_type[0] = sw_uint64_type;
    metadataVec[17].field_id[0] = 1;
    metadataVec[17].wire_type[1] = sw_float_type;
    metadataVec[17].field_id[1] = 2;
    metadataVec[17].wire_type[2] = sw_enum_type;
    metadataVec[17].field_id[2] = 3;
    metadataVec[17].wire_type[3] = sw_repeated_string_type;
    metadataVec[17].field_id[3] = 4;
    metadataVec[17].wire_type[4] = sw_string_type;
    metadataVec[17].field_id[4] = 7;
    metadataVec[17].wire_type[5] = sw_bool_type;
    metadataVec[17].field_id[5] = 8;
    metadataVec[17].wire_type[6] = sw_bytes_type;
    metadataVec[17].field_id[6] = 16;
    metadataVec[17].wire_type[7] = sw_ptr_type;
    metadataVec[17].field_id[7] = 20;

    metadataVec[20].class_id = 20;
    metadataVec[20].field_num = 1;
    metadataVec[20].wire_type[0] = sw_string_type;
    metadataVec[20].field_id[0] = 1;

    metadataVec[22].class_id = 22;
    metadataVec[22].field_num = 8;
    metadataVec[22].wire_type[0] = sw_string_type;
    metadataVec[22].field_id[0] = 1;
    metadataVec[22].wire_type[1] = sw_int32_type;
    metadataVec[22].field_id[1] = 4;
    metadataVec[22].wire_type[2] = sw_fix64_type;
    metadataVec[22].field_id[2] = 5;
    metadataVec[22].wire_type[3] = sw_int32_type;
    metadataVec[22].field_id[3] = 6;
    metadataVec[22].wire_type[4] = sw_uint32_type;
    metadataVec[22].field_id[4] = 7;
    metadataVec[22].wire_type[5] = sw_bool_type;
    metadataVec[22].field_id[5] = 10;
    metadataVec[22].wire_type[6] = sw_string_type;
    metadataVec[22].field_id[6] = 11;
    metadataVec[22].wire_type[7] = sw_fix64_type;
    metadataVec[22].field_id[7] = 12;

    metadataVec[21].class_id = 21;
    metadataVec[21].field_num = 3;
    metadataVec[21].wire_type[0] = sw_ptr_type;
    metadataVec[21].field_id[0] = 4;
    metadataVec[21].wire_type[1] = sw_fix64_type;
    metadataVec[21].field_id[1] = 5;
    metadataVec[21].wire_type[2] = sw_string_type;
    metadataVec[21].field_id[2] = 9;

    metadataVec[19].class_id = 19;
    metadataVec[19].field_num = 14;
    metadataVec[19].wire_type[0] = sw_int32_type;
    metadataVec[19].field_id[0] = 5;
    metadataVec[19].wire_type[1] = sw_bool_type;
    metadataVec[19].field_id[1] = 6;
    metadataVec[19].wire_type[2] = sw_string_type;
    metadataVec[19].field_id[2] = 8;
    metadataVec[19].wire_type[3] = sw_bool_type;
    metadataVec[19].field_id[3] = 11;
    metadataVec[19].wire_type[4] = sw_int32_type;
    metadataVec[19].field_id[4] = 13;
    metadataVec[19].wire_type[5] = sw_ptr_type;
    metadataVec[19].field_id[5] = 15;
    metadataVec[19].wire_type[6] = sw_int32_type;
    metadataVec[19].field_id[6] = 16;
    metadataVec[19].wire_type[7] = sw_uint64_type;
    metadataVec[19].field_id[7] = 17;
    metadataVec[19].wire_type[8] = sw_fix64_type;
    metadataVec[19].field_id[8] = 20;
    metadataVec[19].wire_type[9] = sw_ptr_type;
    metadataVec[19].field_id[9] = 21;
    metadataVec[19].wire_type[10] = sw_float_type;
    metadataVec[19].field_id[10] = 22;
    metadataVec[19].wire_type[11] = sw_float_type;
    metadataVec[19].field_id[11] = 23;
    metadataVec[19].wire_type[12] = sw_string_type;
    metadataVec[19].field_id[12] = 24;
    metadataVec[19].wire_type[13] = sw_int32_type;
    metadataVec[19].field_id[13] = 26;

    metadataVec[24].class_id = 24;
    metadataVec[24].field_num = 5;
    metadataVec[24].wire_type[0] = sw_float_type;
    metadataVec[24].field_id[0] = 1;
    metadataVec[24].wire_type[1] = sw_uint64_type;
    metadataVec[24].field_id[1] = 2;
    metadataVec[24].wire_type[2] = sw_uint64_type;
    metadataVec[24].field_id[2] = 3;
    metadataVec[24].wire_type[3] = sw_int32_type;
    metadataVec[24].field_id[3] = 4;
    metadataVec[24].wire_type[4] = sw_float_type;
    metadataVec[24].field_id[4] = 5;

    metadataVec[23].class_id = 23;
    metadataVec[23].field_num = 10;
    metadataVec[23].wire_type[0] = sw_ptr_type;
    metadataVec[23].field_id[0] = 1;
    metadataVec[23].wire_type[1] = sw_double_type;
    metadataVec[23].field_id[1] = 2;
    metadataVec[23].wire_type[2] = sw_string_type;
    metadataVec[23].field_id[2] = 3;
    metadataVec[23].wire_type[3] = sw_bool_type;
    metadataVec[23].field_id[3] = 5;
    metadataVec[23].wire_type[4] = sw_int64_type;
    metadataVec[23].field_id[4] = 13;
    metadataVec[23].wire_type[5] = sw_string_type;
    metadataVec[23].field_id[5] = 14;
    metadataVec[23].wire_type[6] = sw_int32_type;
    metadataVec[23].field_id[6] = 18;
    metadataVec[23].wire_type[7] = sw_int32_type;
    metadataVec[23].field_id[7] = 22;
    metadataVec[23].wire_type[8] = sw_float_type;
    metadataVec[23].field_id[8] = 23;
    metadataVec[23].wire_type[9] = sw_int32_type;
    metadataVec[23].field_id[9] = 29;

    metadataVec[26].class_id = 26;
    metadataVec[26].field_num = 2;
    metadataVec[26].wire_type[0] = sw_int32_type;
    metadataVec[26].field_id[0] = 1;
    metadataVec[26].wire_type[1] = sw_float_type;
    metadataVec[26].field_id[1] = 2;

    metadataVec[25].class_id = 25;
    metadataVec[25].field_num = 12;
    metadataVec[25].wire_type[0] = sw_int32_type;
    metadataVec[25].field_id[0] = 1;
    metadataVec[25].wire_type[1] = sw_int32_type;
    metadataVec[25].field_id[1] = 2;
    metadataVec[25].wire_type[2] = sw_bytes_type;
    metadataVec[25].field_id[2] = 3;
    metadataVec[25].wire_type[3] = sw_int32_type;
    metadataVec[25].field_id[3] = 8;
    metadataVec[25].wire_type[4] = sw_int32_type;
    metadataVec[25].field_id[4] = 9;
    metadataVec[25].wire_type[5] = sw_int32_type;
    metadataVec[25].field_id[5] = 10;
    metadataVec[25].wire_type[6] = sw_string_type;
    metadataVec[25].field_id[6] = 11;
    metadataVec[25].wire_type[7] = sw_int32_type;
    metadataVec[25].field_id[7] = 14;
    metadataVec[25].wire_type[8] = sw_fix32_type;
    metadataVec[25].field_id[8] = 15;
    metadataVec[25].wire_type[9] = sw_double_type;
    metadataVec[25].field_id[9] = 16;
    metadataVec[25].wire_type[10] = sw_bool_type;
    metadataVec[25].field_id[10] = 17;
    metadataVec[25].wire_type[11] = sw_ptr_type;
    metadataVec[25].field_id[11] = 25;

}

// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

int M13_Create_F1(M13* message, M13* other_message, std::string* serialized) {
  return 0;
}



int M13_Destroy_F1(M13* message, M13* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M13_Get_F1(M13* message, M13* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}



int M13_Set_F1(M13* message, M13* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[13]);
  message->set_f5("sgfrGnWXayVMYFiGuOiuPJQARfaBAzmYcmBnpNfWkGSlRSBGywSjpdnMpkYjnNGPgxanrAvfsmwYHemkaHqnQNpneWboJkrRpzgCzzrvprcXNsVjfHeMkKOXbopZCfcDLArUhckMwrwfGcmqFkmkUXhWMXqHsUnDiKDWhFmufdJTVSXOkUJyLQlofTQPdWlLRKvmaTDQiZMwAEgEvbGBGPJBtBttpqkWAGMDNArLyrmSPNFLtnZgBEceyqrwoeSnqBMiXqAMTCpadbKDOBLjUYrXxspPkRddgukfwbhINtwyjwIotJHaVnzeacrzdFjLImDiApEgqZKxFMhuSrqIkLTbPghynSfHEREMgXbEtvfjbsUnXrGBZmOQnhabqgOkKAFkfGNlRBEJavaSrUNrYGNbMNoaYNScjWHZlWCrJcqkmpeQqtGanRGmuvLsaxkBaysxaiFhnMDYvtsJovWcQvhBrUYTyStwyVuCyHzfzWbGAxGBSUeHWeCUBDHicjpWDHoyhbRbsECINoWBUILwBxLNnqTHgYrSTztLSKFSPsXqmSQJAXPvsJXEDmyGlBQsoXeJyKXwnNTUmljdVXVtKbGfpkfEhUaCXADJQKuYEIfgWpzyGkuAFbgVaDRUEuzLaGuABnmXWxxjAxJuzuwtVWQtpqGAVwEDBhVZzdghVEJCHTHTyPVchBwCMYzlexGZiFxXTtDczeJGipcdwNWOIiJFjqPiSSBxeDKKKuWNVfTgWbRIaoZVgDkvvyEGDzdUZOWKMZpKvoukICnbKdnJjvymeJoxpZYSKXrpcROvpfYnfyYPmoCIQrehCeFgXzYnIoalWwIRIYLSYqfjfcpkHFdDmlkxUKLsTcJfvRLxKQHpHazUYPCsEcrnVpSLylghIkNdiLpoBwklZgQkEqkSuJaNNgPdqDQyeHymxySFTJAdysgGcNRAYdWPeatckLdGtbYEOhVbHjoUEwtlRjoPEMZISnqQLGziwSuCCnZppunMQZnfzbKWloZNGdEzKoYcqmmikpwFQvIwMrCSCBlJZMfXOpiwXzclOnmccoZhkWUFVRtZOAgrSDATOIqQrYXeTnEoTqATtgOCiwFGQGqGTGKfMuqIIYhmucbyCGUIsTzvEPyEfKDqEmndTFlCdRMajWELdlLXyBPtaNVRdwSnCwWIRxNRfAElsyMRVVHHiMzytMEymsVwqxRokHpyLrVqGkNtOnjXkcDZRajHnICVxJZDZUVLiugpJXjUTJabhQduCUPGeEzqMaQCBfKjYkJcbxDkcxaJaythzOhKpMFEImkDIjrQoekFWtpEeCEusdHUOimuYPETaKeaWvNCdAcWCqBqtCznJULDlociOMIZKtuxYPwrRMenIhPGrBsSteyIfWqnVkPEcNomXKWmTgReAsVgBURyQUiyBBGexCFdwZpeQybmsgZoluRQkPNJKGOKycOFyFkXMrQLXJBorLyAOLaeHDBVGjNqNZPEQbutGYIMJGVBctodiJodtYyLvjuZkNcnrzmSdSQBIZTefoEtQKDYuDshloHLjiRooJKYXlITcfAYOzzpRKecTRlGZksFXXVkLkaxMXRcGsXqPWXIzAGydbqlSlQfCYtWyNDsozTtNQoJbtYlYUzToznUOwZZviOjbmklnBTlOTLZngUcHkaLfPQOPfxWsMxsLzWbpiwdhqCOvjOuIKHnbGIwIPmAoyRSKYDVAnHFrgvmeAXLCRoHyaLwdSdpKvIAUGiyjLmACoRJoHTninRYKbGWtwyxNNzhXrZhmarSvpxPKKKcRgsublhUqekWfOTRxLuXQAZHeLyZORpnuqIrfoEFfnyBxTuhCrlLOUHempaXMjcBFxntTTAngraHQPkbcghHOfpkXhyxQMNWdlbaHsiMObspSdWbRGBJjqqhxsNkfmMxccJxRuACqgItKfMCuozDwAVWAeRXWgPttdOPBzHSdOibImHQdvmamatpczHbxENYxtxwdodoLOHnwvoPKvWhGVlvLQCMnhpoQubwiGrNwpBLkdpszsNGQcwyfJOcfVnhIJUinTRSuUHKBnuAGXaFmNnEmczkfxEcClvEkYHAtuFcLFmlTzkkMjKgEalwbowqsoYbHNTRPRcSDIqfsZpKaxDkgjpUvBROnkWQaowMlIeOShyYCsekslCPflTOUYHikUVqgyfVXpaKaAcAQaoKaEULiistozUBKNiyvWdsmLAPXYogwHmtPOhqtUXLWDBkRsYIDDdykSmNDCNSNjtbFIxRxJasItOmWYBdlweOfMejBcGjDUGxLHEPDKPsDlsblCHCVbEeNvKRxGjDDppbHYVduGxTpYElmKnYcrRzXxNPxVPINBaGuHyycFxcSWIBpuDMvpVXLPxLZJWBZfTyBnstHnZHmKjhWcowGuWCWeoPigZCxBxZuNeGUvuDGVyEcNQXwhxdtokaHWOvrnPzBaCqmzOWJxIpfVXhQTiAanXmFmijszkrjNefLsXEmPePQVyZNebapuddtMoDAJiqnNoJNucEMvKclJSripyserZvCbCmMMJfDdDukYcPyOtqjIirpxDvrYNQVWHdYyIZwiywlsAKNeftvXakqDiGzfroCXXRaaQGsWXVTVFhHxeEWASQfEcTcmMBAYYeTFiwRHsUVWEwJzSayNPrtKgGsfQcyVWceELMephyUnMRCGETMGnnUQPdSpqEoEbESFbmMdMwEcjBtoNtlEbcRmZuNYyPbKyazQTYqKCRkgFhQMDFNkEdPYaoZxKMeqwzKJJpypwywYKqQizzFKRjueMyaNPWpZPfsOCbqTNqKJSUrNhYyKLoYtLLEHyHjSULUniAUUAtYEqLtoqUglUuCpwikrmzfzLEhKPLjsgCvuXglFRqGJNqVujDCbQgJGdzKsMqkXcYZoMQHgnhNclegDlCdUAPatgbgZFhPHgebjHOyxySTFJQuaAmOqdXNRwkaupmltChbwjSEtIxgXQQAdnGblMrDydMpgFmAOtVkePVHTYmiFHbPoDYMYXMHOnQDtnnunpeCHqcTuTBTCJNkrgfCLvxBzTbswmxSuSzaqZztvtHtTUaLiuOxBypHybkKvNFoBoBLQxvsxHadcGhLGgIkkZUBUJuLmgcoQkYyAEuMHtSucdoEjazljwhJfSuWCbBvTbAhCOxXVSDTIDICubosWBLrnOEosgVCwDzkNYRinDDmfgBBmSEBcOBSTnTDgLgEGLyjgROQeCeaqIzvxUJdTWSryhaLzLMDWFDCsuVEWTaRRKZBTDPfuQcWeFlldFHGwifGFPDOnIvJbbpZalvSqXrkiHHnUhYBOZPkxboxpVkPFOstakapzuZZINMoWxpRIHFnErVgnDVdppTkUsUSJGgnyByJNqQxbcbQJjAOfKbyXdrmvzTKEmWNcbxUjWnvnDVYvqIQURwReKtDINyPfuEieChFdPfXDiDUiNvQcyNyiPnlIYmOAmQbgIpTQLhFiRJLERRMiNCcBTPLPGoceKLtrRwuuwugnpLvzFsuAobTJutigwadYRRKltlBPqObYuWJuISdLjrfyUJPjOAtLoSwmuoxawRqcRUGjRiQyzOKezfvnAZWSgGCjuYnMsemuVuFgkxGLEuCDFxogpVQhMzHDZILXrGOXmAnwrZSFaDcbbrCPHuhOmpczDpcqxulDdEmPtZufcaShKmsaGAKgqnVJXxHGtbKTtlVYPXPmELxZepzATwKAWrFUscvZgGsGJmkVjOTRfiFsbNirsQIwVXyVaZQeakCJTEvjWSdImBmYrXzhQrSAhShMTAteffAXXplRDSMZrsdpSggEdppvFsbSemliEFXHXNtkuFytihfqZhNEVTuVcEnZkTtRaVgxKyakMmNsXkFVAWlHvyJwMWcAmcrTsSOLWdGChWNCJEWnNEBXmgYkacwhOOTGqHfadqeIElZTVCQmtdGziCzAXMtgDwSGGMGlfSkbQbaMBUhtgJYlkpUMbubLdIhJXobWckednXgieJbOhjRMjKLCiLJySAUrVRdbyASmNUMTyGmkfydFlVIsaWnbBLeHeeEYZufmakHfhQREtXVQqkmfvCXDopMRcYDOhusdNRqVqEGBBheIhhSgincblmIAnmukkWGcorHiZPezzthXXIkkmdcxeVXnMAvHmfBprNVccpLvcegDgWwFNMIlFjFSRcMHGmKOMxxQKMrZqiVfTPcnpinOQjBEAUkiFinMLMyvPgasrasCYsnCrqxjGMQwkQTiNJtJgALaatWLpFxTAzxSyKqOjDRLuEdjUSYdYaxkmwsbNVgVKzOlnvJLRDCTGTmmCQUexhyYIWsoDFittFLDSnovxrmAYVKuZXAGjrujXUUHDNYsppGHXmxUFcslmaOWPIVBOQzgpQepDrljAkscGSWEoXwZUKhpdisnWDXKkSbaRfjbpiHvRhENjVWnDLKLhxwrlelSgEjXygYPPDNPBLGZJAYridVIuMsuBVCeWSOexZXmbeJZfCcutpxErCChzESFGswMHGnPpNTDMylIBZunvbgktLtcmyupHFgbBXgWOSBfistnVjTpBGAsOMPgNhRUwxHCABnHLDdOPcxJhfEtemgwNRXTMsAfEcTcCwiikwLiZYLoEbMwdOhdTjmQYpZxVlInKuBOQblBDfSBwZTXEPYcKWCAQEcqqnmReFCvBOQsNWBfJTnLOJyVzHhXEpFEWmgZMmBeUeYlUYwidJhYpCRaMRBQyuDFeELIEiTJjIWqgzpBhLMGSxmnrxqApqAWyrXmuvtvErTBoWcFOeIjVVGFbkXPHXBqQHrBiHZAUsGCgCMJyzRLbFgsvMNXLMGdDDXZtrzyUKoQosJMdqZZEJKSFLHRkdIwzuzAPqknRuLzvInLHkwOtGtVMDPVVgqzKDGLxZsEpauBBRBthklGKIZlgKcDafTjoEHfcEESuqOmwocAhAcgBVBdfhkIXCJaaILffNgFZoYmLfUpyJtHyXoebuhNdIMuYIsjlTpAAfGSnZSlayGlPtvrkLuEMcgokypcXjabVajUrrYdBfMElNzwqcqDWGAywwkWvCgwTjjdoUAZIVxrgYDcswelcKuOoaNxXlbmhVhhCJNzQEtflypTZoQtBNPDuVfNdXdLPsHImQdzsMTFUYJtysPBKdRLiKHoRHDukMZiHJqPrcVBAhACcDyiwZLNHouVtPFYyidfetnMivmIdcIpirfgzEvReFoVljTfSLGMhqkrdCKUsCvdybvEaiCAHGvFbCUuaowKNthtfGdnJHSGizuAYkPLJUznAotidtkMvGvSksQtNYlUQkSJQRDslBladuXMPsqmlkGbtJJBvwxysFAmMtynaJjvhxMqNiNTQklbFGcemSpeeDbObIbScSUAaLvQxKDAHxdoYkuOMnaBlpyoxTsvhrMhUEyUooEyNtSjCdgJwcfXMMrChIWpBCbnSpGTgymGDdkUXqBDycabVOaqlffTQqkHcnOWaRaHaODYOWGivHtygsvXfURazanAhOYLBXbhEWpJRZQBzofveoINSWUUCJOQWizfBJGcRmrNObMYAZRxUfWKrVaNISPKybxcFvaxBPsebKDLgIUEccVOtHynlvJlZkuiAumiUTCuHlDgVGUGYicGYVYNsvtdFSnYuQskKNwikTFGRXCIFpuwaBcBsAaFrvPlAUzqvtTnAoCSXxjenVZrMwatgdDlTuasbRERcxFlYeENUlBEuAewYJBKCQfPrjLLkKOFqjcUybuAEtmgDQrcpytzIMgABnnZOErYSgROoqlVabBSmyXKpAOmRRHYECOjuvUrNwaMytziaPnCOacstoWBBxzoLdTgRPDejDeRQaCekXCSxaTVFDxJkFthDcmHQrHZgXMNbNdFwpSKvYDZelIclaHCtOotOJbxpKDBQGAIYOaQESaEGOeMfxSebcaRYzzVEubgNOROjKeLUIKTBTKUDSfIpqSDghMfShOGDHfoENfIglHPJJlXGxCdbfGoTBhJxcAXHqDAKFLjnTEBcfmPSyBpYfBOIsEnqHaKrJVPqqOmZQHgIvhdMdlmRLncTIdycGfKHDDJrrZbMyilCXUhWLFOKWakeHpEHKouEAhXeELrAirdFnzwKvrvkEyFIxJhykltDtniJrWTlDLCqzYZPxqdcEpGIjJodmIFCGHiEVtXchMwXOXiPnFwEgXqKCfdyWiCYgJXeEQyDZfdajeNJVBVXCNROBFNBowIUlPlHbJQFLGqXNqwlHZeihTseQBiQClVXtitxMmLudVTOlETCMDsZYLpQAgVuPolzgvYbOTpQbDYHRRiyOTOxMjiLYmhlioXbvieyhaeQGHySoRZRlJTlknqDeLSFgXSbEdnvakfVKowAGrDhXbeIZMLdBuKCGvMSzAYVbcqFGaYJfTdfrNxUtpRUBaRmnjgmvRSDuyDJjAODfqYfyxEZaqGngnGibrTwjsiPfOgFdsSpCZxTcWqxceAnknpoQtXsExwSUdPUxIjTjEMyFAGTnBPmuzcupVxjZENPAMrLpmLrjYoMObaPqDtuCRHingBjbOdONYjSnAhyOHxCXjAwCVIiKmJZELZGprVYIwNMnHtbiHjaUoNuzTneiLNkwVFaowAXlfqmoicWYEzyTEsXeRnSRdEwzlxEYvuwomzpKaxLVKmiUyyYFPlYIMDDohUYLwMSkszfnNTYCMikBVSLlcmDvbevihPkKuEFYlTQnKRmBYKDLkxMjKZkWZAmdExesWhkkMnoYSvZxFcZcnDEuUBGMYFDQPlQHaRoTtEABWHesAxymEidRJOgrgpFzrEvMLufYimcNWmDDwLAmGKawRjuQygJAkyrfEXAyoVrfpiDKSAkAfaOMQzqUJYUKoVajhUMgUjdxojnVhZfyeAtLrDEYZsgsqpIJbtMZKlLthqOewxySLhKGqRNjcayVSirwLeydJDbOxoerIgOQVJeVbgbxFiHOMQYOUXGektAKGHdPTlpCuITvNmFBAjQiBvrPjqKVsZYleUrLfjShllTriwVJWSvnLOXldHZYGPpVwrktzUlgwRTHRMDWSEgwLGNGuTGZqqfalqqNOLuBUqNuUnBtvqLbEgBeCdROBrlKpVUnseTfkrUdcbhIChmRMPjwnnHEhbYxyalTgLAaQSYwWcVvVpiEvGjSxLSOTBufYzCCRHbuAerDfMZLbKCfRMLqVIQpgFDhkEdDrTherKNUArBmjNuuApfzPbAUUNQuVyqVreJfKOqVmiDmdafQhoLKgDVPppDFBlOYglVstqIedYPIBHFiYmhqtBltRksgkrdcbfPIJyVekrzzYbuZUflrYjZTZdESdmqahRsRNoNpQXIGlVFXKcnmUfVfafpYxzmfIwhhRwsXNrANQVvBprtvLmVSmJProVLQVFvviiQWPWXrhJZFnjAAbntYzZrwEVrPWCnuFgIktdLDOeUmvFDdYmbAdPiBrYoAdAMNdkrbqtnKGBipuBahXpKSebwAgjGqUGAfaSHbpCsMOTegsbGioultqHAJMCokPHXxIvCubHEpTxDkzEorjENjEGcUYldSteKyvDDCxjbLdfWAUgkSrCoLyEwUoTEtCdizAuBVFgPHiNEcwDxNhcCWVEhrHCPboPjssIZlelOSRAanSZBMIWVGfIXwDYgFabNFvLFlYBhHciDDULgTvtQmlVXtUmPMszBLgOLaeALFmSJPfXJUQcKPIEOGLsxkarAMkZCyLVBwcELTfxwrqCzoHuhwgETTCbLAvCKevcWbHjqLldsKFrEEEmHVVTBmoxSdEZwQKrQRegBaYKpMaZLykbnChGotiiteWAyZKSiFRTpeUqCIgJeJNlpJZxVdVYhpeAyCgzRhVQCeHLRFhdXRPczyPtPUpUHOVpUFwdQdVTbkiIwkSVCEdaSoknPLYnwDqVDzXfCpiYteWTByWwRBjPhsBXMbjJhOmzIAwXQtgKasDOOUaVqSGxoctczahZiBfvxbHYUjvEmHBZtforcMQoiPZnhuulzlLpRVMcMqqLiTuqsdntyIvHKLYHGkqqkQRkaxBtbpmCZQMWsdmbHOpSGynICpWVWAPGwIvGricfNCyfjcsndwLxtdqztJiZTBUnaIKgZgHxpXnoVIeqvrGyMwoaLqLvGmhjQOEUrPuFQPwKSnaYZAufNNoSgbilgEYFFwkjKFmoebMvUklcYooZytcAJQsEdgVUlAcRjYEOhjeBghUSJPPwUexyJqjmNTncquuwInjXUyVnciuzngemfOlWKvkKHRNzEPWmQWWNyvXEQfIEEHvQuOxDquuNBOjGcebscAdKGglWpVSWDPGPXCknyuLkkIXkYSSPemcXnoLaEpWuJXTLoqKbfTwGETZPbUYjwpsadolkQfqvExKLudqobABlCNFBpuzexiANUZZPvyRykGOwZmJTFCUEiwLPqRqYzPmrAzGwwMkFOMKSnNeWkgAvNoybOWcvuIHIBenKVMIVjnyZJqLCKYDhisJWFBmNCoXbLaQgILLRdryCEeBVeaZvBuqFvpqvukbXnMUuLnjFOvAgFJcvHoHtJMjYJsChJtNlCQUNIzqHTEXUGlhszGTmjGEfiQsaLlKHNdYLyaXqoSrRjEQmLGuBqnVUfevaMHUjXLrFZvbsAVXIBDNmuDTAuAgaJAxuTZlKjdYhbhrdJHHcXMgkfVrHLSUoFsjfbfHKuffnwtBiPncloJgkRnaBbGSHFScvZnLSgOgMFXsVDKlrNOxdganTyUCHyKFeiWrpilFiTvbNANsndaoeBDiUVEgjyJaCoVQCjTDXQFRAuuRdmSjhgdGImwVCYzqFiYiEJBXuAbSXLAJEvulfgXzpDFilurAWAudYOCeCEsCaHduICtymAKwRxTLBWfIDKRXrXXCxUVTPVPexUKGibZirrlVPccNGCpsTuqfsdwvfHEJJdzBtJutQCWsQTabpISJIqJgmqpACqpzXYynrifsQGRegdRwilCnvAfzFQXviXULBbbSLZfkNUIuAWIjybtFBafiylCHbQeFHmlkGRqFAEepaXvZCYhZxVDIdiraTrRQtgVjNUCkBkWKXmQZzSecqvPsNxwUkopxLcPXGOBdyNcbWtmWtHJecHuSuFiwJQWSkghpvbVxfZfjeHolBeVFNzDhOLSnSJuKfytJQysEvWTfZUtwiqCIKXASjVYXqmtOyVSfOkdwxsUBJNrRvpUwWyZuXrbpIkXderpaYPNlSqtLhfNOJNxlBtixRHIxNcvTSAFlaZtAICwOCjwflKJVkWeLReHVCBapomLmJhGeWIqWlJYRqYKqfrAKkohCzLiiqpmetcKfxySzLsXEaddmpZxWyShSTmzxDXsbMzKXjvsBRXTgZYqprZaFDsOWzsifDuZATCInhXJHXPGhycWDznUTLVrSmnUrDPRpgYrqEhVfaCtciJrsiQpJddkBTKWeqbFpFKeAQFViRQpBbJIzTGjtONTQzneXmfgaaIqUsHKSLIywyyPeVJsxNvuwHXXhkAoVgVBqZELQtEUHHbXYBhHCMiXgXlTlgJigSBxwBEuPKNfRFuDrShohTCfFnUKEXhFMbJJpxpjeNXwHwEERMcPRSopGrgaTmXuaEJkRCMJSBCEUOJVpvNIVqLRzVcvBePSmlJKmYBcqFNTsaHeCgylkGAuzUnuwdzvGrVcmiEcARMiEVyHGEAuxXLlcRgirofsbeYnxpaaVnxeQAKqQUfsAQFtiHuEpaiovhBFixSWYzwbSrhhZltnhuBUWhdvjvBKjZXPHRhfCXyfWVDSWiTMhhVgxKsPrKQnCqjiycCbAujAyExxToiyDZPNmOzmEmbNYjgCWwPRWLqXaTJuFFUOufodCAwAyjVDVWMaegyIyjcrcmbaUsVOvSalqlFPeZhvKCtYsPAFTKYGvidZnSotsrKQvIcsEbCrtTAuYCzwSFVZVebUOwGCQMDcIIGuEESfjFLdpeRcWhwSBQApybLWqWrZvsPpOVyAOOMZiPFkoveIILixkQyDuppFxzHEeOrCwgnqCpzLBFvEBfjVzzVqcJHxRIGckCnNUPsOhUzgyKCKjaAwrBKMtpdmQFCbaitntKwGnFrcfpawcuJRESNVTFOQSYkDpVBBjBGYxpqMUzJLMQUXrHIttEafqnYeLvHjAvOVIklXjXyUpuyJVzQwhrINDrxWSQXFCmptUvdGvTdAbsCqMYrGFoGiVRGLOmQQCeNiPTqzZkjaAcrcvXmhGhEgqsytzWHysppJxQyEQhYRQPKZAcbyWTXgLAWCSpSjZWWhyhnHNIWCtuQulehXNxEVWBOLDDgYqQHTUgiAoyFYgLLgbQAITcYrpVyhFXfroxxEtYfTXokGQhyocmbDeWIEguYPNBnHmhbZptfdoTvwGMGZLdDmROLoLPpKFtYgqkhouQnMhrtLFQLOmXiEQfHxubwjigzpBMwiOfdpCZyomUSTajaDQBIIbfYPpKkmXVSbdBnBSjRxlPaxLcmrMgxRRqcsZsZQVszeuymlCLqkREXGViNMJoZVDhxqSKRYOYYjFHoVxDovlnlSevnkbwwOfCgFnhJBnuTSPFAIXFhbRxkLuzwzSaEOYQoiGEdrrGisiiOxQRJzxMEpvhDFBllulLXHJJrqhKyqjOgbNWhGJejRpjmDwcifzqrhdysJNQcUMnNKkDSyZYgFvEbWdgwlPPvTwyDustOiztCjjuxiYuiyEuLwjhsUSaOZCoEoVdemIRgJCLetyBGlsmWyBQQBHQClZIuygwlBLLKKusvynXPysyWKlblTgWyeaOHzETpBnlcaKqGuKTboCIDiGlygbWJDrKhaMiIrApVhNitVPEZfagyIrXFMvsoBgZEGFUHJdMxodtjsxbUJbSQYiLdnTYOshWAtMUAhNogoDrGoflLVxVHtxPgycqorvGVGUBDYoRzoennYMWPwhoIuSPqNGxZEMzdWHYSXxmqXSHYSJaHCLXPSrpJUHlzkDyUVKhPoZYBsypXCBTPgCGOwnBncvDIsuMzbFgGCryqurIqlCHbvBKuYlnFXJZjTnkbpHUKFxObqdmKNvKfjVRBprbJIhxWHSDoeESbhQwrVnDjKSIjwUsYlOUNSzAilpqbCWZNJPwYUHkqTlHeOkdSFSybgpbHjjXIErBUrxRghzcxTSbauTzPSNetCJEFEVMJdasNzPpoZTTxZgFYQomziGlVxSACazMQfvEXYmbmNiIFCkGzCzBWpubhiMbjiUDvUJoDPoOmjCZoMSpRlyLgPTSEaSUBDVfgXKQuIKyMVqKKlVRmlBvDxGWfmmFoesqfWBrmtcuAVqDSHhAjKSJUKfJBuaSRGQaRLPuXHAsaaBrAvfBMytBjrMVfcXWnpbuWsASgMUmaZAIEiPyCKgqwgYXmzOoeFLpxsgEoQeyBvkaSYRmSWCwOxwquUKRtdXmiASnUQgUGHBUhPTtFeoZWjmbogpzqSHCCGrjUUhpmAzKyRlgBZBQWQuiGZFHAmLXfF");
  M13::M14* v2 = message->mutable_f2();
  v2->set_metadata_ptr(&metadataVec[14]);
  v2->set_f1(0x34b5U);
  message->set_f4("MvSelqVgFhrxPvIScdCPhjksiwaiUOuetckhbmBnFEjXwmEjuagWcisFjBsBsyyJPjIRSpqQlhBQdKEkLzyuZKqZqHgHjaOVXXCoPMoIZHyyZMtIOesxxdcIMCQpqoPldoTxkJXWNTjdypztrKKjYkntUMqeaivzXnraQVFKSesvAMxqrSkPJMDnKwpbtDsDTzlAJjBVtwtWpZjfkbvEnwstvkjNsqCxhrKqcjSAAgmEFFjBxqlaBmFStKNowkhPvbkfHPsPzUGAJWiHfLMNVYYAmCkSdQtTycTQCfLSrbnTrRObjLDRyRsUquXDlqdeyIkcBvtThQBRBSUrWuSOczTYoofmoEzVzxSvipySagcjkkrVSMmHJySppdGFJywdEWKvgtxjHRwaIrgsaaUDrWSqhAfpWQcYPgfrtDrmdNvnYccwxjQOKPvLzZNyoORoVpwiGRgVJxLrOBCcABTByfNqVPmTmAMWEWxlLsolAjWHPVhNsDkkyLqxsBfOCjTJFLfvhSxOyxlJqCsaBWYaTufbxwoZoAbEbUKeEiCrYxjtZbHEXSqMJACJuMpnKZZsaHElSLTuzbDYvSndVjjgcEKuZNWtbfIvkAqBgepixvWYQkDEWXpIySNyBJujNjSgeeJqfCIRQOaZnLlAMbOHjxNTjQzMLruJOHrmjeNYkuXnlawnNuyGoxIDSgOYdGknShQMsascOMiDlAsbWDRHkXatRcCdAxCzbWLzHUpnTwOXQSgCEPgwxMHbvOiEFTECLfJukpyEpKqeQeebysKgutvKqlpnsinrXoUaCgjmEtvdNRWbUOZiENbeYvgKHRNpstbVlpcafgeHbkJRdbEVDphAKWTXXTAfIRITUTwaDPsBTKVKvWXgUbcwSxmdxsbECqlgPMOhtCWJSAvThoIcHTxiBVlmlvRBYKno");
  message->set_f3(0x1d1bf6U);
  message->set_f6("MChGQBtXlMaruATrsnrkUf");
  message->set_f9(0xb7ba95bcU);
  message->set_f7(true);
  message->set_f1(0.489);
  message->set_f8(696);
  return 0;
}

int M15_Create_F1(M15* message, M15* other_message, std::string* serialized) {
  return 0;
}


int M15_Destroy_F1(M15* message, M15* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M15_Get_F1(M15* message, M15* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M15_Set_F1(M15* message, M15* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[15]);
  M15::M16* v2 = message->mutable_f2();
  v2->set_metadata_ptr(&metadataVec[16]);
  v2->set_f1(0x3f0fU);
  message->set_f4(0x1865U);
  message->set_f3(0x38dbU);
  message->set_f1(0x1917U);
  message->set_f5(0x2913U);
  return 0;
}

int M17_Create_F1(M17* message, M17* other_message, std::string* serialized) {
  return 0;
}


int M17_Destroy_F1(M17* message, M17* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M17_Get_F1(M17* message, M17* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M17_Set_F1(M17* message, M17* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[17]);
  message->set_f7("OKVEZlalxeFWBdlzLyqNlmSdePgObqjVdfyRZmoswdGzbKDzjReUfCAxenlukfxsbZxoOvKYVCkncCIAvjLzWgtmdIKKqkDxWeQDPPYprlcKGhFWTcnxkdzDXkvGhUJmJfWJmJVmhFarhZgAjsxsIPGEfVvQwfRHOMFVkAjvpQFNqrhBrMuWAmWjNtwZOXmOjWwbWGizKryLjkPbKqKGPzEAulidMUAQtwTnxphfqndGeUGMZCZoGQkSXodsYrevUEpTRtzfsNtVnFkTSBQFBxFWikGzuNUcIttCIVGuUnrWMWuSAnNaVinhRyIdYlFcOeTSXXAvAiXWlIUOkeAzMqkGlQOXdUatHWXqufAZfXsJilPucYRVlFDyJFLbsSxVAZrDlgIrQOQzjRVZjRhKrgXhvaQWlHjUjNuuIPbrpIbtZZqSiZqqApXVioKLLIsyLgJmxwpXkVLMWRkFYMaBAkFcEgroQnvLxpVVGKSHiTXLBSnuDnYufzhYhSQAqIYYqjnTCfYWwYAahKrtsIoQAdRkekEFRRelREMxYkIBtZycqxYauzgLIRYykaHRWnGlSeqXYcBROmuBwHbPTFQtDuqkWMPbjENKirVElToezPbunxLbzdTfEvUPoyOYPsEUGFmqNGOoSgETopAFZnMJEcgBTvWdorSUNHZpYDqLgpOwBLGllVHbDmFmMDSmGoWq");
  message->set_f2(0.471);
  M17::M18* v6 = message->mutable_f8();
  v6->set_metadata_ptr(&metadataVec[18]);
  v6->set_f3(0x19bdU);
  v6->set_f4(0x3dd2U);
  v6->set_f5(M17::M18::E1_CONST_5);
  v6->set_f1(0x4b1U);
  v6->set_f2(596);
  message->add_f4("bMfSsngCAWz");
  message->add_f4("sQPfuqOTKRka");
  message->add_f4("uTBsJkzhmPCT");
  message->add_f4("vepEUemizhXwlfdA");
  message->add_f4("arruZMWbKAjnrvAgMdkUXpAkWthNpLbtdnkDgieXJgLlGDZOTWyZBpxxEcCGMGAIOHtGEFehjhBxpNnctBZvxuKdySvTEanzbTYzzeejHlLNCTrHsSbmFPQesZrjKPLMiBqLbadvGCwqmVjlPtmQxivSuOBpUZGHcNBXhSyqcoIasCIZweaxeAjtZvlcbSjztJeIAcpZeiCVIinyMjwycWRwZLrdHKKpjVuuzZRkErCBhhuFhRSLjyLqgmvPRJdXFPWZWPVshuUHVNeEinVBXeNRykIoZAsYxiwdNBOGfZXNfHibevfmnTrVbqRgnqAzSkblajONGMbjcrTrLICAdjEQyIHnwqBtQmkFPEQZBvAsPtiKRWbNXhmRwpsirPPuvimEhVnLYXkIpOpmFvmldcSuJCzjdaVOMIRDwVQjYnGquRbZFfvKsqKHCTsrrtNKwNzMzJSuyEdXpJohIprpIaNIOuiqEGmxneFreOQZILaxudXBeNTGqPMAhTfjvnxIizRznIFsTarKxjFYohDbodSeBUhIaNxbQqQwaIzlOLiGTnkfmCkLPDKPHpHUgdsxUoVdgdyXpNLjoWnGlWfftAfYUKCFiCBfVbsnofyTuvSeBBlLZGhBXGcKcMvWdPTnsGmaClzDRLZyxSRHAzLhseZYjoiXFZjZOQVpXusiLXpzZtxyKAdZTzdNGFRzHOHhGewIBkjnUCvBOJqaHQbFruoSUTCRRhCnxZCjsFtipfXWvyYKJXkuymBSOeSHSxqkOxJwTyOfDAaDirJVUgWORwBfcToDGMsLikNLqEuyDGGYtDLvckQhHhKdGumOCYntbjbkgpbpxZHYHwheggbvdIigEdeCvnxNtZRjlzCcRzVyAhMcfVQjefIkuKtBpOTLPWjFPlOBtmvMEOGaLTAWxRfxSEgbylEErmhEMtTqhQCNtUomfMdJJleqZiOOUpVKfYIDtZQZLNvqzerOmuJTaizPzLPVknvsaEHVJsAhPRwHXdLuXKvMQwvvLbtbujorSIvuMvmJGZqmcerDAzKswVuTysYYmsvlLnnKLTJaykokmeMxulULmYhBWBtDIsxMSXCVITYlxxyNZfRJnnssVYCmpjgIWoHdGrRDVZfUoqtYpCnkGYNWKHQJfAlpGciLkgIUVLsjLVkxYHpuGntuKeJtzXzWSENImzDjUdpbZMBhQTCIexOyouTGCsgTzCakVWVgzcYAbkhQtqezsnXXWvlqVggUhgHeeQrbNdNiWFXEaAGyDdMecvXzODvhiNVMxmAocsEKLbhiNisCWjjcTOlYNsdpULTYMUqgdGVEkyMxfqFlGAqgtVNRiuXwNibmlYydDDTDIdcqzBLxnJhscwhZINRAWkPoFPkYtxibdrNsygsVqGkfhNafXrgYJxFzymJUQpvxUDagHmQhueQfgMZBFRRSQLoAfJZszFUVUGtTwJwtVoTpsUjabolMnkrdczaCiAZgfIairdIDJtokQZalNMueeGQXssnziLOfWMQWKAJNqIaWBsUzlzDhTbbIJKLoQqImGkJjKkbeOfhNZXkKFTvzovvZhxFhpBAEgRGyQ");
  message->set_f5("EQkHkHISOZ");
  message->set_f3(M17::E1_CONST_4);
  message->set_f6(true);
  message->set_f1(0x6ee4f24e6U);
  return 0;
}

int M19_Create_F1(M19* message, M19* other_message, std::string* serialized) {
  return 0;
}


int M19_Destroy_F1(M19* message, M19* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M19_Get_F1(M19* message, M19* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M19_Set_F1(M19* message, M19* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[19]);
  message->set_f12(0.108);
  message->set_f2(false);
  message->set_f3("lcPXTQVWqGmT");
  message->set_f11(0.788);
  message->set_f13("RPLBUpObIuBjUtVsCMmAREmjQzuumPcYNQARXxgxSFNvuHxOuzNrTsAqYlvPkzFAvuAftGJTLhxsrNtvOCzsUsqhlNhGgrGAOdZhGFXAagQNHtdfBROSllsnlXxOggMajgmklqWdjUiqwuMsApEjBaSTAxBKtaSZpzHYnNRgGRqFYmRjthcDqKYoNKDUJtdbqqAfGsBUPvmGqhZqyVJMYerrcBRaDQHePtrkyKLTWuALBYKkcRMykfrFLcUvaTDjsRUzHjEweAqwRhrWDzUltrAwzpTFHlkqdTZjIrmKVThdaQPBRFlWxjVZUkvmwetuGuzGKzCZoklYIqbXDUlCNEOeIXiATBRmOidRjNIEoxHbVUVCvjaMQhHvUgezbRjIpZlqQHtyIrcXBZuBTHxiUYaCUHbrqrLlIdADQnsBqobhgyLNAUuVLvyxkPIkzskDPPimsWujZCMnKhLZAEneXdoBPNpfaWDFWaGfSCTRMHHwRyeAKJshtVXpKDFHHWVEXdFgiaFJfSMXllMlYSmxQkDLBMkaAaTsAeGFjNFUtyVcLbGMEPSyrLRNnPNIkpZaXzAsEEEVYSGZvaEYFqhAQaBqCjnFbIkWHPquZgjOszqYGZosBoXsdvZUPAxJybwxIGXLemSJfPdZyPLnHalFYPYTpXRflDILVbhywGybmYwEehmXuNYeTPvbBmLLxNQAXSvGLtkjOLeszXRtZOmPLOvuHwYewalQnMaIGKlenBlhLjIDQYJIwcQZEwvvmIKqmXSpxqLoOCpkmrfCTaeRLmYJBvCQlmobceWfNfeFDaxqOhEBDjFukaEfpDfpykNGPLI");
  M19::M20* v2 = message->mutable_f6();
  v2->set_metadata_ptr(&metadataVec[20]);
  v2->set_f1("EZkbyxYTck");
  message->set_f1(0x3dd5U);
  message->set_f7(0xedaU);
  message->set_f9(259);
  message->set_f4(false);
  message->set_f8(0xffffffffffffffffU);
  message->set_f5(0x1f4aU);
  message->set_f14(0x39e9U);
  M19::M21* v6 = message->mutable_f10();
  v6->set_metadata_ptr(&metadataVec[21]);
  v6->set_f2(777);
  v6->set_f3("yBDyPoXpHqPLbhPxKM");
  M19::M21::M22* v15 = v6->mutable_f1();
  v15->set_metadata_ptr(&metadataVec[22]);
  v15->set_f6(false);
  v15->set_f4(0x2d0aU);
  v15->set_f3(688);
  v15->set_f5(0x654131dU);
  v15->set_f7("eLLffCaPsAeE");
  v15->set_f1("kWaQhnvUweLfWASF");
  v15->set_f2(0x3ffbU);
  v15->set_f8(180);
  return 0;
}

int M1_Create_F1(M1* message, M1* other_message, std::string* serialized) {
  return 0;
}



int M1_Destroy_F1(M1* message, M1* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M1_Get_F1(M1* message, M1* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M1_Set_F1(M1* message, M1* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[1]);
  message->set_f1("hdLKsEdfWvKuDkciMRJvLGXlJOFWCqcQJqYLuiUkNBorKvvBEJKAXcDPCyWFZVlWgpBZdWICkHfIkcbBQZVGvlPGcVwQdALzSOqhYjrUDFhAhJrZcJDwyvGiGdmIaUjMXLlZZhIDzcRlvfgyscncwFAxqzezdHZlbBiKVwkejHRFcpDYFBphOGAuZuYxMuExtEORIxlvMRFePLZofylcqQeBRtsXqIiWfqZCGdRLFWlwiwhOjKIdIWDdwEpTRgBDyfFYcESQoGFaxYbVlcjzWplzGZHqFODepqbCNlAfyxLRzmuGPNPrysOgOPvTXpIFSYcHPjrndvjcFyKKCRCVXNUanHkYqzMxczKHhiysMStnopAkvbOqObHoUVgsnTMMOucytWuQvWPhbNPaDYaTsouBLSywxdeOmHGQqFRqbLhhtYqFkwQwXNauvnDNwulUWiYhBYqNJeatjheXEyPOHVNZtEeMBqDVknQdXmOMWrmZSXcskhmwMhYDyxunuoVLRGWRLwAkJfeXUHGanGweaHYTEEYAbUhxjFvTGVDXlyUTikHgypzFDHvHTZmpEpySDtycVBCelHsRSYGokrCKogYOiilbZeDWaqDxhXtnnwQmrMerbtiengltpRYrxVPOsnifYyjtJzQQbXeVkxyAovKOVYiRDZbPHILSjcShjDJvtiBUqPvqrTnNgZLxGltPPQChsPBQJvauRnQXTVcmvtDmryLDidfpBtrWhKuulbvgSshXJoAmnEsSCRFtuoGqTaARJQmzDVpwBQhIPeEbxpddgNXNoVbnUGHmQAlkTsUseNmPajZaHQOWLepstmLjXRsbvmqYTgrXWNnBdzqChhTaFHdJvBbHSpCjGBvpnztFAwNSFXSopHenYYirqEQUxDVnGnETOWJxdmkrTPkVwedtqeNTBoKMGEdLgohBclqYknmyNBHbVELDYmZolxgsyPhdGTDCCzPnwPpuiwffjNNpknWKbLpcYKMkCXXZYIvpCJENSqeFNLYLyCgfOGmUYahpqtdLKPLjRNARvYAuJDJelgWzNbohvkrLPZEzWoGZpQIMrWiaQJbXcTzYuhxlnnrRaejRLfDowyqQZOmHxiouhFigNJGtmHSKDfgebnSSHnDcuNTdYIasuhpKywfBSceykinxTksxKwtjpVOlJUGiCgNTNEIAlBuCaAgvvUkKVqVPVtpVjYElTFcrGgPyTlhRoaymQHcAEYVhIjkeJTKxknytodGHvBzBdsVvMRzeIPOmETwhxSsNVIR");
  message->set_f8(0x1d60U);
  message->set_f11(0x5adc17f87U);
  message->set_f7(0x13b4U);
  message->set_f6(0x2c96U);
  M1::M2* v4 = message->mutable_f2();
  v4->set_metadata_ptr(&metadataVec[2]);
  v4->set_f1("Lh");
  v4->set_f2("NbmleLRVCAokD");
  v4->set_f3("hmZcTZrZfsZImpkC");
  message->set_f10(false);
  message->set_f3("aaUxEWnNcaClSAMRQpfKWfzHfkOhKJayzihfwhjxKHdNHpFRatvbtFODvaNtIBUWxLNYCEtPhkOKkNvioYuhlzJVZKAjWQtfyhLFsPJfCrWuajwEipVxQdQYASEYMiApImIXXvnAaknEBHMBgcJhfVjBkcPXXlMzwUcEZDhvImgltTZQqDcXgFPTRUPvLpsHzzFQVAWHuiHJEFcpVOXuxXCfODnaWktLBXeGGhvhaQsacCXlFZazRVwdtsZOzSebmDaPTbVeMIRAwlQtzxNceTpQFXqZenvRIwgZMyUXAgDBdyijdKOrmOwnfKSBXfYLppnVtfFVpBuaeeRmaQprEMkiYmvvuQJcxsolHhIBHqirmsnYuoaQxixxAJRMKcXiaSgoFLWaZwMxMbSRSEHPkvhjPsRTXUrcvffGeYyylWfjWHYleesiZMlcRnPybiXULsrAVOoEBOavYIkrbXBWZCtpRsBvcExcxJglXvKENYlSrIQXKUbsNOUYgZvENIfappRtskRDPrvahFpJQOHbmRQHzUqHgrkhqNRscyUjzkZkIdqNmLeaFWcGhnxAyKlEDPwLvOHTHLxRGNGKrkFQeyILlxcZZaWyudvYDTzSjxYqnFRoojTdmKHTGdUIbshKkVkgdlUdaDzqccoMjqVzknVTtIkdRjxzGosHDWnkhhBHsTZIqWIWSeMLiXaZWyOzBVhTWzmWKGBYviZhQmbIiHDwmQjLRKHorGcDROinzuwStrbACbAkBpHofHAfoxpZsQJcoiLBiTSlRCtRJoNbefGeNugzPBpBhBiSfUxvEfvdquqFGASoroKBlLVisezmWBzcVZkJtbbgHggZIewRIoxpDjjGPJTtqQwuDllykzPhBovdqldzgIqmNxhTvWmkpHYcCuCEIOPsmoCYwYeQsgNgZIzsIkFZXsChxYUYGAGVXlZPcyEXmSiTNdLZriRbsLqxJgSrYGnjyCRfTBAwmDXOXxuWYLvATlXrAHDqatEejUCYehdLgLadXdqiLrwAymSpAlRsCecqKMBEFcetONberpoBNhdQcHvotAYoslraAxtaInPOSyZeCrAOGujFedYwRvsqIQQdLRCyVfkytPVkWUjQwsrIIOIZGsJsnqNqjBMhPwOHDBREFYBifUPfGDdCKbRIvqQCSruPnmmhVakcICZkhiESrCvvDJGfAPueeBYsygTBCsVxPaUXDexsyGfkknTsePSTkoUxaXLgKPebwDuvEqdTaYfPeWFFifitQDFKXdwfZlZPLwZUIgzNSwweSnhnKHrOAmiiDGmkByKzIpOSkATnXqbrlcOSoPvZxkZbRkhxbQxwSAhERVUzmrMMyBqdLRiyEdMcnbfrpXGRlKDzSWRkrsFHqrRGeBpmJLPjlcfKfxDkhTNhBbzLTXMbrBfVODGwJwegPuzJkWpcAKhvRVUdItDQGubIiWgIIlblpNqMKjsTeqLSIFzZsKmqhxkPmRDTtTIwNjzSWMNcEeVuDURUfGtSHMVcVUzNjsnRfCnvLaaLuCIItINTLBumTUvTTDWltrXGCfROOckrzcAkupptxLCsCjZTSLQXeVQzqJcYJNFsPTwrQtEbObmcHXEaxoyUEyjArUOCSBWYBsGfhbUXxgCmdYrDRMXUIATsbZGlWpaYElcsEHautPHnESaISVNleQGDagCwFeGoeDAkBohNUnhkZKXfpxCWnaeXzbAVTTAhWLbCCMAfQncdJITuMprmTETXAZXBDymnddZrgyYrjvBCupazwZZBrqZQwaKfcmPYWKaTibhFspzeUmggpNzntaGnltLmaEgyhkXOUOvIXArHCOxaZdxHcWDqfqpCRGquVNMErshSmMbCOUOeDiLFFJFbxpvBOgNbUACfqiAFquJGRTZGQTxeDqypfKsJiGPKDTwTDhwyubAGojZKhAhSrjFYyzJZXdnojlPpZqKgzrWoXEPMPaYYEcHrhhJSHSanYySmVseaGEyUCODIpHeWqmXFCbwNfKpnxquBeaEuwfGMVdtvCiwOAEsIpnIhkquPAxqdgYpPiIFVlddywiIfwueLJNrUkaXSOaCjTNJNmAZhpmTJPMbSmpCfIQTvNOUiyWsZiniRAnNnZAJXkzRaPHIzNtXjUgzsIHiWGgCgYOPeuQChnGmsxwyZKlqXESVKmoNqCBBxqVQmlQweOOcJHBXeivqLnzRrjNaNGeNQBfDIqpjeqsvInVlPMKprAkUyZssZktjwETxYHoAgkKFNsNOnBDzBUpFQyEGQcqrUsYtDoFXCQHkwenktQwwNaMahbAZtCyZZpvPCFKdMYprLNPZrUXVpClGcDBqrcjZbTgksmGJeRwAHdBtaTyxIbifVkzkyXKunXizzOONNVJYftqPASdgEciVOFUwIwZMAWVgCiyoFrqzGYGrCQWbFwRCRefpBhghqGzjyfERqPRzOnOoeTVTYzVQgRLiXiJnUFegGEmbXAgnumQidWmqgHjDVeMwgaOkgSUmmEzlwUghaQMYHTBmaCPuSspJObYOXXqgNAWHwpiwFAaxsmIrruGxTYlGwyBGujltzoJzkhfHwggxdmRZsgeUEPyZHgrSNNtCLytGyDzqsqUxAddTueSyLtSSTwrcnvUKVZQevXGIZYDwDjllgAdrBkCNlYDFOiJNFmtJSfHqLBHkOaHhgWkJwrfkzysPWMfeUIuZahyvwzeNzwjANhXfZlfMeRQrDhiwrFBUSYLIgkJyYjxtMslbggjYCkkTDRtTyZiFeJHzXNXgHnXexQncnGxjzbYFnoncJwfDgILBhmrRwVybKVMABMtEbqWLhKeEpFHobKXculhQpCHkCOMbjOXXklWRKXbglRLgaYTTgoHIwfBnfhwoVSWyDpMVSbWRPHxtXSPDJnxWFbruVBTZnVSwFWVZZzoNgPWshyrDWJPCCrPnZchQswMQCvhcIppjoRcknZKSDZAjCnSQsHRSnLJPQfEwOTxvVBepOXmUfjDMXWIBQJcMJLeVHhtQNpshOftBYjOtWidOxIYjIpIxtoNVPXXhNupGACpuVhKCJcSWnNxUpLLnRajwSBobSRntIEQdsrGZNKAYPJeAGkHKhrKJPowrfgumGyIpuVlxIxUETyBOOgIkLyCqDXQFjFcUvljuroTUBHCJSLYJOENAbHjuAEGbysrSPoknlyivORMsnvdGmSKKofQRgUamaYRNihxTkfTyIqxJRDfEjqrRRhYwAHeWeVSaoZIhnRvMejIhiCoJcrTUaJirrMbCvPjmeLvjCYkvuNHqvpCEMAWLdWmJhHBqlPBMYokAHxVEnWHVbElDWULgIRQHeXwIGmvphEYmHnhlNqQWRBizycDOmeWJMlJJXWZinlDxcDpZxDDOqQErvkNqsxhNBeHnkmdiCsrFiKKvoMgudphFpPDFFwxBrLNktfjOFJhjIyacbwMzHWgSsuKEzHSXLsgzRdwvYPFiNtAfvAqHqAZkmxOOPaEruRAxmrwgNmmIJOvYzlTYdQohysjtJQwNdoemhgbkTPhsLbPpgGwAZzmPAeXZELcwjeklnGvNcKmKGfDgHbHKLcCfCFpApbwEqlQdjmOIcyItqiSavhHeHIKshxGSimPBjHAskrZjjDJTOqGUGKToUXGxDhkKGbweoxOpkmOuFIlnLnKRJOkhyoVVFaHHpbbzheQvjPOiTxzIMUysBNPHIMdXunRebZqmOHnpKeBxVUCFGghQFjCMkEBiUNpMblqAZPigzyuydboYHVbBaXoPNvrvodfESBoZWWrHMdCZRDViKJFSKFJldYVcpsujbEaxwDqfGzbLBLYoCdEvsyIpkBOuHLSxukVRnqjOlYrWufZJztvoxAEoEWTkMciMeAuDaZgPnRgbKHHmmhyLWmBiOuwZlnnLQdoaUhCenzCatCVxQXhoLAYMSWBgdHDyrfNYrOOPlmcvgcgTXOFayULutePIuENspboCVWfJQDFkVpnwdTmRtWrGTuZCBhkOaYRsEiLspsiRUyDoecfkscfovCHKNeXFBTfhWDIJUqPQEbGgVIsLQtuvHbzKDjcoFgetbctSTjPRDAKlnltXXOsnQRqBKWBlvEDuGErAVKYFDeOQcdMrXwdFDcgJydqyWsRhOaLYnqOjnKSDQkekdkbolgoEOfIJnGgaXcIafPVMQUHraORNNJOkiArqdBtJqevKSTynFTBOPTXaXFekTYFSkaXiioiLSnXQREeNfProZDSsAjrbMMEKKfGUBMKkNYoJojzVMlRlnIOHrfrvzXqkwfmiymESuSCXPqrUsXJzTnpLhkEJJaszaIdIXNHXmBNczjvnogQuYxHQCPHjxYMfwgJxxFucmOJhFOplhkTUUcaIvMwLZStoMREbqiGTmwLXwoWextHQuYHAzkFwedasXfVXbNBtADcfLxPJPMYKyLrXXLFDgWzqhJpZnBwObCtwTNbWkpgMLnwmPIJdxLAoWOAhedCfKGWtcHvdYFDIrAQtfXkbLRICBtkREBMZHJXwrOBsARsueymbUjahdcJXHMFfXhcuomdZnjwxpZXxHPWNgZdmOKzyYHBalPfiWnrizzajwVLNtNcpqDPibSITcuibVIGxgjUieFkAwgdwcXIGLdjEgwJcfYEcDozPoZBFSlLxdxrKwGAizUaguODIaseVKlfTirwIjFWNydAhCtguPfNoOUCbmoyOIAbDcNPVJpruKJPMTrOHBJKSUdcNtFllFqDDsiDTzusFewFILtadfKPsAwFUugQdauPszADwLZmpDMbrqtgKPdRIdUsEdzkSlzuEXTLYEhvsclkpJcQWLGdVxpSrHDmuiziYNLZSUUNbwCKkkSHUMedvNuRSjJQDBGqhQwCKZagiuknHqYfFLpdKDwNrACdvtOwNBEclaGvAfSDgYCMULcIHEnZpMWSveKHsqwWKeFysSfbKSlRhlKYuNVWxRFgwdtmasWPPEArzZzNkZXasNWRzPOeNpEIotsXWUblnSyjVLXEvqQBaWogrLcHDosVaHxlARdjhaujtCrkUAXNiRlzvOEVfDJzIGTBqtSiBzhWrouSgKrYmCTvmdyrFklrXWardWWwxktxIGwimDrWPuKZnyfjRNZTEHmHtJaAwlLmuCZdYSsrvmAwKCMzYjKAanBeJRkIadLEoksqjdqncrraAyTgQFgTAiLfWvzMWEbhNeJOmSpPVYNksDmKSxUVIxwdCunjgnxhVQsqhiTQkFnMkXlaGDFuMurrMdKLTBEhvEZyxgZCoJxOdHRzPIAWeiEpBwjcTdNBMyakMTXzxRQhkSeAtyukQAAbZFSXNJCXsfNnErlqHQpTcNihYhWtzPVFETAyVZoFDLfosgbJcBUtpfwSugfnhjPipzhMyuRDCElMKiKvrSPZJZPDlDSbTdboMXSvwrPdYYkiIJYRVrdWFIHajykMjaDhzVCbcxrEgklKoNRFKUnTDufNcwoJFooOmyREJJlYFjhVQWdWatdGoTAFNuwUkFnYYPknxKNeiAtkscXxkxYSMlxKee");
  message->set_f9(0xa918195U);
  message->set_f5(0.335);
  message->set_f4(0.232);
  return 0;
}

int M23_Create_F1(M23* message, M23* other_message, std::string* serialized) {
  return 0;
}


int M23_Destroy_F1(M23* message, M23* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M23_Get_F1(M23* message, M23* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M23_Set_F1(M23* message, M23* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[23]);
  message->set_f9(0.791);
  message->set_f7(0x50daeU);
  message->set_f6("VeAJhurcWYX");
  M23::M24* v6 = message->mutable_f1();
  v6->set_metadata_ptr(&metadataVec[24]);
  v6->set_f5(0.464);
  v6->set_f1(0.328);
  v6->set_f2(0xffffffffffffffffU);
  v6->set_f3(0x1929f5U);
  v6->set_f4(0x14e8U);
  message->set_f10(0x3a49U);
  message->set_f5(0xd8f5eU);
  message->set_f4(false);
  message->set_f3("IwUgUCVdBB");
  message->set_f2(0.161);
  message->set_f8(0x2abfU);
  return 0;
}

int M25_Create_F1(M25* message, M25* other_message, std::string* serialized) {
  return 0;
}


int M25_Destroy_F1(M25* message, M25* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M25_Get_F1(M25* message, M25* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M25_Set_F1(M25* message, M25* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[25]);
  message->set_f5(0x1f0eU);
  message->set_f1(0x1368U);
  message->set_f7("AEoWduAVtk");
  message->set_f11(false);
  message->set_f10(0.18);
  message->set_f9(771);
  message->set_f6(0x2050U);
  message->set_f3("SRSElnZzclZuVbNjHUdOFLFRVIxnggtqoXPmlqKsinuUOwkOnbwnmurldKOjCxZnigLTCKSYxCCdeXtcXCGMoPzpoEsJEUqqWlUJQkfwhLbmiPjzpyjbBmxpZsdlYJquqOJKouhbWtttScAPCszMcjQfrsVxSqtSaBrahUYOUxHCcXABpfInmxWpYWyiJzHWRDYNYCiCarrMmZcyZTziIvuPTyeGINDiFjzbmxHEAvqTAsPaapWaThYXNBzSsIUrXtPsLyLlkcNdMDgacSwjvmNFvHCwlHlyXRYNiIaOeZSKFBigcBYWCuRBYUHMbCXzVAgkUhkdiJbajdkpZHEpREzPGyRrBJPYQOafnuOqaMzPjpOowFQDmHKObfCQfUTMVZWhyrgWfnYwPNTCenIHAYlYgLSJRXGhUnZQmvNsSWSsCGhaxDPowUpLuMzWdPgKrwRaoXHHljFgrMThjSUqAfmNPCBoKdtaDWMdaCeECaUpRNtpjqHfILkkpDVehebQtRaleAZOPXeQLMQJifzZrSgwMzQmPchDJXAKTVuDwLUYEEtOycsyLZHsBiTfrMrKgBnSvIdxRgYvrxPunrjiHmmpgvnXDVMNAbDdGgzWtdykdnNtFRtLBtdBqRliwJvQKlmuudZOVNMRTCrPpjgvIeigpMmHZbVEwNYzVWHELeoLAuIxklZcJWnvkVTIzXgtuojkxDWwamtaGnVPOdZvohNKvnjyfcVLskGPppSoYUtYxnwWaykGxlwOUozpTsGFVyMgmPfgtPOeEQoOxUIxpuHpSqSVkawgVfNFGNosnSxMmOfimdTiaNdLHgrdYQQIdzNenAyoZiLTXaIDPkgeTchEkHcNzadRthegJDxuJrkJVVZlidcCorFnCiHXZoOHgukerpjYCBSmkLBKuiKMWZobHbEaMauhcUfYlPuexPZyeKTGwobiVtMfoNgEhprtYLelRtslJgAKXHVORVTAtQuKwtYToTfJlTWXKZQTdqgtJHAMUNQRDuvCUhBXbbbqdQiILnJGXQeKUdholsDlNMEQUlSwCeqefoJmIszwRwixsImYJNgiQWtEnryeCPVSfNjwOBQYZddhBZqPgCLkvrVSIPylbjgUxajRFTeZdhzDXRWzjuJELTYMAhINwDunfqSZqtNQnMwtNMejUlCAbUfRRVbygbQFNELRsXzoeJkoCfiKoiGIMwnrHOFBQdOPbdzHQwfRxVwUHMbUQAYBFdgYgySAVyMARSqojXtTUWYPmQdrBEQvYjhHtnwtXTPOJzYQveaeemIBoRQoATRcUhfdDFcAeYJuBvOAKXQSeBiCwnPCxfTYDJkHZDbbekPpaHLGcniffRpLbAigCDRhVlxyAHNGH");
  message->set_f2(0xb27U);
  message->set_f4(0x3969U);
  M25::M26* v3 = message->mutable_f12();
  v3->set_metadata_ptr(&metadataVec[26]);
  v3->set_f1(0x25fdU);
  v3->set_f2(0.364);
  message->set_f8(0x12a0U);
  return 0;
}

int M3_Create_F1(M3* message, M3* other_message, std::string* serialized) {
  return 0;
}


int M3_Destroy_F1(M3* message, M3* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M3_Get_F1(M3* message, M3* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M3_Set_F1(M3* message, M3* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[3]);
  message->set_f2(0x15ee81U);
  message->set_f6("hPzuXGvybTSCtFjhCsgGWzVLfIerFdYSvBzNTWcrousrSFZVCYumuhDOIVUwGajmARBCKc");
  message->set_f10(0.357);
  message->set_f1(0x115ac9U);
  message->set_f11("TFbtIWycHzBqkK");
  message->set_f7("FCiAhueheEJayOQxHWrrgZROhbmTpDoXELRadmREngAnuidsmOKFcErmOdlAqqkiNFcdlwkjAPfFTiQdWpIowQwxGOOgqLbhLmvrInMDXcWMvUmhsxjlLlATOueXpkmenoTbwsgbFOZZuELfjlQglmLdxEfQRCjvjImGnyAkJZnhETnihMVHHMjoFRkMItZeNlactmwpXwkAkzNrSjgHSJYbGnbvsQOSseEYfOpVXrFFTtdiBVlkAwddtgMyjBENGeLUcimQztKFlqIDGmNgFvMiOmERrjnpnuQSDCRAcQuELGczvbapUfsQKXbhfLUjXKlDZEAHpZWOFPzwIreyZEBpythalFcGHMxYDoOLwIAVEvEePXdHNunNbVImroIgrhsaerEljzmBDelwmgXpjoXvVIkBwWFRmLphzuvzCXthIRZC");
  message->set_f4(0.513);
  M3::M4* v3 = message->mutable_f9();
  v3->set_metadata_ptr(&metadataVec[4]);
  v3->set_f1(0.091);
  v3->set_f2(0x1243U);
  message->set_f3("ukoiAwxZKVAvkRrTyfHrZk");
  message->set_f8(M3::E1_CONST_5);
  message->set_f5(0.337);
  return 0;
}

int M5_Create_F1(M5* message, M5* other_message, std::string* serialized) {
  return 0;
}


int M5_Destroy_F1(M5* message, M5* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M5_Get_F1(M5* message, M5* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M5_Set_F1(M5* message, M5* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[5]);
  message->set_f11(false);
  M5::M7* v3 = message->mutable_f14();
  v3->set_metadata_ptr(&metadataVec[7]);
  v3->set_f2("XsOCaKvcHpgDMWANuoWZIovXkHwSSuiqrMirzjYFVTFqDYqopBDgvRPkkQRVEzvdasMrjqNuBHKuiNagFXBLAkRtUFVxcvlwofeVSJuCcjKUGEcAKKrNregPQzBSPkbQqXOXujDeXaSBFGIhXIuLaotFnrnkFaChvUKcugqHEveyEEnfHoNZfKJEGHrRHViBNoLZydJhtSkPGRIOimIDHYkJgGIRHowgToGXGQSzLodClToXvSmlIpRCnvrfdAqDSaymEvdVWSAyVgENVxkSLlHIitRfkdSOfuDTkSFXEjGvpcMHMmkgVoOaRPImrRhhZsENHNMBLMszSAGingHrXUxFGKrZsRjKgicURrTwbbepbOznaWniBeTjpRSEvonxhRfrYsVnMTfkqPjPXtMcLNRILlzUHDfJKTXcZhLfRfsHSkNzoXijIcsNorVvOqDKWpOkwpZbelclVHxusXwrKPJisHiAQvQrIUdhpqaUInaqAGfUWBAMqxAEOsRnnecofZiGifZkViTonYMJsfxsViilWymgssKQqyIyntlmnVanVXFYFGmVupTGCNxbOJBQNnxPmfqNwNzBufkogPQKPQntKAlBVUkBpfCzfzhPCQbeCbDNKvQEbCATXIObDoCxQOepgGgiquSZIncpRVJdkSQLoVqZqeEVEyZzpLllfxoFSeSegmBbDJVkAtoAWZHNdBLjusJYItvIxUGlkUQxKGzDgbquVVkXAsDTJBZbbfAWJpufLYgwVSxtZRVPAiPDirSOIOFMSLBPdIgLqKyDPfOJIIVTygFBDiKWErrnWUrdAVEbVIEMbopvtnDhxkShhjabzORfwGaSqrNIovZRiJSpRONwPeFMpITnfwnZXqFdjVhMyMxripkyJKaBwGsrYTDqstjiiCfMobRBqqFYfykBffeKFINfjKbLxpAoQnJznIXdNtjFqsjHkBqpMSTUMsalHPiDuLXTvKjxmhpYjKErzEbWonuIBWQamYoCUYAQPSGrnZUfjTqVsqpNrOAPkNzmmeOuAbnybKWwrsTzMtlJIkDGPlHnPLXAYBZiUwDziPPKEyrrOopvCrkkhSBuLPaKnDxPCxrPOArYyirdUYEdilwbiTwrlNlyfVrtghpTjOMtKENobsvbqWxiCOKSfSVbucDRotwjXpsySeUZTXZoRWlpWRLnlgGqnsOFpGjdrUjsGsLrlDpsTnQSZphWOnElfnhvIPnlXnoAVkVKoLiDoKJVgnrStIFwXAXtYVgjYTBdzsJAegYhUyXAzyjTBKuFKYhNeutqEfCNYcljawjVVkdHzlWokfUeIdmqMtdOFwTmbVYayQfBMgKJsqAzxrafWGtbJDkIPxgrXwmAMBMmSrxrYSEtIeulUKppcytqOcGxnvjbkzQIPAMYJNpqfjoZVGrsHXAmsRWlGTxECIaKjPRdvUPlZLbhKpZEDinfQxciOTNyZwNnwjmrioOihhryCcFJUZCIEmehniTvTMvhGEysEhSmbuZJRSZOemNkMzZOQNZGaYlCPyBJBFlfImBumVjQHHnvIAAVMBinElfCHpZXAYvgtPpAYcQEbxGIORiOUrOHtOhWnpEwlaEUEpxIvyNibCcigkasaxQItbYckYakULIpKIZAsgCSgMIVwKeIqbEzpNRJdyinHpbtbSXdxbrBZuRtduOdngVzidEqjpFpquOMwKWczuIbnrSAkPwFagZoxtXOhdEZRenasUiiJgLEWLozBXdeSaxfnCUcDNINXGyAhZMBmxllSkivmBJKZYrkhsTJuOqtKGncZBRrlEXQtKaIZgGoPAIbsBYTqflfWeOMHNzftVyOcfsHTJhjjyxooDDewfUwpRpGlKVDZliGrnsteeucOJTKgRnoJxOJpRcmtkaHFasgxIKWRNosXvvPfqwrBafEnulmrHsPyahaRgdVepkytkXepcOkCcnlcHAsBqvOezEOSpgyYToizFHbunCVHoNZkRBaCgPGISDzEvUDQCjSSZFylQzguttjhgLwGdDXKlYrtzWIdRMoSiQUMAnYHubHnnAqgoBWgQDVvVSQhNRLUJMISoSppFwQihWmdZdUzfzPisXaLawmWRRUpVqpdZIABwaaHSedqFMWVKkIOhSetnXviPDizWpYkMXYRmBjjvmWiCUrUZfhetAqzdZNZxFmmPStnlJHITYVsArDSfIOVTRUwoZicRlSfNcaCfaTQQQFBrkcNDfyWssqtBJTTevIhlmobmpqfKUjRHqJJqjGlblpzwgueTfnxfvuNirXSCGHhgVBrKJLsNevxMKSdwrqBawtMulvPDKReXzXmuBGFilCElhVWZEfPKKZyGevpLyMiIEXxAmGZLPSiPvnKdkNNpHmcgpfGkKoCKQbSugiArXJPVRQpJbffSuoHBnCZLsfNIidgYyrZFTSlVALkoqJaOgQfLoJdfTPxrHpvziBctgoaYDudowuSsqkbdVPzakxHbQqqJHIuYbUtVXKItxjhmzApPolRmhMkatelwttbATOaNiTxBnCcWkLIiORJStFlvkmESaijbhuYrtIrJYRqjwotSdABIVODCjCFyWTAilQOOXNRcVAyazrmFnxeCIHusYzoAMeLNfjQgnVYuMcvfWHUrAeZhvPxNHHrtWBEHQFKKBkomtISMRovhXBNakRENlHtihQVxZnEoumVWDnThjRLGHSNmEIDVlLuoWbulGCZMMjxXUeeLgXTjArxtTKqocZEDpVQYfWnAJBgkLezxplanswHGGbOeHxImbfqhEspHXWqyGJnaITUjQjxyInNQshHAqOWJwltHewBNyvxpZSZkQMeZvQGftbCIpnyZstWoLnUehIXDELloVMbCTzGueCkeVDETvBoGOHSHAVIuIiHtldNNkYHOEJMjzwIiECFZioPHFGZEVINbDDlFBhclGbdmkwqVMABDHGwWdQGvdEhioaKpHpAXGCpdSCdXCsrFLOLIsczOkxdhIVapaNZPORwBFLSiRPEbkFFFEMvXjjUZxqzUrKCvDyWlJlpIqHeFbWBTgqpiMQwgEgLbmPFrSsJMnqWxStuijJyVnICWmMALMmpKfCLYgKsQoaQxHtcIkHzvUuLdhpRcmkPfazqgwRNNnCywwIUWlLIZDrOyxvlvAmoYCaamnIGhONRoSZZVKIgUasQiZLAvtzCGDKIBgNJxghUlgNIgOzmacMoqODMqUTzsfQBuRrRNVvpqgkRAeUgEMeNcXjxrzWQoIRFjOoawzhuFFstFcBdSRiXGapYEvCgnNhXQDiscDThfhUQdzfrYlMMIKiAsQpnJmVmuAslzqoKruFyCrFIgBlcmREOUrKnOJqBNBYHYUiXqcNmnUxOwATpYgljxQsJcUmfxAgiVtaHVRAYIUrLriajvKdZqbbWAYyeIcfXSYggXOQZyTwpZKTBYGDMySiTgWbhzyCOzHVobPQTkLSWkLEIfSjOyLpUusPCGimDFGBUnFyMWhZKPindzUmHNojJLoPAmSTbJIhiLebVMQRbAPonnrsWDKCIpExzkBDpNRzKIpmoUFwxlRjreOYyRfWFjudBjkWwwoBklnjbzQjOjxDshTGYgcbgPAFnKVaoWfLYGXyBXTzKfMKkGvNOjdefsolKrWekchsyhZphpeDDlBaxlEpJWrQIinEUJxXKhOUAeQdXarrnykJJoTrsglgfUTlKVvwAHOINgDHQxBbjAGfOJTXYyMpxIrcuCsmmyBjTbwZzdoXzMWtCDHKYAGilFTfYgWRpGyweDWbPBddwvRAZIQmmtVFPvhUBjkVybXezxQwNCxgFOqQNnkZpnpmYjLhVGAYXWNnPbmrAqkdPzCLJvZBUYUdmyYACIGfCyRwkFDldyEPAGscjzUkvQJgRpVQgAkeAmWhoXNYMduotIlLAljdZkpFXBCkmcMAdpLKnvRSOekAijnsgDniASrWJjJkdRVVwyLtzxEARAvmCYtMKIPeFdJmoQvnLHvCgsTAeROdLbvyLUwuRhYmNjBjDDyfbJoeAGglurjCxHPfAUApribZbCoThOxNpUFIpfcdYlzmOhzHMzLDsRZnEihBtQQfvYUEIBYTindjGEDUcqKEPcwSujCcfRveBPyduBhPSYeCvdIiNIAkGhrJfCIMRKjEuiVOiaIcGMefjGltJhzZljgpFyBuNdatpRkqbwGJIAzlZoURuslSpfBGxIdxWPYILEgWTOrQBWwwwjLaoNmbAYDuhZOdKbYOkDGLqUEOWtLuZWZijUdVAuYErYcezDRVfhcolSeKYCUDahSPKucBTyuIDHPJcDyKDEcvzMsKNzbrmSXjrtZuTwDMLjbFrLWwOyeebBhASYOpLTvNsSzMkgFnsRaVYkHbbkVpBotVaJdczFKIbVTDSSUmLGbxeRXoTrnVwUcfHttmdukPTretLjykpAkMoDkUwOuPymeXiFTPbjuZbKKymIBYVmnoSROIJEqTXSpqpNNMoHuUveDbdXefVBGleYDddsbojYvXyIEVabEnVskBgzSHkqaXKJgqvCgBpjvLRubdyPbyUDuOmdbEpMujhLXHajTnwVbnONHVRtdPDzYyMDCMHNJMEybiEJHFauAJxUwTOEbiHdOocoEDaxeMdnqLZYVkpRNspYjixfXYSBxCPnWVyGdXohtYPAEdlPcaMAMFUNSZAwGrlbAyJBNWpGxHUZyeerWdOHVJPCdlTNyrWGUwksMWfbmzDMGiYGKUzircgLuTcBxAbWNYnEAVNUgDPATNElimEnUaIqouFwWFchVdeKbvaBLFBIkLfMXLEaKhfsrJoUPtCWBrKYqdocndQsTmiydOHDWpoZwbwAIRzoghfNzAtwiMHRbRfbcSROUdXkYqYpusNqarPSxGtFYPCmvprejfLTzkENbKXYFExnIOPKRxTfcwmMGBRVWwOJnbYxozqHQCZymWZdgTSIkvhaooCPPbgJblMlrZUDuPBOAgOgzbryWhcQaPxJAykXZHSsFBhoWdMGOKKOcqyNtZkYYnsEzRHRoLDDrZccifPkdaOXBLkgmIGJCajbKBytQivWARqvkMgPGhtLzbevtEABPdEfwTAhpJfNvOgkbfZQlNTSrbEUktlGGFqekGDpntkKUpGVHNqftczeEymPKKzpoVkHCJmHtKzByOfzKlFwKvNyvkfEsDwffIyLTCdjvYdfWlszXiLTXoOIMDIygBcbRNWJkgQyXuvNYSwfEqDCmxMKnHvqOjmKoKCXaulCRRzMimGITdVZhnNgmSItkqsyRITISgIWYDtVvprDbaSYDlCxTurWibzbqbWltylBIdLtFUmQQYhWNptEerlzOrwevnmlTChkwcAUHAWZOEIPHLWCrtJifYMRXFlZxTMURIXcznVLzCMPVCdLFuWZfNbbCPViBEetUYAZEVtANARunPpTpeSJUEQZygpLcwhVeSgNNTnFrqvBiKlAIasVuBxdReOwjFIiayNVmPCHxyhwqdcWLehRAmNRYWzEfmktdxFRMZdrkCtZhvZBDTaZhzmLCnMWXaseRYrwbileyYnOzfalVHVFKtPClKUiohFOijBlCoYnfGMbfBIZxhSvtjTjoRuOmbVuFrsHLHvDDTrXtxdmZHyxlWsGtPgzKDUuupUYcujdvBnAbFzsjJwjvUbQgHULbHffSZAqnDSwnUAtTRxYHaHEQYikIreRsfnvGsrGhdjSIPSuZYRMKaAFfjObdMIMJtBFyllDAdWkFMJWOgkLpMfLBntRCVinWIimrWHCEQoVqijThnVCUZYYFfUktNzeanlDdqvchFxshciJhpvatmOXHjaGJqpvfpPnPmRiNXetTMPfXFVAndAhaKOSqDEOIUAPqmCdyUgXxjsGQonxrwdMluqigLJTkbiULnAnmZpgeWPhByiTsRcoaGjexUaafCSaKeIkPpZBWUWQPduSeOjFKbsjftOOKejVYsaisLaxJPZyHfOBjEBKrFcjGtXsASpechwrkPSnMLhpIvOmNxSvxDVJenWMthyUwKxBiPnGLwhzljdQpzjXSJRbDUgpzxMTsbwleAPsrajglCzYoAHlbOJDcLMAWJbVZrGyFdQhVpEmxfTULeVslBGJDqQeKlCUuFQdQRDLeyUgAWHptMNYsyLFAlolsoTzGCazniDgpoxfIgYtRMqszjwBKwqYQLSCIpuQzRwIMXhLKmxjzgrbWoAHkpkjsVuwgvWAafiVhCmkvYYMDsMjczPsWVdpNWiFkFKYEvRnkZXWDZOJTZaKhIvotGZowTOKRWeoFVgpVyBUggwmjKJDfolqDOHBInXLAgWopjSrdfWwMeRynrjJeePyQlDjoMvuOhTMcLEDSbVOeqlswPovmuxVedoLWbXWfbCUChCCxJApGssWidMvBFjyTcquJNAxvgoGbhMEutAldhKleDvsEVTuaFLZNoSbrKGDgWrANoSssKnEkTjytUaErDSejRMBIhqcTNgffJWHvZCfUqvwGYGyEOuxBZFqUJgLCjnbNONLpUbOwbHCYOgbNChHQISzBtWxpghClhKfTjgayggrvrVTqCAkWmYWXATQBkSNTvSDDGpyhbwmfYFgIddZojCmiTLRZtjQdTGpmyIbioVIXoAXoWLFrXklVHfcWtkTUvisgPWARQVwDMrAfGgckcdokpkFwsgbPaMZlqKuVmInvbUEKLZVXjNYoowSjafODkRIsyfxfqvgoKJdGmDcScuuMXObyLLfSaBFNovjtaupwaaJirsMSjKnObpTLgrtixxKzYdaNmAxXhHtdIDFeLibesJbYRCiswMIBpTtMiZRbygYYfpSLjgUuJoCYKlIdlLtsOZxFfwUFPkGsQrEdlwOqJwipILeemtzaVWnblVTnAeKoHVwhlmteVysKyYQbRdUoFpDuRwIjqvMtOKTMprhqCVyFbfcqZkGyDhpXUuvowIcpeUXbZWIiKTJuSnIGiBRlfbabdervktHiwzGUNhWTnEKmEhkHtFcbJPtkHxVomnqcaSSdfrIzTHXsrBITHyKrYEBllBqWMmelvGsFWFVgvIODozOaSJsizoqzhEfrIeatxknPqUDcydAmEcDFopcoulnobHLeFkBvAiRYKHftKTylGEJeEQinwsbdOsCipxNxYKaIbkOelABiNDJddQmcEvsHTYmSotmSDqWayRlYduyyzmkXPcyCNuXJIexNMqaaZaXcAgHaUBVmyQrSmvXmgmarfcCSKixipVUwDejnTCYFTyWXRiesLofIyIaDhHkpRbljLviYXaVvNVMWPjiNbOQRKBXymUpFYeCQNbkhQrIdxJjulyMTRtYbjEKotecDBWlrjrgkyYaTcnDmhsiSpdejwAQBzrwDfKhzWIEzbqaVTruEPvkCAuOxvAWaFHMGBcGvqmYoDhFSmplnkjkeYpCwvodIOPvpiITOZdELyTAYRrMPtDKgcbdZKacTgXeIXNpPBYcpteElIOthmOUxhhJNEyZBVAzWxFCnOXcjqfkfyrGrWxCdDemGiQdvxNxYXqeZyyZIwiOhgfXytlgoNHJZTtCxrdwrSZhHrxaMMJwZLkSPAEcomsLzgEnEbAzsKveMxduxzhBoUpxEmnRvJyEPKSzmuJYhiwKcZGZGeljvhPXSMBdwOJIxOUiVaoITULoIdXeQKNMyRxSmCvODNyuMpDqUMGzpiVLCObACyLyHGWYVyoKcAgchxZwLlXLyPQADYXmrHcitmvqvGyJbQcNDyvXRDbSsJMUsdJPAUNrXXZYokrAMQiWJXqitTpqmDqsFsbbJkGezcAUKSMwjdFmvYQmFyYcFOPDGBzjsEredhXKhdjTVPXJiQlLnoyLxQxtflrzIQGFkqVbatflmJakMyyhtsUppWUChVALCVdwiesYuAujoRFuOwCZjSbyChdiwiorZApNExCosssimDWVfCPvdanHYDDevwZNVPMqudkDNKBqtYGQIPFSbzOOfvRNBDVLzIumFwAEWoNRsWGOJXvDGhxLZQuyRZZAyKXLXSewdXRHwuZLefIxGtbjguDudyaDBXjEScxGsDABiLgfmnPoNICPFtrPcPRKIvxizrTWdjrLlGdibQbvoPOBPZGQGJFUAehByBVJlFzHnmwkSRbyAQkXDsacgnqCtZQTYSdZHSeCfXPmOieHRGskjDxbbQIxwEmjGhJIOMyGRiFsNJIijBFFNUnwIvvwWChwRWCDYsNiOlEGqReWABpHkWaYinZsAzdJekFAWFQXJleVUeljWnZNvTTIEPqoOqpeosfMNxDhVvSqruzvWEgnYhBRdAMOEToSdNmGwUZvgmqYyTvgQAYDDiBAQoJPrCXkJxknfSrlNhBprBwNuEqALGdUmfhVYvzSzpMhiTbzbNGLWfpsIZWFtUezJXNRVUKyYsmRiuNthGWMJGcOKdoqNqtLPwZreIhrqAxdtJOATEhBoxWQDTQGctGtimIUujKWhLZAwNMPAerbeTnbWRXkOZmOYBmhNbrVNGggkDYncTxZciEQaXsXvZuOGSNeXdebjwOebnBygcKmnEXlXGpQpjJPXRYszfEuqDbBRsWHHlcrmGofjDMfhSgDacaZTrGCGvHYOyqqwcqGSbMYYCoTCMuzhyCbZMZkIQfaNYIqgRicISOFndfmUQcERaOYHvCOQiqaqhTTUwQGMVFIKIdAGKeGRwpyTREHGzMFDxyKRUsffemyTgxquywxXZolbQfLOyfCKIqSEIyjRmntenQxnXkdQZxscdicslQywbuQyWoEdGGwptijFeYEfaebXxLcDNiIdDyxiBQYVzfbkSuUirDGutZlPNmNdWJMXRcZTJvVaPGAPVmojZGpaTPBOqVrDWclRpmRkTQzOKrPNYVHiAdiLhRWmWrMKvzpJgFyNoPGXlbTQwgKGpsQWTKDYZVMLtCgvphZxBmJbYGVnJDZgQEPPZaoADiXzJOQoNqZQZOjjLfNmQbzNgYZMVNIelCVvPQLeBflbPKAHkMncLKqhlNtazfUFRKGmaJdqeFdviFawOGaylASWGBDavQNCNcnZTsDcMNRvaylUcyhoTcfWzCbh");
  M5::M7::M8* v5 = v3->mutable_f1();
  v5->set_metadata_ptr(&metadataVec[8]);
  v5->set_f1(false);
  message->set_f2(0x267aU);
  M5::M6* v7 = message->mutable_f12();
  v7->set_metadata_ptr(&metadataVec[6]);
  v7->set_f1(0xb52U);
  message->set_f10(0.302);
  message->set_f13(0x3ed0U);
  message->set_f5(false);
  message->set_f9(0x69971fb78U);
  message->set_f8(0x55646104U);
  message->set_f4(0x1e36U);
  message->set_f6(407);
  message->set_f7(0x1485U);
  message->set_f1(0xad826e1U);
  message->set_f3(0.865);
  return 0;
}

int M9_Create_F1(M9* message, M9* other_message, std::string* serialized) {
  return 0;
}


int M9_Destroy_F1(M9* message, M9* other_message, std::string* serialized) {
  delete message;
  delete other_message;
  return 0;
}

int M9_Get_F1(M9* message, M9* other_message, std::string* serialized, std::ofstream &fout1, std::ofstream &fout2) {
  message->print_message(fout1);
  other_message->print_message(fout2);
  return 0;
}


int M9_Set_F1(M9* message, M9* other_message, std::string* serialized, Metadata *metadataVec) {
  message->set_metadata_ptr(&metadataVec[9]);
  message->set_f12(0x38abU);
  message->add_f1(0x331bU);
  message->set_f14(0x1506f8U);
  message->set_f10(true);
  message->set_f6(0x370dU);
  message->set_f11(0.704);
  message->set_f4(0.824);
  message->set_f13(0.703);
  message->set_f7("gjJjDDwJRMpaYwiWDMNqwOdJgubrcbecfYCXsjpNCpXpUWBFHXhUTrVbBHZYHVZkTXTfNeQutIayDNRqUNFSrPuWtlPJwmnpxNRZhUhghpjArNsvOqfKVAvKnkJRvyjqSlmZujHfnwJPGqJQrNyamEyiDMNsizBdioljGfTvlmwZRDgxZvOwRtnlRnLkGMERNLIPMliCnYlOcNiFNutDOMTVYfDfiqskkPzzCkoghSodOwNpgnrqLsZCSSIYxKbBumgUnKzvezqTRVqNsylbpqwMoBbrUfQeXxgsLvoGENOyXbtrjdLKApxPghyJvYVkifDmrEmngNHguOgTJNjjsSATkqdBALOPuFyUMyvAOkkUPaCiWqCeGUAIqjvreOTPVloGxppOMFuWnwnwdPHaFJrTclhxnfSUhJyqmOFLeMlZoxqtGFnwsHhWCCMwkhoLdOopmDxfmfIqJzbdivAdGRRfsFdzRSYzhDwZVLvqhaBLaggVFxAGfIfBxGFPCZLofcuRvtyuGDwFimZgoSIcZsBUinpmwKzxQjpJexjhiGwQbobvFRlzlpnkJlvjiSWnmKnrGuTJaFbRaTOdtiGuIxKacvskQGCcVHeNYXhsQmQymLAwljOmzsIGDSmsAmeWmTJudlYYlgaBXTCWbteBUIbdiLIQoyRSdgHoBcJYAtWeFrNCVgZijhdXMshFFCyuCwpRwWwOYEULgIoNCuEiuyWKsjVrHxjfABQxlqZMtubFUwMNwkhwWjFpjWXxEgesFgEJtYHambTFtgvsadGtRpGkMbulQeYcakTVuUuFFPjJqFbFQKsuWkqONlOwIeLjGfcxcNNIBquyYAqfwHBXtwAPAhElCikUlwSGdZWcSSWoxMBPotEkExyfjFcKSrUuZfzKdDwTjzoPvHuCpulPXDIocMfXQiPIRBBvnzEMiTdcUyPDNeQTfmcqxtIDFSigyrkApeyjnxRrXCzJpBHvnrbOOgrxohOmPhrnYRxHATfnQZcFqMkaZHZHPfCtRoHhrXpwfrmKHCVnhtgfGXnJTdtlAjbwEeLtytqZTrTDMsgQMDlEspwZoRqskxZNWVDNTfvydOBQrkXoWcszBwthEHbIbABgvjlkUEVOYizJGiqGGxcufvppoGsKPVugkqtfmzDWamGOllQxInqVgTwzDOfPyWUgigvmpNaITkedSrTbdalbXEezMlZkZbCAOOcCpnlKVHHWUShTDZbUzsTNpkgMHKvkjZuefMpnojCkCUMiRKoljNBgxgZpDVGMDukGNYoybQxJOWHCOgBTzUpNesMRHcDBRAeKsSHoiIqdCHAogQQZvDoCwjDIvfvyRoWFTkJgiqzblXlxGVoktPvcoLbmXvdaKPbGqMvqFnozVAYbnfsYAexiCfgRgYSJPPlxKjzVrjIgjfqSfawfVgmVuKoMgpmfaVjoRPJGiKaydDIFdmTeWPpAKgAruXPemKohnWwVctacHnvZcGWDulbQJUHFZLtpcLXONavplGvtfrgRgprQlaMizLrVXCUNknKFceOKMPJSdLloeSvXQgrSVhZWlNCMqOVRwHHSAujFymJHZYeNLEIUYwKQoYpuuqggCScvwXXhImbSohqVzVDmlmyNNSEYsgiHvfCubmRbROpRoAztoRNDUIazFkZOCunqNUXVMBnGsrwWaVpIBIQJBBATnGPwtuLZWRRqhCzWVTROdgCcPmPgnDxcUOyjvWPPkaBoITSpDdmPDDmNBCTbmtGmbyzuWsYBoumhQHuRolqHQmbpdRFkzanzsSYjgGnGMZJGESoEYprSebrDCXsCqktmganIVIVIrQqRbbNSDJXWLGdzKMKPngOIwsUBXdAohfNtRqaNoyYGeetitGKkXeBimSFYKwKNnvqhxQbQQagtWgnYxoezPMQxoCzcEGMpKbFCnqfKPaAMeOPlZULhfAQRbovgvuTUHjEwJTpGjtybKKuKlGEbxyEbMHqRzanbtNdfWfsgGVINHQpWLCvpsKdJIhpDfAcnOVAoBFDymVMVttyBupECIbHYlNvOknfypGXWuwqMaVlsDxpSbKDABtiiwVKfiaLeAuIKVxJUaYAwxwpcOQfDJWbwXTPRwbBhrTFBJusZrihbpjuCBnnUVUQIBlSYFuofBrqeSiBPpoNCHIzarBDTPSEHhcCURXmIOOeodMFDtZAWzpEGCWXHxeWMyVaDuTXFVXqEUwDQFeklVcfHhyQTStwPipZeQmZiGdpOgODRYRUECHAxNplClJapEnBumIQPptYsmwqsffSDZVZKAjvRkFqhsPKHICioSPZWowMdaWNKpnnCFJTjnfROhRBevLmXAbDKRWewbJlECLbuKrcVurudZRoqdMnNEoLWzPQToHOwJTFEsnRvbMFdrSpsaNaaCuVpFoIddVkrtcqPEPDnQpBMktpVgDWonBFpkiKOVoNnCjvTqpTzxhZpKyFBLdWjDheRiZBKTVrjwSStSgXufdEhkYMwIxBFUhwVPyahqFupfPlLPAOXhmwkrXoxoPmhqLqQofnLsIUXVnWWZwjKMxEhUHfTrFYQLirpCwYNEpKqeGsujkUdOjBkuFvLTnlxRXqclWgGunnzyHcELidBehQfzyXKSLEGWqKWtetADsynCjVvgeJrikZXPIlNPauxUoHEanSmtLiZeBsmILhKxICnSegAXYGQnSXkKErmXUInEigxtFgLYrFqGrtjMuefJWWTMLxjydduEHiAGzPjDcGWNRWYrPywcsktlIStsXaaHgMkPPWBcWkjnlPRIUbNImrIWCygyJVqroQpZoSsWQTtBvhHiKAXXiFIXCjvvCNrkFnhQiFvaOSXQGjmEeuytPHZyuKoFtxdjXWKrPVceLsNKyqNuHdFzIawTjXLMpuZqgwWVQMCYIakJnlMewuNodFOkydrMafcDQcpnCrwlKfZypmvClfsWAvecgRsLLhwvwnnhIfKqAvPFMoywdwOpPpcndnhLUaNlITetvBNuxHYWjNadrxigitjNSGIpAyztAKLNqzNNZoWvGuqDzynZrVdJUAKsinjEdGYhSKooqhzecdzUwtVNvunXTKlyySOfDUDOGTXhdpVwBZiNKOKKNkFxcLwWXjNPYNMvipiYGkyvLAnjzUOjfwVyaUMPqLPDVRMlRBYAtRUgTTqRhzEIogRlxOUxniWzcuuPRLVzxtHZMnHsREwDrjHeJphKZzmxNqAfUANPeuBsQumrhvHNFrguUogvsmNREmHeAGqiYcERGLhYjURVUPwjrpnRerxwBpmrAATEIcgnwhoawokrcynXtIhoKoVfWWznjxElxoonnrMcfWTBFazFqBytQezGVyrcBvsrRMCHknQdypMoxzaydWZockCdmaXywtFYaZAEKpGCGUDUEJSYGNsWjvHlcBrkRlswRlxfsQCwZCsHshbrbALWtvsHbYfSelUmXQYorcxzUizAQvbhLCLkjTVKFtvURZOnkBsSSiQraIlpfePtDjGkPnabyRBCGFFlXjUCrFazvQyLNHbsmfkiBLYeLGCmKzdLNwbRObbvvVnIoyYIpoyYZJimsRZXYvGczyFDJKBEEOCaImcwvqXOiWImPbnWhOPXYOFTyfYRMgksHIYbHxMGIDIXRiHqnXerCKcxDkVkooYNfIibGCBjpetSWmfdYqJYBcxmrHhHPxhhZAKwynhbpYaYijOEbkDHEQgEjCApBEsPoKMtjortRoWPDUwtmqhKKmfKMunJZTQInNhnxRebsHNLsRsiJXfZzAzexwEubyIPfJvsVNZYXGhOsPBsJaNuTvhWSXbABnMmPdeIgmgTdajcvBtEsyWOadeBlFUHALUjDubIdpqPFFMDFsvpjqTGNjmUWYgUeEPiMQNmOKRAChYGlpskbhkNrcVBkgAAxgHgVlkdtppqHfrZrWWdvltiuNniUYjeUtWKOTkmlsAYbvnjsasXEoxqMlInPNDzKEmYcxRfhFfbxFLPgUXfKxLZrMqPLZcpZRWqfkYSRITjbfRAUeHKyTituEuoEyzHrQiYIcVyFpxsSxQnEScjQxabAJtwvjwtzMZuqxEXCLsLUXjIhVjdQzUkgpqmYnxMnULZlUxDZQNwQfvSevgxhsCOkaAMePutqiwPOMJBVVypbpALUyifKDepZGHgBAwOyobVWQzzokDuxerBivmySkEziVWczbGBvNqwqjsLakmlHkwbwRbzjbCCPSxezOhZYsxhkNBAEzLFkjEWnrrVBzcxAypgwPOPXkPdcOlGAfbKtKiLxwlGuIJfqVddYgzMThKXHuSelAOiUSYuKuWJpJvIqJFgAyxFLkZijINYDBmyYoqdPaQuGzGvKZWCBHVeNngaEpVaBjwyhWdZBxCvQeQNqyaaBkpygQhYXqiMwtCOMuNTGcoMiqxsDtRRoMjdUvPiidebdXBCHZttKDwNvLIURqknuDTPGNNfNxDpoCERpcpYnLwtjzmLXfbqCAegOmtUuDIDSENJuRALfAUJjfCGVztMLIqcqYxuWmrDXzLgnDQycTERxQTcxPhcjzDEtqIXiFUXMQvXxkzgxUzJMFugQCZtGMAOMacPjJkbIwZOyLKXERojyRxoMTMaydKJVdfXFquGYiPnEtFIjEMMRxNfpZBxtsNQLYKmLxjffaafxEgADTndmoSOwwIUuPPoKiGIpJHxMveHlMkxJozDVtTPvqBNnMGbKRNpufxMJSxCKvQgeupHJFlAYrLlVxqpivVzbJZDCapryCgvOgeaoqELLpsFBSIukFGZiGhMrpVBAIxJsvDkNTUZeSKsrxvDSJoaqRuVIqsMKUkUPVqerdobZBbdvLRBvFICrFKwzdUlbwXLazMsVnMqsZPBgCvplsXaexhSofJFVAUWtBsctjiphVVKFRLfOvEnzJdFiMdEespDIRCBDUtZxAzXkrEWuHpNChEtVOoBnZoYSlMaLTpcRuyYTbYJuecZUDGvhvKRbHHOHGpTifahuCmxtehYxuqmInKypMNMzTviYRHQuuovbKKrxLZfySuBijOOsVewHBEavDdxCQVroONZAnkGPhVnrzaSFOeabKCsUiRtDSieagFTIeEsdeSjlqWuBGArYeHbToiKINcVgKzHiUZSmjcNUAQyHvgmXsOSMMwnyigceUHnaVGoRWaDYCLouMxviweGWrlZcbkuvseSZePYZpdlofKWJJulnplmuhnxfOZvbUTHPUtVBuHfFXixkabcBinfMumihKxBNxjQvWOkVPgVZMVnnNWiBoAPxdIUKUrLqlEBzrVnEbDeHIAnhiUhhVsTbtDSiGjrIEvQHMFWsFTmtJVIIcclTOflgElyHLvRTFTqbIVDvIxBDBKhHeCbJVwPxkJQLseiTxGFVhUZwYmFLagshAsPuTMmafNkZwuMhKMOXWIcIwVbQeGXjuXwyzsHDTfHlOKWdskOcNWTsIdApcYfkGTeQyJNMXbzzSrWZzfmDlLMWsLNmOLAocgpgyDsAPfXnOUMbspckvVALNmiSPLtPLcKZbWkOCAJMlZkrPavuLZTXglZwPsPNdpLTUjYJikKADTTQTWArpYViAJbKyyWOXrwWDIMOIyRCafFuuwDLXkcKbCtLlymzfJOwhyykZuLPyfpKjnKVoemOTOfMBQMoCFMxbYyYklWWqLlarZUQHzBqOjpkJujhUXeejZvOwUZzpFJiaKtWwILbmMMyjZAhpnSyIaraBQqfVkafzuiilgHQznooFnreIGsBIbwdKNnBIPvJZtKSIzGLyqIuoinuGKhjCLLpAhrwwbkgTSbwAofgcritLLleAizrzKkxsWvtMhifaylJJaQAtzNEWfAnnjuxgJLpQOBQAwCldclJpDvIURuOgVKKukByMnCgsNKNMsicmHUrvTFjtfahxOUdCSEpTthJjIhRKfcqZQTMRTLKGKcdWmBgbDUkYjHBOYsFdbpoiQarGXOcrAbhfdVNBmJsgrjmGhHyBuWNBVbbetaKXhwKLEfyFizVXElCnsluqOyMXYPECkoQVYjsSRyEqbBdXObmePshJCTIXNyRlHtwILqjtxNIqOSlXQTwbNacOuyljRjkYpoqnVdEgeCvOuiLQIMlrhtHdQWbGTFEHvjIfMKcDQccVnxkgmTDBuHCCCIJewMDOtZkhtjgVMcimKziSBgHbvRhIjJFAnhVeaHDHxISAqYLUHXyYCdGwnnYcWeSCezgImINDJWgTpkMQUaTgvrHgFOgjcmGztkCgFsJawJQcJEqvbIphIosoXVrzCOVkXDCRGGijIUKzzGlRGrMSsCxcTZPUAeDUDGuvKleeKKLllMzTMDzgMGYhmNemITbqeeBVgGLlGNToNITNFRlZWRaobfGEaIdNWJEUVUfpvDMPDSUPTipvhILspaaiyaOQpsSygbhzjTfwrbnMbsthoRjfUeQDROdkteROohYwxADGWAgUKNdJWeCnUPKmFXdGTHiFVaizjBeMYGCkpgghElCfPDcwdnMrSetKkdeCAkxrQzGybaORBdBXYkWKGySZNIUUqnLtPIObcCLacsgeePnhrBfAQYMrUreFcBdabSYWIdgEkRKOeyTPUvmDEWBwGQagWRmBbCSVKnlZiswUThrirxKdHrcBxWjuBPnHdlTlvyMrxkousGfjhWbDXFYaLKmDEAWHvUyXGWaeZANgQnAljylXkaEqoTeRhfBVyWiVDPOwtLLdVwUmuSuXuOmoYcdsqEkkgtXWQlqcbAcaSqrOwsUMgMlXJHwtLwsAekCMvYWfpVFefCVtRCipmoZNHBWbgGPjWEBcTJyZxMuCSdPNltqlLmCaJfLIJDjAGSEIOgcTFanwdjybFxwWMBJULajNdWHGaYhNMaPODpSQGiRABrswAlwalUHdxyiLeDfBJOkserAATLIDnhiIfUtskgxrvEvbYDDionZkHYgSUeFrIJCuIGOsdQLNxCmVdsPvdwDXEdOCOmUAehIjrkXgJPJnsLELcMnasvbekfixmyKsbNJxJWMNFNHnTJzWgJNqfAQiJmUWVWLDGkJDHIgYSfGFqzqIPLDgAfKHZbDWmmSLGZRtPlrLoOdQOeAkuLENTxBXYUbbVRAKwQwrdYWvurTCEBJPuispMLVcZKeBZYptYwBaHCpMjKpSaFlsGZYjJjCiSbQGnVucBFkUSGmsKIsjMIgBJmuDKFFTCRSLvGEzLXZzySTJgQyGcwbeGcRlohaexpKxpYtDCoOwcPHeiVQOoCTcovyrsUVNNnHCeyyBRPjATddPcRKmjhwiaIEjoeZpSCGjCbCDhnfegnHALylNGPwQtojsbtslwEwFmDPfVhmyewrTrEvRTHYnufSJVLEIbZqYWtKMOgiFjTihowtOhgxrxgcQsyfCuIJjgNlNBIazHrIQoeHBYPiDSWwvShDJxTyQdoKxKGPuRkEsSRPWrOOExsuKwWjrDNrnFaMrFPqlsNBhYXMSdrvnagDIKVYwGaDPeICsX");
  message->set_f3("uUTSgMfEJNcpRkRBpZzxsUyZoLBevmRuTRKwNJcdJfapUMotLQXTyyBoipGQfnPcSdBuhtuoYiOFaSocadPHZAIqyeRjxFpejLBUrJJLPrnunNqEPgSsTQoqgHEHpQVUuCkrseCOJgxuXjCybXZXWSwpydNJwATfjBeEnriDXueTlwJnJSUgBVVYNebXapEyVpfDvrenmvtnWMGZvenZnHRhbjcEIQSrkeZnJaMeIpbvXpFBcvgqtskynNKDWCGuBXvZsKVgoqPzNNBvlbYUVLSwPMxVWgYHxEHgpaFzuHOATTgaRZrmnasgYlVsLPBPKirOZZajapCmmPfpdtnexyooeUBjuDIuQCDWTdTdYcFPldhfnwKTccgsycDgfILWOmGdNlHFIozOWNBeLcpXmCoQaLVYRWmhwxlcCBPpgIwUIOJbqUXucLywKGvjIwLjDOeFVFdbpvUmVHddQAtzVDFhZPWGLIoEONwsOTxuipJAhDfwQWPAbXAFdaZaJYinUlvTgbwLxwjSgJUrqWwZSaeWjaJCPFuunsAEsoEBpJpjcZjRmyxfAYAXvNPyyjFiJmoyKxkBrtCIfCOeIiZCYRJRDGLdCcxQbrXEYmYqHwITnbhyljnHIctxuCzrVjcSGKSbwaLtmpqKeKCMlBBvjvjPSZSyzYMyUZhLygKqJettZERScVTThewIJabFBrvKgKDOQhcOLPjJJzLbNnlncWQiaYJqZLOHtsYsVQQOAYaEhuMpwNGVKygqeoyycRQVFIGBITtAHUigFGrwSuZNRgjRTaiEcnFwYtnThzaYODmeOCQCjTobdGepxZMnbzrAhxxMtmMnOZcgzXECfRaSucreSUSDESQvqPIJuJdGRVXMfCLG");
  M9::M12* v16 = message->mutable_f5();
  v16->set_metadata_ptr(&metadataVec[12]);
  v16->add_f1(0x223aU);
  v16->add_f1(0xbae13U);
  v16->add_f1(0x1dd05cU);
  v16->add_f1(0x16bdU);
  v16->add_f1(0x23a0U);
  v16->add_f1(0x2df9U);
  v16->add_f1(0x7c5U);
  v16->add_f1(0x450U);
  v16->add_f1(0xffffffffU);
  v16->add_f2(0x1f9df6U);
  v16->set_f5(0.437);
  v16->set_f7(true);
  v16->set_f4(0xeeaU);
  v16->set_f3("fCAtDREatgIbRqtlsYYuCmIUlHlBuzLknxtTkTukKCCxbckwSFhuJteVOVaVaDcDWYAMxPiEJEURsaDXcZPhQBfLcSfctgDAwsRomnBEQbYNclPrEjudbbRQbWxpDAwYpozeMMMUXVzZnjBoxJOGUpQHhlglEaeTsfjBMQafLvEEMagIgwYLnrXulTeElUAtijjNxJkozBFZPoOkoOdhIRBtgelhVLMuLuvUQPVSsolSrxowAKvpeqOFRfILkEXrLfDmvGRiEkylFzsjBrqeRtXMyEDoVHNSjbsRhvPxHSdwXyRuwgsiGOpfXlYuLYavUawzhybVymoRPJwDXDLpVqqFlyjgCPgCmOFGMSRCkPspsmugimudXwRbwBnhXiIqlcljMPfxwyxkWYFkAZMoKPzrpFZoaoMXHfExzcwouMPMopgETRIZbbReWCmwmbtXbGWMPjl");
  v16->set_f6(0xa73U);
  message->set_f8(0x1d0fU);
  M9::M10* v19 = message->mutable_f2();
  v19->set_metadata_ptr(&metadataVec[10]);
  v19->set_f2(0xffffffffffffffffU);
  M9::M10::M11* v27 = v19->mutable_f1();
  v27->set_metadata_ptr(&metadataVec[11]);
  v27->set_f3(0.76);
  v27->set_f2(0.053);
  v27->set_f4(0x1c43U);
  v27->set_f1(149);
  v27->set_f6(0.297);
  v27->set_f5(0x10f5d6U);
  v27->set_f7(false);
  message->set_f9(0.503);
  return 0;
}

  M1 m1, m1_other;
  M3 m3, m3_other;
  M5 m5, m5_other;
  M9 m9, m9_other;
  M13 m13, m13_other;
  M15 m15, m15_other;
  M17 m17, m17_other;
  M19 m19, m19_other;
  M23 m23, m23_other;
  M25 m25, m25_other;

inline M_base* BenchmarkInit(size_t idx, Metadata *metadataVec, size_t *messageSizeVec) {
  uint32_t working_set_size = 1;
  vector<M_base*> messages;
  RegisterTestClass(metadataVec);
  InitMessageSizeVec(messageSizeVec);
  messages.push_back(&m1);
  messages.push_back(&m3);
  messages.push_back(&m5);
  messages.push_back(&m9);
  messages.push_back(&m13);
  messages.push_back(&m15);
  messages.push_back(&m17);
  messages.push_back(&m19);
  messages.push_back(&m23);
  messages.push_back(&m25);
  std::vector<int> indices(working_set_size);
  for (int i = 0; i < indices.size(); ++i) { indices[i] = i; };
  // Declare local variables for M1 lifecycles;
  std::vector<M1*> m1_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m1_messages[i] = &m1; };
  std::vector<M1*> m1_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m1_other_messages[i] = &m1_other; };
  std::vector<std::string> m1_strings(working_set_size);
  // Declare local variables for M3 lifecycles;
  std::vector<M3*> m3_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m3_messages[i] = &m3; };
  std::vector<M3*> m3_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m3_other_messages[i] = &m3_other; };
  std::vector<std::string> m3_strings(working_set_size);
  // Declare local variables for M5 lifecycles;
  std::vector<M5*> m5_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m5_messages[i] = &m5; };
  std::vector<M5*> m5_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m5_other_messages[i] = &m5_other; };
  std::vector<std::string> m5_strings(working_set_size);
  // Declare local variables for M9 lifecycles;
  std::vector<M9*> m9_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m9_messages[i] = &m9; };
  std::vector<M9*> m9_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m9_other_messages[i] = &m9_other; };
  std::vector<std::string> m9_strings(working_set_size);
  // Declare local variables for M13 lifecycles;
  std::vector<M13*> m13_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m13_messages[i] = &m13; };
  std::vector<M13*> m13_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m13_other_messages[i] = &m13_other; };
  std::vector<std::string> m13_strings(working_set_size);
  // Declare local variables for M15 lifecycles;
  std::vector<M15*> m15_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m15_messages[i] = &m15; };
  std::vector<M15*> m15_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m15_other_messages[i] = &m15_other; };
  std::vector<std::string> m15_strings(working_set_size);
  // Declare local variables for M17 lifecycles;
  std::vector<M17*> m17_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m17_messages[i] = &m17; };
  std::vector<M17*> m17_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m17_other_messages[i] = &m17_other; };
  std::vector<std::string> m17_strings(working_set_size);
  // Declare local variables for M19 lifecycles;
  std::vector<M19*> m19_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m19_messages[i] =  &m19; };
  std::vector<M19*> m19_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m19_other_messages[i] = &m19_other; };
  std::vector<std::string> m19_strings(working_set_size);
  // Declare local variables for M23 lifecycles;
  std::vector<M23*> m23_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m23_messages[i] = &m23; };
  std::vector<M23*> m23_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m23_other_messages[i] = &m23_other; };
  std::vector<std::string> m23_strings(working_set_size);
  // Declare local variables for M25 lifecycles;
  std::vector<M25*> m25_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m25_messages[i] = &m25; };
  std::vector<M25*> m25_other_messages(working_set_size);
  for (int i = 0; i < working_set_size; ++i) { m25_other_messages[i] = &m25_other; };
  std::vector<std::string> m25_strings(working_set_size);
  for (const auto& i : indices) {
    M1_Create_F1(m1_messages[i], m1_other_messages[i], &m1_strings[i]);
  };
  for (const auto& i : indices) {
    M3_Create_F1(m3_messages[i], m3_other_messages[i], &m3_strings[i]);
  };
  for (const auto& i : indices) {
    M5_Create_F1(m5_messages[i], m5_other_messages[i], &m5_strings[i]);
  };
  for (const auto& i : indices) {
    M9_Create_F1(m9_messages[i], m9_other_messages[i], &m9_strings[i]);
  };
  for (const auto& i : indices) {
    M13_Create_F1(m13_messages[i], m13_other_messages[i], &m13_strings[i]);
  };
  for (const auto& i : indices) {
    M15_Create_F1(m15_messages[i], m15_other_messages[i], &m15_strings[i]);
  };
  for (const auto& i : indices) {
    M17_Create_F1(m17_messages[i], m17_other_messages[i], &m17_strings[i]);
  };
  for (const auto& i : indices) {
    M19_Create_F1(m19_messages[i], m19_other_messages[i], &m19_strings[i]);
  };
  for (const auto& i : indices) {
    M23_Create_F1(m23_messages[i], m23_other_messages[i], &m23_strings[i]);
  };
  for (const auto& i : indices) {
    M25_Create_F1(m25_messages[i], m25_other_messages[i], &m25_strings[i]);
  };
  // PRE_SET_HOOK;
  for (const auto& i : indices) {
    M1_Set_F1(m1_messages[i], m1_other_messages[i], &m1_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M3_Set_F1(m3_messages[i], m3_other_messages[i], &m3_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M5_Set_F1(m5_messages[i], m5_other_messages[i], &m5_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M9_Set_F1(m9_messages[i], m9_other_messages[i], &m9_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M13_Set_F1(m13_messages[i], m13_other_messages[i], &m13_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M15_Set_F1(m15_messages[i], m15_other_messages[i], &m15_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M17_Set_F1(m17_messages[i], m17_other_messages[i], &m17_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M19_Set_F1(m19_messages[i], m19_other_messages[i], &m19_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M23_Set_F1(m23_messages[i], m23_other_messages[i], &m23_strings[i], metadataVec);
  };
  for (const auto& i : indices) {
    M25_Set_F1(m25_messages[i], m25_other_messages[i], &m25_strings[i], metadataVec);
  };

  return messages[idx];
}
