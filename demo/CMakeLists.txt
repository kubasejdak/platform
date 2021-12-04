add_subdirectory(init)

add_library(appplatform-demo EXCLUDE_FROM_ALL
    appMain.cpp
)

target_link_libraries(appplatform-demo
    PUBLIC platform-init
)
