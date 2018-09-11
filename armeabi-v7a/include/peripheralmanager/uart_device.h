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

#ifndef SYSTEM_PERIPHERALMANAGER_UART_DEVICE_H_
#define SYSTEM_PERIPHERALMANAGER_UART_DEVICE_H_

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

/// @defgroup Uart Uart device interface
/// @brief Functions to control an UART device.
///
/// These functions can be used to control an UART device.
/// @{

typedef struct AUartDevice AUartDevice;

/// Writes to a UART device.
/// @param device Pointer to the AUartDevice struct.
/// @param data Data to write.
/// @param len Size of the data to write.
/// @param bytes_written Output pointer to the number of bytes written.
/// @return 0 on success, errno on error.
int AUartDevice_write(const AUartDevice* device,
                      const void* data,
                      uint32_t len,
                      uint32_t* bytes_written);

/// Reads from a UART device.
/// @param device Pointer to the AUartDevice struct.
/// @param data Buffer to read the data into.
/// @param len Number of bytes to read.
/// @param bytes_read Output pointer to the number of bytes read.
/// @return 0 on success, errno on error.
int AUartDevice_read(const AUartDevice* device,
                     void* data,
                     uint32_t len,
                     uint32_t* bytes_read);

/// Sets the input and output speed of a UART device.
/// @param device Pointer to the AUartDevice struct.
/// @param device Uart device to configure.
/// @param baudrate Speed in baud.
/// @return 0 on success, errno on error.
int AUartDevice_setBaudrate(const AUartDevice* device, uint32_t baudrate);

/// Destroys a AUartDevice struct.
/// @param device Pointer to the AUartDevice struct.
void AUartDevice_delete(AUartDevice* device);

/// @}

__END_DECLS

#endif  // SYSTEM_PERIPHERALMANAGER_UART_DEVICE_H_
