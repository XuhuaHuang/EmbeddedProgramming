cmake_minimum_required(VERSION 3.20)

project("friend_class" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(square_rectangle "square_rectangle.cpp")
add_executable(time_date "time_date.cpp")

add_subdirectory("TimeDate")
