cmake_minimum_required(VERSION 3.20)

project("printf_precision"
    VERSION 1.0.0
    DESCRIPTION "Examples on printf() usage"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(ctrl_printf "ctrl_printf.c")
