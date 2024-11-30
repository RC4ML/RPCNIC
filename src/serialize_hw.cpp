#define MICROBENCH_32INT
#define NO_ENCODE

#ifdef NO_ENCODE
#include "no_encode_main.h"
#else
#include "encode_main.h"
#endif

struct DEVICE_DATA_INFO {
    size_t rpc_class_id;
    size_t length;
} device_info[60];

int main(int argc, char *argv[]) {
    if (argc != 2) {
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

    //------------------------------------------- FPGA control code BEGIN-------------------------------------------    
    int pci_bus = 0x1a;
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

    for (int i = 0;i < 1;i++) {//one q in total
        fpga_ctl->writeConfig(0x1408 / 4, i);
        uint32_t tag = fpga_ctl->readConfig(0x140c / 4);
    }
    size_t host_serialized_len = 0;
    //------------------------------------------- FPGA control code END-------------------------------------------

        // TODO: software write serialized data to p_h2c buffer
    M_base *top_msg_ptr = BenchmarkInit(top_msg_idx, metadataVec, messageSizeVec);
    SendMetadataToFPGA_hw(top_msg_ptr, p_c2h, messageSizeVec, FPGA_metadataVec, p_c2h_buffer_size, min_class_id, max_class_id);

    //------------------------------------------- FPGA control code BEGIN-------------------------------------------
        // TODO: software write metadata to hardware by writeBridge()

    fpga_ctl->writeReg(0, 1);
    sleep(1);
    fpga_ctl->writeReg(0, 0);
    sleep(1);

    uint64_t metadata[3][8];
    std::cout << "range of class_id is [" << min_class_id << "," << max_class_id << "]" << std::endl;
    for (int j = min_class_id; j <= max_class_id; j++) {
        std::memcpy(metadata, &FPGA_metadataVec[j], sizeof(FPGA_Metadata));
        fpga_ctl->writeBridge(20, metadata[0]);
        fpga_ctl->writeBridge(21, metadata[1]);
        fpga_ctl->writeBridge(22, metadata[2]);
        for (int i = 7;i >= 0;i--) {
            std::cout << std::hex << std::setw(16) << std::setfill('0') << metadata[0][i];
        }
        std::cout << std::endl;
        for (int i = 7;i >= 0;i--) {
            std::cout << std::hex << std::setw(16) << std::setfill('0') << metadata[1][i];
        }
        std::cout << std::endl;
        for (int i = 7;i >= 0;i--) {
            std::cout << std::hex << std::setw(16) << std::setfill('0') << metadata[2][i];
        }
        std::cout << std::endl;
    }

    //eng cmd
    uint64_t engcmd[8];
    for (int i = 0;i < 8;i++) {
        engcmd[i] = 0;
    }

    struct ENG_CMD {
        uint32_t engine_num;
        uint64_t src_length;
        uint64_t src_addr;
        uint64_t dest_addr;
        uint32_t src_device; //0:host //1 device
        uint32_t dest_device;
    } eng_cmd;

    eng_cmd.engine_num = 0;
    eng_cmd.src_length = p_c2h_buffer_size;
    eng_cmd.src_addr = (unsigned long)p_c2h;
    eng_cmd.dest_addr = 0x80000000;
    eng_cmd.src_device = 0;
    eng_cmd.dest_device = 1;

    engcmd[0] = (eng_cmd.src_length << 32) + eng_cmd.engine_num;
    engcmd[1] = eng_cmd.src_addr;
    engcmd[2] = eng_cmd.dest_addr;
    engcmd[3] = (eng_cmd.dest_device << 1) + eng_cmd.src_device;


    // fpga_ctl->writeBridge(13, engcmd);

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


    // PRE_SER_HOOK;
    auto start = chrono::high_resolution_clock::now();

    bool skip_big_string_flag = true;
    size_t bytesizelong_size = ByteSizeLong(top_msg_ptr, skip_big_string_flag);
    SerializeToString(top_msg_ptr, (string *)p_h2c, skip_big_string_flag, total_size, messageSizeVec, bytesizelong_size);


    host_serialized_len = total_size;

    ser_cmd.class_id = min_class_id;
    ser_cmd.host_addr = (unsigned long)p_h2c;
    ser_cmd.device_addr = 0x80000000;
    ser_cmd.host_length = host_serialized_len;
    ser_cmd.device_length = p_c2h_buffer_size;
    ser_cmd.result_base_addr = 0x1000;

    sercmd[0] = ser_cmd.class_id;
    sercmd[1] = ser_cmd.host_addr;
    sercmd[2] = ser_cmd.device_addr;
    sercmd[3] = (ser_cmd.device_length << 32) + ser_cmd.host_length;
    sercmd[4] = ser_cmd.result_base_addr;

    fpga_ctl->writeBridge(12, sercmd);
    while (fpga_ctl->readReg(512 + 300) == 0) {};

    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_1 = end - start;
    std::chrono::duration<double> millis_1 = diff_1 * 1000 * 1000;
    cout << "1. Hyperprotobench.bench0.Serialize() timeing: " << millis_1.count() << " us\n";

    std::cout << "host_serialized_len = " << host_serialized_len << std::endl;
    std::cout << "p_c2h_buffer_size = " << p_c2h_buffer_size << std::endl;
    std::cout << "################################ p_h2c data BEGIN ################################" << std::endl;
    // for(int j=0;j<(host_serialized_len+63)/64;j++){
    //     for(int i=7;i>=0;i--){
    //         std::cout << std::hex << std::setw(16) << std::setfill('0') << p_h2c[i+j*8];
    //     }    
    //     std::cout << std::endl;        
    // }
    std::cout << "################################ p_h2c data END ################################" << std::endl << std::endl;

    std::cout << "################################ p_c2h data BEGIN ################################" << std::endl;
    // for(int j=0;j<(p_c2h_buffer_size)/64;j++){
    //     for(int i=7;i>=0;i--){
    //         std::cout << std::hex << std::setw(16) << std::setfill('0') << p_c2h[i+j*8];
    //     }    
    //     std::cout << std::endl;        
    // }
    std::cout << "################################ p_c2h data END ################################" << std::endl << std::endl;

    cpu_mem_ctl->free(dma_buff);
    //------------------------------------------- FPGA control code END -------------------------------------------
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
#ifdef MICROBENCH_1INT
    std::cout << "################################ MICROBENCH_1INT ################################" << std::endl;
#endif
#ifdef MICROBENCH_2INT
    std::cout << "################################ MICROBENCH_2INT ################################" << std::endl;
#endif
#ifdef MICROBENCH_4INT
    std::cout << "################################ MICROBENCH_4INT ################################" << std::endl;
#endif
#ifdef MICROBENCH_8INT
    std::cout << "################################ MICROBENCH_8INT ################################" << std::endl;
#endif
#ifdef MICROBENCH_16INT
    std::cout << "################################ MICROBENCH_16INT ################################" << std::endl;
#endif
#ifdef MICROBENCH_32INT
    std::cout << "################################ MICROBENCH_32INT ################################" << std::endl;
#endif
#ifdef MICROBENCH_64INT
    std::cout << "################################ MICROBENCH_64INT ################################" << std::endl;
#endif
#ifdef NO_ENCODE
    std::cout << "################################ NO_ENCODE ################################" << std::endl;
#endif
    std::cout << "################################ " << "message[" << top_msg_idx << "]" << " ################################" << std::endl;
    return 0;
}


