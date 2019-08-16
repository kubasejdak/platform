add_library(freertos-portable EXCLUDE_FROM_ALL
    port.c
    portasm.c
)

target_include_directories(freertos-portable
    INTERFACE include
    PRIVATE include/freertos ../../../include/freertos
)
