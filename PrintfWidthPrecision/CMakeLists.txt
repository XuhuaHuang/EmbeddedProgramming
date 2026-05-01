cmake_minimum_required(VERSION 3.20)

project("printf_precision"
    VERSION 1.0.0
    DESCRIPTION "Examples on printf() usage"
    LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(ctrl_printf
    ctrl_printf.c
)

add_executable(std_fmtprint
    std_fmtprint.cpp
)

add_executable(std_printf
    std_printf.cpp
)
