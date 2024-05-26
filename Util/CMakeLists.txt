cmake_minimum_required(VERSION 3.20)

project("utility"
    VERSION 1.0.0
    DESCRIPTION "Demonstration on utility functions"
    LANGUAGES CXX
)

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

# Add sub-directories with CMakeLists.txt in them
add_subdirectory("stdcxx20")
add_subdirectory("stdcxx23/CountLeaves")
add_subdirectory("tests")
