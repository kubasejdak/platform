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
