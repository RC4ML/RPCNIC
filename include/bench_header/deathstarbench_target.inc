void RegisterTestClass(Metadata* metadataVec) {
    metadataVec[1].class_id = 1;
    metadataVec[1].field_num = 5;
    metadataVec[1].wire_type[0] = sw_int64_type;
    metadataVec[1].field_id[0] = 1;
    metadataVec[1].wire_type[1] = sw_string_type;
    metadataVec[1].field_id[1] = 2;
    metadataVec[1].wire_type[2] = sw_string_type;
    metadataVec[1].field_id[2] = 3;
    metadataVec[1].wire_type[3] = sw_string_type;
    metadataVec[1].field_id[3] = 4;
    metadataVec[1].wire_type[4] = sw_string_type;
    metadataVec[1].field_id[4] = 5;

    metadataVec[2].class_id = 2;
    metadataVec[2].field_num = 3;
    metadataVec[2].wire_type[0] = sw_int64_type;
    metadataVec[2].field_id[0] = 1;
    metadataVec[2].wire_type[1] = sw_string_type;
    metadataVec[2].field_id[1] = 2;
    metadataVec[2].wire_type[2] = sw_string_type;
    metadataVec[2].field_id[2] = 3;

    metadataVec[3].class_id = 3;
    metadataVec[3].field_num = 2;
    metadataVec[3].wire_type[0] = sw_int64_type;
    metadataVec[3].field_id[0] = 1;
    metadataVec[3].wire_type[1] = sw_string_type;
    metadataVec[3].field_id[1] = 2;

    metadataVec[4].class_id = 4;
    metadataVec[4].field_num = 2;
    metadataVec[4].wire_type[0] = sw_int64_type;
    metadataVec[4].field_id[0] = 1;
    metadataVec[4].wire_type[1] = sw_ptr_type;
    metadataVec[4].field_id[1] = 2;

    metadataVec[5].class_id = 5;
    metadataVec[5].field_num = 6;
    metadataVec[5].wire_type[0] = sw_int64_type;
    metadataVec[5].field_id[0] = 1;
    metadataVec[5].wire_type[1] = sw_string_type;
    metadataVec[5].field_id[1] = 2;
    metadataVec[5].wire_type[2] = sw_int64_type;
    metadataVec[5].field_id[2] = 3;
    metadataVec[5].wire_type[3] = sw_string_type;
    metadataVec[5].field_id[3] = 4;
    metadataVec[5].wire_type[4] = sw_ptr_type;
    metadataVec[5].field_id[4] = 5;
    metadataVec[5].wire_type[5] = sw_enum_type;
    metadataVec[5].field_id[5] = 6;

    metadataVec[8].class_id = 8;
    metadataVec[8].field_num = 2;
    metadataVec[8].wire_type[0] = sw_int64_type;
    metadataVec[8].field_id[0] = 1;
    metadataVec[8].wire_type[1] = sw_string_type;
    metadataVec[8].field_id[1] = 2;

    metadataVec[9].class_id = 9;
    metadataVec[9].field_num = 2;
    metadataVec[9].wire_type[0] = sw_int64_type;
    metadataVec[9].field_id[0] = 1;
    metadataVec[9].wire_type[1] = sw_string_type;
    metadataVec[9].field_id[1] = 2;

    metadataVec[10].class_id = 10;
    metadataVec[10].field_num = 2;
    metadataVec[10].wire_type[0] = sw_string_type;
    metadataVec[10].field_id[0] = 1;
    metadataVec[10].wire_type[1] = sw_string_type;
    metadataVec[10].field_id[1] = 2;

    metadataVec[7].class_id = 7;
    metadataVec[7].field_num = 9;
    metadataVec[7].wire_type[0] = sw_int64_type;
    metadataVec[7].field_id[0] = 1;
    metadataVec[7].wire_type[1] = sw_ptr_type;
    metadataVec[7].field_id[1] = 2;
    metadataVec[7].wire_type[2] = sw_int64_type;
    metadataVec[7].field_id[2] = 3;
    metadataVec[7].wire_type[3] = sw_string_type;
    metadataVec[7].field_id[3] = 4;
    metadataVec[7].wire_type[4] = sw_ptr_type;
    metadataVec[7].field_id[4] = 5;
    metadataVec[7].wire_type[5] = sw_ptr_type;
    metadataVec[7].field_id[5] = 6;
    metadataVec[7].wire_type[6] = sw_ptr_type;
    metadataVec[7].field_id[6] = 7;
    metadataVec[7].wire_type[7] = sw_int64_type;
    metadataVec[7].field_id[7] = 8;
    metadataVec[7].wire_type[8] = sw_enum_type;
    metadataVec[7].field_id[8] = 9;

    metadataVec[6].class_id = 6;
    metadataVec[6].field_num = 2;
    metadataVec[6].wire_type[0] = sw_int64_type;
    metadataVec[6].field_id[0] = 1;
    metadataVec[6].wire_type[1] = sw_ptr_type;
    metadataVec[6].field_id[1] = 2;

}

void M1_Set_F1(M1* message, Metadata *metadataVec) {
	message->set_metadata_ptr(&metadataVec[1]);
	message->set_req_id(0x7FFFFFFFFFFFFFF0);
	message->set_first_name("first_name");
	message->set_last_name("last_name");
	message->set_username("username");
	message->set_password("password");
}

void M2_Set_F1(M2* message, Metadata *metadataVec) {
	message->set_metadata_ptr(&metadataVec[2]);
	message->set_req_id(0x7FFFFFFFFFFFFFF1);
	message->set_username("username");
	message->set_password("password");
}

void M4_Set_F1(M4* message, Metadata *metadataVec) {
	message->set_metadata_ptr(&metadataVec[4]);
	message->set_req_id(0x7FFFFFFFFFFFFFF2);
	M3* m3 = message->mutable_medias();
	m3->set_metadata_ptr(&metadataVec[3]);
	m3->set_media_id(0x7FFFFFFFFFFFFFF3);
	m3->set_media_type("media_type");
}

void M5_Set_F1(M5* message, Metadata *metadataVec) {
	message->set_metadata_ptr(&metadataVec[5]);
	message->set_req_id(0x7FFFFFFFFFFFFFF4);
	message->set_username("username");
	message->set_user_id(0x7FFFFFFFFFFFFFF5);
	message->set_text("text");
	M3* m3 = message->mutable_medias();
	m3->set_metadata_ptr(&metadataVec[3]);
	m3->set_media_id(0x7FFFFFFFFFFFFFF6);
	m3->set_media_type("media_type");
	message->set_post_type(M5::E1::POST);
}

void M6_Set_F1(M6* message, Metadata *metadataVec) {
	message->set_metadata_ptr(&metadataVec[6]);
	message->set_req_id(0x7FFFFFFFFFFFFFF7);
	M6::M7* m7 = message->mutable_post();
	m7->set_metadata_ptr(&metadataVec[7]);
	m7->set_post_id(0x7FFFFFFFFFFFFFF8);
	M6::M7::M8* m8 = m7->mutable_creator();
	m8->set_metadata_ptr(&metadataVec[8]);
	m8->set_user_id(0x7FFFFFFFFFFFFFF9);
	m8->set_username("username");
	m7->set_req_id(0x7FFFFFFFFFFFFFFA);
	m7->set_text("text");
	M6::M7::M9* m9 = m7->mutable_user_mentions();
	m9->set_metadata_ptr(&metadataVec[9]);
	m9->set_user_id(0x7FFFFFFFFFFFFFFB);
	m9->set_username("username");
	M3* m3 = m7->mutable_media();
	m3->set_metadata_ptr(&metadataVec[3]);
	m3->set_media_id(0x7FFFFFFFFFFFFFFC);
	m3->set_media_type("media_type");
	M6::M7::M10* m10 = m7->mutable_urls();
	m10->set_metadata_ptr(&metadataVec[10]);
	m10->set_shortened_url("shortened_url");
	m10->set_expanded_url("expanded_url");
	m7->set_timestamp(0x7FFFFFFFFFFFFFFD);
	m7->set_post_type(M6::M7::E1::REPOST);
}

  M1 m1, m1_other;
  M2 m2, m2_other;
  M4 m4, m4_other;
  M5 m5, m5_other;
  M6 m6, m6_other;

inline M_base* BenchmarkInit(size_t idx, Metadata *metadataVec, size_t *messageSizeVec) {
  vector<M_base*> messages;
  RegisterTestClass(metadataVec);
  InitMessageSizeVec(messageSizeVec);
  messages.push_back(&m1);
	messages.push_back(&m2);
	messages.push_back(&m4);
	messages.push_back(&m5);
	messages.push_back(&m6);
  // PRE_SET_HOOK;
  M1_Set_F1(&m1, metadataVec);
	M2_Set_F1(&m2, metadataVec);
	M4_Set_F1(&m4, metadataVec);
	M5_Set_F1(&m5, metadataVec);
	M6_Set_F1(&m6, metadataVec);
  return messages[idx];
}