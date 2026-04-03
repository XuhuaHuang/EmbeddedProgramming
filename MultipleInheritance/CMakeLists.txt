cmake_minimum_required(VERSION 3.20)

project("multiple_inheritance" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(date_time "date_time.cpp")
add_executable(coloured_circle "coloured_circle.cpp")
add_executable(modern_coloured_circle "modern_coloured_circle.cpp")
