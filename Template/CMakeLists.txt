cmake_minimum_required(VERSION 3.20)

project("template")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(template_cls
    "ClassTemplate/main.cpp"
    "ClassTemplate/Stack.hpp"
)

add_executable(template_fn
    "FunctionTemplate/main.cpp"
    "FunctionTemplate/max.hpp"
)

add_executable(template_notes
    "template_notes.cpp"
)

add_executable(template_for
    "template_for.cpp"
)

target_compile_options(template_for PRIVATE -std=c++26)
