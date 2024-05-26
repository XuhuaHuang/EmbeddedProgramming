cmake_minimum_required(VERSION 3.20)

project("bitwise_operator" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bitwise_operator "bitwise_operator.cpp")
add_executable(exclusive_or "xor.c")
