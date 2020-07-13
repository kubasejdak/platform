## v1.1.2

### Changed (4)

* Changed embedded toolchain from `gcc-arm-none-eabi-9-2019-q4-major` to `gcc-arm-none-eabi-9-2020-q2-update`. (!40)
* Started using `kubasejdak/arm-tests` docker image for tests on RPi. (!41)
* Updated fmt to v7.0.1. (!42)
* Changed default C++ standard to C++2a. (!42)

### Fixed (1)

* Added missing include on baremetal platforms. (!42)

## v1.1.1

### Fixed (1)

* Changed all variables in `main()` in `FreeRTOS ARM` platform to be static. (!39)

## v1.1.0

### Added (1)

* Added support for `gcc-10`. (!38)

### Removed (1)

* Dropped support for `gcc-7`. (!38)

### Changed (2)

* Changed optimization flags in debug for embedded to `-Os`. (!37)
* Changed default heap size for `STM32F4DISCOVERY` board.

## v1.0.0

### Added (3)

* Merged `linux` and `linux-arm` platforms.
* Added support for `clang-10`.
* Added explicitly set `CMAKE_LINKER` variable in toolchain files.

### Removed (1)

* Dropped support for `clang-7`.
