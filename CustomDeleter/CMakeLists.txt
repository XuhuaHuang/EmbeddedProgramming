cmake_minimum_required(VERSION 3.20)

project(CustomDeleter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CustomDeleter "custom_deleter_fclose.cpp")
