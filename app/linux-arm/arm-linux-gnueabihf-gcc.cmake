set(CMAKE_SYSTEM_NAME       Linux)
set(CMAKE_SYSTEM_PROCESSOR  ARM)

if (WIN32)
    set(EXE_EXTENSION       ".exe")
else ()
    set(EXE_EXTENSION       "")
endif ()

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_AR                arm-linux-gnueabihf-ar${EXE_EXTENSION})
set(CMAKE_ASM_COMPILER      arm-linux-gnueabihf-as${EXE_EXTENSION})
set(CMAKE_C_COMPILER        arm-linux-gnueabihf-gcc${EXE_EXTENSION})
set(CMAKE_CXX_COMPILER      arm-linux-gnueabihf-g++${EXE_EXTENSION})
set(CMAKE_OBJCOPY           arm-linux-gnueabihf-objcopy${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_RANLIB            arm-linux-gnueabihf-ranlib${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_SIZE_UTIL         arm-linux-gnueabihf-size${EXE_EXTENSION} CACHE INTERNAL "")
set(CMAKE_STRIP             arm-linux-gnueabihf-strip${EXE_EXTENSION} CACHE INTERNAL "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
