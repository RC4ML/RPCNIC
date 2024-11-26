cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(RPCNIC LANGUAGES CXX)



if (CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    message(STATUS "Compile on DPU")
    message(STATUS "Output Dir is /bin_dpu")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin_dpu)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build_dpu)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib_dpu)

elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    message(STATUS "Compile on HOST")
    message(STATUS "Output Dir is /bin_host")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin_host)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build_host)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib_host)
else()
    # 在其他架构下的逻辑代码
    message("Unknown architecture detected")
    return()
endif ()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DALLOW_EXPERIMENTAL_API -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Wno-unused-function -Wno-missing-braces")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-address-of-packed-member -Wno-nested-anon-types -Wno-keyword-macro -Wno-deprecated-declarations")

include_directories("${CMAKE_SOURCE_DIR}/utils")

include_directories("${CMAKE_SOURCE_DIR}/include")

include_directories(${CMAKE_SOURCE_DIR}/third_party/atomic_queue/include)

add_subdirectory(third_party/fmt)
add_subdirectory(third_party/eRPC)

#include: eRPC
if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    include_directories(${CMAKE_SOURCE_DIR}/third_party/eRPC/src)
endif()



set(UTILSOURCES
        ${CMAKE_SOURCE_DIR}/utils/QDMAController.cpp
)

set(LIBRARIES ${LIBRARIES} ibverbs mlx5 gflags numa pthread)

add_executable(microbench_co
	${CMAKE_SOURCE_DIR}/src/microbench_co.cpp ${UTILSOURCES}
)

target_link_libraries(microbench_co ${LIBRARIES})
