add_library(freertos-portable EXCLUDE_FROM_ALL
    port.c
    portASM.S
)

target_include_directories(freertos-portable
    PUBLIC include/freertos
    PRIVATE ../../include/freertos
)

target_link_libraries(freertos-portable
    PUBLIC freertos-config
)

target_compile_options(freertos-portable
    PRIVATE -w
)
