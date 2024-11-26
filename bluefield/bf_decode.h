#pragma once
#include <string>
#include <cstring>
#include <functional>

std::function<void(uint64_t, uint64_t, size_t)> dma_func;

size_t dma_inner_local_buffer;
size_t dma_inner_remote_buffer;

size_t dma_inner_now_offset = 0;
size_t dma_ops = 0;
size_t decoding_tsc = 0;

// #define DECODE_EACH_TIME

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

inline const char *ReadTag(const char *p, uint32_t *tag, uint32_t *wire_type) {
  uint32_t res0 = static_cast<uint8_t>(p[0]);
  *wire_type = res0;
  return p + 1;
};

std::pair<const char *, uint32_t> VarintParseSlow32(const char *p,
  uint32_t res) {
  for (std::uint32_t i = 2; i < 5; i++) {
    uint32_t byte = static_cast<uint8_t>(p[i]);
    res += (byte - 1) << (7 * i);
    if (byte < 128) {
      return { p + i + 1, res };
    }
  }
  // Accept >5 bytes
  for (std::uint32_t i = 5; i < 10; i++) {
    uint32_t byte = static_cast<uint8_t>(p[i]);
    if (byte < 128) {
      return { p + i + 1, res };
    }
  }
  return { nullptr, 0 };
}

std::pair<const char *, uint64_t> VarintParseSlow64(const char *p,
  uint32_t res32) {
  uint64_t res = res32;
  for (std::uint32_t i = 2; i < 10; i++) {
    uint64_t byte = static_cast<uint8_t>(p[i]);
    res += (byte - 1) << (7 * i);
    if (byte < 128) {
      return { p + i + 1, res };
    }
  }
  return { nullptr, 0 };
}

inline const char *VarintParseSlow(const char *p, uint32_t res, uint32_t *out) {
  auto tmp = VarintParseSlow32(p, res);
  *out = tmp.second;
  return tmp.first;
}

inline const char *VarintParseSlow(const char *p, uint32_t res, uint64_t *out) {
  auto tmp = VarintParseSlow64(p, res);
  *out = tmp.second;
  return tmp.first;
}

template <typename T>
const char *VarintParse(const char *p, T *out) {
  auto ptr = reinterpret_cast<const uint8_t *>(p);
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

inline uint64_t ReadVarint64(const char **p) {
  size_t now_tsc = get_tsc();
  uint64_t tmp;
  *p = VarintParse(*p, &tmp);
  decoding_tsc += get_tsc() - now_tsc;

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(uint64_t));
  dma_inner_now_offset += round_up(sizeof(uint64_t), 64);
  dma_ops++;
#endif

  return tmp;
};

inline uint16_t ReadFieldLength(const char **p) {
  uint16_t res;
  memcpy(&res, *p, sizeof(uint16_t));
  *p += sizeof(uint16_t);

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(uint16_t));
  dma_inner_now_offset += round_up(sizeof(uint16_t), 64);
  dma_ops++;
#endif

  return res;
};

inline uint32_t ReadFixed32(const char **p) {
  uint32_t res;
  memcpy(&res, *p, sizeof(uint32_t));
  *p += sizeof(uint32_t);

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(uint32_t));
  dma_inner_now_offset += round_up(sizeof(uint32_t), 64);
  dma_ops++;
#endif

  return res;
}

inline uint64_t ReadFixed64(const char **p) {
  uint64_t res;
  memcpy(&res, *p, sizeof(uint64_t));
  *p += sizeof(uint64_t);

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(uint64_t));
  dma_inner_now_offset += round_up(sizeof(uint64_t), 64);
  dma_ops++;
#endif

  return res;
}

inline double ReadDouble(const char **p) {
  uint64_t res;
  memcpy(&res, *p, sizeof(double));
  *p += sizeof(double);

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(double));
  dma_inner_now_offset += round_up(sizeof(double), 64);
  dma_ops++;
#endif

  return DecodeDouble(res);
}

inline float ReadFloat(const char **p) {
  uint32_t res;
  memcpy(&res, *p, sizeof(float));
  *p += sizeof(float);

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(float));
  dma_inner_now_offset += round_up(sizeof(float), 64);
  dma_ops++;
#endif

  return DecodeFloat(res);
}

inline uint32_t ReadVarint32(const char **p) {
  size_t now_tsc = get_tsc();
  uint32_t tmp;
  *p = VarintParse<uint32_t>(*p, &tmp);
  decoding_tsc += get_tsc() - now_tsc;

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(uint32_t));
  dma_inner_now_offset += round_up(sizeof(uint32_t), 64);
  dma_ops++;
#endif

  return tmp;
};

inline int32_t ReadVarintZigZag32(const char **p) {
  size_t now_tsc = get_tsc();
  uint64_t tmp;
  *p = VarintParse(*p, &tmp);
  decoding_tsc += get_tsc() - now_tsc;

#ifdef DECODE_EACH_TIME
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, sizeof(uint32_t));
  dma_inner_now_offset += round_up(sizeof(uint32_t), 64);
  dma_ops++;
#endif

  return ZigZagDecode32(static_cast<uint32_t>(tmp));
}

__attribute__((warn_unused_result))
const char *ReadString(const char *ptr, int size,
  std::string *s) {
  s->assign(ptr, size);

#ifdef DECODE_EACH_TIME
  while (size > 2097152) {
    dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, 2097152);
    dma_inner_now_offset += 2097152;
    dma_ops++;
    size -= 2097152;
  }
  dma_func(dma_inner_remote_buffer + dma_inner_now_offset, dma_inner_local_buffer + dma_inner_now_offset, size);
  dma_inner_now_offset += round_up(size, 64);
  dma_ops++;
#endif

  return ptr + size;
};