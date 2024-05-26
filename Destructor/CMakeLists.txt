cmake_minimum_required(VERSION 3.20)

project("destructor")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(destructor_notes "notes.cpp")
add_executable(sequence_destruction "sequence_destruction.cpp")
