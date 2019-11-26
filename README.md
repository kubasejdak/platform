[![Build Linux](https://github.com/kubasejdak/platform/workflows/Build%20Linux/badge.svg)](https://github.com/kubasejdak/platform/actions?query=workflow%3A%22Build+Linux%22)
[![Build Linux ARM](https://github.com/kubasejdak/platform/workflows/Build%20Linux%20ARM/badge.svg)](https://github.com/kubasejdak/platform/actions?query=workflow%3A%22Build+Linux+ARM%22)
[![Build baremetal ARM](https://github.com/kubasejdak/platform/workflows/Build%20baremetal%20ARM/badge.svg)](https://github.com/kubasejdak/platform/actions?query=workflow%3A%22Build+baremetal+ARM%22)
[![Build FreeRTOS ARM](https://github.com/kubasejdak/platform/workflows/Build%20FreeRTOS%20ARM/badge.svg)](https://github.com/kubasejdak/platform/actions?query=workflow%3A%22Build+FreeRTOS+ARM%22)

[![Github Releases](https://img.shields.io/github/release/kubasejdak/platform.svg)](https://github.com/kubasejdak/platform/releases)
[![License](https://img.shields.io/badge/License-BSD%202--Clause-orange.svg)](https://opensource.org/licenses/BSD-2-Clause)

[![CodeFactor Grade](https://img.shields.io/codefactor/grade/github/kubasejdak/platform)](https://www.codefactor.io/repository/github/kubasejdak/platform)

### Basic usage

Set toolchain file for the selected platform:

```cmake
include(platform/app/${PLATFORM}/toolchain.cmake)
```

Add platform to your build system:

```cmake
add_subdirectory(platform/app)
```

Implement main application function:

```cpp
int appMain(int argc, char* argv[])
{
    // ...
    return 0;
}
```

Launch CMake with the desired platform and toolchain setup:

```bash
cmake <PATH_TO_SRC> -DPLATFORM=freertos-arm
cmake <PATH_TO_SRC> -DPLATFORM=linux -DTOOLCHAIN=clang-9
cmake <PATH_TO_SRC> -DPLATFORM=linux -DTOOLCHAIN=gcc-7
cmake <PATH_TO_SRC> -DPLATFORM=linux-arm
cmake <PATH_TO_SRC> -DPLATFORM=linux-arm -DTOOLCHAIN=arm-linux-gnueabihf-clang-9
```
