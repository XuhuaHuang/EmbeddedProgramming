cmake_minimum_required(VERSION 3.20)

project(LegacyDealer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LegacyDealer
    "dealer.h"
    "dealer.cpp"
    "main.cpp"
)
