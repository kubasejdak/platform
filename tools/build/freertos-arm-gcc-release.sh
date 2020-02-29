#!/bin/bash

cmake .. -DPLATFORM=freertos-arm -DCMAKE_BUILD_TYPE=Release "${@}"
