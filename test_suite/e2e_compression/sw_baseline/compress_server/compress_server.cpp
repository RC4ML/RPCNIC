#include <thread>
#include "numautil.h"
#include "spinlock_mutex.h"
#include "compress_server.h"

void ping_handler(erpc::ReqHandle *req_handle, void *_context) {
    auto *ctx = static_cast<ServerContext *>(_context);
    ctx->stat_req_ping_tot++;
    auto *req_msgbuf = req_handle->get_req_msgbuf();
    rmem::rt_assert(req_msgbuf->get_data_size() == sizeof(RPCMsgReq<PingRPCReq>), "data size not match");

    auto *req = reinterpret_cast<RPCMsgReq<PingRPCReq> *>(req_msgbuf->buf_);

    new (req_handle->pre_resp_msgbuf_.buf_) RPCMsgResp<PingRPCResp>(req->req_common.type, req->req_common.req_number, 0, { req->req_control.timestamp });
    ctx->rpc_->resize_msg_buffer(&req_handle->pre_resp_msgbuf_, sizeof(RPCMsgResp<PingRPCResp>));

    ctx->rpc_->enqueue_response(req_handle, &req_handle->pre_resp_msgbuf_);
}

void compress_handler(erpc::ReqHandle *req_handler, void *_context) {
    auto *ctx = static_cast<ServerContext *>(_context);
    ctx->stat_compress_tot++;

    auto *req_msgbuf = req_handler->get_req_msgbuf();
    auto *req = reinterpret_cast<RPCMsgReq<CommonRPCReq> *>(req_msgbuf->buf_);

    rmem::rt_assert(req_msgbuf->get_data_size() == sizeof(RPCMsgReq<CommonRPCReq>) + req->req_control.data_length, "data size not match");

    // 现在先用RTC模式来做，后面有需要再改成异步
#if USE_SERIALIZATION
    cloudnic::CompressImgReq compress_img_req;
    compress_img_req.ParseFromArray(req + 1, req->req_control.data_length);
    rmem::rt_assert(compress_img_req.IsInitialized(), "req parsed error");

    cloudnic::CompressImgResp compress_img_resp = generate_compress_img(compress_img_req);

    size_t resp_data_length = compress_img_resp.ByteSizeLong();

    req_handler->dyn_resp_msgbuf_ = ctx->rpc_->alloc_msg_buffer(sizeof(RPCMsgResp<CommonRPCResp>) + resp_data_length);

    new (req_handler->dyn_resp_msgbuf_.buf_) RPCMsgResp<CommonRPCResp>(req->req_common.type, req->req_common.req_number, 0, { resp_data_length });

    compress_img_resp.SerializeToArray(req_handler->dyn_resp_msgbuf_.buf_ + sizeof(RPCMsgResp<CommonRPCResp>), resp_data_length);

    ctx->rpc_->resize_msg_buffer(&req_handler->dyn_resp_msgbuf_, sizeof(RPCMsgResp<CommonRPCResp>) + resp_data_length);

    ctx->rpc_->enqueue_response(req_handler, &req_handler->dyn_resp_msgbuf_);
#else 

    auto [compressed_img_ptr, img_size] = generate_compress_img_without_ser(reinterpret_cast<char *>(req + 1), req->req_control.data_length);
    req_handler->dyn_resp_msgbuf_ = ctx->rpc_->alloc_msg_buffer(sizeof(RPCMsgResp<CommonRPCResp>) + img_size);

    new (req_handler->dyn_resp_msgbuf_.buf_) RPCMsgResp<CommonRPCResp>(req->req_common.type, req->req_common.req_number, 0, { img_size });

    memcpy(req_handler->dyn_resp_msgbuf_.buf_ + sizeof(RPCMsgResp<CommonRPCResp>), compressed_img_ptr, img_size);

    ctx->rpc_->resize_msg_buffer(&req_handler->dyn_resp_msgbuf_, sizeof(RPCMsgResp<CommonRPCResp>) + img_size);

    ctx->rpc_->enqueue_response(req_handler, &req_handler->dyn_resp_msgbuf_);

    delete compressed_img_ptr;
#endif
}


void server_thread_func(size_t thread_id, ServerContext *ctx, erpc::Nexus *nexus) {
    ctx->server_id_ = thread_id;
    std::vector<size_t> port_vec = flags_get_numa_ports(0);
    uint8_t phy_port = port_vec.at(thread_id % port_vec.size());

    uint8_t rpc_id = thread_id;

    erpc::Rpc<erpc::CTransport> rpc(nexus, static_cast<void *>(ctx),
        rpc_id,
        basic_sm_handler_server, phy_port);
    rpc.retry_connect_on_invalid_rpc_id_ = true;
    ctx->rpc_ = &rpc;

    while (true) {
        ctx->reset_stat();
        erpc::ChronoTimer start;
        start.reset();
        rpc.run_event_loop(kAppEvLoopMs);
        const double seconds = start.get_sec();
        printf("thread %zu: ping_req : %.2f, compress : %.2f \n", thread_id,
            ctx->stat_req_ping_tot / seconds, ctx->stat_compress_tot / seconds);

        ctx->rpc_->reset_dpath_stats();
        // more handler
        if (ctrl_c_pressed == 1) {
            break;
        }
    }
}

void leader_thread_func() {
    erpc::Nexus nexus(FLAGS_server_addr, FLAGS_numa_server_node, 0);

    nexus.register_req_func(static_cast<uint8_t>(RPC_TYPE::RPC_PING), ping_handler);
    nexus.register_req_func(static_cast<uint8_t>(RPC_TYPE::RPC_APP1), compress_handler);

    std::vector<std::thread> servers(FLAGS_server_num);
    auto *context = new AppContext();

    servers[0] = std::thread(server_thread_func, 0, context->server_contexts_[0], &nexus);
    sleep(2);
    rmem::bind_to_core(servers[0], FLAGS_numa_server_node, get_bind_core(FLAGS_numa_server_node));
    for (size_t i = 1; i < FLAGS_server_num; i++) {
        servers[i] = std::thread(server_thread_func, i, context->server_contexts_[i], &nexus);

        rmem::bind_to_core(servers[i], FLAGS_numa_server_node, get_bind_core(FLAGS_numa_server_node));
    }
    sleep(3);
    if (FLAGS_timeout_second != UINT64_MAX) {
        sleep(FLAGS_timeout_second);
        ctrl_c_pressed = true;
    }
    for (size_t i = 0; i < FLAGS_server_num; i++) {
        servers[i].join();
    }

}

int main(int argc, char **argv) {

    signal(SIGINT, ctrl_c_handler);
    signal(SIGTERM, ctrl_c_handler);
    // only config_file is required!!!
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    std::thread leader_thread(leader_thread_func);
    rmem::bind_to_core(leader_thread, 1, get_bind_core(1));
    leader_thread.join();
}