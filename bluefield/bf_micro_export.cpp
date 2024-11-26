#include "bf_micro.h"

using namespace std;
std::mutex IO_LOCK;

int BUF_SIZE;
int NUM_THREADS;
int NUMA_NODE;
string DEVICE_NAME;


DEFINE_int32(bufSize, 104857600, "bufSize");
DEFINE_int32(threads, 1, "num_threads");
DEFINE_int32(numaNode, 0, "numaNode");
DEFINE_string(deviceName, "mlx5_0", "deviceName");
DEFINE_int32(port, 6666, "bind_port");
DEFINE_int32(life_time, 20, "time(s) to live");


// sudo ./dma_copy_export -numaNode 0 -deviceName mlx5_0 -bufSize 104857600 -threads 1 -life_time 30
int main(int argc, char *argv[]) {
    signal(SIGINT, ctrl_c_handler);
    signal(SIGTERM, ctrl_c_handler);

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    BUF_SIZE = FLAGS_bufSize;
    NUM_THREADS = FLAGS_threads;
    NUMA_NODE = FLAGS_numaNode;
    DEVICE_NAME = FLAGS_deviceName;

    NetParam net_param;
    net_param.numNodes = 2;
    net_param.nodeId = 0;
    net_param.device_name = DEVICE_NAME;
    net_param.numa_node = NUMA_NODE;
    net_param.sock_port = FLAGS_port;
    net_param.sockfd = new int[128];
    net_param.ib_port = 1;//minimum 1
    net_param.page_size = sysconf(_SC_PAGESIZE);
    net_param.cacheline_size = get_cache_line_size();

    roce_init(net_param, NUM_THREADS);
    struct devx_hca_capabilities caps;
    if (devx_query_hca_caps(net_param.contexts[0], &caps) != 0) {
        printf("can't query_hca_caps\n");
        return -1;
    }

    printf("vhca_id %u\n", caps.vhca_id);
    printf("vhca_resource_manager %u\n", caps.vhca_resource_manager);
    printf("hotplug_manager %u\n", caps.hotplug_manager);
    printf("eswitch_manager %u\n", caps.eswitch_manager);
    // direct access host physical address
    printf("introspection_mkey_access_allowed %d\n", caps.introspection_mkey_access_allowed);
    printf("introspection_mkey %u\n", caps.introspection_mkey);
    // import representor introspection mkey
    printf("crossing_vhca_mkey_supported %d\n", caps.crossing_vhca_mkey_supported);
    // local mkey to remote mkey
    printf("cross_gvmi_mkey_enabled %d\n", caps.cross_gvmi_mkey_enabled);
    printf("---------------------------\n");

    vhca_resource *resources = new vhca_resource[NUM_THREADS];

    for (int i = 0;i < NUM_THREADS;i++) {
        resources[i].pd = ibv_alloc_pd(net_param.contexts[i]);
    }

    uint8_t access_key[32] = { 0 };

    for (size_t i = 0; i < 32;i++) {
        access_key[i] = 1;
    }

    for (int i = 0;i < NUM_THREADS;i++) {
        resources[i].vhca_id = caps.vhca_id;
        resources[i].addr = malloc_2m_numa(BUF_SIZE, NUMA_NODE);
        if (!resources[i].addr) {
            LOG_E("can't malloc_2m_numa\n");
            return -1;
        }
        resources[i].size = BUF_SIZE;
        resources[i].mr = devx_reg_mr(resources[i].pd, resources[i].addr, resources[i].size, IBV_ACCESS_LOCAL_WRITE | IBV_ACCESS_REMOTE_READ
            | IBV_ACCESS_REMOTE_WRITE | IBV_ACCESS_HUGETLB | IBV_ACCESS_RELAXED_ORDERING);
        if (!resources[i].mr) {
            LOG_I("can't devx_reg_mr\n");
            return -1;
        }
        resources[i].mkey = devx_mr_query_mkey(resources[i].mr);
        if (devx_mr_allow_other_vhca_access(resources[i].mr, access_key, sizeof(access_key)) != 0) {
            LOG_E("can't allow_other_vhca_access\n");
            return -1;
        }
        LOG_I("mr (umem): thread %d vhca_id %u addr %p mkey %u\n", i, caps.vhca_id, resources[i].addr, resources[i].mkey);
    }

    socket_init(net_param);
    exchange_vhca_data(net_param, resources, NUM_THREADS);

    for (int i = 0;i < FLAGS_life_time;i++) {
        if (stop_flag) {
            break;
        }
        sleep(1);
    }

    for (int i = 0;i < NUM_THREADS;i++) {
        if (devx_dereg_mr(resources[i].mr) != 0) {
            LOG_E("can't devx_dereg_mr\n");
            return -1;
        }
        ibv_dealloc_pd(resources[i].pd);
        ibv_close_device(net_param.contexts[i]);
    }
}