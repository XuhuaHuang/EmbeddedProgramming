cmake_minimum_required(VERSION 3.20)

project(BoostLambdaExample)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BoostLambdaExample "LambdaExample.cpp")
# Modern style CMake: target-centric
target_include_directories(BoostLambdaExample PUBLIC "C:\\boost\\boost_1_80_0")
