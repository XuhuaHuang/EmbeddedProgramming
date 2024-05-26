cmake_minimum_required(VERSION 3.20)

project("legacy_dealer" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(legacy_dealer
    "dealer.h"
    "dealer.cpp"
    "main.cpp"
)
