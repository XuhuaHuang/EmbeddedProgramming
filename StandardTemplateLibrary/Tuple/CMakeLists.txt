cmake_minimum_required(VERSION 3.20)

project(Tuple)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(CompareTwoNumbers "compare_two_nums.cpp")
add_executable(GetTie "get_tie.cpp")
add_executable(TupleNotes "notes.cpp")
