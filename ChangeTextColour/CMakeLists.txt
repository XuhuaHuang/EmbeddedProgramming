cmake_minimum_required(VERSION 3.20)

project(ChangeTextColour)

set(C_STANDARD 98)
set(C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    change_text_colour_c
    "change_text_colour.c"
)

add_executable(
    change_text_colour_cpp
    "color.hpp"
    "color.cpp"
)
