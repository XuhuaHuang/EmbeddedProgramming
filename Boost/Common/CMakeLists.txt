cmake_minimum_required(VERSION 3.20)

project("installation_test")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(installation_test "test.cpp")
# Modern style CMake: target-centric
target_include_directories(installation_test PUBLIC "C:\\boost\\boost_1_82_0")
