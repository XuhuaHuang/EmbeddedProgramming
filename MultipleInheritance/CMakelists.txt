cmake_minimum_required(VERSION 3.20)

project(MultipleInheritance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(ClassTimeDateExample "example_Time_Date.cpp")
add_executable(ClassColouredCircleLab "lab_Circle_Colour.cpp")
