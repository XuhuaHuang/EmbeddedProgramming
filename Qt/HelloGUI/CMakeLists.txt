cmake_minimum_required(VERSION 3.20)

project("hello_qt_gui"
    VERSION 1.0.0
    DESCRIPTION "Introduction to Qt Creator"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(hello_qt_gui
    "TestWidget.h"
    "TestWidget.cpp"
    "main.cpp"
)

target_link_libraries(hello_qt_gui PRIVATE Qt6::Widgets)

set_target_properties(hello_qt_gui PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)
