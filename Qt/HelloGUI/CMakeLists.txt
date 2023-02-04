cmake_minimum_required(VERSION 3.20)

project(HelloGUI
    VERSION 1.0.0
    DESCRIPTION "Introduction to Qt Creator"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Platform dependant Qt-CMake config                              │
# └──────────────────────────────────────────────────────────────────┘
if(WIN32)
    set(Qt5_DIR "C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5" CACHE PATH "directory where Qt5Config.cmake exists.")
elseif(APPLE)
    set(Qt5_DIR "/usr/local/Cellar/qt/5.14.0/clang_64/lib/cmake/Qt5/" CACHE PATH "directory where Qt5Config.cmake exists.")
else()
    set(Qt5_DIR "" CACHE PATH "directory where Qt5Config.cmake exists.")
endif()

find_package(Qt5 REQUIRED COMPONENTS Widgets)

if(WIN32)
    set(CMAKE_WIN32_EXECUTABLE ON)
elseif(APPLE)
    set(CMAKE_MACOSX_BUNDLE ON)
endif()

# ┌──────────────────────────────────────────────────────────────────┐
# │  Executable                                                      │
# └──────────────────────────────────────────────────────────────────┘
add_executable(HelloGUI
    "TestWidget.h"
    "TestWidget.cpp"
    "main.cpp"
)

# Note that the application will still link against Qt5::Core
# since Qt5::Widgets depends on it.
target_link_libraries(HelloGUI PRIVATE Qt5::Core)

set_target_properties(HelloGUI PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)
