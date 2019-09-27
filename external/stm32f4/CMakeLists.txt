add_library(libstm32f4 EXCLUDE_FROM_ALL
    CMSIS/system_stm32f4xx.c
    CMSIS/startup_stm32f40_41xxx.s
    drivers/stm32f4xx_gpio.c
    drivers/stm32f4xx_rcc.c
    drivers/stm32f4xx_usart.c
)

target_compile_definitions(libstm32f4
    PUBLIC USE_STDPERIPH_DRIVER
)

target_include_directories(libstm32f4
    SYSTEM PUBLIC CMSIS drivers
)

target_compile_options(libstm32f4
    PRIVATE -w
)