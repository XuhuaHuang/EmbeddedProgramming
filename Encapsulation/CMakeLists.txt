cmake_minimum_required(VERSION 3.20)

project(Encapsulation)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(IDate "interface_design_example.cpp")
add_executable(PrintableEntity "printable_entity.cpp")
add_executable(IUncopyable "uncopyable_class.cpp")
