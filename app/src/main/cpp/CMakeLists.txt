cmake_minimum_required(VERSION 3.22.1)

project("aicoded")

add_library(
        aicoded
        SHARED
        native-lib.cpp
)

find_library(
        log-lib
        log
)

target_link_libraries(
        aicoded
        ${log-lib}
)
