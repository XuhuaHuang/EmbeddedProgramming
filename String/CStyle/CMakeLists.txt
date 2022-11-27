cmake_minimum_required(VERSION 3.20)

project(StringCStyle LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(StringLabCStyle "stringLab.c")
add_executable(StringNotesCStyle "stringNotes.c")
add_executable(GetLineTrimCStyle "getLineTrimImpl.c")
