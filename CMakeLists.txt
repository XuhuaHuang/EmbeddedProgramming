cmake_minimum_required(VERSION 3.20)

project(EmbeddedProgramming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
add_subdirectory("Vector")
add_subdirectory("View")
