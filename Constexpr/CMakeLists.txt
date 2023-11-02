cmake_minimum_required(VERSION 3.20)

project(Constexpr)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConstexprForLoop "constexpr_for.cpp")
add_executable(NotesOnConstexpr "constexpr_notes.cpp")
