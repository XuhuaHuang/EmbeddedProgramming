cmake_minimum_required(VERSION 3.20)

# Project metadata
project("static-scoping" LANGUAGES CXX)

# Use modern C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable target
add_executable(static_scoping
    "static_scope_binding.cpp"
)

# Recommended compiler warnings (portable)
if (MSVC)
    target_compile_options(static_scoping PRIVATE /W4 /permissive-)
else()
    target_compile_options(static_scoping PRIVATE -Wall -Wextra -Wpedantic)
endif()

message(STATUS "Building target: static_scoping with C++${CMAKE_CXX_STANDARD}")
