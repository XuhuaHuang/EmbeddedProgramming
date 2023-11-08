cmake_minimum_required(VERSION 3.20)

project(EmbeddedProgramming LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

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

# The following executable is a preliminary "Hello World" program in the repository
add_executable(HelloWorld "Miscellaneous/hello_world.cpp" "LICENSE.md" "README.md")

# To add more build target,
# Simply call the add_directory() function with the folder name with a "CMakeLists.txt" in it
# Consider the following example:
# add_subdirectory("AbstractDataTypeCStyle")  # "./AbstractDataTypeCStyle/CMakeLists.txt"
add_subdirectory("Array")
add_subdirectory("BitwiseOperator")
# add_subdirectory("Boost")
# add_subdirectory("Util")  # "Util/CMakeLists.txt", includes sub-directories inside
add_subdirectory("ValArray")
add_subdirectory("Vector")
add_subdirectory("View")
# add_subdirectory("WriteAccessStructralBinding")
