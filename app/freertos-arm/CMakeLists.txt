set(OSAL_PLATFORM freertos PARENT_SCOPE)

if (NOT DEFINED FREERTOS_VERSION)
    message(FATAL_ERROR "'FREERTOS_VERSION' is not defined!")
endif ()

add_subdirectory(${FREERTOS_VERSION})

add_executable(${APP_EXEC_NAME}
    main.cpp
    syscalls.cpp
)

target_link_libraries(${APP_EXEC_NAME}
    PRIVATE app${APP_MAIN} freertos
)

set_target_properties(${APP_EXEC_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/bin"
)

add_custom_target(${APP_EXEC_NAME}.bin
    COMMAND                     ${CMAKE_OBJCOPY} -O binary ${APP_EXEC_NAME} ${APP_EXEC_NAME}.bin
    DEPENDS                     ${APP_EXEC_NAME}
    WORKING_DIRECTORY           ${CMAKE_BINARY_DIR}/bin
)
