cmake_minimum_required(VERSION 3.20)

project("variadic_template_param")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(variadic_template_param
    "sequence.hpp"
    "main.cpp"
)
