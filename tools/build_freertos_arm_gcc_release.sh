#!/bin/bash

conan install .. --build missing -pr arm-none-eabi-gcc-9 -s build_type=Release
cmake .. -DPLATFORM=freertos-arm -DCMAKE_BUILD_TYPE=Release
make
