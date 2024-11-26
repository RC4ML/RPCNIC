#pragma once
#include <hdr/hdr_histogram.h>
#include "../cloudnic.h"
#include "atomic_queue/atomic_queue.h"
#include <hs_clock.h>
#include "../AES.h"
#include "../cloudnic.pb.h"


std::vector<std::vector<rmem::Timer>> timers(kAppMaxRPC, std::vector<rmem::Timer>(kAppMaxConcurrency));
hdr_histogram *latency_hist_;

std::atomic<int> total_speed = 0;
spinlock_mutex total_speed_lock;

constexpr size_t IMG_SIZE = 4096;
unsigned char src_img[IMG_SIZE];
unsigned char encrypted_img[IMG_SIZE];
struct REQ_MSG {
    uint32_t req_id;
    RPC_TYPE req_type;
};

struct RESP_MSG {
    uint32_t req_id;
    int status;
};
static_assert(sizeof(REQ_MSG) == 8, "REQ_MSG size is not 8");
static_assert(sizeof(RESP_MSG) == 8, "RESP_MSG size is not 8");

class ClientContext: public BasicContext {

public:
    ClientContext(size_t cid): client_id_(cid) {
        spsc_queue = new atomic_queue::AtomicQueueB2<REQ_MSG, std::allocator<REQ_MSG>, true, false, true>(kAppMaxConcurrency);
    }
    ~ClientContext() {
        delete spsc_queue;
    }
    //
    void PushNextTCReq() {
        spsc_queue->push(REQ_MSG{ req_id_++, RPC_TYPE::RPC_APP1 });
    }
    erpc::MsgBuffer req_msgbuf[kAppMaxConcurrency];
    erpc::MsgBuffer resp_msgbuf[kAppMaxConcurrency];

    erpc::MsgBuffer ping_msgbuf;
    erpc::MsgBuffer ping_resp_msgbuf;

    size_t client_id_;
    uint32_t req_id_{};
    rmem::Timer now_timer;
    atomic_queue::AtomicQueueB2<REQ_MSG, std::allocator<REQ_MSG>, true, false, true> *spsc_queue;
};

class AppContext {
public:
    AppContext() {
        src_img[1] = 1;
        src_img[2] = 2;
        src_img[1001] = 3;
        src_img[1002] = 4;
        AES aes(AESKeyLength::AES_128);
        unsigned char *encrypted_img_tmp = aes.EncryptECB(reinterpret_cast<const unsigned char *>(src_img), IMG_SIZE, aes_key);
        memcpy(encrypted_img, encrypted_img_tmp, IMG_SIZE);
        delete encrypted_img_tmp;

        for (size_t i = 0; i < FLAGS_client_num; i++) {
            client_contexts_.push_back(new ClientContext(i));
        }
    }
    ~AppContext() {

        for (auto &ctx : client_contexts_) {
            delete ctx;
        }
    }

    std::vector<ClientContext *> client_contexts_;
};
