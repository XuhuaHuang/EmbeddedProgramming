cmake_minimum_required(VERSION 3.20)

project("design_principle" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(composition_over_inheritance "composition_over_inheritance.cpp")
add_executable(interface_segregation "interface_segregation.cpp")
