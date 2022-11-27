cmake_minimum_required(VERSION 3.20)

project(Template)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(ClassTemplateBasics
    "ClassTemplate/main.cpp"
    "ClassTemplate/Stack.hpp"
)

add_executable(FunctionTemplateBasics
    "FunctionTemplate/main.cpp"
    "FunctionTemplate/max.hpp"
)
