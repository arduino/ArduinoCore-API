/*
  BLE Remote Peripheral Service API
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

#ifndef ARDUINO_BLE_REMOTE_PERIPHERAL_SERVICE_H
#define ARDUINO_BLE_REMOTE_PERIPHERAL_SERVICE_H

#include "BLERemotePeripheralAttribute.h"
#include "BLERemotePeripheralCharacteristic.h"

class BLERemotePeripheral;

class BLERemotePeripheralService : public BLERemotePeripheralAttribute
{
  public:
    BLERemotePeripheralService();

    operator bool() const;  // is the service valid (discovered from peripheral)

    int characteristicCount() const; // returns the number of characteristics the service has
    bool hasCharacteristic(const char* uuid) const; // does the service have a characteristic with the specified UUID
    bool hasCharacteristic(const char* uuid, int index) const; // does the service have an nth characteristic with the specified UUID
    BLERemotePeripheralCharacteristic characteristic(int index) const;  // return the nth characteristic of the service
    BLERemotePeripheralCharacteristic characteristic(const char * uuid) const; // return the characteristic with the specified UUID
    BLERemotePeripheralCharacteristic characteristic(const char * uuid, int index) const; // return the nth characteristic with the specified UUID
};

#endif
