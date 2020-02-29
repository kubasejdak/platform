add_subdirectory(${PLATFORM})

add_library(appplatform-demo EXCLUDE_FROM_ALL
    appMain.cpp
)

conan_get(fmt/6.1.2)
find_package(fmt REQUIRED)

target_link_libraries(appplatform-demo
    PUBLIC platform-init
    PRIVATE fmt::fmt
)
