#include "QDMAController.hpp"

#include <map>
#include <memory>
#include <string>
#include <string_view>

#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/args.h>
#include <fmt/ostream.h>
#include <fmt/std.h>	
#include <fmt/color.h>

#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <immintrin.h>

#include <rc4ml.h>

#ifdef GPU_ENABLE

#include <cuda.h>
#include <gdrapi.h>

#define ASSERT(x)                                               \
    do                                                          \
    {                                                           \
        if (!(x))                                               \
        {                                                       \
            fprintf(stderr, "Assertion \"%s\" failed at %s:%d\n", #x, __FILE__, __LINE__); \
            exit(EXIT_FAILURE);                                 \
        }                                                       \
    } while (0)

#define ASSERTDRV(stmt)                     \
    do                                      \
    {                                       \
        CUresult result = (stmt);           \
        if (result != CUDA_SUCCESS) {       \
            const char *_err_name;          \
            cuGetErrorName(result, &_err_name); \
            fprintf(stderr, "CUDA error: %s\n", _err_name); \
        }                                   \
        ASSERT(CUDA_SUCCESS == result);     \
    } while (0)

#define ASSERT_EQ(P, V) ASSERT((P) == (V))
#define ASSERT_NEQ(P, V) ASSERT(!((P) == (V)))

#endif

[[maybe_unused]] static bool debug_flag = false;

static auto getSysPathBarName(uint8_t bus_id, uint8_t dev_id, uint8_t func_id, uint8_t bar_id) {
    return fmt::format("/sys/bus/pci/devices/0000:{:02x}:{:02x}.{:x}/resource{}", bus_id, dev_id, func_id, bar_id);
}

[[maybe_unused]] static void errorPrint(std::string_view str) {
    fmt::print(fg(fmt::color::red), "{}\n", str);
}

[[maybe_unused]] static void passPrint(std::string_view str) {
    fmt::print(fg(fmt::color::green), "{}\n", str);
}

[[maybe_unused]] static void warnPrint(std::string_view str) {
    fmt::print(fg(fmt::color::yellow), "{}\n", str);
}

[[maybe_unused]] static void infoPrint(std::string_view str) {
    fmt::print(fg(fmt::color::cyan), "{}\n", str);
}

static const size_t config_region_size = 256 * 1024;
static const size_t lite_region_size = 4 * 1024;
static const size_t bridge_region_size = 1024 * 1024 * 1024;

static std::map<uint8_t, std::shared_ptr<FPGACtl>> device_list;

FPGACtl::FPGACtl(uint8_t pci_bus,
    size_t bridge_bar_size):pci_bus(pci_bus),
    bridge_bar_size(bridge_bar_size) {

    infoPrint(fmt::format("Try to init FPGA with PCI Bus: {:#x}", pci_bus));

    std::string resourceFilename;
    int fd;
    uint8_t pci_dev = 0;
    uint8_t dev_func = 0;

    //axi-lite
    resourceFilename = getSysPathBarName(pci_bus, pci_dev, dev_func, 2); //lite bar is 2

    fd = open(resourceFilename.c_str(), O_RDWR);
    if (fd < 0) {
        errorPrint(fmt::format(
            "Open lite error, maybe need sudo or you can check whether if {} exists", resourceFilename));
        exit(1);
    }
    lite_bar = (uint32_t *)mmap(nullptr, lite_region_size, PROT_WRITE, MAP_SHARED, fd, 0);
    // safe to close fd after mmap
    close(fd);
    if (lite_bar == MAP_FAILED) {
        errorPrint(fmt::format(
            "MMAP lite bar error, please check fpga lite bar size in vivado"));
        exit(1);
    }

    //axi-bridge
    resourceFilename = getSysPathBarName(pci_bus, pci_dev, dev_func, 4); //bridge bar is 4

    fd = open(resourceFilename.c_str(), O_RDWR);
    if (fd < 0) {
        errorPrint(fmt::format(
            "Open bridge error, maybe need sudo or you can check whether if {} exists", resourceFilename));
        exit(1);
    }
    bridge_bar = (__m512i *)mmap(nullptr, bridge_bar_size, PROT_WRITE, MAP_SHARED | MAP_LOCKED, fd, 0);
    close(fd);
    if (bridge_bar == MAP_FAILED) {
        errorPrint(fmt::format(
            "MMAP bridge bar error, please check fpga bridge bar size in vivado"));
        exit(1);
    }

    //config bar
    resourceFilename = getSysPathBarName(pci_bus, pci_dev, dev_func, 0); //config bar is 0

    fd = open(resourceFilename.c_str(), O_RDWR);
    if (fd < 0) {
        errorPrint(fmt::format(
            "Open config error, maybe need sudo or you can check whether if {} exists", resourceFilename));
        exit(1);
    }
    config_bar = (uint32_t *)mmap(nullptr, config_region_size, PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (config_bar == MAP_FAILED) {
        errorPrint(fmt::format(
            "MMAP config bar error, please check fpga config bar size in vivado"));
        exit(1);
    }

    passPrint(fmt::format(
        "Init pci dev: {:#x}", pci_bus));
}

FPGACtl::~FPGACtl() {
    if (munmap((void *)config_bar, config_region_size) == -1) {
        warnPrint(fmt::format("Unmap config bar failed"));
    }
    if (munmap((void *)lite_bar, lite_region_size) == -1) {
        warnPrint(fmt::format("Unmap lite bar failed"));
    }
    if (munmap((void *)bridge_bar, bridge_bar_size) == -1) {
        warnPrint(fmt::format("Unmap bridge bar failed"));
    }
}

void FPGACtl::explictInit(uint8_t pci_bus, size_t bridge_bar_size) {
    if (device_list.find(pci_bus) == device_list.end()) {
        auto *tmp = new FPGACtl(pci_bus, bridge_bar_size);
        device_list[pci_bus] = std::shared_ptr<FPGACtl>(tmp);
    } else {
        warnPrint(fmt::format("Device {:#x} has been initialized", pci_bus));
    }
}

FPGACtl *FPGACtl::getInstance(uint8_t pci_bus) {
    if (device_list.find(pci_bus) == device_list.end()) {
        warnPrint(fmt::format("Device {:#x} will be initialized with default Bridge Bar Size {}", pci_bus, bridge_region_size));
        auto *tmp = new FPGACtl(pci_bus, bridge_region_size);
        device_list[pci_bus] = std::shared_ptr<FPGACtl>(tmp);
    }
    return device_list[pci_bus].get();
}

void FPGACtl::writeConfig(uint32_t index, uint32_t value) {
    config_bar[index] = value;
}

uint32_t FPGACtl::readConfig(uint32_t index) {
    return config_bar[index];
}

void FPGACtl::writeReg(uint32_t index, uint32_t value) {
    lite_bar[index] = value;
}

uint32_t FPGACtl::readReg(uint32_t index) {
    return lite_bar[index];
}

void FPGACtl::writeBridge(uint32_t index, const std::array<uint64_t, 8> &value) {
    auto avx_reg = _mm512_loadu_epi64(value.data());
    _mm512_stream_si512((__m512i *)(bridge_bar + index), avx_reg);
}

std::array<uint64_t, 8> FPGACtl::readBridge(uint32_t index) {
    auto avx_reg = _mm512_stream_load_si512((void *)(bridge_bar + index));
    alignas(64) std::array<uint64_t, 8> ret;
    _mm512_store_epi64(ret.data(), avx_reg);
    return ret;
}

void FPGACtl::writeBridge(uint32_t index, uint64_t *value) {
    auto avx_reg = _mm512_loadu_epi64(value);
    _mm512_stream_si512((__m512i *)(bridge_bar + index), avx_reg);
}

void FPGACtl::readBridge(uint32_t index, uint64_t *value) {
    auto avx_reg = _mm512_stream_load_si512((void *)(bridge_bar + index));
    _mm512_storeu_epi64(value, avx_reg);
}

void FPGACtl::writeBridgeAligned(uint32_t index, uint64_t *value) {
    auto avx_reg = _mm512_load_epi64(value);
    _mm512_stream_si512((__m512i *)(bridge_bar + index), avx_reg);
}

void FPGACtl::readBridgeAligned(uint32_t index, uint64_t *value) {
    auto avx_reg = _mm512_stream_load_si512((void *)(bridge_bar + index));
    _mm512_store_epi64(value, avx_reg);
}

void *FPGACtl::getBridgeAddr() {
    return (void *)bridge_bar;
}

void *FPGACtl::getLiteAddr() {
    return (void *)lite_bar;
}

void FPGACtl::enableDebug() {
    debug_flag = true;
}

void FPGACtl::disableDebug() {
    debug_flag = false;
}

std::pair<uint64_t, uint64_t> findFreeChunk(const std::map<uint64_t, uint64_t> &freeChunk, uint64_t mSize) {
    for (auto const &it : freeChunk) {
        if (it.second >= mSize) {
            return { it.first, it.second };
        }
    }
    return { 0, 0 };
}

static bool contains(const std::map<uint64_t, uint64_t> &mp, uint64_t addr) {
    auto it = mp.find(addr);
    if (it == mp.end()) {
        return false;
    } else {
        return true;
    }
}

void *MemCtl::alloc(size_t size) {
    size = (size + 64UL - 1) & ~(64UL - 1);
    std::lock_guard<std::mutex> lock(allocMutex);
    /*查找大小大于申请空间大小的空闲内存块*/
    auto ck = findFreeChunk(free_chunk, size);
    auto &free_addr = ck.first;
    auto &free_size = ck.second;
    /*如果找到的块为空则报告申请失败*/
    if (free_addr == 0) {
        warnPrint(fmt::format("No Free CPU Chunk. Alloc failed!"));
        return nullptr;
    }
    /*如果内存块分配后仍存在剩余空间, 从内存块高地址部分分配*/
    if (free_size > size) {
        free_chunk[free_addr] = free_size - size;
        used_chunk[free_addr + free_size - size] = size;
        return (void *)(free_addr + free_size - size);
    } else {
        free_chunk.erase(free_addr);
        used_chunk[free_addr] = size;
        return (void *)(free_addr);
    }
}

void MemCtl::free(void *ptr) {
    std::lock_guard<std::mutex> lock(allocMutex);
    /*检查释放的内存块的合法性*/
    if (!contains(used_chunk, (uint64_t)ptr)) {
        errorPrint(fmt::format("Pointer to free is not in Alloc Log"));
        exit(1);
    }
    auto it = used_chunk.find((uint64_t)ptr);
    uint64_t free_size = it->second;
    used_chunk.erase(it);
    /*寻找第一个首地址大于ptr的空闲块, 返回map结构的迭代器*/
    auto nextIt = free_chunk.upper_bound((uint64_t)ptr);
    if (!free_chunk.empty()) {
        auto prevIt = std::prev(nextIt);
        /*检查前置空闲块 首地址+块大小 与 释放块首地址 是否连续, 连续则将释放块合并到前置空闲块中*/
        if (prevIt->first + prevIt->second == (uint64_t)ptr) {
            free_size += prevIt->second;
            ptr = (void *)prevIt->first;
        }
    }
    /*合并后置块*/
    if (nextIt != free_chunk.end() && (uint64_t)ptr + free_size == nextIt->first) {
        free_size += nextIt->second;
        free_chunk.erase(nextIt);
    }
    free_chunk[(int64_t)ptr] = free_size;
}

static std::vector<std::shared_ptr<CPUMemCtl>> cpu_mem_ctl_list;

CPUMemCtl::CPUMemCtl(uint64_t size) {
    pool_size = size;

    int fd, hfd;
    void *huge_base;
    std::string dev_path = fmt::format("/dev/rc4ml_dev");
    if ((fd = open(dev_path.c_str(), O_RDWR)) == -1) {
        errorPrint(fmt::format("Open {rc4ml_dev} error, maybe need sudo or you can check whether if {rc4ml_dev} exists",
            fmt::arg("rc4ml_dev", dev_path)));
        exit(1);
    }

    std::string hfd_path = fmt::format("/media/huge/hfd");
    if ((hfd = open(hfd_path.c_str(), O_CREAT | O_RDWR | O_SYNC, 0755)) == -1) {
        errorPrint(fmt::format("Open {fn} error, maybe need sudo or you can check whether if {fn} exists",
            fmt::arg("fn", hfd_path)));
        exit(1);
    }

    huge_base = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, hfd, 0);
    close(hfd);
    passPrint(fmt::format("Huge Pages Base VAddr: {}\nTotal Size: {}", fmt::ptr(huge_base), size));

    struct huge_mem hm {};
    hm.vaddr = (uint64_t)huge_base;
    hm.size = size;
    if (ioctl(fd, HUGE_MAPPING_SET, &hm) == -1) {
        errorPrint(fmt::format("IOCTL SET failed."));
        exit(1);
    }

    struct huge_mapping map {};
    map.nhpages = size / (2UL * 1024 * 1024);
    map.phy_addr = new uint64_t[map.nhpages];
    if (ioctl(fd, HUGE_MAPPING_GET, &map) == -1) {
        errorPrint(fmt::format("IOCTL GET failed."));
        exit(1);
    }
    close(fd);

    page_table = { map.nhpages, (uint64_t)(huge_base), map.phy_addr };
    free_chunk.emplace(std::get<1>(page_table), std::get<0>(page_table) * 2UL * 1024 * 1024);
}

CPUMemCtl::~CPUMemCtl() {
    const auto &[n_pages, vaddr, parray] = page_table;
    munmap((void *)vaddr, n_pages * 2UL * 1024 * 1024);
    delete[] parray;
}

CPUMemCtl *CPUMemCtl::getInstance(size_t pool_size) {
    // up round to 2MB
    pool_size = (pool_size + 2UL * 1024 * 1024 - 1) & ~(2UL * 1024 * 1024 - 1);

    if (cpu_mem_ctl_list.empty()) {
        auto tmp = new CPUMemCtl(pool_size);
        cpu_mem_ctl_list.push_back(std::shared_ptr<CPUMemCtl>(tmp));
        return tmp;
    } else {
        static bool warn_flag = false;
        if (!warn_flag) {
            warn_flag = true;
            warnPrint(fmt::format("This QDMA library now only support one CPU Memory Pool"));
            warnPrint(fmt::format("Request pool size will be ignored"));
            warnPrint(fmt::format("The previous CPU Memory Pool with size {} will be returned",
                cpu_mem_ctl_list[0]->getPoolSize()));
        }
        return cpu_mem_ctl_list[0].get();
    }
}

void CPUMemCtl::writeTLB(const std::function<void(uint32_t, uint32_t, uint64_t, uint64_t)> &func) {
    const auto &[n_pages, vaddr, parray] = page_table;
    const auto page_size = 2UL * 1024 * 1024;
    for (int i = 0; i < n_pages; i++) {
        func(i, page_size, vaddr + i * page_size, parray[i]);
    }
}

uint64_t CPUMemCtl::mapV2P(void *ptr) {
    const auto &[n_pages, vaddr, parray] = page_table;
    const auto page_size = 2UL * 1024 * 1024;
    uint64_t offset = (uint64_t)ptr - vaddr;
    return parray[offset / page_size] + (offset & (page_size - 1));
}

void CPUMemCtl::legacyWriteTLB(FPGACtl *fpga_ctl) {
    writeTLB([=](uint32_t page_index, uint32_t page_size, uint64_t vaddr, uint64_t paddr) {
        fpga_ctl->writeReg(8, (uint32_t)(vaddr));
        fpga_ctl->writeReg(9, (uint32_t)((vaddr) >> 32));
        fpga_ctl->writeReg(10, (uint32_t)(paddr));
        fpga_ctl->writeReg(11, (uint32_t)((paddr) >> 32));
        fpga_ctl->writeReg(12, (page_index == 0));
        fpga_ctl->writeReg(13, 1);
        fpga_ctl->writeReg(13, 0);
        });
}

#ifdef GPU_ENABLE

class gdrMemAllocator {
public:
    ~gdrMemAllocator();

    CUresult gpuMemAlloc(CUdeviceptr *pptr, size_t psize, bool align_to_gpu_page = true, bool set_sync_memops = true);

    CUresult gpuMemFree(CUdeviceptr pptr);

private:
    std::map<CUdeviceptr, CUdeviceptr> _allocations;
};

gdrMemAllocator::~gdrMemAllocator() {
    for (auto &it : _allocations) {
        CUresult ret;
        ret = cuMemFree(it.second);
        if (ret != CUDA_SUCCESS) {
            warnPrint(fmt::format("Fail to free cuMemAlloc GPU Memory"));
        }
    }
}

CUresult gdrMemAllocator::gpuMemAlloc(CUdeviceptr *pptr, size_t psize, bool align_to_gpu_page, bool set_sync_memops) {
    CUresult ret = CUDA_SUCCESS;
    CUdeviceptr ptr;
    size_t size;

    if (align_to_gpu_page) {
        size = psize + GPU_PAGE_SIZE - 1;
    } else {
        size = psize;
    }

    ret = cuMemAlloc(&ptr, size);
    if (ret != CUDA_SUCCESS)
        return ret;

    if (set_sync_memops) {
        unsigned int flag = 1;
        ret = cuPointerSetAttribute(&flag, CU_POINTER_ATTRIBUTE_SYNC_MEMOPS, ptr);
        if (ret != CUDA_SUCCESS) {
            cuMemFree(ptr);
            return ret;
        }
    }

    if (align_to_gpu_page) {
        *pptr = (ptr + GPU_PAGE_SIZE - 1) & GPU_PAGE_MASK;
    } else {
        *pptr = ptr;
    }
    // Record the actual pointer for doing gpuMemFree later.
    _allocations[*pptr] = ptr;

    return CUDA_SUCCESS;
}

CUresult gdrMemAllocator::gpuMemFree(CUdeviceptr pptr) {
    CUresult ret = CUDA_SUCCESS;
    CUdeviceptr ptr;

    if (_allocations.count(pptr) > 0) {
        ptr = _allocations[pptr];
        ret = cuMemFree(ptr);
        if (ret == CUDA_SUCCESS)
            _allocations.erase(ptr);
        return ret;
    } else {
        return CUDA_ERROR_INVALID_VALUE;
    }
}

static gdrMemAllocator allocator;

static int32_t devID{ -1 };

static const gdr_mh_t null_mh = { 0 };

static gdr_t gdrDev{};
static gdr_mh_t gdrUserMapHandler{ null_mh };
static gpu_tlb_t gdrPageTable{};
static gdr_info_t info{};

static CUdeviceptr devAddr{};
static void *mapDevPtr{};

static inline bool operator==(const gdr_mh_t &a, const gdr_mh_t &b) {
    return a.h == b.h;
}

#endif

static std::vector<std::shared_ptr<GPUMemCtl>> gpu_mem_ctl_list;

GPUMemCtl::GPUMemCtl(uint64_t size) {
#ifdef GPU_ENABLE
    pool_size = size;
    auto page_size = 64UL * 1024;

    CUdevice dev;
    CUcontext devCtx;
    ASSERTDRV(cuInit(devID));
    ASSERTDRV(cuDeviceGet(&dev, devID));
    ASSERTDRV(cuDevicePrimaryCtxRetain(&devCtx, dev));
    ASSERTDRV(cuCtxSetCurrent(devCtx));

    ASSERTDRV(allocator.gpuMemAlloc(&devAddr, size));

    gdrDev = gdr_open();
    ASSERT_NEQ(gdrDev, nullptr);

    // 64KB * 64K = 4GB
    // 4GB * 20 = 80GB
    gdrPageTable.pages = new uint64_t[65536 * 20];

    ASSERT_EQ(gdr_pin_buffer(gdrDev, devAddr, size, 0, 0, &gdrUserMapHandler, &gdrPageTable), 0);
    ASSERT_NEQ(gdrUserMapHandler, null_mh);

    ASSERT_EQ(gdr_map(gdrDev, gdrUserMapHandler, &mapDevPtr, size), 0);

    ASSERT_EQ(gdr_get_info(gdrDev, gdrUserMapHandler, &info), 0);

    ASSERT_EQ((info.va - devAddr), 0);
    ASSERT_EQ((devAddr & (page_size - 1)), 0);

    page_table = { gdrPageTable.page_entries, (uint64_t)(devAddr), gdrPageTable.pages };
    free_chunk.emplace((uint64_t)devAddr, size);
#else
    warnPrint(fmt::format("GPU Options is not enabled at compile time"));
    exit(1);
#endif
}

GPUMemCtl::~GPUMemCtl() {
#ifdef GPU_ENABLE
    const auto size = std::get<0>(page_table) * 64UL * 1024;
    delete[] std::get<2>(page_table);
    ASSERT_EQ(gdr_unmap(gdrDev, gdrUserMapHandler, mapDevPtr, size), 0);
    ASSERT_EQ(gdr_unpin_buffer(gdrDev, gdrUserMapHandler), 0);
    ASSERT_EQ(gdr_close(gdrDev), 0);
    ASSERTDRV(allocator.gpuMemFree(devAddr));
#else
    warnPrint(fmt::format("GPU Options is not enabled at compile time"));
    exit(1);
#endif
}

GPUMemCtl *GPUMemCtl::getInstance(int32_t dev_id, size_t pool_size) {
#ifdef GPU_ENABLE
    if (devID >= 0 && devID != dev_id) {
        errorPrint(fmt::format("This QDMA library now only support one GPU Memory Pool"));
        errorPrint(fmt::format("New device id {} is not equal to previous device id {}", dev_id, devID));
        exit(1);
    }
    // up round to 64KB
    pool_size = (pool_size + 64UL * 1024 - 1) & ~(64UL * 1024 - 1);

    if (pool_size % (2UL * 1024 * 1024) != 0) {
        warnPrint(fmt::format("Suggest GPU Memory Pool Size to be multiple of 2MB for Page Aggregation"));
        errorPrint(fmt::format("For correctness safety, the program will exit. Please change the pool size"));
        exit(1);
    }

    if (gpu_mem_ctl_list.empty()) {
        auto tmp = new GPUMemCtl(pool_size);
        gpu_mem_ctl_list.push_back(std::shared_ptr<GPUMemCtl>(tmp));
        return tmp;
    } else {
        static bool warn_flag = false;
        if (!warn_flag) {
            warn_flag = true;
            warnPrint(fmt::format("This QDMA library now only support one GPU Memory Pool"));
            warnPrint(fmt::format("Request pool size will be ignored"));
            warnPrint(fmt::format("The previous GPU Memory Pool with size {} will be returned",
                gpu_mem_ctl_list[0]->getPoolSize()));
        }
        return gpu_mem_ctl_list[0].get();
    }
#else
    warnPrint(fmt::format("GPU Options is not enabled at compile time"));
    exit(1);
#endif
    }

void GPUMemCtl::writeTLB(const std::function<void(uint32_t, uint32_t, uint64_t, uint64_t)> &func, bool aggr_flag) {
#ifdef GPU_ENABLE
    const auto &[n_pages, vaddr, parray] = page_table;

    if (aggr_flag) {
        const auto page_size = 2UL * 1024 * 1024;
        auto aggr_n_pages = n_pages / 32;
        for (uint32_t i = 0; i < aggr_n_pages; ++i) {
            for (uint32_t j = 1; j < 32; ++j) {
                ASSERT_EQ((parray[i * 32 + j] - parray[i * 32 + j - 1]), 65536);
            }
            func(i, page_size, vaddr + i * page_size, parray[i * 32]);
        }
    } else {
        const auto page_size = 64UL * 1024;
        for (int i = 0; i < n_pages; i++) {
            func(i, page_size, vaddr + i * page_size, parray[i]);
        }
    }
#else
    warnPrint(fmt::format("GPU Options is not enabled at compile time"));
    exit(1);
#endif
}

uint64_t GPUMemCtl::mapV2P(void *ptr) {
    const auto &[n_pages, vaddr, parray] = page_table;
    const auto page_size = 64UL * 1024;
    uint64_t offset = (uint64_t)ptr - vaddr;
    return parray[offset / page_size] + (offset & (page_size - 1));
}

extern "C" {

    void init(uint8_t pci_bus, size_t bridge_bar_size) {
        FPGACtl::explictInit(pci_bus, bridge_bar_size);
    }

    void writeConfig(uint32_t index, uint32_t value, uint8_t pci_bus) {
        device_list[pci_bus]->writeConfig(index, value);
    }
    uint32_t readConfig(uint32_t index, uint8_t pci_bus) {
        return device_list[pci_bus]->readConfig(index);
    }

    void writeReg(uint32_t index, uint32_t value, uint8_t pci_bus) {
        device_list[pci_bus]->writeReg(index, value);
    }
    uint32_t readReg(uint32_t index, uint8_t pci_bus) {
        return device_list[pci_bus]->readReg(index);
    }

    void writeBridge(uint32_t index, uint64_t *value, uint8_t pci_bus) {
        device_list[pci_bus]->writeBridge(index, value);
    }

    void readBridge(uint32_t index, uint64_t *value, uint8_t pci_bus) {
        device_list[pci_bus]->readBridge(index, value);
    }


    void *getBridgeAddr(uint8_t pci_bus) {
        return device_list[pci_bus]->getBridgeAddr();
    }

    void *getLiteAddr(uint8_t pci_bus) {
        return device_list[pci_bus]->getLiteAddr();
    }

    void enableDebug() {
        FPGACtl::enableDebug();
    }
    void disableDebug() {
        FPGACtl::disableDebug();
    }

} // extern "C"
