set(OSAL_PLATFORM none PARENT_SCOPE)

if (APP_EXEC_NAME)
    add_executable(${APP_EXEC_NAME}
        main.cpp
        syscalls.cpp
    )

    target_link_libraries(${APP_EXEC_NAME}
        PRIVATE app${APP_MAIN}
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
endif ()
