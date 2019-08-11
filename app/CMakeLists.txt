cmake_minimum_required(VERSION 3.14)

if (NOT DEFINED PLATFORM)
    message(FATAL_ERROR "'PLATFORM' is not defined!")
endif ()

add_subdirectory(${PLATFORM})

# Make OSAL_PLATFORM visible in the application root directory.
set(OSAL_PLATFORM ${OSAL_PLATFORM} PARENT_SCOPE)
