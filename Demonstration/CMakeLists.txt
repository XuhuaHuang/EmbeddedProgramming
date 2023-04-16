cmake_minimum_required(VERSION 3.20)

project(Demonstration LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
# add_executable(auto "auto.cpp")
add_executable(multiple_of "demo_is_multiple_of.cpp")
add_executable(unions_align "unions_align.cpp")
add_executable(winapi_cmdarg "winAPI_GetCommandLineA.cpp")
