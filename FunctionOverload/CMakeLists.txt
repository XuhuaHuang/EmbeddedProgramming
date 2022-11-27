cmake_minimum_required(VERSION 3.20)

project(FunctionOverload)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FunctionOverload
    "MyTime.h"
    "MyTime.cpp"
    "main.cpp"
)
