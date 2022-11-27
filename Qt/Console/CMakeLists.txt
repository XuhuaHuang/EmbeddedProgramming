# Qt itself requires at least CMake version 3.16
# Qt version 5.14 is required for this project
cmake_minimum_required(VERSION 3.20)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
project(ConsoleApplication
    VERSION 1.0.0
    DESCRIPTION "Qt console application with CMake example"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Qt                                                              │
# └──────────────────────────────────────────────────────────────────┘
set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

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
# set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build")
add_executable(ConsoleApplication
    # "mainwindow.ui"
    # "mainwindow.cpp"
    "main.cpp"
    # "resources.qrc"
)

# Note that the application will still link against Qt5::Core
# since Qt5::Widgets depends on it.
target_link_libraries(ConsoleApplication PRIVATE Qt5::Core)

set_target_properties(ConsoleApplication PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)
