#ifndef _QDMACONTROLLER_HPP_
#define _QDMACONTROLLER_HPP_

#include <map>
#include <array>
#include <mutex>
#include <functional>

#include <cstdint>
#include <immintrin.h>

class FPGACtl{
protected:
	FPGACtl(uint8_t pci_bus, size_t bridge_bar_size);
public:
	~FPGACtl();

	static void explictInit(uint8_t pci_bus, size_t bridge_bar_size);
	static FPGACtl* getInstance(uint8_t pci_bus);

    static void enableDebug();
    static void disableDebug();

public:
	void writeConfig(uint32_t index,uint32_t value);
	uint32_t readConfig(uint32_t index);

	void writeReg(uint32_t index,uint32_t value);
	uint32_t readReg(uint32_t index);

	void writeBridge(uint32_t index, const std::array<uint64_t, 8> &value);
	std::array<uint64_t, 8> readBridge(uint32_t index);
    void writeBridge(uint32_t index, uint64_t *value);
    void readBridge(uint32_t index, uint64_t *value);
    void writeBridgeAligned(uint32_t index, uint64_t *value);
    void readBridgeAligned(uint32_t index, uint64_t *value);

	void* getBridgeAddr();
	void* getLiteAddr();

private:
	uint8_t pci_bus;
    size_t bridge_bar_size;
private:
    volatile uint32_t *config_bar{};
	volatile uint32_t *lite_bar{};
	volatile __m512i *bridge_bar{};
};

class MemCtl {
public:
    virtual ~MemCtl() = default;

    [[nodiscard]] size_t getPoolSize() const {
        return pool_size;
    }

    void *alloc(size_t size);

    void free(void *ptr);

protected:
    MemCtl() = default;

    size_t pool_size{};

    std::mutex allocMutex;
    /*<首地址, 块大小>*/
    std::map<uint64_t, uint64_t> free_chunk, used_chunk;
    /* n_pages, virt_addr_base, phy_addr_array */
    std::tuple<uint32_t, uint64_t, uint64_t *> page_table;
};

class CPUMemCtl : public MemCtl {
public:
    ~CPUMemCtl() override;

    static CPUMemCtl *getInstance(size_t pool_size);

protected:
    explicit CPUMemCtl(uint64_t size);

public:
    /*
     * void(uint32_t, uint32_t, uint64_t, uint64_t) => (page_index, page_size, virt_addr, phy_addr)
     */
    void writeTLB(const std::function<void(uint32_t, uint32_t, uint64_t, uint64_t)> &func);

    void legacyWriteTLB(FPGACtl *fpga_ctl);

    // For performance reason, mapV2P does not check the ptr's range
    uint64_t mapV2P(void *ptr);

};

class GPUMemCtl : public MemCtl {
public:
    ~GPUMemCtl() override;

    static GPUMemCtl *getInstance(int32_t dev_id, size_t pool_size);

protected:
    explicit GPUMemCtl(uint64_t size);

public:
    /*
     * void(uint32_t, uint32_t, uint64_t, uint64_t) => (page_index, page_size, virt_addr, phy_addr)
     */
    void writeTLB(const std::function<void(uint32_t, uint32_t, uint64_t, uint64_t)> &func, bool aggr_flag);

    uint64_t mapV2P(void *ptr);

};

#endif