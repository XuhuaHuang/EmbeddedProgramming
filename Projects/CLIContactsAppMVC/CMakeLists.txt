cmake_minimum_required(VERSION 3.20)

project("contact_cli" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(contact_cli "main.cpp")
