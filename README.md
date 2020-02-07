### Overview

Platform project creates an easy to use abstraction for launching applications on various OS platforms.
It's main goal is to provide:
* compiler configuration for target platform,
* abstraction of launching main application thread on target platform.

Compiler configuration is provided via CMake toolchain file. It's aim is to set all required CMake variables in order
to allow cross-compilation to the target platform. It also handles the basic set of compilation and linking flags for
particular platform/compiler pair.

Launching main application thread is implemented by distinguishing the `main()` function from the main thread. On desktop
systems first app thread is executing directly code from `main()`. On systems where a dedicated scheduler is launched
(e.g. baremetal RTOS), it is required that in the first thread user has to call some sort of "scheduler start" function,
which usually never returns (at least until all threads are destroyed). Previously mentioned separation requires, that
the main application logic should be placed in `appMain()` function. On desktop systems this function would be called
directly from `main()`. On RTOS systems, this function would be used as feed for a new user thread.

### Original author

Original idea, design and implementation done by Grzegorz Heldt `grzegorz.heldt@gmail.com`.

### Usage

> Note: `Platform` usage requires CMake build system. 

In order to use `platform` follow the steps below.

#### 1. Make `platform` code available in you build system

Code of `platform` project can be included in another project in several ways.

##### 1.1. git submodule
##### 1.2. regular copy
##### 1.3. CMake `FetchContent`
##### 2. Set `APP` variable with the name of the application
##### 3. Define application specific settings
##### 4. Include toolchain file for the given platform
##### 5. Add `platform/app` subdirectory to build system
##### 6. Provide `app${APP}` library containing `appMain()` function body
##### 7. Put application main thread into `appMain()` function
##### 8. Optional: redirect STDOUT to the demanded destination

### Benefits

#### 1. No need to setup manually cross-compiler

This is already done by the platform project. All that is left to be done is to select which platform should be used
and which compiler among all supported by that platform.

#### 2. No need to mess business logic with bootstrapping code

Application shouldn't rely on the fact that it runs directly from main or in a separate thread. With `appMain()`
introduced all OS specific bootstrapping is hidden in the platform library making business logic truly OS independent. 

### Usage

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

### Requirements

### Doxygen documentation

### Contribution
