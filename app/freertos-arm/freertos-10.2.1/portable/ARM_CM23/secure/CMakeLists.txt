add_library(freertos-portable EXCLUDE_FROM_ALL
    secure_context.c
    secure_context_port.c
    secure_heap.c
    secure_init.c
)

target_include_directories(freertos-portable
    INTERFACE include
    PRIVATE include/freertos ../../../include/freertos
)
