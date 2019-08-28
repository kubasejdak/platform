set(OSAL_PLATFORM none PARENT_SCOPE)

add_executable(${APP}.elf main.cpp)

target_link_libraries(${APP}.elf
    PRIVATE app${APP}
)

set_target_properties(${APP}.elf PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_custom_target(${APP}.bin)
get_target_property(OUTPUT_OUTPUT ${APP}.elf RUNTIME_OUTPUT_DIRECTORY)
add_custom_command(TARGET ${APP}.bin
    COMMAND ${CMAKE_OBJCOPY} -O binary ${OUTPUT_OUTPUT}/${APP}.elf ${OUTPUT_OUTPUT}/${APP}.bin
)
add_dependencies(${APP}.bin ${APP}.elf)
