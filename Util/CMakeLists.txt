cmake_minimum_required(VERSION 3.20)

project(Utility)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add sub-directories with CMakeLists.txt in them
add_subdirectory("stdcxx23/CountLeaves")
add_subdirectory("tests")
