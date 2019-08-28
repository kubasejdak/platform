set(OSAL_PLATFORM freertos PARENT_SCOPE)

if (NOT DEFINED FREERTOS_VERSION)
    message(FATAL_ERROR "'FREERTOS_VERSION' is not defined!")
endif ()

if (NOT DEFINED FREERTOS_CONFIG_PATH)
    message(FATAL_ERROR "'FREERTOS_CONFIG_PATH' is not defined!")
endif ()

add_subdirectory(${FREERTOS_VERSION})

add_executable(${APP}.elf main.cpp)

target_link_libraries(${APP}.elf
    PRIVATE app${APP} freertos
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
