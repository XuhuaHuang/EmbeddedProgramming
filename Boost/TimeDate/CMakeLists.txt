# vcpkg install boost-timer

cmake_minimum_required(VERSION 3.20)

project("time_date")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost via vcpkg
find_package(Boost REQUIRED COMPONENTS timer)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(progress_timer "progress_timer.cpp")
add_executable(timer "timer.cpp")

# Explicitly add Boost include directories if needed
target_include_directories(progress_timer PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(timer PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(progress_timer PRIVATE Boost::timer)
target_link_libraries(timer PRIVATE Boost::timer)
