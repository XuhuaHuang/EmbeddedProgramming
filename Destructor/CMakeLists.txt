cmake_minimum_required(VERSION 3.20)

project(Destructor)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(DestructorNotes "destructor_notes.cpp")
add_executable(SequenceDestruction "sequence_destruction.cpp")
