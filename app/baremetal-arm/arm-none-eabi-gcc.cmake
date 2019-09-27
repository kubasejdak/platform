set(CMAKE_SYSTEM_NAME       Generic)
set(CMAKE_SYSTEM_PROCESSOR  ARM)

if (WIN32)
    set(EXE_EXTENSION       ".exe")
else ()
    set(EXE_EXTENSION       "")
endif ()

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_AR                arm-none-eabi-ar${EXE_EXTENSION})
set(CMAKE_ASM_COMPILER      arm-none-eabi-as${EXE_EXTENSION})
set(CMAKE_C_COMPILER        arm-none-eabi-gcc${EXE_EXTENSION})
set(CMAKE_CXX_COMPILER      arm-none-eabi-g++${EXE_EXTENSION})
set(CMAKE_OBJCOPY           arm-none-eabi-objcopy${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_RANLIB            arm-none-eabi-ranlib${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_SIZE_UTIL         arm-none-eabi-size${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_STRIP             arm-none-eabi-strip${EXE_EXTENSION} CACHE INTERNAL "")

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -mcpu=cortex-m4 -mfloat-abi=hard --specs=nosys.specs")
set(CMAKE_CXX_FLAGS         "${CMAKE_C_FLAGS}")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
