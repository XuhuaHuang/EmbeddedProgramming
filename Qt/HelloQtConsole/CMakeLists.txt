# Qt itself requires at least CMake version 3.16
# Qt version 6.8.2 is used for this project
cmake_minimum_required(VERSION 3.20)

project("hello_qt_console"
    VERSION 1.0.0
    DESCRIPTION "Qt console application with CMake"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

qt_add_executable(hello_qt_console
    "qt_console.cpp"
)

target_link_libraries(hello_qt_console PRIVATE Qt6::Core)

set_target_properties(hello_qt_console PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)
