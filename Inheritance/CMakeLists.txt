cmake_minimum_required(VERSION 3.20)

project(Inheritance)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(InheritanceNotes "Inheritance_notes.cpp")

add_subdirectory(BankingAccounts)
add_subdirectory(Relatives)
