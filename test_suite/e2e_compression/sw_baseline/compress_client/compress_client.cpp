#include <thread>
#include "numautil.h"
#include "spinlock_mutex.h"
#include "compress_client.h"

std::atomic<uint64_t> ping_count = 0;
void connect_sessions(ClientContext *c) {
    int session_num = c->rpc_->create_session(FLAGS_remote_addr, c->client_id_);
    rmem::rt_assert(session_num >= 0, "Failed to create session");
    c->session_num_vec_.push_back(session_num);
    while (c->num_sm_resps_ != 1) {
        c->rpc_->run_event_loop(kAppEvLoopMs);
        if (unlikely(ctrl_c_pressed)) {
            printf("Ctrl-C pressed. Exiting\n");
            return;
        }
    }
}

void callback_ping(void *_context, void *_tag) {
    _unused(_tag);
    auto *ctx = static_cast<ClientContext *>(_context);

    auto *resp = reinterpret_cast<RPCMsgResp<PingRPCResp> *>(ctx->ping_resp_msgbuf.buf_);

    rmem::rt_assert(resp->resp_common.status == 0);
    ping_count++;
}


void handler_ping(ClientContext *ctx, REQ_MSG req_msg) {
    new (ctx->ping_msgbuf.buf_) RPCMsgReq<PingRPCReq>(RPC_TYPE::RPC_PING, req_msg.req_id, { SIZE_MAX });
    ctx->rpc_->enqueue_request(ctx->session_num_vec_[0], static_cast<uint8_t>(RPC_TYPE::RPC_PING),
        &ctx->ping_msgbuf, &ctx->ping_resp_msgbuf,
        callback_ping, nullptr);
}

void callback_compress(void *_context, void *_tag) {
    auto *ctx = static_cast<ClientContext *>(_context);
    auto req_id_ptr = reinterpret_cast<std::uintptr_t>(_tag);
    uint32_t req_id = req_id_ptr;
    hdr_record_value_atomic(latency_hist_,
        static_cast<int64_t>(timers[ctx->client_id_][req_id % FLAGS_concurrency].toc() * 10));
    ctx->req_id_++;
    ctx->spsc_queue->push(REQ_MSG{ static_cast<uint32_t>(ctx->req_id_), RPC_TYPE::RPC_APP1 });
}

void handler_compress(ClientContext *ctx, REQ_MSG req_msg) {
    erpc::MsgBuffer &req_msgbuf = ctx->req_msgbuf[req_msg.req_id % kAppMaxConcurrency];
    erpc::MsgBuffer &resp_msgbuf = ctx->resp_msgbuf[req_msg.req_id % kAppMaxConcurrency];

    new (req_msgbuf.buf_) RPCMsgReq<CommonRPCReq>(RPC_TYPE::RPC_APP1, req_msg.req_id, { req_msgbuf.get_data_size() - sizeof(RPCMsgReq<CommonRPCReq>) });

    timers[ctx->client_id_][req_msg.req_id % FLAGS_concurrency].tic();
    ctx->rpc_->enqueue_request(ctx->session_num_vec_[0], static_cast<uint8_t>(RPC_TYPE::RPC_APP1),
        &req_msgbuf, &resp_msgbuf,
        callback_compress, reinterpret_cast<void *>(req_msg.req_id));
}

void client_thread_func(size_t thread_id, ClientContext *ctx, erpc::Nexus *nexus) {
    ctx->client_id_ = thread_id;
    std::vector<size_t> port_vec = flags_get_numa_ports(0);
    uint8_t phy_port = port_vec.at(thread_id % port_vec.size());
    erpc::Rpc<erpc::CTransport> rpc(nexus, static_cast<void *>(ctx),
        static_cast<uint8_t>(thread_id + FLAGS_server_num),
        basic_sm_handler_client, phy_port);
    printf("client %p\n", reinterpret_cast<void *>(ctx));
    rpc.retry_connect_on_invalid_rpc_id_ = true;
    ctx->rpc_ = &rpc;

#if USE_SERIALIZATION
    cloudnic::CompressImgReq compress_img_req;
    compress_img_req.set_img_id(1);
    compress_img_req.set_img(std::string(reinterpret_cast<const char *>(encrypted_img)));
    std::string serialized_img = compress_img_req.SerializeAsString();
    for (size_t i = 0; i < kAppMaxConcurrency; i++) {
        // TODO
        ctx->req_msgbuf[i] = rpc.alloc_msg_buffer_or_die(sizeof(RPCMsgReq<PingRPCReq>) + serialized_img.size());
        memcpy(ctx->req_msgbuf[i].buf_ + sizeof(RPCMsgReq<PingRPCReq>), serialized_img.c_str(), serialized_img.size());
        ctx->resp_msgbuf[i] = rpc.alloc_msg_buffer_or_die(sizeof(RPCMsgReq<PingRPCReq>) + serialized_img.size());
    }
#else
    for (size_t i = 0; i < kAppMaxConcurrency; i++) {
        // TODO
        ctx->req_msgbuf[i] = rpc.alloc_msg_buffer_or_die(sizeof(RPCMsgReq<PingRPCReq>) + IMG_SIZE);
        memcpy(ctx->req_msgbuf[i].buf_ + sizeof(RPCMsgReq<PingRPCReq>), encrypted_img, IMG_SIZE);
        ctx->resp_msgbuf[i] = rpc.alloc_msg_buffer_or_die(sizeof(RPCMsgReq<PingRPCReq>) + IMG_SIZE);
    }
#endif


    ctx->ping_msgbuf = rpc.alloc_msg_buffer_or_die(sizeof(RPCMsgReq<PingRPCReq>));
    ctx->ping_resp_msgbuf = rpc.alloc_msg_buffer_or_die(sizeof(RPCMsgReq<PingRPCResp>));

    connect_sessions(ctx);

    using FUNC_HANDLER = std::function<void(ClientContext *, REQ_MSG)>;
    FUNC_HANDLER handlers[] = { handler_ping, handler_compress, nullptr };

    printf("begin to worke \n");
    while (true) {
        unsigned size = ctx->spsc_queue->was_size();
        for (unsigned i = 0; i < size; i++) {
            REQ_MSG req_msg = ctx->spsc_queue->pop();

            handlers[static_cast<uint8_t>(req_msg.req_type)](ctx, req_msg);
        }
        ctx->rpc_->run_event_loop_once();
        if (unlikely(ctrl_c_pressed)) {
            break;
        }
    }
    long us_time = ctx->now_timer.toc();
    total_speed.fetch_add(ctx->req_id_ * 1e6 * 1.0 / us_time);
}

void leader_thread_func() {
    erpc::Nexus nexus(FLAGS_server_addr, FLAGS_numa_server_node, 0);

    std::vector<std::thread> clients(FLAGS_client_num);
    auto *context = new AppContext();

    clients[0] = std::thread(client_thread_func, 0, context->client_contexts_[0], &nexus);
    sleep(2);
    rmem::bind_to_core(clients[0], FLAGS_numa_client_node, get_bind_core(FLAGS_numa_client_node));
    for (size_t i = 1; i < FLAGS_client_num; i++) {
        clients[i] = std::thread(client_thread_func, i, context->client_contexts_[i], &nexus);
        rmem::bind_to_core(clients[i], FLAGS_numa_client_node, get_bind_core(FLAGS_numa_client_node));
    }

    sleep(3);

    for (size_t i = 0; i < FLAGS_client_num; i++) {
        context->client_contexts_[i]->spsc_queue->push(REQ_MSG{ 0, RPC_TYPE::RPC_PING });
    }
    while (!ctrl_c_pressed && ping_count != FLAGS_client_num) {
        usleep(1);
    }
    for (size_t i = 0; i < FLAGS_client_num; i++) {
        size_t tmp = FLAGS_concurrency;
        while (tmp--) {
            context->client_contexts_[i]->PushNextTCReq();
        }
        context->client_contexts_[i]->now_timer.tic();
    }
    if (FLAGS_timeout_second != UINT64_MAX) {
        sleep(FLAGS_timeout_second);
        ctrl_c_pressed = true;
    }
    for (size_t i = 0; i < FLAGS_client_num; i++) {
        clients[i].join();
    }
}

bool write_latency_and_reset(const std::string &filename) {

    FILE *fp = fopen(filename.c_str(), "w");
    if (fp == nullptr) {
        return false;
    }
    hdr_percentiles_print(latency_hist_, fp, 5, 10, CLASSIC);
    fclose(fp);
    hdr_reset(latency_hist_);
    return true;
}

bool write_bandwidth(const std::string &filename) {
    FILE *fp = fopen(filename.c_str(), "w");
    if (fp == nullptr) {
        return false;
    }
    fprintf(fp, "%d\n", total_speed.load());
    fclose(fp);
    return true;
}


int main(int argc, char **argv) {
    signal(SIGINT, ctrl_c_handler);
    signal(SIGTERM, ctrl_c_handler);
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    int ret = hdr_init(1, 1000 * 1000 * 10, 3,
        &latency_hist_);
    rmem::rt_assert(ret == 0, "hdr_init failed");

    std::thread leader_thread(leader_thread_func);
    // rmem::bind_to_core(leader_thread, 1, get_bind_core(1));
    leader_thread.join();

    write_latency_and_reset(FLAGS_latency_file);
    write_bandwidth(FLAGS_bandwidth_file);
    hdr_close(latency_hist_);
}