#!/bin/bash

conan install .. --build missing -pr arm-linux-gnueabihf-gcc-8 -s build_type=Debug
cmake .. -DPLATFORM=linux-arm
make
