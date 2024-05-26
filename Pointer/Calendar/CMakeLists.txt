cmake_minimum_required(VERSION 3.20)

project("calendar")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(calendar
    "Time.hpp"
    "Date.hpp"
    "Calendar.hpp"
    "main.cpp"
)
