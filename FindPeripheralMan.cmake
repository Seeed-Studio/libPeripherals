#
# Copyright (C) 2017 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Overview
# --------
# This CMake script is for use in Android Studio, to populate variables for
# linking to the Android Things shared library. After running, the following
# variables will be available:
#   PERIPHERAL_FOUND - TRUE if libperipheralman was found
#   PERIPHERAL_INCLUDE_DIRS - The libperipheralman include directories
#   PERIPHERAL_LIBRARIES - The libraries needed to use libperipheralman
#   PERIPHERAL_DEFINITIONS - Compiler switches for libperipheralman
#
# Usage
# -----
# 1. Add this file's directory to CMAKE_MODULE_PATH and call find_package().
# 2. Add PERIPHERAL_INCLUDE_DIRS to your include_directories().
# 3. Add PERIPHERAL_LIBRARIES to your target_link_libraries().
# 4. Disable unavailable ABIs (see "ABI Specification" below)
#
# Example:
#   set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} <path_to_this_file's_parent_dir>)
#   find_package(PeripheralMan REQUIRED)
#   include_directories(${PERIPHERAL_INCLUDE_DIRS})
#   target_link_libraries(<your_target_name> ${PERIPHERAL_LIBRARIES})
#
# Finding the Source
# ------------------
# Normally the libperipheralman headers and .so are expected to live in the
# same directory as this file, but if the PERIPHERAL_DIR variable is
# provided in the app's build.gradle file, that path will be searched for the
# headers and .so first. For example:
#
#   android {
#     defaultConfig {
#       externalNativeBuild {
#         cmake {
#           arguments "-DPERIPHERAL_DIR=<path/to/libperipheralman/files>"
#         }
#      }
#   }
#
# ABI Specification
# -----------------
# libperipheralman is only available for the ABIs supported by Android Things
# devices. By default, Android Studio attempts to build for all ABIs, which may
# lead to errors like:
#
#   Could NOT find PeripheralMan (missing: PERIPHERAL_LIBRARY
#   PERIPHERAL_INCLUDE_DIR)
#
# To work around this, you will need to modify your app's build.gradle to
# only build the ABIs you need:
#
#  android {
#     defaultConfig {
#       externalNativeBuild {
#         cmake {
#           abiFilters "<abi_1>", "<abi_2>", ...
#         }
#      }
#   }


# Find the libperipheralman header files.
find_path(PERIPHERAL_INCLUDE_DIR
          NAMES pio/peripheral_manager_client.h
          HINTS "${PERIPHERAL_DIR}" "${CMAKE_CURRENT_LIST_DIR}"
          PATH_SUFFIXES "${ANDROID_ABI}/include"
          NO_CMAKE_FIND_ROOT_PATH)

# Find the libperipheralman.so library.
find_library(PERIPHERAL_LIBRARY
             NAMES libperipheralman.so
             HINTS "${PERIPHERAL_DIR}" "${CMAKE_CURRENT_LIST_DIR}"
             PATH_SUFFIXES "${ANDROID_ABI}/lib"
             NO_CMAKE_FIND_ROOT_PATH)

# Register the package and set PERIPHERAL_FOUND.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PeripheralMan DEFAULT_MSG
                                  PERIPHERAL_LIBRARY
                                  PERIPHERAL_INCLUDE_DIR)

# Hide these variables by default.
mark_as_advanced(PERIPHERAL_INCLUDE_DIR PERIPHERAL_LIBRARY)

# Set the remaining variables we want to export.
set(PERIPHERAL_LIBRARIES ${PERIPHERAL_LIBRARY})
set(PERIPHERAL_INCLUDE_DIRS ${PERIPHERAL_INCLUDE_DIR})
set(PERIPHERAL_DEFINITIONS "")

