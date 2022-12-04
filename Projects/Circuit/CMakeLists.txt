cmake_minimum_required(VERSION 3.20)

project(Circuit
    VERSION 1.0.0
    DESCRIPTION "Console application representing a basic analog circuitry"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(Circuit
    "circuit.hpp"
    "circuit.cpp"
    "main.cpp"
)
