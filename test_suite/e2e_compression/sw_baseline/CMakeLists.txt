project(cloudnic)

set(APP_ADDITIONAL_SOURCES ${CMAKE_SOURCE_DIR}/cn/app/cloudnic/cloudnic.pb.cc ${CMAKE_SOURCE_DIR}/cn/app/cloudnic/AES.cpp)

set(PROGRAMS compress_client compress_server)

foreach (project_name IN LISTS PROGRAMS)
    add_executable(${project_name} ${CMAKE_SOURCE_DIR}/cn/app/cloudnic/${project_name}/${project_name}.cpp ${APP_ADDITIONAL_SOURCES})
    target_link_libraries(${project_name} -Wl,--whole-archive erpc -Wl,--no-whole-archive rmem lz4 ${LIBRARIES})
endforeach ()