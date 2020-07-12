cmake_minimum_required(VERSION 3.15)

if (NOT DEFINED PLATFORM)
    message(FATAL_ERROR "'PLATFORM' is not defined!")
endif ()

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror $<$<COMPILE_LANGUAGE:C>:-std=c17> $<$<COMPILE_LANGUAGE:CXX>:-std=c++2a>)

add_subdirectory(${PLATFORM})

# Make OSAL_PLATFORM visible in the application root directory.
set(OSAL_PLATFORM ${OSAL_PLATFORM} PARENT_SCOPE)
