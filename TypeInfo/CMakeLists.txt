cmake_minimum_required(VERSION 3.20)

project(TypeInfo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(Decltype "decltype.cpp" "README.md")
add_executable(IsSomething "is_something.cpp" "README.md")
