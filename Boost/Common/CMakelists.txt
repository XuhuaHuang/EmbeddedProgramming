cmake_minimum_required(VERSION 3.20)

project(BoostInstallationTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BoostInstallationTest "./test.cpp")
# Modern style CMake: target-centric
target_include_directories(BoostInstallationTest PUBLIC "C:\\boost\\boost_1_80_0")
