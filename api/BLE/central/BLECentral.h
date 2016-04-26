/*
  BLE Central API
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

#ifndef ARDUINO_BLE_CENTRAL_H
#define ARDUINO_BLE_CENTRAL_H

#include <Arduino.h>

#include "BLERemotePeripheral.h"
#include "BLERemotePeripheralCharacteristic.h"

enum BLECentralEvent {
  BLEDiscovered = 0
};

typedef void (*BLECentralEventHandler)(BLERemotePeripheral& peripheral);

class BLECentral
{
  public:
    BLECentral();
    virtual ~BLECentral();

    void begin(); // initiliaze hardware
    void poll(); // poll for events
    void end(); // deinitiliaze hardware

    void startScanning(); // start scanning for peripherals
    void startScanningWithDuplicates(); // start scanning for peripherals, and report all duplicates
    void stopScanning(); // stop scanning for peripherals

    BLERemotePeripheral available(); // retrieve a discovered peripheral

    void setEventHandler(BLECentralEvent event, BLECentralEventHandler eventHandler); // set an event handler (callback)
};

#endif
