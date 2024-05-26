cmake_minimum_required(VERSION 3.20)

project("structural_binding_write_aceess")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(structural_binding_write_aceess
    "customer.hpp"
    "customer.cpp"
    "main.cpp"
)
