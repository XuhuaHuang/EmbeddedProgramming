cmake_minimum_required(VERSION 3.20)

project("array" LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(array
    array.c
)
add_executable(matrix
    matrix.c
)

add_executable(iterable_array
    iterable_array.cpp
)
