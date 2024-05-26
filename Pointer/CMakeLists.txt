cmake_minimum_required(VERSION 3.20)

project("pointer")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(compare_replace "compare_replace.cpp")
add_executable(smart_ptr "smart_ptr.cpp")
add_executable(weak_ptr "weak_ptr.cpp")

add_subdirectory("Calendar")
add_subdirectory("StudentClub")
