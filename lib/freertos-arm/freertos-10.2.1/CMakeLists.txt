add_library(freertos EXCLUDE_FROM_ALL
    portable/Common/mpu_wrappers.c
    croutine.c
    event_groups.c
    list.c
    queue.c
    stream_buffer.c
    tasks.c
    timers.c
)

add_subdirectory(portable)

target_include_directories(freertos
    PUBLIC include
    PRIVATE include/freertos
)

target_link_libraries(freertos
    PUBLIC freertos-config freertos-portable
)

target_compile_options(freertos
    PRIVATE -w
)