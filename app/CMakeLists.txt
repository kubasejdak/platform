cmake_minimum_required(VERSION 3.19)

if (NOT DEFINED PLATFORM)
    message(FATAL_ERROR "'PLATFORM' is not defined!")
endif ()

# Project-wide compilation options.
add_compile_options(-Wall -Wextra -Wpedantic -Werror $<$<COMPILE_LANGUAGE:C>:-std=c17> $<$<COMPILE_LANGUAGE:CXX>:-std=c++17> $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)

if (DEFINED APP_PREFIX)
    message(STATUS "Using '${APP_PREFIX}' prefix in executable name")
endif ()

if (DEFINED APP_POSTFIX)
    message(STATUS "Using '${APP_POSTFIX}' postfix in executable name")
endif ()

get_filename_component(APP_MAIN ${APP} NAME)
set(APP_EXEC_NAME ${APP_PREFIX}${APP_MAIN}${APP_POSTFIX})

add_subdirectory(${PLATFORM})

# Make OSAL_PLATFORM visible in the application root directory.
set(OSAL_PLATFORM ${OSAL_PLATFORM} PARENT_SCOPE)
