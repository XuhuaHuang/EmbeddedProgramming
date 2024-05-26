cmake_minimum_required(VERSION 3.20)

project("copy_constructor" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(derived_class_copying "derived_class_copying.cpp")
add_executable(rectangle "rectangle.cpp")
add_executable(time "time.cpp")
