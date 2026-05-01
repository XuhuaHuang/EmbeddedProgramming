cmake_minimum_required(VERSION 3.20)

project("fibonacci_st")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(fibonacci_st
    Fibonacci.hpp
    main.cpp
)
