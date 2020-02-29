#!/bin/bash

cmake .. -DPLATFORM=linux -DTOOLCHAIN=clang-9 -DCMAKE_BUILD_TYPE=Release "${@}"
