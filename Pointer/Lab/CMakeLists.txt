cmake_minimum_required(VERSION 3.20)

project(PointerLab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PointerLab
    "Numbers.hpp"
    "Student.hpp"
    "StudentClub.hpp"
    "main.cpp"
)
