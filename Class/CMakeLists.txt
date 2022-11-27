cmake_minimum_required(VERSION 3.20)

project(Class LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(AngryBirdsWithClass
    "AngryBirds/AngryBirds.hpp"
    "AngryBirds/AngryBirds.cpp"
    "AngryBirds/main.cpp"
)
add_executable(ClassNotes "ClassNotesUser.cpp")
