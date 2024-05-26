cmake_minimum_required(VERSION 3.20)

project("user_defined_literal"
    VERSION 1.0.0
    DESCRIPTION "Demonstration on User-defined Literals in C++20"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(user_defined_literal "udl_notes.cpp")
