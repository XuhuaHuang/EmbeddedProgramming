cmake_minimum_required(VERSION 3.20)

project("relatives")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(relatives
    "Relatives.hpp"
    "Relatives.cpp"
    "main.cpp"
)
