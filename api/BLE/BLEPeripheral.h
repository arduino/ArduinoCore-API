/*
  BLE Peripheral API (deprecated)
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

#ifndef ARDUINO_BLE_PERIPHERAL
#define ARDUINO_BLE_PERIPHERAL

#include "BLECentral.h"
#include "BLESerivce.h"
#include "BLECharacteristic.h"
#include "BLEDescriptor.h"

enum BLEPeripheralEvent {
  BLEConnected = 0,
  BLEDisconnected = 1
};

typedef void (*BLEPeripheralEventHandler)(BLECentral &central);

class BLEPeripheral {
  public:
    BLEPeripheral(void);
    virtual ~BLEPeripheral(void);

    void setAdvertisedServiceUuid(const char* advertisedServiceUuid); // set the advertised service uuid
    void setLocalName(const char* localName); // set the local name


    void setDeviceName(const char *deviceName); // set the device name    
    void setAppearance(const unsigned short appearance); // set the appearance type

    // Set the min and max connection interval
    void setConnectionInterval(const unsigned short minConnInterval, const unsigned short maxConnInterval);

    // Add an attribute to the BLE Peripheral Device
    void addAttribute(BLEService& service);
    void addAttribute(BLECharacteristic& characteristic);
    void addAttribute(BLEDescriptor& descriptor);

    void setEventHandler(BLEPeripheralEvent event, BLEPeripheralEventHandler callback); // register an event handler

    bool begin(void); // Setup attributes and start advertising

    void poll(void); // poll the BLE radio for events

    void end(void); // Stop advertising and disconnect a central if connected

    bool disconnect(void); // disconnect the central if connected


    BLECentral central(void);
    bool connected(void); // Is a central connected?

private:
    void init();

    bool _initCalled;
    BLEService* _lastService;
    BLECharacteristic* _lastCharacteristic;
    BLEPeripheralEventHandler _eventHandlers[2];
};

#endif // _BLE_DEVICE_H_INCLUDED
