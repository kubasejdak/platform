cmake_minimum_required(VERSION 3.19)

# Define application name and settings.
set(APP platform-demo)
include(demo/settings.cmake)

include(cmake/conan.cmake)
include(cmake/doxygen.cmake)
include(cmake/platform.cmake)
include(cmake/sanitizers.cmake)

project(platform VERSION 1.1.2 LANGUAGES ASM C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

conan_init()

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror $<$<COMPILE_LANGUAGE:C>:-std=c17> $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)

if (USE_ASAN OR USE_LSAN OR USE_UBSAN)
    # Enable compiler sanitizers.
    enable_sanitizers()
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(app)
add_subdirectory(demo)

# Generate documentation.
doxygen_addTarget(${CMAKE_CURRENT_SOURCE_DIR}/app README.md)
