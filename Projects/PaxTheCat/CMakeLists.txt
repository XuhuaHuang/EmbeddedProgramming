cmake_minimum_required(VERSION 3.20)

project("pax_the_cat")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pax_the_cat "pax_the_cat.cpp")
add_executable(refactored_pax_the_cat "pax_the_cat_v2.cpp")
