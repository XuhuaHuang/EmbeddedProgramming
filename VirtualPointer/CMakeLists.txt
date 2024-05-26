cmake_minimum_required(VERSION 3.20)

project("virtual_pointer")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(virtual_pointer "vtbl_vptr.cpp")
