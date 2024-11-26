#pragma once
#include <hdr/hdr_histogram.h>
#include "../cloudnic.h"
#include "../cloudnic.pb.h"
#include <lz4.h>
#include "../AES.h"


AES aes(AESKeyLength::AES_128);
class ServerContext: public BasicContext {
public:
    explicit ServerContext(size_t sid): server_id_(sid) {
    }
    ~ServerContext()
        = default;
    size_t server_id_{};
    size_t stat_req_ping_tot{};
    size_t stat_compress_tot{};

    void reset_stat() {
        stat_req_ping_tot = 0;
        stat_compress_tot = 0;
    }
};

class AppContext {
public:
    AppContext() {
        int ret = hdr_init(1, 1000 * 1000 * 10, 3,
            &latency_hist_);
        rmem::rt_assert(ret == 0, "hdr_init failed");

        for (size_t i = 0; i < FLAGS_server_num; i++) {
            auto *ctx = new ServerContext(i);
            server_contexts_.push_back(ctx);
        }
    }
    ~AppContext() {
        hdr_close(latency_hist_);

        for (auto &ctx : server_contexts_) {
            delete ctx;
        }
    }

    [[maybe_unused]] [[nodiscard]] bool write_latency_and_reset(const std::string &filename) const {

        FILE *fp = fopen(filename.c_str(), "w");
        if (fp == nullptr) {
            return false;
        }
        hdr_percentiles_print(latency_hist_, fp, 5, 10, CLASSIC);
        fclose(fp);
        hdr_reset(latency_hist_);
        return true;
    }

    std::vector<ServerContext *> server_contexts_;

    hdr_histogram *latency_hist_{};
};


cloudnic::CompressImgResp generate_compress_img(const cloudnic::CompressImgReq &req) {
    const std::string &origin_img = req.img();
    unsigned char *decrypted_img = aes.DecryptECB(reinterpret_cast<const unsigned char *>(origin_img.c_str()), origin_img.size(), aes_key);

    char *compressed_img = new char[origin_img.size()];

    int compressed_len = LZ4_compress_default(reinterpret_cast<const char *>(decrypted_img), compressed_img, origin_img.size(), origin_img.size());
    rmem::rt_assert(compressed_len > 0, "compress failed");

    // 将compressed_len做16Bytes对齐
    compressed_len = (compressed_len + 15) & ~15;
    unsigned char *encrypted_img = aes.EncryptECB(reinterpret_cast<const unsigned char *>(compressed_img), compressed_len, aes_key);

    cloudnic::CompressImgResp resp;
    resp.set_img(std::string(reinterpret_cast<const char *>(encrypted_img), compressed_len));
    resp.set_img_id(req.img_id());

    delete decrypted_img;
    delete compressed_img;
    delete encrypted_img;
    return resp;
}

std::pair<unsigned char *, size_t> generate_compress_img_without_ser(char *img_ptr, size_t img_size) {
    unsigned char *decrypted_img = aes.DecryptECB(reinterpret_cast<const unsigned char *>(img_ptr), img_size, aes_key);

    char *compressed_img = new char[img_size];

    int compressed_len = LZ4_compress_default(reinterpret_cast<const char *>(decrypted_img), compressed_img, img_size, img_size);
    rmem::rt_assert(compressed_len > 0, "compress failed");

    // 将compressed_len做16Bytes对齐
    compressed_len = (compressed_len + 15) & ~15;
    unsigned char *encrypted_img = aes.EncryptECB(reinterpret_cast<const unsigned char *>(compressed_img), compressed_len, aes_key);
    delete decrypted_img;
    delete compressed_img;

    return { encrypted_img, compressed_len };
}