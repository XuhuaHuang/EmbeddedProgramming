cmake_minimum_required(VERSION 3.20)

project("std_template_lib")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(array "array.cpp")
add_executable(two_dims_array "two_dims_array.cpp")
add_executable(array_string "array_string.cpp")
add_executable(array_tranform "array_tranform.cpp")
add_executable(dequeue "deque.cpp")
add_executable(list "list.cpp")
add_executable(map "map.cpp")
add_executable(string_tranform "string_tranform.cpp")
add_executable(template "template.cpp")
add_executable(valarray "valarray.cpp")

add_subdirectory("tuple")
