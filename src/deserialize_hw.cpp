#define BENCH0
// #define DEATHSTARBENCH
#include "paralizer.h"

uint64_t HexStringToUInt64(const std::string &hexstr) {
    uint64_t result;
    std::stringstream ss;
    ss << std::hex << hexstr;
    ss >> result;
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: sudo " << argv[0] << " [0-9]" << std::endl;
        return 1;
    }
    int top_msg_idx = std::atoi(argv[1]); // 将字符串转换为整数
    if (top_msg_idx < 0 || top_msg_idx > 9) {
        std::cerr << "Usage: sudo " << argv[0] << " [0-9]" << std::endl;
        return 1;
    }

    Metadata metadataVec[1000];
    size_t messageSizeVec[1000];
    FPGA_Metadata FPGA_metadataVec[1000];
    size_t total_size = 0;
    size_t p_c2h_buffer_size = 0;
    size_t min_class_id = 65535;
    size_t max_class_id = 0;
    int outstanding_req = std::atoi(argv[2]);

    int pci_bus = 0x40;
    FPGACtl::explictInit(pci_bus, 4 * 1024 * 1024);
    auto fpga_ctl = FPGACtl::getInstance(pci_bus);

    auto cpu_mem_ctl = CPUMemCtl::getInstance(1UL * 1024 * 1024 * 1024);

    size_t size = 1L * 1024 * 1024 * 1024;

    cpu_mem_ctl->writeTLB([=](uint32_t page_index, uint32_t page_size, uint64_t vaddr, uint64_t paddr) {
        fpga_ctl->writeReg(8, (uint32_t)(vaddr));
        fpga_ctl->writeReg(9, (uint32_t)((vaddr) >> 32));
        fpga_ctl->writeReg(10, (uint32_t)(paddr));
        fpga_ctl->writeReg(11, (uint32_t)((paddr) >> 32));
        fpga_ctl->writeReg(12, (page_index == 0));
        fpga_ctl->writeReg(13, 1);
        fpga_ctl->writeReg(13, 0);
        });

    auto dma_buff = cpu_mem_ctl->alloc(size);
    size_t *p_h2c = (size_t *)dma_buff;
    size_t *p_c2h = ((size_t *)dma_buff) + size / 2 / sizeof(size_t);

    for (int i = 0;i < size / 2 / 64;i++) {//initial
        p_h2c[i * 8] = i * 64;//sizeof(size_t)*8=512
    }

    for (size_t i = 0;i < size / 2 / sizeof(size_t);i++) {
        p_c2h[i] = 0;
    }


    //----------reset    
    fpga_ctl->writeReg(0, 1);
    sleep(1);
    fpga_ctl->writeReg(0, 0);
    sleep(1);

    //----------init set
    uint32_t eng_delay_cycle = 100;
    uint64_t der_host_base_addr = (unsigned long)p_c2h;
    uint64_t der_device_base_addr = 0x10000000;
    uint64_t eng_notice_addr = (unsigned long)p_h2c;

    uint32_t total_rpcs = 100000;
    uint32_t idle_cycle = 0;
    // uint32_t outstanding_req = 4;


    fpga_ctl->writeReg(105, total_rpcs);
    fpga_ctl->writeReg(106, idle_cycle);
    fpga_ctl->writeReg(107, outstanding_req);
    fpga_ctl->writeReg(110, (uint32_t)(der_host_base_addr));
    fpga_ctl->writeReg(111, (uint32_t)(der_host_base_addr >> 32));

    for (int i = 0;i < 1;i++) {//one q in total
        fpga_ctl->writeConfig(0x1408 / 4, i);
        uint32_t tag = fpga_ctl->readConfig(0x140c / 4);
    }


    //TODO: protobuf-like serialize
    bool skip_big_string_flag = false;
    // M_base* top_msg_ptr = BenchmarkInit(metadataVec, messageSizeVec);
    M_base *top_msg_ptr = BenchmarkInit(top_msg_idx, metadataVec, messageSizeVec);
    SendMetadataToFPGA(top_msg_ptr, p_c2h, messageSizeVec, FPGA_metadataVec, p_c2h_buffer_size, min_class_id, max_class_id);

    uint64_t metadata[3][8];
    std::cout << "range of class_id is [" << min_class_id << "," << max_class_id << "]" << std::endl;
    for (int k = 0;k < 4;k++) {
        for (int j = min_class_id; j <= max_class_id; j++) {
            std::memcpy(metadata, &FPGA_metadataVec[j], sizeof(FPGA_Metadata));
            metadata[2][7] = k;
            fpga_ctl->writeBridge(20, metadata[0]);
            fpga_ctl->writeBridge(21, metadata[1]);
            fpga_ctl->writeBridge(22, metadata[2]);
            // if(k==0){
            //     for(int i=7;i>=0;i--){
            //         std::cout << std::hex << std::setw(16) << std::setfill('0') << metadata[0][i];
            //     }
            //     std::cout << std::endl;
            //     for(int i=7;i>=0;i--){
            //         std::cout << std::hex << std::setw(16) << std::setfill('0') << metadata[1][i];
            //     }
            //     std::cout << std::endl;
            //     for(int i=7;i>=0;i--){
            //         std::cout << std::hex << std::setw(16) << std::setfill('0') << metadata[2][i];
            //     }
            //     std::cout << std::endl;                
            // }
        }
    }



    total_size = ByteSizeLong(top_msg_ptr, skip_big_string_flag);
    SerializeToString(top_msg_ptr, p_h2c, skip_big_string_flag);

    std::cout << "total size: " << total_size << std::endl;
    fpga_ctl->writeReg(108, total_rpcs * (total_size) / 64);
    // for(int j=0;j<((total_size)/64+1);j++){
    //     for(int i=7;i>=0;i--){
    //         std::cout << std::hex << std::setw(16) << std::setfill('0') << p_h2c[i+j*8];
    //     }    
    //     std::cout << std::endl;        
    // }
    //ser cmd
    uint64_t sercmd[8];
    for (int i = 0;i < 8;i++) {
        sercmd[i] = 0;
    }

    struct SER_CMD {
        uint32_t class_id;
        uint64_t host_addr;
        uint64_t device_addr;
        uint64_t host_length;
        uint64_t device_length;
        uint32_t result_base_addr;
    } ser_cmd;

    ser_cmd.class_id = min_class_id;
    ser_cmd.host_addr = (unsigned long)p_h2c;
    ser_cmd.device_addr = 0x40000000;
    ser_cmd.host_length = total_size;
    ser_cmd.device_length = 0;
    ser_cmd.result_base_addr = 0x1000;


    sercmd[0] = ser_cmd.class_id;
    sercmd[1] = ser_cmd.host_addr;
    sercmd[2] = ser_cmd.device_addr;
    sercmd[3] = (ser_cmd.device_length << 32) + ser_cmd.host_length;
    sercmd[4] = ser_cmd.result_base_addr;

    // fpga_ctl->writeReg(110, 1);    // 正式读写数据之前打开
    // fpga_ctl->writeReg(112, 1);    // 正式读写数据之前打开
    // fpga_ctl->writeReg(120, 1);    // 正式读写数据之前打开
    usleep(10);

    fpga_ctl->writeBridge(12, sercmd);

    sleep(12);
    // fpga_ctl->writeReg(110, 0);
    // fpga_ctl->writeReg(112, 0);
    // fpga_ctl->writeReg(120, 0);

    fmt::println("data_cnt                                   : {}", fpga_ctl->readReg(512 + 300));
    fmt::println("timer_en                                   : {}", fpga_ctl->readReg(512 + 301));
    fmt::println("timer_cnt                                  : {}", fpga_ctl->readReg(512 + 302));
    fmt::println("timer_cnt                                  : {}", fpga_ctl->readReg(512 + 302));

    std::cout << "speed: " << total_size * total_rpcs * 8 / (fpga_ctl->readReg(512 + 302) * 5.0) / 1024 / 1024 * 1000 * 1000 << std::endl;

    fmt::println("timer                                  : {}", (fpga_ctl->readReg(512 + 302)) * 4 / 1000);


    cpu_mem_ctl->free(dma_buff);
#ifdef BENCH0
    std::cout << "################################ BENCH 0 ################################" << std::endl;
#endif
#ifdef BENCH1
    std::cout << "################################ BENCH 1 ################################" << std::endl;
#endif
#ifdef BENCH2
    std::cout << "################################ BENCH 2 ################################" << std::endl;
#endif
#ifdef BENCH3
    std::cout << "################################ BENCH 3 ################################" << std::endl;
#endif
#ifdef BENCH4
    std::cout << "################################ BENCH 4 ################################" << std::endl;
#endif
#ifdef BENCH5
    std::cout << "################################ BENCH 5 ################################" << std::endl;
#endif
#ifdef DEATHSTARBENCH
    std::cout << "################################ DEATHSTARBENCH ################################" << std::endl;
#endif
#ifdef NO_ENCODE
    std::cout << "################################ NO_ENCODE ################################" << std::endl;
#endif
    // std::cout << "################################ " << "message[" << top_msg_idx << "]" << " ################################" << std::endl;
    return 0;
}


