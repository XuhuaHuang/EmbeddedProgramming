cmake_minimum_required(VERSION 3.18)

project("numpy_cxx")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(numpycxx main.cpp)

find_package (Python3 COMPONENTS Interpreter NumPy Development REQUIRED)

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
    Python3::NumPy
)
