cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project("dcgan")

set(Torch_DIR "C:/libtorch/")
set(CMAKE_PREFIX_PATH "C:/libtorch/share/cmake/")

find_package(Torch REQUIRED)

add_executable(dcgan "dcgan.cpp")

target_link_libraries(dcgan
    "${TORCH_LIBRARIES}"
    "C:/libtorch/lib/c10.dll"
    "C:/libtorch/lib/torch_cpu.dll"
)

set_property(TARGET dcgan PROPERTY CXX_STANDARD 20)
