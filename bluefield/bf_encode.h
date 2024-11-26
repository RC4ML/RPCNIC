#pragma once
#include <string>
#include <cstring>
#include "config.h"
#include <functional>
#include "util.hpp"
using std::vector;
using std::string;

#define OFFSET_SIZE 4

std::function<void(uint64_t, uint64_t, size_t)> dma_func;
std::function<void(size_t)> wait_cq_func;
size_t dma_inner_local_buffer;
size_t dma_inner_remote_buffer;

size_t dma_inner_now_offset = 0;
size_t dma_ops = 0;

// #define ENCODE_EACH_TIME

// ZigZag Transform:  Encodes signed integers so that they can be
// effectively used with varint encoding.
//
// varint operates on unsigned integers, encoding smaller numbers into
// fewer bytes.  If you try to use it on a signed integer, it will treat
// this number as a very large unsigned integer, which means that even
// small signed numbers like -1 will take the maximum number of bytes
// (10) to encode.  ZigZagEncode() maps signed integers to unsigned
// in such a way that those with a small absolute value will have smaller
// encoded values, making them appropriate for encoding using varint.
//
//       int32_t ->     uint32_t
// -------------------------
//           0 ->          0
//          -1 ->          1
//           1 ->          2
//          -2 ->          3
//         ... ->        ...
//  2147483647 -> 4294967294
// -2147483648 -> 4294967295
//
//        >> encode >>
//        << decode <<

inline uint32_t ZigZagEncode32(int32_t n) {
  // Note:  the right-shift must be arithmetic
  // Note:  left shift must be unsigned because of overflow
  return (static_cast<uint32_t>(n) << 1) ^ static_cast<uint32_t>(n >> 31);
}

inline uint64_t ZigZagEncode64(int64_t n) {
  // Note:  the right-shift must be arithmetic
  // Note:  left shift must be unsigned because of overflow
  return (static_cast<uint64_t>(n) << 1) ^ static_cast<uint64_t>(n >> 63);
}

static uint32_t Log2FloorNonZero64(uint64_t n) {
  // Older versions of clang run into an instruction-selection failure when
  // it encounters __builtin_clzll:
  // https://bugs.chromium.org/p/nativeclient/issues/detail?id=4395
  // This includes arm-nacl-clang and clang in older Android NDK versions.
  // To work around this, when we build with those we use the portable
  // implementation instead.
  return 63 ^ static_cast<uint32_t>(__builtin_clzll(n));
}

static uint32_t Log2FloorNonZero(uint32_t n) {
  return 31 ^ static_cast<uint32_t>(__builtin_clz(n));
}

inline size_t VarintSize32(uint32_t value) {
  // This computes value == 0 ? 1 : floor(log2(value)) / 7 + 1
  // Use an explicit multiplication to implement the divide of
  // a number in the 1..31 range.
  // Explicit OR 0x1 to avoid calling Bits::Log2FloorNonZero(0), which is
  // undefined.
  uint32_t log2value = Log2FloorNonZero(value | 0x1);
  return static_cast<size_t>((log2value * 9 + 73) / 64);
}

inline size_t VarintSize64(uint64_t value) {
  // This computes value == 0 ? 1 : floor(log2(value)) / 7 + 1
  // Use an explicit multiplication to implement the divide of
  // a number in the 1..63 range.
  // Explicit OR 0x1 to avoid calling Bits::Log2FloorNonZero(0), which is
  // undefined.
  uint32_t log2value = Log2FloorNonZero64(value | 0x1);
  return static_cast<size_t>((log2value * 9 + 73) / 64);
}

inline size_t VarintSize32SignExtended(int32_t value) {
  return VarintSize64(static_cast<uint64_t>(int64_t{ value }));
}

inline size_t LengthDelimitedSize(size_t length) {
  // The static_cast here prevents an error in certain compiler configurations
  // but is not technically correct--if length is too large to fit in a uint32_t
  // then it will be silently truncated. We will need to fix this if we ever
  // decide to start supporting serialized messages greater than 2 GiB in size.
  return length + VarintSize32(static_cast<uint32_t>(length));
}

inline size_t Int32Size(int32_t value) {
  return VarintSize32SignExtended(value);
}

inline size_t Int64Size(int64_t value) {
  return VarintSize64(static_cast<uint64_t>(value));
}

inline size_t UInt64Size(uint64_t value) {
  return VarintSize64(value);
}

inline size_t UInt32Size(uint32_t value) {
  return VarintSize32(value);
}

inline size_t SInt32Size(int32_t value) {
  return VarintSize32(ZigZagEncode32(value));
}

inline size_t EnumSize(int value) {
  return VarintSize32SignExtended(value);
}

inline size_t StringSize(const std::string &value) {
  return LengthDelimitedSize(value.size());
}

// Helper functions for converting between floats/doubles and IEEE-754
// uint32s/uint64s so that they can be written.  (Assumes your platform
// uses IEEE-754 floats.)
template<typename To, typename From>
inline To bit_cast(const From &from) {
  static_assert(sizeof(From) == sizeof(To), "bit_cast_with_different_sizes");
  To dest;
  memcpy(&dest, &from, sizeof(dest));
  return dest;
}

inline uint32_t EncodeFloat(float value) {
  return bit_cast<uint32_t>(value);
}

inline uint64_t EncodeDouble(double value) {
  return bit_cast<uint64_t>(value);
}

template <typename T>
inline static uint8_t *UnsafeVarint(T value, uint8_t *ptr) {
  static_assert(std::is_unsigned<T>::value,
    "Varint serialization must be unsigned");
  ptr[0] = static_cast<uint8_t>(value);
  if (value < 0x80) {
    return ptr + 1;
  }
  // Turn on continuation bit in the byte we just wrote.
  ptr[0] |= static_cast<uint8_t>(0x80);
  value >>= 7;
  ptr[1] = static_cast<uint8_t>(value);
  if (value < 0x80) {
    return ptr + 2;
  }
  ptr += 2;
  do {
    // Turn on continuation bit in the byte we just wrote.
    ptr[-1] |= static_cast<uint8_t>(0x80);
    value >>= 7;
    *ptr = static_cast<uint8_t>(value);
    ++ptr;
  } while (value >= 0x80);
  return ptr;
}

inline uint8_t *WriteLittleEndian64ToArray(uint64_t value, uint8_t *target) {
  memcpy(target, &value, sizeof(value));
  return target + sizeof(value);
}

inline uint8_t *WriteLittleEndian32ToArray(uint32_t value, uint8_t *target) {
  memcpy(target, &value, sizeof(value));
  return target + sizeof(value);
}

inline uint8_t *WriteVarint32SignExtendedToArray(int32_t value, uint8_t *target) {
  return UnsafeVarint(static_cast<uint64_t>(value), target);
}

inline uint8_t *WriteVarint32ToArray(uint32_t value, uint8_t *target) {
  return UnsafeVarint(value, target);
}

inline uint8_t *WriteVarint64ToArray(uint64_t value, uint8_t *target) {
  return UnsafeVarint(value, target);
}

inline uint8_t *WriteInt32NoTagToArray(int32_t value, uint8_t *target) {
  return WriteVarint32SignExtendedToArray(value, target);
}

inline uint8_t *WriteInt64NoTagToArray(int64_t value, uint8_t *target) {
  return WriteVarint64ToArray(static_cast<uint64_t>(value), target);
}

inline uint8_t *WriteUInt64NoTagToArray(uint64_t value, uint8_t *target) {
  return WriteVarint64ToArray(value, target);
}

inline uint8_t *WriteBoolNoTagToArray(bool value, uint8_t *target) {
  return WriteVarint32ToArray(value ? 1 : 0, target);
}

inline uint8_t *WriteSInt32NoTagToArray(int32_t value, uint8_t *target) {
  return WriteVarint32ToArray(ZigZagEncode32(value), target);
}

inline uint8_t *WriteDoubleNoTagToArray(double value, uint8_t *target) {
  return WriteLittleEndian64ToArray(EncodeDouble(value), target);
}

inline uint8_t *WriteFloatNoTagToArray(float value, uint8_t *target) {
  return WriteLittleEndian32ToArray(EncodeFloat(value), target);
}

inline uint8_t *WriteFixed64NoTagToArray(uint64_t value, uint8_t *target) {
  return WriteLittleEndian64ToArray(value, target);
}

inline uint8_t *WriteFixed32NoTagToArray(uint32_t value, uint8_t *target) {
  return WriteLittleEndian32ToArray(value, target);
}

inline uint8_t *WriteLengthToArray(uint16_t current_field_size, uint8_t *target) {
  memcpy(target, &current_field_size, 2);
  return target + 2;
}

inline uint8_t *WriteTagToArray(uint32_t field_number, uint32_t type, uint8_t *target) {
  uint32_t value = (field_number << 3) | type;
  return WriteVarint32ToArray(value, target);
}

inline uint8_t *WriteInt32ToArray(int field_number, int32_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_VARINT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(int32_t));
  dma_inner_now_offset += round_up(sizeof(int32_t), 64);
  wait_cq_func(1);
#endif
  return WriteInt32NoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedInt32ToArray(int field_number, vector<int32_t> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += Int32Size(value[j]);
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteInt32NoTagToArray(value[i], target);
  }
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(int32_t) * value.size());
  dma_inner_now_offset += round_up(sizeof(int32_t) * value.size(), 64);
  wait_cq_func(1);
#endif
  return target;
}

inline uint8_t *WritePtrToArray(int field_number, int32_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  return WriteInt32NoTagToArray(value, target);
}

inline uint8_t *WriteClassIdToArray(int field_number, int32_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_START_GROUP_TYPE, target);
  return WriteInt32NoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedPtrToArray(int field_number, uint32_t *temp_id_array, uint32_t temp_id_array_size, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < temp_id_array_size; ++j) {
    length += Int32Size(temp_id_array[j]);
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < temp_id_array_size; i++) {
    target = WriteInt32NoTagToArray(temp_id_array[i], target);
  }
  return target;
}

inline uint8_t *WriteInt64ToArray(int field_number, int64_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_VARINT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(int64_t));
  dma_inner_now_offset += round_up(sizeof(int32_t), 64);
  wait_cq_func(1);
#endif
  return WriteInt64NoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedInt64ToArray(int field_number, vector<int64_t> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += Int64Size(value[j]);
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteInt64NoTagToArray(value[i], target);
  }
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(int64_t) * value.size());
  dma_inner_now_offset += round_up(sizeof(int64_t) * value.size(), 64);
  wait_cq_func(1);
#endif
  return target;
}

inline uint8_t *WriteUInt64ToArray(int field_number, uint64_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_VARINT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(uint64_t));
  dma_inner_now_offset += round_up(sizeof(uint64_t), 64);
  wait_cq_func(1);
#endif
  return WriteUInt64NoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedUInt64ToArray(int field_number, vector<uint64_t> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += UInt64Size(value[j]);
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteUInt64NoTagToArray(value[i], target);
  }
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(uint64_t) * value.size());
  dma_inner_now_offset += round_up(sizeof(uint64_t) * value.size(), 64);
  wait_cq_func(1);
#endif

  return target;
}

inline uint8_t *WriteUInt32ToArray(int field_number, uint32_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_VARINT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(uint32_t));
  dma_inner_now_offset += round_up(sizeof(uint32_t), 64);
  wait_cq_func(1);
#endif

  return WriteVarint32ToArray(value, target);
}

inline uint8_t *WriteRepeatedUInt32ToArray(int field_number, vector<uint32_t> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += UInt32Size(value[j]);
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteVarint32ToArray(value[i], target);
  }
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, sizeof(uint32_t) * value.size());
  dma_inner_now_offset += round_up(sizeof(uint32_t) * value.size(), 64);
  wait_cq_func(1);
#endif

  return target;
}

inline uint8_t *WriteBoolToArray(int field_number, bool value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_VARINT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 4);
  dma_inner_now_offset += round_up(4, 64);
  wait_cq_func(1);
#endif

  return WriteBoolNoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedBoolToArray(int field_number, vector<uint8_t> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += 1;
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteBoolNoTagToArray(value[i], target);
  }

#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 4 * value.size());
  dma_inner_now_offset += round_up(4 * value.size(), 64);
  wait_cq_func(1);
#endif

  return target;
}

inline uint8_t *WriteSInt32ToArray(int field_number, int32_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_VARINT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 4);
  dma_inner_now_offset += round_up(4, 64);
  wait_cq_func(1);
#endif
  return WriteSInt32NoTagToArray(value, target);
}

inline uint8_t *WriteDoubleToArray(int field_number, double value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_64BIT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 8);
  dma_inner_now_offset += round_up(8, 64);
  wait_cq_func(1);
#endif
  return WriteDoubleNoTagToArray(value, target);
}

inline uint8_t *WriteFloatToArray(int field_number, float value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_32BIT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 4);
  dma_inner_now_offset += round_up(4, 64);
  wait_cq_func(1);
#endif
  return WriteFloatNoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedFloatToArray(int field_number, vector<float> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += 4;
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteFloatNoTagToArray(value[i], target);
  }
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 4 * value.size());
  dma_inner_now_offset += round_up(4 * value.size(), 64);
  wait_cq_func(1);
#endif
  return target;
}

inline uint8_t *WriteEnumToArray(int field_number, int32_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_VARINT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 4);
  dma_inner_now_offset += round_up(4, 64);
  wait_cq_func(1);
#endif
  return WriteInt32NoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedEnumToArray(int field_number, vector<int32_t> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += EnumSize(value[j]);
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteInt32NoTagToArray(value[i], target);
  }
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 4 * value.size());
  dma_inner_now_offset += round_up(4 * value.size(), 64);
  wait_cq_func(1);
#endif
  return target;
}

// inline uint8_t* WriteMessageToArray(int field_number, EmbedMsg* submessage, size_t submessage_size, size_t offset, uint8_t* target, uint8_t* target_backup) {
//   target = WriteTagToArray(field_number, ptr_type, target);
//   target = WriteVarint32ToArray(static_cast<uint32_t>(submessage_size), target);
//   target = WriteFixed32NoTagToArray(static_cast<uint32_t>(offset), target);
//   // submessage->serialize(target_backup + offset);
//   return target;
// }

inline uint8_t *WriteFixed64ToArray(int field_number, uint64_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_64BIT_TYPE, target);
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 8);
  dma_inner_now_offset += round_up(8, 64);
  wait_cq_func(1);
#endif
  return WriteFixed64NoTagToArray(value, target);
}

inline uint8_t *WriteRepeatedFixed64ToArray(int field_number, vector<uint64_t> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += 8;
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteFixed64NoTagToArray(value[i], target);
  }
#ifdef ENCODE_EACH_TIME
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 8 * value.size());
  dma_inner_now_offset += round_up(8 * value.size(), 64);
  wait_cq_func(1);
#endif
  return target;
}

inline uint8_t *WriteFixed32ToArray(int field_number, uint32_t value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_32BIT_TYPE, target);
  return WriteFixed32NoTagToArray(value, target);
}

inline uint8_t *WriteStringToArray(int field_number, const std::string &s, uint8_t *target) {
  size_t s_size = s.size();
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  target = WriteVarint32ToArray(static_cast<uint32_t>(s_size), target);
  memcpy(target, s.data(), s_size);
#ifdef ENCODE_EACH_TIME 
  size_t ops = 0;
  size_t now_size = s_size;
  while (now_size > 2097152) {
    dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    ops++;
    now_size -= 2097152;
  }
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, now_size);
  dma_inner_now_offset += round_up(now_size, 64);
  wait_cq_func(++ops);
#endif
  return target + s_size;
}

inline uint8_t *WriteStringNoTagToArray(int field_number, const std::string &s, uint8_t *target) {
  size_t s_size = s.size();
  target = WriteVarint32ToArray(static_cast<uint32_t>(s_size), target);
  memcpy(target, s.data(), s_size);
#ifdef ENCODE_EACH_TIME 
  size_t ops = 0;
  size_t now_size = s_size;
  while (now_size > 2097152) {
    dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    ops++;
    now_size -= 2097152;
  }
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, now_size);
  dma_inner_now_offset += round_up(now_size, 64);
  wait_cq_func(++ops);
#endif
  return target + s_size;
}

inline uint8_t *WriteRepeatedStringToArray(int field_number, vector<string> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    length += StringSize(value[j]);
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteStringNoTagToArray(0, value[i], target);
  }
#ifdef ENCODE_EACH_TIME 
  size_t ops = 0;
  size_t now_size = length;
  while (now_size > 2097152) {
    dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    ops++;
    now_size -= 2097152;
  }
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, now_size);
  dma_inner_now_offset += round_up(now_size, 64);
  wait_cq_func(++ops);
#endif
  return target;
}

inline uint8_t *WriteSkipRepeatedStringToArray(int field_number, vector<string> &value, uint8_t *target, string &skip_field) {
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  uint32_t length = 0;
  for (int j = 0; j < value.size(); ++j) {
    if ((value[j].size() > 1024)) {
      length += StringSize(skip_field);
    } else {
      length += StringSize(value[j]);
    }
  }
  target = WriteVarint32ToArray(length, target);
  for (int i = 0; i < value.size(); i++) {
    if ((value[i].size() > 1024)) {
      target = WriteStringNoTagToArray(0, skip_field, target);
    } else {
      target = WriteStringNoTagToArray(0, value[i], target);
    }
  }
#ifdef ENCODE_EACH_TIME 
  size_t ops = 0;
  size_t now_size = length;
  while (now_size > 2097152) {
    dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    ops++;
    now_size -= 2097152;
  }
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, now_size);
  dma_inner_now_offset += round_up(now_size, 64);
  wait_cq_func(++ops);
#endif
  return target;
}

inline uint8_t *WriteBytesToArray(int field_number, const std::string &s, uint8_t *target) {
  size_t s_size = s.size();
  target = WriteTagToArray(field_number, PROTOBUF_LENGTH_DELIMITED_TYPE, target);
  target = WriteVarint32ToArray(static_cast<uint32_t>(s_size), target);
  memcpy(target, s.data(), s_size);
#ifdef ENCODE_EACH_TIME 
  size_t ops = 0;
  size_t now_size = s_size;
  while (now_size > 2097152) {
    dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    ops++;
    now_size -= 2097152;
  }
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, now_size);
  dma_inner_now_offset += round_up(now_size, 64);
  wait_cq_func(++ops);
#endif
  return target + s_size;
}

inline uint8_t *WriteBytesNoTagToArray(int field_number, const std::string &s, uint8_t *target) {
  size_t s_size = s.size();
  target = WriteVarint32ToArray(static_cast<uint32_t>(s_size), target);
  memcpy(target, s.data(), s_size);
#ifdef ENCODE_EACH_TIME 
  size_t ops = 0;
  size_t now_size = s_size;
  while (now_size > 2097152) {
    dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    ops++;
    now_size -= 2097152;
  }
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, now_size);
  dma_inner_now_offset += round_up(now_size, 64);
  wait_cq_func(++ops);
#endif
  return target + s_size;
}

inline uint8_t *WriteRepeatedBytesToArray(int field_number, vector<string> &value, uint8_t *target) {
  target = WriteTagToArray(field_number, sw_repeated_bytes_type, target);
  target = WriteVarint32ToArray(static_cast<uint32_t>(value.size()), target);
  for (int i = 0; i < value.size(); i++) {
    target = WriteBytesNoTagToArray(0, value[i], target);
  }

#ifdef ENCODE_EACH_TIME 
  size_t ops = 0;
  size_t now_size = 0;
  for (auto &s : value) {
    now_size += s.size();
  }
  while (now_size > 2097152) {
    dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    ops++;
    now_size -= 2097152;
  }
  dma_func(dma_inner_local_buffer + dma_inner_now_offset, dma_inner_remote_buffer + dma_inner_now_offset, now_size);
  dma_inner_now_offset += round_up(now_size, 64);
  wait_cq_func(++ops);
#endif
  return target;
}