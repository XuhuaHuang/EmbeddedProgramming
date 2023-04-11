cmake_minimum_required(VERSION 3.20)

project(VariadicTemplateParameter)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(var_template_param
    "sequence.hpp"
    "main.cpp"
)
