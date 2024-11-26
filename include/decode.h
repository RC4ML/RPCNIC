#pragma once
#include <string>
#include <cstring>

inline int32_t ZigZagDecode32(uint32_t n) {
  // Note:  Using unsigned types prevent undefined behavior
  return static_cast<int32_t>((n >> 1) ^ (~(n & 1) + 1));
}

inline int64_t ZigZagDecode64(uint64_t n) {
  // Note:  Using unsigned types prevent undefined behavior
  return static_cast<int64_t>((n >> 1) ^ (~(n & 1) + 1));
}

inline float DecodeFloat(uint32_t value) {
  return bit_cast<float>(value);
}

inline double DecodeDouble(uint64_t value) {
  return bit_cast<double>(value);
}

inline const char* ReadTag(const char* p, uint32_t* tag, uint32_t* wire_type){
    uint32_t res0 = static_cast<uint8_t>(p[0]);
    *wire_type = res0;
    return p + 1;
};

std::pair<const char*, uint32_t> VarintParseSlow32(const char* p,
                                                   uint32_t res) {
  for (std::uint32_t i = 2; i < 5; i++) {
    uint32_t byte = static_cast<uint8_t>(p[i]);
    res += (byte - 1) << (7 * i);
    if (byte < 128) {
      return {p + i + 1, res};
    }
  }
  // Accept >5 bytes
  for (std::uint32_t i = 5; i < 10; i++) {
    uint32_t byte = static_cast<uint8_t>(p[i]);
    if (byte < 128) {
      return {p + i + 1, res};
    }
  }
  return {nullptr, 0};
}

std::pair<const char*, uint64_t> VarintParseSlow64(const char* p,
                                                   uint32_t res32) {
  uint64_t res = res32;
  for (std::uint32_t i = 2; i < 10; i++) {
    uint64_t byte = static_cast<uint8_t>(p[i]);
    res += (byte - 1) << (7 * i);
    if (byte < 128) {
      return {p + i + 1, res};
    }
  }
  return {nullptr, 0};
}

inline const char* VarintParseSlow(const char* p, uint32_t res, uint32_t* out) {
  auto tmp = VarintParseSlow32(p, res);
  *out = tmp.second;
  return tmp.first;
}

inline const char* VarintParseSlow(const char* p, uint32_t res, uint64_t* out) {
  auto tmp = VarintParseSlow64(p, res);
  *out = tmp.second;
  return tmp.first;
}

template <typename T>
const char* VarintParse(const char* p, T* out) {
  auto ptr = reinterpret_cast<const uint8_t*>(p);
  uint32_t res = ptr[0];
  if (!(res & 0x80)) {
    *out = res;
    return p + 1;
  }
  uint32_t byte = ptr[1];
  res += (byte - 1) << 7;
  if (!(byte & 0x80)) {
    *out = res;
    return p + 2;
  }
  return VarintParseSlow(p, res, out);
}

inline uint64_t ReadVarint64(const char** p) {
    uint64_t tmp;
    *p = VarintParse(*p, &tmp);
    return tmp;
};

inline uint16_t ReadFieldLength(const char** p) {
  uint16_t res;
  memcpy(&res, *p, sizeof(uint16_t));
  *p += sizeof(uint16_t);
  return res;
};

inline uint32_t ReadFixed32(const char** p) {
  uint32_t res;
  memcpy(&res, *p, sizeof(uint32_t));
  *p += sizeof(uint32_t);
  return res;
}

inline uint64_t ReadFixed64(const char** p) {
  uint64_t res;
  memcpy(&res, *p, sizeof(uint64_t));
  *p += sizeof(uint64_t);
  return res;
}

inline double ReadDouble(const char** p) {
  uint64_t res;
  memcpy(&res, *p, sizeof(double));
  *p += sizeof(double);
  return DecodeDouble(res);
}

inline float ReadFloat(const char** p) {
  uint32_t res;
  memcpy(&res, *p, sizeof(float));
  *p += sizeof(float);
  return DecodeFloat(res);
}

inline uint32_t ReadVarint32(const char** p) {
    uint32_t tmp;
    *p = VarintParse<uint32_t>(*p, &tmp);
    return tmp;
};

inline int32_t ReadVarintZigZag32(const char** p) {
    uint64_t tmp;
    *p = VarintParse(*p, &tmp);
    return ZigZagDecode32(static_cast<uint32_t>(tmp));
}

__attribute__((warn_unused_result))
const char* ReadString(const char* ptr, int size,
                                            std::string* s) {
    s->assign(ptr, size);
    return ptr + size;
};