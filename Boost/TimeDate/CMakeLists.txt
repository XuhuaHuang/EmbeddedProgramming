cmake_minimum_required(VERSION 3.20)

project(BoostTimeDate)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(ProgressTimer "progress_timer.cpp")
add_executable(Timer "timer.cpp")

# Adding additional include directories
target_include_directories(ProgressTimer PUBLIC "C:\\boost\\boost_1_80_0")
target_include_directories(Timer PUBLIC "C:\\boost\\boost_1_80_0")
