cmake_minimum_required(VERSION 3.20)

project("type_info")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(decltype "decltype.cpp" "README.md")
add_executable(is_something "is_something.cpp" "README.md")
