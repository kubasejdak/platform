
set(OSAL_PLATFORM linux)

add_executable(${APP}.elf main.cpp)

target_link_libraries(${APP}.elf
    PRIVATE app${APP}
)

set_target_properties(${APP}.elf PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
