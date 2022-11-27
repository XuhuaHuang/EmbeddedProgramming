cmake_minimum_required(VERSION 3.20)

project(MoveSemantic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(MoveAssignment "move_assignment.cpp")
add_executable(MoveSemantic "move_semantics.cpp")
add_executable(MoveWithUtil "move_with_util.cpp")
