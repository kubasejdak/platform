add_subdirectory(${CMAKE_SOURCE_DIR}/external/stm32f4xx ${CMAKE_BINARY_DIR}/external/stm32f4xx)

add_library(platform-init EXCLUDE_FROM_ALL
    platformInit.cpp
)

target_include_directories(platform-init
    PUBLIC ..
)

target_link_libraries(platform-init
    PRIVATE stm32f4xx
)

target_link_options(platform-init
    PUBLIC -T ${CMAKE_CURRENT_SOURCE_DIR}/stm32f407vgtx.ld
)
