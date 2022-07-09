set(OSAL_PLATFORM freertos PARENT_SCOPE)

if (NOT DEFINED FREERTOS_VERSION)
    message(FATAL_ERROR "'FREERTOS_VERSION' is not defined!")
endif ()

add_subdirectory(${FREERTOS_VERSION})

target_sources(platform-main PRIVATE
    main.cpp
    syscalls.cpp
)

target_link_libraries(platform-main
    PRIVATE freertos
)

function (objcopy_generate_bin TARGET_NAME)
    add_custom_target(${TARGET_NAME}.bin
        COMMAND                     ${CMAKE_OBJCOPY} -O binary ${TARGET_NAME} ${TARGET_NAME}.bin
        DEPENDS                     ${TARGET_NAME}
        WORKING_DIRECTORY           ${PLATFORM_BIN_PATH}
    )
endfunction ()
