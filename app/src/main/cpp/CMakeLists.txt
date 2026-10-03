cmake_minimum_required(VERSION 3.22.1)

project("aicoded")

add_library(
        aicoded
        SHARED
        native-lib.cpp
)

# llama.cpp source
set(LLAMA_CPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../llama.cpp")

# llama.cpp ko project mein include karo
add_subdirectory(
        "${LLAMA_CPP_DIR}"
        "${CMAKE_CURRENT_BINARY_DIR}/llama-build"
        EXCLUDE_FROM_ALL
)

find_library(
        log-lib
        log
)

target_link_libraries(
        aicoded
        llama
        ${log-lib}
)
