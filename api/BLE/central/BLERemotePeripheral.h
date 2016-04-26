/*
  BLE Remote Peripheral API
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


#ifndef ARDUINO_BLE_REMOTE_PERIPHERAL_H
#define ARDUINO_BLE_REMOTE_PERIPHERAL_H

#include <Arduino.h>

#include "BLERemotePeripheralService.h"
#include "BLERemotePeripheralCharacteristic.h"
#include "BLERemotePeripheralDescriptor.h"

enum BLERemotePeripheralEvent {
  BLERemoteDisconnected = 0
};

class BLERemotePeripheral;

typedef void (*BLERemotePeripheralEventHandler)(BLERemotePeripheral& peripheral);

class BLERemotePeripheral
{
  public:
    BLERemotePeripheral();
    virtual ~BLERemotePeripheral();

    operator bool() const; // is the peripheral valid (discovered)

    String address() const; // returns the BT address of the peripheral as a String
    int rssi() const; // returns the RSSI of the peripheral at discovery

    bool hasLocalName() const; // does the peripheral advertise a local name
    bool hasAdvertisedService() const; // does the peripheral advertise a service
    bool hasAdvertisedService(int index) const; // does the peripheral advertise a service n

    String localName() const; // returns the advertised local name as a String
    String advertisedService() const; // returns the advertised service as a UUID String
    String advertisedService(int index) const; // returns the nth advertised service as a UUID String

    bool connect(); // connect to the peripheral
    bool disconnect(); // disconnect from the peripheral
    bool connected(); // is the peripheral connected

    bool discoverAttributes(); // discover the peripherals attributes (services, characteristic, and descriptors)

    String deviceName(); // read the device name attribute of the peripheral, and return String value
    unsigned short appearance(); // read the appearance attribute of the peripheral and return value as int

    void setEventHandler(BLERemotePeripheralEvent event, BLERemotePeripheralEventHandler eventHandler); // set an event handler (callback)

    int serviceCount() const; // returns the number of services the peripheral has
    bool hasService(const char* uuid) const; // does the peripheral have a service with the specified UUID
    bool hasService(const char* uuid, int index) const;  // does the peripheral have an nth service with the specified UUID
    BLERemotePeripheralService service(int index) const; // return the nth service of the peripheral
    BLERemotePeripheralService service(const char * uuid) const; // return the service with the specified UUID
    BLERemotePeripheralService service(const char * uuid, int index) const; // return the nth service with the specified UUID

    int characteristicCount() const; // returns the number of characteristics the peripheral has
    bool hasCharacteristic(const char* uuid) const; // does the peripheral have a characteristic with the specified UUID
    bool hasCharacteristic(const char* uuid, int index) const; // does the peripheral have an nth characteristic with the specified UUID
    BLERemotePeripheralCharacteristic characteristic(int index) const; // return the nth characteristic of the peripheral
    BLERemotePeripheralCharacteristic characteristic(const char * uuid) const; // return the characteristic with the specified UUID
    BLERemotePeripheralCharacteristic characteristic(const char * uuid, int index) const; // return the nth characteristic with the specified UUID
};

#endif
