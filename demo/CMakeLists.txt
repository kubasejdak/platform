add_subdirectory(init)

add_executable(platform-demo
    appMain.cpp
)

target_link_libraries(platform-demo
    PRIVATE platform::init platform::main
)

if (PLATFORM STREQUAL freertos-arm OR PLATFORM STREQUAL baremetal-arm)
    objcopy_generate_bin(platform-demo)
endif ()
