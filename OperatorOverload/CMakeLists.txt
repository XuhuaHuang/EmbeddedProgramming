cmake_minimum_required(VERSION 3.20)

project("operator_overload" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(assignment "assignment.cpp")
add_executable(conversion "conversion.cpp")
add_executable(insertion_extraction "insertion_extraction.cpp")
add_executable(parenthesis "parenthesis_fn_obj.cpp")
