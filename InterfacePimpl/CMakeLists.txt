cmake_minimum_required(VERSION 3.20)

project(InterfacePimpl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(InterfacePimpl
    "./InterfacePimpl/Person.h"
    "./InterfacePimpl/main.cpp"
)
