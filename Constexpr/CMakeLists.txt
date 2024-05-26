cmake_minimum_required(VERSION 3.20)

project("constexpr" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(constexpr_for "constexpr_for.cpp")
add_executable(constexpr_notes "notes.cpp")
