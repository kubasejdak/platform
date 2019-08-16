if (NOT DEFINED FREERTOS_PORTABLE)
    message(FATAL_ERROR "'FREERTOS_PORTABLE' is not defined!")
endif ()

add_subdirectory(${FREERTOS_PORTABLE})
