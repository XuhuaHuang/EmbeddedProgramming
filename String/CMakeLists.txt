cmake_minimum_required(VERSION 3.20)

project("String" LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(CStyle)
add_subdirectory(CXXStyle)
add_subdirectory(RawStringLiteral)
