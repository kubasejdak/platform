set(OSAL_PLATFORM none PARENT_SCOPE)

target_sources(platform-main PRIVATE
    main.cpp
    syscalls.cpp
)

function (objcopy_generate_bin TARGET_NAME)
    add_custom_target(${TARGET_NAME}.bin
        COMMAND                     ${CMAKE_OBJCOPY} -O binary ${TARGET_NAME} ${TARGET_NAME}.bin
        DEPENDS                     ${TARGET_NAME}
        WORKING_DIRECTORY           ${PLATFORM_BIN_PATH}
    )
endfunction ()
