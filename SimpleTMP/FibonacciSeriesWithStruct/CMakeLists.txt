cmake_minimum_required(VERSION 3.20)

project(FibonacciSeriesWithStruct)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FibonacciSeriesWithStruct
    "Fibonacci.hpp"
    "main.cpp"
)
