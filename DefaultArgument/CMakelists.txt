cmake_minimum_required(VERSION 3.20)

project(DefaultArgument LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(ClassPersonExample "example_Person.cpp")
add_executable(ClassScheduleLab "lab_Schedule.cpp")
add_executable(ClassPersonNotes "notes_class_Person.cpp")
add_executable(ClassScheduleNotes "notes_class_Schedule.cpp")
