add_subdirectory(init)

add_library(appplatform-demo EXCLUDE_FROM_ALL
    appMain.cpp
)

conan_get(REQUIRES fmt/7.0.3 OPTIONS fmt:header_only=True)
find_package(fmt REQUIRED)

target_link_libraries(appplatform-demo
    PUBLIC platform-init
    PRIVATE fmt::fmt
)
