set(OSAL_PLATFORM none PARENT_SCOPE)

add_executable(${APP}
    main.cpp
    syscalls.cpp
)

target_link_libraries(${APP}
    PRIVATE app${APP}
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
