cmake_minimum_required(VERSION 3.20)

project(PointerLectureDemoMyCalendar)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PointerLectureDemoMyCalendar
    "MyTime.hpp" "MyDate.hpp"
    "MyCalendar.hpp"
    "main.cpp"
)
