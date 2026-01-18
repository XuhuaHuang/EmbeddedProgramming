cmake_minimum_required(VERSION 3.20)

project("misc" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Compiler is Microsoft Visual C++
    # Set MSVC-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module")

    add_executable(winapi_cmdarg "winapi_cmdarg.cpp")
    add_executable(multiple_of "is_multiple_of.cpp")
endif()

add_executable(unions_align "unions_align.cpp")
add_executable(std_any "use_std_any.cpp")
add_executable(std_make_any "use_std_make_any.cpp")
