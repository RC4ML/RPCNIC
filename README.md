# RPCNIC: A High-Performance and Reconfigurable PCIe-attached RPC Accelerator[HPCA2025]

A software-hardware co-designed RPC on-NIC accelerator that enables reconfigurable RPC kernel offloading. This is the source code for our HPCA2025 paper.



## Required hardware and software

- Xilinx Alevo U280 FPGA
- Required lib: cmake, gflags, numa, lz4, z
- HugePage: At least 2048 huge pages on specific NUMA node
- g++ >= 11.3.0
- MLNX_OFED 
- Nvidia Bluefield-3 (optimal)
- Intel Sapphire Rapids CPU or Emerald Rapids CPU with Data Streaming Accelerator(DSA) equipped (optimal)
- DPDK >= 22.11(optimal)



## Install Dependencies

- Install QDMA Driver(assume FPGA pci address is 1a:00.0):
  - `cd qdma_driver`
  - `make`
  - `sudo insmod /path/to/qdma_driver/src/qdma-pf.ko`
  - `echo '1024' | sudo tee -a /sys/bus/pci/devices/0000:1a:00.0/qdma/qmax`
  - `sudo dma-ctl qdma1a000 q add idx 0 mode st dir bi`
  - `sudo dma-ctl qdma1a000 q start idx 0 dir bi desc_bypass_en pfetch_bypass_en`
- Install MLNX_OFED:
  - `wget https://content.mellanox.com/ofed/MLNX_OFED-23.04-1.1.3.0/MLNX_OFED_LINUX-23.04-1.1.3.0-ubuntu18.04-x86_64.tgz`
  - `tar -zxvf ./MLNX_OFED_LINUX-23.04-1.1.3.0-ubuntu18.04-x86_64.tgz`
  - `cd MLNX_OFED_LINUX-23.04-1.1.3.0-ubuntu18.04-x86_64 && sudo ./ofedinstall`
- Install required libs:
  - `sudo apt install libgflags-dev libnuma-dev `

## Run Test



### Directory Structure:

~~~
.
├── bitstream (U280 Bitstream)
├── bluefield  (Bluefiled-3 DMA and ser/des test)
├── hardware_verilog (chisel compiled intermediate products)
├── include
│   └── bench_header (HyperProtoBench and DeathStarBench header file)
├── src (main CPU control code)
│   └── chisel (partial used chisel code)
├── test_suite (source code of experiments)
│   ├── dsa_offload (used for DSA offload experiment)
│   ├── e2e_compression (used for e2e compression experiment)
│   └── hardware_tb (used for micro benchmark)
├── third_party (software used third party libs)
│   ├── asio
│   ├── atomic_queue
│   ├── eRPC
│   └── fmt
└── utils
~~~


### ThirdParty

| project      | Version |
| ------------ | ------- |
| asio         | latest  |
| eRPC         | latest  |
| atomic_queue | latest  |
| fmt          | latest  |



### Getting help

Working in the process...



### Contact

email at carlzhang4@zju.edu.cn