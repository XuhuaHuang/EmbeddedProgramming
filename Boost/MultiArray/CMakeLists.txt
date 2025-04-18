# vcpkg install boost-multi-array

cmake_minimum_required(VERSION 3.20)

project("multi_array" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost via vcpkg
find_package(Boost REQUIRED COMPONENTS multi_array)

add_executable(multi_array "multi_array.cpp")

# Explicitly add Boost include directories if needed
target_include_directories(multi_array PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(multi_array PRIVATE Boost::multi_array)
