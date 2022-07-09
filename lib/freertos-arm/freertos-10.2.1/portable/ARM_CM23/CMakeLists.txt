if (NOT DEFINED FREERTOS_ARM_CM23_IMPL)
    message(FATAL_ERROR "'FREERTOS_ARM_CM23_IMPL' is not defined!")
endif ()

add_subdirectory(${FREERTOS_ARM_CM23_IMPL})
