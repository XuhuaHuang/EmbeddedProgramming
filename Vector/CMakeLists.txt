cmake_minimum_required(VERSION 3.20)

project(Vector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(VectorLab "vectorLab.cpp")
add_executable(VectorLabTemplated "vectorLabTemplated.cpp")
add_executable(VectorNotes "vectorNotes.cpp")
