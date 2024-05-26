cmake_minimum_required(VERSION 3.20)

project("encapsulation" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(itf_date "interface_design_date.cpp")
add_executable(printable_entity "printable_entity.cpp")
add_executable(itf_uncopyable "uncopyable_class.cpp")
