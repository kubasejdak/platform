#!/bin/bash

cmake .. -DPLATFORM=linux -DTOOLCHAIN=clang-9 "${@}"
