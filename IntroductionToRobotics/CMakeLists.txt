cmake_minimum_required(VERSION 3.20)

project("robitics_intro")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set any necessary compile flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Compiler is Microsoft Visual C++
    # Set MSVC-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zc:__cplusplus /EHsc /std:c17 /std:c++latest /experimental:module")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Compiler is g++
    # Set g++-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_executable(matrix_multiply_unittest
    "matrix_multiply_unittest.cpp"
    "matrix_multiply.hpp"
    "matrix_multiply.inl"
)
