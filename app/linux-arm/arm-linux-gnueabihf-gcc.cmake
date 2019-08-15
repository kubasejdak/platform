set(CMAKE_SYSTEM_NAME       Linux)
set(CMAKE_SYSTEM_PROCESSOR  ARM)

if (WIN32)
    set(EXE_EXTENSION       ".exe")
else ()
    set(EXE_EXTENSION       "")
endif ()

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_AR                ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-ar${EXE_EXTENSION})
set(CMAKE_ASM_COMPILER      ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-as${EXE_EXTENSION})
set(CMAKE_C_COMPILER        ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-gcc${EXE_EXTENSION})
set(CMAKE_CXX_COMPILER      ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-g++${EXE_EXTENSION})
set(CMAKE_OBJCOPY           ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-objcopy${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_RANLIB            ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-ranlib${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_SIZE_UTIL         ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-size${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_STRIP             ${LINUX_ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-strip${EXE_EXTENSION} CACHE INTERNAL "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
