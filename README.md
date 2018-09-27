Grove for android Native Library
=============================

This repository contains the symbols and the headers for the Seeed's Android system with following architecture:
- `armeabi-v7a`

Usage
=====
- donwload the libPeripherials to your project `app/libs` directory.
```
git clone https://github.com/Seeed-Studio/libPeripherals
```
- Add the following lines to the native project `CMakeLists.txt`:
```
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/libs/libPeripherals)
# Resolve PeripheralMans headers and librarie
find_package(PeripheralMan REQUIRED)
include_directories(${PERIPHERAL_INCLUDE_DIR})

target_link_libraries(<your_target_name> ${PERIPHERAL_LIBRARYS})
```
- Add the following arch to the native module `build.gradle`:
```
    defaultConfig {
        ...
        ndk {
            abiFilters 'armeabi-v7a'
        }
    }

    sourceSets {
        main {
            jniLibs.srcDirs 'libs/libPeripherals/'
        }
    }

```

