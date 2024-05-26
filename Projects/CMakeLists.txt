cmake_minimum_required(VERSION 3.20)

project("projects" LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple directories with CMakeLists.txt located in them
add_subdirectory("Circuit")
add_subdirectory("CLIContactsAppMVC")
add_subdirectory("Dealer/Legacy")
add_subdirectory("GamePromotion")
add_subdirectory("PaxTheCat")
add_subdirectory("TwelveDays")
