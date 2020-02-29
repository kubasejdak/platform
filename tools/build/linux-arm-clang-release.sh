#!/bin/bash

cmake .. -DPLATFORM=linux-arm -DTOOLCHAIN=arm-linux-gnueabihf-clang-9 -DCMAKE_BUILD_TYPE=Release "${@}"
