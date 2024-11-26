// APP1: 反序列化 -> aes解密 -> LZ4压缩 -> aes加密  -> 序列化
// APP2: 

#pragma once

#include <gflags/gflags.h>
#include <csignal>
#include <app_helpers.h>
#include "rpc.h"
#include "cloudnic_rpc_type.h"
#include "atomic_queue/atomic_queue.h"
#include "spinlock_mutex.h"

DEFINE_uint64(test_loop, 10, "Test loop");

DEFINE_uint64(concurrency, 0, "Concurrency for each request, 1 means sync methods, >1 means async methods");

DEFINE_string(numa_0_ports, "", "Fabric ports on NUMA node 0, CSV, no spaces");
// maybe empty
DEFINE_string(numa_1_ports, "", "Fabric ports on NUMA node 1, CSV, no spaces");

// this node server address
DEFINE_string(server_addr, "127.0.0.1:1234", "Server(self) address, format ip:port");
// remote address
DEFINE_string(remote_addr, "192.168.189.8:1234", "Remote address, format ip:port");

// this node
DEFINE_uint64(client_num, 1, "Client(forward usage) thread num, must >0 and <DPDK_QUEUE_NUM");
// this node
DEFINE_uint64(server_num, 1, "Server(self) thread num, must >0 and <DPDK_QUEUE_NUM");

DEFINE_uint64(numa_client_node, 0, "NUMA node for client threads, must be 0 or 1");

DEFINE_uint64(numa_server_node, 0, "NUMA node for server threads, must be 0 or 1");

DEFINE_uint64(timeout_second, UINT64_MAX, "Timeout second for each request, default(UINT64_MAX) means no timeout");

DEFINE_string(latency_file, "latency.txt", "Latency file name");
DEFINE_string(bandwidth_file, "bandwidth.txt", "Bandwidth file name");

using SPSC_QUEUE = atomic_queue::AtomicQueueB2<erpc::MsgBuffer, std::allocator<erpc::MsgBuffer>, true, false, false>;
using MPMC_QUEUE = atomic_queue::AtomicQueueB2<erpc::MsgBuffer, std::allocator<erpc::MsgBuffer>, true, false, false>;


static constexpr size_t kAppMaxConcurrency = 128;       // Outstanding reqs per thread
static constexpr size_t kAppMaxRPC = 12;                // Outstanding rpcs per thread, used for RMEM_BASED

static constexpr size_t kAppMaxBuffer = kAppMaxConcurrency * kAppMaxRPC * 10;

static constexpr size_t kAppEvLoopMs = 1000; // Duration of event loop

constexpr unsigned char aes_key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key

volatile sig_atomic_t ctrl_c_pressed = 0;

#define USE_SERIALIZATION 1

void ctrl_c_handler(int) { ctrl_c_pressed = 1; }

std::vector<size_t> flags_get_numa_ports(size_t numa_node) {
    rmem::rt_assert(numa_node <= 1); // Only NUMA 0 and 1 supported for now
    std::vector<size_t> ret;

    std::string port_str =
        numa_node == 0 ? FLAGS_numa_0_ports : FLAGS_numa_1_ports;
    if (port_str.empty())
        return ret;

    std::vector<std::string> split_vec = rmem::split(port_str, ',');
    rmem::rt_assert(!split_vec.empty());

    for (auto &s : split_vec)
        ret.push_back(std::stoull(s)); // stoull trims ' '

    return ret;
}

class BasicContext {
public:
    erpc::Rpc<erpc::CTransport> *rpc_;
    std::vector<int> session_num_vec_;
    size_t num_sm_resps_ = 0; // Number of SM responses
};

/// A basic session management handler that expects successful responses
/// used for client side
void basic_sm_handler_client(int session_num, int remote_session_num, erpc::SmEventType sm_event_type,
    erpc::SmErrType sm_err_type, void *_context) {
    _unused(remote_session_num);
    printf("client sm_handler receive: session_num:%d\n", session_num);
    auto *c = static_cast<BasicContext *>(_context);
    c->num_sm_resps_++;
    rmem::rt_assert(
        sm_err_type == erpc::SmErrType::kNoError,
        "SM response with error " + erpc::sm_err_type_str(sm_err_type));

    if (!(sm_event_type == erpc::SmEventType::kConnected ||
        sm_event_type == erpc::SmEventType::kDisconnected)) {
        throw std::runtime_error("Received unexpected SM event.");
    }
}

/// A basic session management handler that expects successful responses
/// used for server side
void basic_sm_handler_server(int session_num, int remote_session_num, erpc::SmEventType sm_event_type,
    erpc::SmErrType sm_err_type, void *_context) {
    _unused(remote_session_num);

    auto *c = static_cast<BasicContext *>(_context);
    c->num_sm_resps_++;

    rmem::rt_assert(
        sm_err_type == erpc::SmErrType::kNoError,
        "SM response with error " + erpc::sm_err_type_str(sm_err_type));

    if (!(sm_event_type == erpc::SmEventType::kConnected ||
        sm_event_type == erpc::SmEventType::kDisconnected)) {
        throw std::runtime_error("Received unexpected SM event.");
    }

    c->session_num_vec_.push_back(session_num);
    printf("Server id %" PRIu8 ": Got session %d\n", c->rpc_->get_rpc_id(), session_num);
}

size_t get_bind_core(size_t numa) {
    static size_t numa0_core = 0;
    static size_t numa1_core = 0;
    static spinlock_mutex lock;
    size_t res;
    lock.lock();
    rmem::rt_assert(numa == 0 || numa == 1);
    if (numa == 0) {
        rmem::rt_assert(numa0_core <= rmem::num_lcores_per_numa_node());
        res = numa0_core++;
    } else {
        rmem::rt_assert(numa1_core <= rmem::num_lcores_per_numa_node());
        res = numa1_core++;
    }
    lock.unlock();
    return res;
}
