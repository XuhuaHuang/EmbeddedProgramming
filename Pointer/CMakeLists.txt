cmake_minimum_required(VERSION 3.20)

project(Pointer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(CompareAndReplaceWithPointer "compare_replace.cpp")
add_executable(SmartPointer "smart_ptr.cpp")
add_executable(WeakPointer "weak_ptr.cpp")

# Adding sub-directories
add_subdirectory("Lab")
add_subdirectory("LectureDemo")
