cmake_minimum_required(VERSION 3.20)

project("stl_ranges" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ranges_basics_notes "ranges_notes.cpp")
