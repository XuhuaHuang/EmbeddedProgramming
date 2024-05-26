cmake_minimum_required(VERSION 3.20)

project("vector" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vector_lab "lab.cpp")
add_executable(vector_lab_with_template "lab_with_template.cpp")
add_executable(vector_notes "notes.cpp")
