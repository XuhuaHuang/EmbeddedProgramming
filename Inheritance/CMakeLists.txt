cmake_minimum_required(VERSION 3.20)

project("inheritance")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(inheritance_notes "notes.cpp")

add_executable(constructor_destructor "constructor_destructor.cpp")

if(MSVC)
    add_subdirectory("BankingAccounts")
    add_subdirectory("Relatives")
endif()
