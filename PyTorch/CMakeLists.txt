cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project("dcgan")

# Ensure the path to libtorch is correct. Adjust it according to your installation.
set(Torch_DIR "D:/include/libtorch/share/cmake/Torch")
set(Torch_INCLUDE_DIRS "D:/include/libtorch/include")
find_package(Torch REQUIRED)

# Include the Torch headers
include_directories(${Torch_INCLUDE_DIRS})

# Set any necessary compile flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Compiler is Microsoft Visual C++
    # Set MSVC-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Compiler is g++
    # Set g++-specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_executable(dcgan "dcgan.cpp")
target_link_libraries(dcgan "${TORCH_LIBRARIES}")
set_property(TARGET dcgan PROPERTY CXX_STANDARD 20)

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if(MSVC)
    file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
    add_custom_command(TARGET dcgan
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${TORCH_DLLS}
        $<TARGET_FILE_DIR:dcgan>)
endif(MSVC)
