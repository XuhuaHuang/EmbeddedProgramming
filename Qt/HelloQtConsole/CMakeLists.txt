# Qt itself requires at least CMake version 3.16
# Qt version 6.4.1 is used for this project
cmake_minimum_required(VERSION 3.20)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
project(HelloQtConsole
    VERSION 1.0.0
    DESCRIPTION "Qt console application with CMake"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Qt                                                              │
# └──────────────────────────────────────────────────────────────────┘
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(WIN32)
    set(Qt6_DIR "C:/Qt6/6.4.1/mingw_64/lib/cmake/Qt6" CACHE PATH "directory where Qt6Config.cmake exists.")
elseif(APPLE)
    set(Qt6_DIR "/usr/local/Cellar/qt/6.4.1/clang_64/lib/cmake/Qt6/" CACHE PATH "directory where Qt6Config.cmake exists.")
else()
    set(Qt6_DIR "" CACHE PATH "directory where Qt6Config.cmake exists.")
endif()

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

# ┌──────────────────────────────────────────────────────────────────┐
# │  Executable                                                      │
# └──────────────────────────────────────────────────────────────────┘
add_executable(HelloQtConsole
    qt_console.cpp
)

target_link_libraries(HelloQtConsole PRIVATE Qt6::Core)

set_target_properties(HelloQtConsole PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)
