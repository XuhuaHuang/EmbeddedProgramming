cmake_minimum_required(VERSION 3.20)

project(Polymorphism LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(AnimalExample
    "example_Animal.hpp"
    "example_Animal.cpp"
)
add_executable(PolygonExample "example_Polygon.cpp")
add_executable(ClassPetLab "lab_Pet.cpp")
