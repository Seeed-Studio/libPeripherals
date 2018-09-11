/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SYSTEM_PERIPHERALMANAGER_LED_H_
#define SYSTEM_PERIPHERALMANAGER_LED_H_

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

/// @defgroup Led Led Interface
/// @brief Functions to control onboard LEDs.
///
/// These functions can be used to query and control LEDs.
/// @{

typedef struct BLed BLed;

/// Sets the LED brightness.
/// @param led Pointer to the BLed object.
/// @param brightness Brightness to set. If the brightness exceeds the maximum
/// brightness supported, sets the maximum supported.
/// @return 0 on success, errno on error.
int BLed_setBrightness(const BLed* led, uint32_t brightness);

/// Gets the LED brightness.
/// @param led Pointer to the BLed object.
/// @param brightness Output pointer to the current brightness.
/// @return 0 on success, errno on error.
int BLed_getBrightness(const BLed* led, uint32_t* brightness);

/// Gets the LED max brightness.
/// @param led Pointer to the BLed object.
/// @param max_brightness Output pointer to the maximum brightness supported.
/// @return 0 on success, errno on error.
int BLed_getMaxBrightness(const BLed* led, uint32_t* max_brightness);

/// Destroys a BLed object.
/// @param led Pointer to the BLed object to destroy.
void BLed_delete(BLed* led);

/// @}

__END_DECLS

#endif  // SYSTEM_PERIPHERALMANAGER_LED_H_
