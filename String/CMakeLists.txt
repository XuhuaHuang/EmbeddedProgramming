cmake_minimum_required(VERSION 3.20)

project("string" LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(str_lab_c "lab.c")
add_executable(str_notes_c "notes.c")
add_executable(get_line_trim "getline_trim.c")

add_executable(str_lab_cpp "lab.cpp")
add_executable(str_notes_cpp "notes.cpp")

add_executable(raw_str_literal "raw_string_literal.cpp")

target_compile_options(raw_str_literal PRIVATE CMAKE_CXX_STANDARD 17 CMAKE_CXX_STANDARD_REQUIRED ON)
