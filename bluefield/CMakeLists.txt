project(BF_MICRO)

add_executable(bf_micro_bench ./bf_micro_bench.cpp ${SRCS} ${APP_ADDITIONAL_SOURCES})

add_executable(bf_micro_export ./bf_micro_export.cpp ${SRCS} ${APP_ADDITIONAL_SOURCES})

target_link_libraries(bf_micro_bench ${LIBRARIES})

target_link_libraries(bf_micro_export ${LIBRARIES})