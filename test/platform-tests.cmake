if (APPLE)
    set(LINUX_ARM_TOOLCHAIN_PATH        "/Volumes/Build/arm-linux-gnueabihf")
    set(BAREMETAL_ARM_TOOLCHAIN_PATH    "/usr/local")
elseif (UNIX)
    set(LINUX_ARM_TOOLCHAIN_PATH        "/usr")
    set(BAREMETAL_ARM_TOOLCHAIN_PATH    "/usr")
endif ()

set(FREERTOS_VERSION        freertos-10.2.1)
set(FREERTOS_PORTABLE       ARM_CM4F)
