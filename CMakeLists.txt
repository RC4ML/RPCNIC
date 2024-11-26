cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(qdma LANGUAGES CXX)

add_subdirectory(fmt)

set(SOURCE_FILES
	QDMAController.cpp
)

set(HEAD_FILES 
	QDMAController.h
	QDMAController.hpp
)

SET(COMPILE_CUDA OFF)
if (${COMPILE_CUDA})
	enable_language(CUDA)
	set_source_files_properties(${SOURCE_FILES} PROPERTIES LANGUAGE CUDA)
	add_definitions(-DGPU_ENABLE)
endif ()

add_library(qdma SHARED ${SOURCE_FILES})
target_link_libraries(qdma PRIVATE fmt::fmt-header-only)

if (${COMPILE_CUDA})
	target_compile_options(qdma PRIVATE -O3 -Xcompiler=-fPIC -Xcompiler=-mavx512f)
	set_target_properties(qdma PROPERTIES CUDA_ARCHITECTURES "80")
	target_link_libraries(qdma PRIVATE gdrapi cuda cudart)
else ()
	target_compile_options(qdma PRIVATE -O3 -fPIC -mavx512f)
endif ()

add_subdirectory(example)

install(
	TARGETS qdma
	DESTINATION /usr/lib64
)

install(
	FILES ${HEAD_FILES}
	DESTINATION /usr/include)