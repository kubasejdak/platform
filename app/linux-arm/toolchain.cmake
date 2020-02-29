if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEFAULT_TOOLCHAIN       arm-linux-gnueabihf-gcc-9)

    if (NOT DEFINED TOOLCHAIN)
        message(STATUS "'TOOLCHAIN' is not defined. Using '${DEFAULT_TOOLCHAIN}'")
        set(TOOLCHAIN           ${DEFAULT_TOOLCHAIN})
    endif ()

    set(CONAN_PROFILE           ${TOOLCHAIN})
    set(CMAKE_TOOLCHAIN_FILE    ${CMAKE_CURRENT_LIST_DIR}/${TOOLCHAIN}.cmake)
endif ()

if (NOT DEFINED APP_C_FLAGS)
    set(APP_C_FLAGS             "")
endif ()
if (NOT DEFINED APP_CXX_FLAGS)
    set(APP_CXX_FLAGS           "")
endif ()
