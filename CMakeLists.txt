cmake_minimum_required(VERSION 3.15)

# Define application name and settings.
set(APP platform-demo)
include(demo/${APP}.cmake)

include(cmake/conan.cmake)
include(cmake/doxygen.cmake)
include(cmake/platform.cmake)

project(platform VERSION 1.1.0 LANGUAGES ASM C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

conan_init()

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(app)
add_subdirectory(demo)

# Generate documentation.
doxygen_addTarget(${CMAKE_CURRENT_SOURCE_DIR}/app README.md)
