# RPCNIC: A High-Performance and Reconfigurable PCIe-attached RPC Accelerator [HPCA2025]

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



## Install Dependencies and Build
See [INSTALL.md](./doc/INSTALL.md) for install dependencies and build RPCNIC on a single machine.

## Deploy FPGA Bitstream
See [DEPLOY.md](./doc/DEPLOY.md) for connecting to our artifact machine and  deploying FPGA bitstream on Xilinx U280.

## Run Test
If Check if the configuration is correct in Run Experiments of [EXP.md](./doc/EXP.md) passes, then everything will be fine. Please refer to exp.md for more details.


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
