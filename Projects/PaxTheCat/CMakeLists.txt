cmake_minimum_required(VERSION 3.20)

project(PaxTheCat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PaxTheCat "pax_the_cat.cpp")
add_executable(RefactoredPaxTheCat pax_the_cat_v2.cc)
