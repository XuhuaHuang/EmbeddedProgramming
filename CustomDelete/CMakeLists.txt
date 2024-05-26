cmake_minimum_required(VERSION 3.20)

project("custom_delete" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(custom_delete "custom_delete_fclose.cpp")
