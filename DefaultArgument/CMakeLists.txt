cmake_minimum_required(VERSION 3.20)

project("default_argument" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(person "person.cpp")
add_executable(schedule "schedule.cpp")
