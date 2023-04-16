cmake_minimum_required(VERSION 3.20)

project(HankerRank LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(CamelCase "CamelCase.cpp")
add_executable(FindDigits "FindDigits.cpp")
add_executable(TimeConversion "TimeConversion.cpp")
add_executable(VirtualFunctions "VirtualFunctions.cpp")
