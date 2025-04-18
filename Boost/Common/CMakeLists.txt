cmake_minimum_required(VERSION 3.20)

project("installation_test")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost via vcpkg
find_package(Boost REQUIRED)

add_executable(installation_test "test.cpp")

# Explicitly add Boost include directories if needed
target_include_directories(installation_test PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(installation_test PUBLIC ${Boost_LIBRARIES})
