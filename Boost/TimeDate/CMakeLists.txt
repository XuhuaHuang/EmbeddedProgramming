cmake_minimum_required(VERSION 3.20)

project("time_date")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(progress_timer "progress_timer.cpp")
add_executable(timer "timer.cpp")

# Adding additional include directories
target_include_directories(progress_timer PUBLIC "C:\\boost\\boost_1_82_0")
target_include_directories(timer PUBLIC "C:\\boost\\boost_1_82_0")
