if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEFAULT_TOOLCHAIN       gcc-9)

    if (NOT DEFINED TOOLCHAIN)
        message(STATUS "'TOOLCHAIN' is not defined. Using '${DEFAULT_TOOLCHAIN}'")
        set(TOOLCHAIN           ${DEFAULT_TOOLCHAIN})
    endif ()

    set(CMAKE_TOOLCHAIN_FILE    ${CMAKE_CURRENT_LIST_DIR}/${TOOLCHAIN}.cmake)
endif ()
