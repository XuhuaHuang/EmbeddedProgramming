cmake_minimum_required(VERSION 3.20)

project("bitwise_operator" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(bitwise_operator
    bitwise_operator.cpp
)
add_executable(exclusive_or
    xor.c
)
