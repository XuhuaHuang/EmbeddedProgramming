cmake_minimum_required(VERSION 3.20)

project(WriteAccessStructralBinding)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(WriteAccessStructralBinding
    "customer.hpp"
    "customer.cpp"
    "main.cpp"
)
