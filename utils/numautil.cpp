#include "numautil.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cerrno>
#include <limits>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <functional>
#include <execinfo.h>
#include <unistd.h>
#include <fstream>
#include <random>

size_t num_lcores_per_numa_node() {
    return static_cast<size_t>(numa_num_configured_cpus() /
        numa_num_configured_nodes());
}

std::vector<size_t> get_lcores_for_numa_node(size_t numa_node) {
    assert(numa_node <= static_cast<size_t>(numa_max_node()));

    std::vector<size_t> ret;
    auto num_lcores = static_cast<size_t>(numa_num_configured_cpus());

    for (size_t i = 0; i < num_lcores; i++) {
        if (numa_node == static_cast<size_t>(numa_node_of_cpu(static_cast<int>(i)))) {
            ret.push_back(i);
        }
    }

    return ret;
}
void bind_to_core(std::thread &thread, size_t numa_node,
    size_t numa_local_index) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);

    const std::vector<size_t> lcore_vec = get_lcores_for_numa_node(numa_node);
    if (numa_local_index >= lcore_vec.size()) {
        printf(
            "eRPC: Requested binding to core %zu (zero-indexed) on NUMA node %zu, "
            "which has only %zu cores. Ignoring, but this can cause very low "
            "performance.\n",
            numa_local_index, numa_node, lcore_vec.size());
        return;
    }

    const size_t global_index = lcore_vec.at(numa_local_index);

    CPU_SET(global_index, &cpuset);
    int rc = pthread_setaffinity_np(thread.native_handle(), sizeof(cpu_set_t),
        &cpuset);
    assert(rc == 0);
}
int get_2M_huagepages_free(size_t numa_node) {
    assert(numa_node < static_cast<size_t>(numa_num_configured_nodes()));
    std::ifstream file("/sys/devices/system/node/node" + std::to_string(numa_node) + "/hugepages/hugepages-2048kB/free_hugepages", std::ios::in);

    if (!file) {
        // maybe open error, we need try this function latter
        return -1;
    }
    int res;
    while (file >> res) {
    }
    assert(file.eof());

    file.close();
    return res;
}

int get_2M_huagepages_nr(size_t numa_node) {
    assert(numa_node < static_cast<size_t>(numa_num_configured_nodes()));
    std::ifstream file("/sys/devices/system/node/node" + std::to_string(numa_node) + "/hugepages/hugepages-2048kB/nr_hugepages", std::ios::in);

    if (!file) {
        // maybe open error, we need try this function latter
        return -1;
    }
    int res;
    while (file >> res) {
    }
    assert(file.eof());

    file.close();
    return res;
}

void *get_huge_mem(uint32_t numa_node, size_t size) {
    size = round_up<2 * 1024 * 1024>(size);
    int shm_key, shm_id;

    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, RAND_MAX);

    while (true) {
        // Choose a positive SHM key. Negative is fine, but it looks scary in the
        // error message.
        shm_key = dist(rd);
        shm_key = std::abs(shm_key);

        // Try to get an SHM region
        shm_id = shmget(shm_key, size, IPC_CREAT | IPC_EXCL | 0666 | SHM_HUGETLB);

        if (shm_id == -1) {
            switch (errno) {
            case EEXIST:
                printf("shm_key already exists. Try again.");
                continue; // shm_key already exists. Try again.

            case EACCES:
                printf("Invalid access, maybe code is not illegal");
                exit(-1);

            case EINVAL:
                printf("Invalid argument, maybe code is not illegal");
                exit(-1);
            case ENOMEM:
                // Out of memory
                printf("No enough memory could be allocated, please insure you have enough 2M hugepage on this NUMA\n");
                exit(-1);

            default:
                printf("Unexpect error \n");
                exit(-1);
            }
        } else {
            // shm_key worked. Break out of the while loop.
            break;
        }
    }
    void *shm_buf = shmat(shm_id, nullptr, 0);
    assert(shm_buf != nullptr);
    shmctl(shm_id, IPC_RMID, nullptr);

    const unsigned long nodemask =
        (1ul << static_cast<unsigned long>(numa_node));
    long ret = mbind(shm_buf, size, MPOL_BIND, &nodemask, 32, 0);

    if (ret) {
        printf("mbind error %ld", ret);
        exit(-1);
    }

    return shm_buf;
}

