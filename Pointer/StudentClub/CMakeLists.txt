cmake_minimum_required(VERSION 3.20)

project("student_club")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student_club
    "Numbers.hpp"
    "Student.hpp"
    "StudentClub.hpp"
    "main.cpp"
)
