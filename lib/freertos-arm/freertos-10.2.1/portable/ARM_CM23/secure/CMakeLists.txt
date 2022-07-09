add_library(freertos-portable EXCLUDE_FROM_ALL
    secure_context.c
    secure_context_port.c
    secure_heap.c
    secure_init.c
)

target_include_directories(freertos-portable
    PUBLIC include/freertos
    PRIVATE ../../../include/freertos
)

target_link_libraries(freertos-portable
    PUBLIC freertos-config
)

target_compile_options(freertos-portable
    PRIVATE -w
)
