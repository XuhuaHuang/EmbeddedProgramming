cmake_minimum_required(VERSION 3.20)

project(StandardTemplateLibrary)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(Array "array.cpp")
add_executable(ArrayTwoDims "two_dims_array.cpp")
add_executable(ArrayString "array_string.cpp")
add_executable(ArrayTransform "array_tranform.cpp")
add_executable(Dequeue "deque.cpp")
add_executable(List "list.cpp")
add_executable(Map "map.cpp")
add_executable(StringTransform "string_tranform.cpp")
add_executable(Template "template.cpp")
add_executable(Valarray "valarray.cpp")

add_subdirectory(Tuple)
