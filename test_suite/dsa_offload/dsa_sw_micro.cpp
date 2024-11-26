// #define BENCH0
// #define NO_ENCODE
#define DEATHSTARBENCH
#include "dsa_no_encode_main.h"
#include <x86intrin.h>
#include <assert.h>
#include <numa.h>
#include <mutex>
#include <algorithm>

void set_cpu(thread &t, int cpu_index) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu_index, &cpuset);
    int rc = pthread_setaffinity_np(t.native_handle(), sizeof(cpu_set_t), &cpuset);
    if (rc != 0) {
        printf("%-20s : %d", "Error calling pthread_setaffinity_np\n", rc);
    }
}

void set_cpu_with_numa(thread &t, int cpu_index, int numa_node) {
    std::vector<size_t> cpu_cores_list;
    auto num_lcores = static_cast<size_t>(numa_num_configured_cpus());

    for (size_t i = 0; i < num_lcores; i++) {
        if (numa_node == numa_node_of_cpu(static_cast<int>(i))) {
            cpu_cores_list.push_back(i);
        }
    }

    if (static_cast<size_t>(cpu_index) >= cpu_cores_list.size()) {
        printf("cpu_index[%d] >= cpu_cores_list.size()[%ld]\n", cpu_index, cpu_cores_list.size());
    }

    set_cpu(t, static_cast<int>(cpu_cores_list[cpu_index]));
}

void wait_scheduling(int thread_index) {
    while (thread_index != sched_getcpu()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));//wait set affinity success
    }
    printf("Thread [%2d] has been moved to core [%2d]\n", thread_index, sched_getcpu());
}

void test(int top_msg_idx) {
    wait_scheduling(1);

#ifdef USE_DSA
    uint32_t size = 0u;
    dml_status_t status = dml_get_job_size(DML_PATH_HW, &size);
    dml_job_t *dml_job_ptr = NULL;

    for (int i = 0;i < 100;i++) {
        dml_job_ptr = (dml_job_t *)malloc(size);
        status = dml_init_job(DML_PATH_HW, dml_job_ptr);
        assert(status == DML_STATUS_OK);
        dml_job_ptr->operation = DML_OP_MEM_MOVE;
        dml_job_ptr->numa_id = 0;
        jobs_list.push_back(dml_job_ptr);
    }
#endif

    Metadata metadataVec[1000];
    size_t messageSizeVec[1000];
    size_t *output = (size_t *)malloc(100 * 1024 * 1024);
    size_t *dummy = (size_t *)malloc(100 * 1024 * 1024);

    for (size_t i = 0;i < (100 * 1024 * 1024) / sizeof(size_t);i++) {
        output[i] = i;
    }

    for (size_t i = 0;i < (100 * 1024 * 1024) / sizeof(size_t);i++) {
        dummy[i] = i;
    }

#ifdef USE_DSA
    for (size_t i = 0;i < 100;i++) {
        dml_job_t *now_job = jobs_list[i];
        now_job->source_first_ptr = (uint8_t *)output + (i * 1024);
        now_job->destination_first_ptr = (uint8_t *)dummy + (i * 1024);
        now_job->source_length = 1024;
        now_job->destination_length = 1024;
        dml_status_t status = dml_submit_job(now_job);
        // printf("submit %ld status = %d\n", i, status);
        if (status != DML_STATUS_OK) {
            printf("submit %ld status = %d\n", i, status);
        }
        assert(status == DML_STATUS_OK);
    }
    for (size_t i = 0;i < 100;i++) {
        status = dml_wait_job(jobs_list[i], DML_WAIT_MODE_BUSY_POLL);
        // printf("finish %ld status = %d\n", i, status);
        assert(status == DML_STATUS_OK);
    }
#endif

    size_t target_loop = 3;
    size_t target_message = 5;
    std::vector<std::vector<size_t>>middle_cycles(target_message);
    std::vector<std::vector<size_t>>total_cycles(target_message);
    for (size_t msg_idx = 0;msg_idx < target_message;msg_idx++) {
        for (size_t loop_idx = 0;loop_idx < target_loop;loop_idx++) {
            size_t total_size = 0;
            now_job_idx = 0;

            memset(metadataVec, 0, sizeof(Metadata) * 1000);
            memset(messageSizeVec, 0, sizeof(size_t) * 1000);
            M_base *top_msg_ptr = BenchmarkInit(msg_idx, metadataVec, messageSizeVec);

            for (size_t i = 0;i < (100 * 1024 * 1024) / sizeof(size_t);i++) {
                dummy[i] = i;
            }
            unsigned int ui;

            size_t start = __rdtscp(&ui);
            bool skip_big_string_flag = false;
            size_t total_len = ByteSizeLong(top_msg_ptr, skip_big_string_flag);
            SerializeToString(top_msg_ptr, (string *)output, skip_big_string_flag, total_size, messageSizeVec, total_len);

#ifdef USE_DSA
            size_t middle_cycle = __rdtscp(&ui);
            for (size_t i = 0;i < now_job_idx;i++) {
                status = dml_wait_job(jobs_list[i], DML_WAIT_MODE_BUSY_POLL);
                // printf("finish %ld status = %d\n", i, status);
                assert(status == DML_STATUS_OK);
            }
            size_t total_cycle = __rdtscp(&ui);
            middle_cycles[msg_idx].push_back(middle_cycle - start);
            total_cycles[msg_idx].push_back(total_cycle - start);
            // std::cout << "middle_cycle = " << middle_cycle - start << std::endl;
            // std::cout << "total_cycle = " << total_cycle - start << std::endl;
#else
            size_t total_cycle = __rdtscp(&ui) - start;
            total_cycles[msg_idx].push_back(total_cycle);
            // std::cout << "total_cycle = " << total_cycle << std::endl;
#endif
            // std::cout << "host_serialized_len = " << total_size << std::endl;

#ifdef USE_DSA
            for (size_t i = 0;i < now_job_idx;i++) {
                status = dml_finalize_job(jobs_list[i]);
                assert(status == DML_STATUS_OK);
            }
#endif
        }
        printf("finish test %ld\n", msg_idx);
    }
    for (size_t msg_idx = 0;msg_idx < target_message;msg_idx++) {
        std::sort(total_cycles[msg_idx].begin(), total_cycles[msg_idx].end());

#ifdef USE_DSA
        std::sort(middle_cycles[msg_idx].begin(), middle_cycles[msg_idx].end());
        size_t middle_cycle_sum = 0, middle_cycle_num = 0;
        size_t total_cycle_sum = 0, total_cycle_num = 0;
        for (size_t i = 0;i < target_loop;i++) {
            if (middle_cycles[msg_idx][i] < 1.5 * middle_cycles[msg_idx][0]) {
                middle_cycle_sum += middle_cycles[msg_idx][i];
                middle_cycle_num++;
            }
            if (total_cycles[msg_idx][i] < 1.5 * total_cycles[msg_idx][0]) {
                total_cycle_sum += total_cycles[msg_idx][i];
                total_cycle_num++;
            }
        }
        middle_cycles[msg_idx][0] = middle_cycle_sum / middle_cycle_num;
        total_cycles[msg_idx][0] = total_cycle_sum / total_cycle_num;
#else
        size_t total_cycle_sum = 0, total_cycle_num = 0;
        for (size_t i = 0;i < target_loop;i++) {
            if (total_cycles[msg_idx][i] < 3 * total_cycles[msg_idx][0]) {
                total_cycle_sum += total_cycles[msg_idx][i];
                total_cycle_num++;
            }
        }
        total_cycles[msg_idx][0] = total_cycle_sum / total_cycle_num;
#endif
    }

    if (middle_cycles[0].size()) {
        for (size_t i = 0;i < target_message;i++) {
            printf("%ld,", middle_cycles[i][0]);
        }
        printf("\n");
    }
    for (size_t i = 0;i < target_message;i++) {
        printf("%ld,", total_cycles[i][0]);
    }
    printf("\n");
}

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
    std::thread t = std::thread(test, top_msg_idx);
    set_cpu_with_numa(t, 1, 0);
    t.join();
    return 0;
}


