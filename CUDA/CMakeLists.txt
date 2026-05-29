# https://cliutils.gitlab.io/modern-cmake/chapters/packages/CUDA.html
# https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
# Compute Unified Device Architecture (CUDA) is a parallel computing platform and application programming interface (API) model created by NVIDIA.
# This CMake configuration file sets up a simple CUDA project for vector addition.
# This CMake configuration file is designed to build a CUDA project for vector addition. It specifies the required CUDA version, sets the CUDA architecture, and includes necessary directories and libraries.
# cmake -B build -DCMAKE_TOOLCHAIN_FILE="C:/Users/$ENV{USERNAME}/vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE=Debug
# cmake --build build --target clean

cmake_minimum_required(VERSION 3.20)

project(vector_addition LANGUAGES CXX CUDA)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(CUDAToolkit REQUIRED)

enable_language(CUDA)

if(NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 14)
    set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif()

include(CheckLanguage)
check_language(CUDA)

include(CMakePrintHelpers)

if(NOT CMAKE_CUDA_COMPILER)
    message(FATAL_ERROR "CUDA compiler not found. Please ensure CUDA is installed and the path to the compiler is set correctly.")
endif()

# Print the CUDA compiler version
cmake_print_variables(CMAKE_CUDA_COMPILER)
cmake_print_variables(CMAKE_CUDA_COMPILER_ID)
cmake_print_variables(CMAKE_CUDA_COMPILER_VERSION)

cmake_print_variables(CUDAToolkit_INCLUDE_DIRS)
cmake_print_variables(CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES)

set(CMAKE_CUDA_ARCHITECTURES 86)
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -arch=sm_86")

add_executable(vector_addition
    vector_addition.cu
)
target_include_directories(vector_addition PRIVATE
    # ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CUDAToolkit_INCLUDE_DIRS}
    ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
)
target_link_libraries(vector_addition PRIVATE CUDA::cublas)

add_executable(index
    index.cu
)
target_include_directories(index PRIVATE
    # ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CUDAToolkit_INCLUDE_DIRS}
    ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
)
target_link_libraries(index PRIVATE CUDA::cublas)
