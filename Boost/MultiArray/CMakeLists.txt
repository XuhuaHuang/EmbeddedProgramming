cmake_minimum_required(VERSION 3.20)

project("multi_array" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(multi_array "multi_array.cpp")

target_include_directories(multi_array PUBLIC "C:\\boost\\boost_1_82_0")
