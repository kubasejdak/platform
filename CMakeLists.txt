cmake_minimum_required(VERSION 3.15)

include(cmake/doxygen.cmake)

if (NOT DEFINED PLATFORM)
    message(FATAL_ERROR "'PLATFORM' is not defined!")
endif ()

# Define application name and settings.
set(APP platform-demo)
include(demo/${APP}.cmake)

# Setup platform toolchain file.
include(app/${PLATFORM}/toolchain.cmake)

project(platform VERSION 1.0 LANGUAGES ASM C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add conan files.
if (EXISTS ${CMAKE_BINARY_DIR}/conan_paths.cmake)
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif ()

# Find external libraries.
find_package(fmt REQUIRED)

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_subdirectory(app)
add_subdirectory(demo)

# Generate documentation.
doxygen_addTarget(${CMAKE_CURRENT_SOURCE_DIR}/app README.md)
