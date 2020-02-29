#!/bin/bash

cmake .. -DPLATFORM=linux-arm -DCMAKE_BUILD_TYPE=Release "${@}"
