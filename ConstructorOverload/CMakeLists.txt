cmake_minimum_required(VERSION 3.20)

project("constructor_overload")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(constructor_overload
    "Time.hpp"
    "Rectangle.hpp"
    "Point.hpp"
    "main.cpp"
)
