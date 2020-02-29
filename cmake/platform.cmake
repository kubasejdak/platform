if (NOT DEFINED PLATFORM)
    message(FATAL_ERROR "'PLATFORM' is not defined!")
endif ()

# Setup platform toolchain file.
include(app/${PLATFORM}/toolchain.cmake)
