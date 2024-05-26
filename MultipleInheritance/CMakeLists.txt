cmake_minimum_required(VERSION 3.20)

project("multiple_inheritance" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(date_time "date_time.cpp")
add_executable(coloured_circle "coloured_circle.cpp")
