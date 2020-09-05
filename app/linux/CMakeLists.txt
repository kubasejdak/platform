set(OSAL_PLATFORM linux PARENT_SCOPE)

add_executable(${APP_EXEC_NAME} main.cpp)

target_link_libraries(${APP_EXEC_NAME}
    PRIVATE app${APP_MAIN}
)

set_target_properties(${APP_EXEC_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/bin"
)
