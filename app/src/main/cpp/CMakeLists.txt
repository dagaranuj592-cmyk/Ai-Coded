cmake_minimum_required(VERSION 3.22.1)

project("aicoded")

set(LLAMA_CPP_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../llama.cpp"
)

set(GGML_NATIVE OFF CACHE BOOL "" FORCE)
set(GGML_OPENMP OFF CACHE BOOL "" FORCE)
set(GGML_LLAMAFILE OFF CACHE BOOL "" FORCE)
set(LLAMA_OPENSSL OFF CACHE BOOL "" FORCE)

add_subdirectory(
    "${LLAMA_CPP_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/llama.cpp"
    EXCLUDE_FROM_ALL
)

add_library(
    aicoded
    SHARED
    native-lib.cpp
)

find_library(log-lib log)

target_link_libraries(
    aicoded
    llama
    ${log-lib}
)
