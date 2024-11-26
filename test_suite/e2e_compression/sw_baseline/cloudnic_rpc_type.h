#pragma once
#include <cstdint>
#include <cstddef>

enum class RPC_TYPE: uint8_t {
    RPC_PING = 0,
    RPC_APP1,
    RPC_APP2,
};

class CommonReq {
public:
    RPC_TYPE type;
    // for debug
    uint32_t req_number;
} __attribute__((packed));

class CommonResp {
public:
    RPC_TYPE type;
    // for debug
    uint32_t req_number;
    int status;
} __attribute__((packed));

template<class T>
class RPCMsgReq {
public:
    CommonReq req_common;
    T req_control;
    explicit RPCMsgReq(RPC_TYPE t, uint32_t num, T req): req_common{ t, num }, req_control(req) {}
}__attribute__((packed));

template<class T>
class RPCMsgResp {
public:
    CommonResp resp_common;
    T resp_control;
    explicit RPCMsgResp(RPC_TYPE t, uint32_t num, int status, T resp): resp_common{ t, num, status }, resp_control(resp) {}
}__attribute__((packed));

class PingRPCReq {
public:
    size_t timestamp;
};

class PingRPCResp {
public:
    size_t timestamp;
};

class CommonRPCReq {
public:
    size_t data_length;
};

class CommonRPCResp {
public:
    size_t data_length;
};