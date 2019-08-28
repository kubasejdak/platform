add_library(freertos-portable EXCLUDE_FROM_ALL
    port.c
)

target_include_directories(freertos-portable
    PUBLIC include/freertos ${FREERTOS_CONFIG_PATH}
    PRIVATE ../../include/freertos
)
