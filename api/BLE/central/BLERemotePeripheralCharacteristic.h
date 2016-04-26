/*
  BLE Remote Peripheral Characteristic API
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

#ifndef ARDUINO_BLE_REMOTE_PERIPHERAL_CHARACTERISTIC_H
#define ARDUINO_BLE_REMOTE_PERIPHERAL_CHARACTERISTIC_H

#include "BLERemotePeripheralAttributeWithValue.h"
#include "BLERemotePeripheralDescriptor.h"

enum BLERemotePeripheralCharacteristicEvent {
  BLERemoteValueUpdated = 0
};

class BLERemotePeripheralCharacteristic;

typedef void (*BLERemotePeripheralCharacteristicEventHandler)(BLERemotePeripheral& peripheral, BLERemotePeripheralCharacteristic& characteristic);

class BLERemotePeripheralCharacteristic : public BLERemotePeripheralAttributeWithValue
{
  public:
    BLERemotePeripheralCharacteristic();

    operator bool() const; // is the characteristic valid (discovered from peripheral)

    unsigned char properties() const; // returns the properties of the characteristic

    bool canRead(); // can the characteristic be read (based on properties)
    bool canWrite(); // can the characteristic be written (based on properties)
    bool canSubscribe(); // can the characteristic be subscribed to (based on properties)
    bool canUnsubscribe(); // can the characteristic be unsubscribed to (based on properties)

    virtual bool read(); // read the characteristic value
    virtual bool write(const unsigned char* value, int length); // write the charcteristic value

    bool subscribe(); // subscribe to the characteristic
    bool unsubscribe(); // unsubscribe to the characteristic

    bool valueUpdated(); // has the characteristic value been updated

    void setEventHandler(BLERemotePeripheralCharacteristicEvent event, BLERemotePeripheralCharacteristicEventHandler eventHandler); // set an event handler (callback)

    int descriptorCount() const; // returns the number of descriptors the characteristic has
    bool hasDescriptor(const char* uuid) const; // does the characteristic have a descriptor with the specified UUID
    bool hasDescriptor(const char* uuid, int index) const; // does the characteristic have an nth descriptor with the specified UUID
    BLERemotePeripheralDescriptor descriptor(int index) const; // return the nth descriptor of the characteristic
    BLERemotePeripheralDescriptor descriptor(const char * uuid) const; // return the descriptor with the specified UUID
    BLERemotePeripheralDescriptor descriptor(const char * uuid, int index) const; // return the nth descriptor with the specified UUID
};

#endif
