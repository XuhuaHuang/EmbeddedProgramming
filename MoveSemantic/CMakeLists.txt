cmake_minimum_required(VERSION 3.20)

project("move_semantic" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(UTIL_ROOT ../Util ABSOLUTE)

add_executable(move_assignment "move_assignment.cpp")
add_executable(move_semantic "move_semantics.cpp")
add_executable(move_with_util "move_with_util.cpp")

target_include_directories(move_with_util PRIVATE ${UTIL_ROOT})
