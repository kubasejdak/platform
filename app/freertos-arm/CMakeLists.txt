set(OSAL_PLATFORM freertos PARENT_SCOPE)

if (NOT DEFINED FREERTOS_VERSION)
    message(FATAL_ERROR "'FREERTOS_VERSION' is not defined!")
endif ()

add_subdirectory(${FREERTOS_VERSION})

add_executable(${APP}
    main.cpp
    syscalls.cpp
)

target_link_libraries(${APP}
    PRIVATE app${APP} freertos
)

set_target_properties(${APP} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/bin"
)

add_custom_target(${APP}.bin
    COMMAND                     ${CMAKE_OBJCOPY} -O binary ${APP} ${APP}.bin
    DEPENDS                     ${APP}
    WORKING_DIRECTORY           ${CMAKE_BINARY_DIR}/bin
)
