cmake_minimum_required(VERSION 3.20)

project(BasicPlane)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(BasicPlaneModule
    "BasicPlane/BasicPlane.Figures.ixx"
    "BasicPlane/BasicPlane.Figures-Point.ixx"
    "BasicPlane/BasicPlane.Figures-Rectangle.ixx"
    "BasicPlane/BasicPlane.Figures-Rectangle.cpp"
)

add_executable(basic_plane_exec
    "BasicPlane/main.cpp"
)

target_link_libraries(basic_plane_exec BasicPlaneModule)
