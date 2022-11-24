cmake_minimum_required(VERSION 3.20)

project(FriendClass LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(ClassSquareRectangleExample "example_Square_Rectangle.cpp")
add_executable(ClassTimeDataLab "lab_Time_Date.cpp")

add_subdirectory("TimeDate")
