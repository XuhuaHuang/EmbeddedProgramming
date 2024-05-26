cmake_minimum_required(VERSION 3.20)

project("move_semantic" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(move_assignment "move_assignment.cpp")
add_executable(move_semantic "move_semantics.cpp")
add_executable(move_with_util "move_with_util.cpp")
