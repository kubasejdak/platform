cmake_minimum_required(VERSION 3.25)

if (NOT DEFINED PLATFORM)
    message(FATAL_ERROR "'PLATFORM' is not defined!")
endif ()

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror $<$<COMPILE_LANGUAGE:C>:-std=c17> $<$<COMPILE_LANGUAGE:CXX>:-std=c++20> $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)

add_library(platform-main OBJECT EXCLUDE_FROM_ALL)
add_library(platform::main ALIAS platform-main)

set(PLATFORM_LIB_PATH           "${CMAKE_BINARY_DIR}/lib" CACHE INTERNAL "")
set(PLATFORM_BIN_PATH           "${CMAKE_BINARY_DIR}/bin" CACHE INTERNAL "")

set_target_properties(platform-main PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY    "${PLATFORM_LIB_PATH}"
    LIBRARY_OUTPUT_DIRECTORY    "${PLATFORM_LIB_PATH}"
    RUNTIME_OUTPUT_DIRECTORY    "${PLATFORM_BIN_PATH}"
)

add_subdirectory(${PLATFORM})
add_subdirectory(info)

target_link_libraries(platform-main
    PUBLIC platform::info
)

# Make OSAL_PLATFORM visible in the application root directory.
set(OSAL_PLATFORM ${OSAL_PLATFORM} PARENT_SCOPE)
