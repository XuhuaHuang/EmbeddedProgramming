# AddTargetWithFolders.cmake
# A utility function to create targets and organize files into folders for IDEs

function(add_target_with_folders target_name target_type)
    # Collect all source and header files recursively
    file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
    file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/include/*.h")
    file(GLOB_RECURSE LIB_FILES "${CMAKE_SOURCE_DIR}/lib/*.cpp")

    # Create the target
    if(${target_type} STREQUAL "EXECUTABLE")
        add_executable(${target_name} ${SRC_FILES} ${HEADER_FILES} ${LIB_FILES})
    elseif(${target_type} STREQUAL "STATIC_LIBRARY")
        add_library(${target_name} STATIC ${SRC_FILES} ${HEADER_FILES} ${LIB_FILES})
    elseif(${target_type} STREQUAL "SHARED_LIBRARY")
        add_library(${target_name} SHARED ${SRC_FILES} ${HEADER_FILES} ${LIB_FILES})
    else()
        message(FATAL_ERROR "Unknown target type: ${target_type}")
    endif()

    # Set include directories
    target_include_directories(${target_name} PRIVATE "${CMAKE_SOURCE_DIR}/include")

    # Organize files into folders for IDE view
    foreach(FILE ${SRC_FILES} ${HEADER_FILES} ${LIB_FILES})
        file(RELATIVE_PATH REL_PATH "${CMAKE_SOURCE_DIR}" "${FILE}")
        get_filename_component(FOLDER "${REL_PATH}" DIRECTORY)
        string(REPLACE "/" "\\" GROUP "${FOLDER}")
        source_group("${GROUP}" FILES "${FILE}")
    endforeach()
endfunction()
