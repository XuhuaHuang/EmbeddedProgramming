cmake_minimum_required(VERSION 3.00)

project("raw_pointer")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED OFF)

add_executable(raw_pointer_c "pointer.c")
add_executable(void_pointer_c "void_ptr.c")
