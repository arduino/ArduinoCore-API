/*
  BLE API
  Copyright (c) 2016 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef ARDUINO_BLE_H
#define ARDUINO_BLE_H

#define ARDUINO_BLE_API_VERSION 10000 // version 1.0.0

#include <BLEDevice.h>

typedef enum 
{
    BLE_STATUS_SUCCESS = 0,
    BLE_STATUS_FORBIDDEN, /**< The operation is forbidden. Central mode call peripheral API and vice versa */
    BLE_STATUS_PENDING, /**< Request received and execution started, response pending */
    BLE_STATUS_TIMEOUT, /**< Request timed out */
    BLE_STATUS_NOT_SUPPORTED, /**< Request/feature/parameter not supported */
    BLE_STATUS_NOT_ALLOWED, /**< Request not allowed */
    BLE_STATUS_LINK_TIMEOUT, /**< Link timeout (link loss) */
    BLE_STATUS_NOT_ENABLED, /**< BLE not enabled, @ref ble_enable */
    BLE_STATUS_ERROR,   /**< Generic Error */
    BLE_STATUS_ALREADY_REGISTERED, /**< BLE service already registered */
    BLE_STATUS_WRONG_STATE, /**< Wrong state for request */
    BLE_STATUS_ERROR_PARAMETER, /**< Parameter in request is wrong */
    BLE_STATUS_NO_MEMORY, /**< System doesn't have memory */
}BLE_STATUS_T;

extern BLEDevice BLE;

#endif
