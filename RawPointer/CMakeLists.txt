cmake_minimum_required(VERSION 3.20)

project("raw_pointer" LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(raw_pointer_c "pointer.c")
add_executable(void_pointer_c "void_ptr.c")
add_executable(void_pointer_cpp "void_ptr.cpp")

target_compile_features(raw_pointer_c PRIVATE c_std_17)
target_compile_features(void_pointer_c PRIVATE c_std_17)
target_compile_features(void_pointer_cpp PRIVATE cxx_std_23)
