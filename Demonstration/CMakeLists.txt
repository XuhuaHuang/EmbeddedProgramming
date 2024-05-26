cmake_minimum_required(VERSION 3.20)

project("demo" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Compiler is Microsoft Visual C++
    # Set MSVC-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zc:__cplusplus /EHsc /std:c17 /std:c++latest /experimental:module")
endif()

# add_executable(auto "auto.cpp")
add_executable(multiple_of "is_multiple_of.cpp")
add_executable(unions_align "unions_align.cpp")
add_executable(winapi_cmdarg "winapi_cmdarg.cpp")
