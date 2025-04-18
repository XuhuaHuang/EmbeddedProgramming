cmake_minimum_required(VERSION 3.20)

project("polymorphism" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(animal
    "animal.hpp"
    "animal.cpp"
)

add_executable(polygon "polygon.cpp")
add_executable(pet "pet.cpp")
