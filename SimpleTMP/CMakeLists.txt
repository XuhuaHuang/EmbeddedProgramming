cmake_minimum_required(VERSION 3.20)

project(SimpleTemplateMetaprogramming)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(FibonacciSeries "FibonacciSeries.cpp")
add_executable(RecursiveFactorial "RecursiveFactorial.cpp")

add_subdirectory(FibonacciSeriesWithStruct)
