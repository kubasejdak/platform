#!/bin/bash

conan install .. --build missing -pr arm-none-eabi-gcc-9 -s build_type=Debug
cmake .. -DPLATFORM=baremetal-arm
make
