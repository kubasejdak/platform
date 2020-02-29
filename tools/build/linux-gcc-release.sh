#!/bin/bash

cmake .. -DPLATFORM=linux -DCMAKE_BUILD_TYPE=Release "${@}"
