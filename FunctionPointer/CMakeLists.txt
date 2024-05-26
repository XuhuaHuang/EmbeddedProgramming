cmake_minimum_required(VERSION 3.20)

project("function_pointer" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bind_entity_add "bind_entity_add.cpp")
add_executable(for_each_fn_ptr "function_pointers.cpp")
