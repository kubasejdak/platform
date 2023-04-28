cmake_minimum_required(VERSION 3.25)

include(demo/settings.cmake)

include(cmake/conan.cmake)
include(cmake/doxygen.cmake)
include(cmake/platform.cmake)
include(cmake/sanitizers.cmake)

project(platform VERSION 1.1.2 LANGUAGES ASM C CXX)

if (GENERATE_DOCS)
    doxygen_addTarget(${CMAKE_CURRENT_SOURCE_DIR}/lib README.md)
    return()
endif ()

if (USE_CONAN)
    conan_init_wrapper()
    conan_init_profile()
    conan_cmake_install(PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR} BUILD missing PROFILE_BUILD default PROFILE_HOST conan-profile)
    conan_load_buildinfo()
    conan_basic_setup()
endif ()

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror $<$<COMPILE_LANGUAGE:C>:-std=c17> $<$<COMPILE_LANGUAGE:CXX>:-std=c++20>)

if (USE_ASAN OR USE_LSAN OR USE_UBSAN)
    enable_sanitizers()
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)
add_subdirectory(demo)
