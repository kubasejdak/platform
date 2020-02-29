#!/bin/bash

cmake .. -DPLATFORM=baremetal-arm -DCMAKE_BUILD_TYPE=Release "${@}"
