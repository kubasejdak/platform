if (NOT DEFINED PLATFORM)
    set(DEFAULT_PLATFORM    linux)
    message(STATUS "'PLATFORM' is not defined. Using '${DEFAULT_PLATFORM}'")
    set(PLATFORM            ${DEFAULT_PLATFORM})
endif ()

# Setup platform toolchain file.
include(lib/${PLATFORM}/toolchain.cmake)
