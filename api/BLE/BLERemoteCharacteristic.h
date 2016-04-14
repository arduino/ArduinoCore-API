/*
  BLE Remote Characteristic API
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

#ifndef ARDUINO_BLE_REMOTE_CHARACTERISTIC_H
#define ARDUINO_BLE_REMOTE_CHARACTERISTIC_H

#include "BLERemoteAttribute.h"
#include "BLEDeviceLimits.h"

enum BLERemoteCharacteristicEvent {
  BLEValueUpdated = 0
};

typedef void (*BLERemoteCharacteristicEventHandler)(BLERemoteCentral& central, BLERemoteCharacteristic& characteristic);

class BLERemoteCharacteristic : public BLERemoteAttribute
{
public:
  BLERemoteCharacteristic(const char* uuid, unsigned char properties);

  virtual ~BLERemoteCharacteristic();

  unsigned char properties() const; // returns the property mask of the characteristic

  const unsigned char* value() const; // returns the value buffer
  unsigned char valueLength() const; // returns the current length of the value
  virtual unsigned char operator[] (int offset) const; // returns a byte of the value at the specified offset

  bool canRead(); // can the remote characteristic be read
  bool read(); // send a read request
  bool canWrite(); // can the remote characteristic be written
  bool write(const unsigned char value[], unsigned char length); // send a write request
  bool canSubscribe(); // can the remote characteristic be subscribed to
  bool subscribe(); // subscribe to the remote characteristic
  bool canUnsubscribe(); // can the remote characteristic be unsubscribed from
  bool unsubscribe(); // unsubscribe from the remote characteristic

  bool valueUpdated(); // has the peripheral updated a new value

  void setEventHandler(BLERemoteCharacteristicEvent event, BLERemoteCharacteristicEventHandler eventHandler); // set an event handler (callback)
};

#endif
