cmake_minimum_required(VERSION 3.20)

project("numpy_cxx" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 COMPONENTS Interpreter NumPy Development REQUIRED)

add_executable(numpycxx main.cpp)

# Stop Visual Studio Solution from looking for python311_d.dll
set(CMAKE_BUILD_TYPE Release)

# Adding additional include directories
target_include_directories(numpycxx
    PUBLIC
    ${PYTHON_INCLUDE_DIRS}
    ${PYTHON_INSTALL_LOC}/include
    ${PYTHON_INSTALL_LOC}/Lib/site-packages/numpy/core/include
)

target_link_libraries(numpycxx
    PUBLIC
    ${PYTHON_LIBRARIES}
    Python3::Python
    Python3::NumPy
)
