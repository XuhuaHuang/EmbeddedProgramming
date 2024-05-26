cmake_minimum_required(VERSION 3.20)

project("function_overload")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(function_overload
    "Time.hpp"
    "Time.cpp"
    "main.cpp"
)
