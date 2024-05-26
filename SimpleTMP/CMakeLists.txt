cmake_minimum_required(VERSION 3.20)

project("simple_template_metaprogramming")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(fibonacci_series "FibonacciSeries.cpp")
add_executable(recursive_factorial "RecursiveFactorial.cpp")

add_subdirectory("FibonacciSeriesWithStruct")
