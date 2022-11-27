cmake_minimum_required(VERSION 3.20)

project(CopyConstructor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(DerivedClassCopying "derived_class_copying.cpp")
add_executable(ClassRectangleExample "example_Rectangle.cpp")
add_executable(ClassTimeLab "lab_Time.cpp")
