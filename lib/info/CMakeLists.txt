add_library(platform-info EXCLUDE_FROM_ALL
    version.cpp
)
add_library(platform::info ALIAS platform-info)

target_include_directories(platform-info
    PUBLIC include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

find_package(Git)
add_custom_target(platform-generated-version
    ${CMAKE_COMMAND} -D VERSION_TARGET=platform
                     -D SRC=${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
                     -D DST=${CMAKE_CURRENT_BINARY_DIR}/version.h
                     -D GIT_EXECUTABLE=${GIT_EXECUTABLE}
                     -P ${CMAKE_CURRENT_SOURCE_DIR}/generateVersion.cmake
)
add_dependencies(platform-info platform-generated-version)
