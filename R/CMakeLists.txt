cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(statistics LANGUAGES CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set any necessary compile flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Compiler is Microsoft Visual C++
    # Set MSVC-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Compiler is g++
    # Set g++-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_executable(monte_carlo_integration
    monte_carlo_integration.cpp
)

add_executable(normal_distribution_vec
    normal_distribution_vec.cpp
)

add_executable(normal_distribution
    normal_distribution.cpp
)

add_executable(simple_linear_regression
    simple_linear_regression.cpp
)
