/*
  BLE Device API
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

#ifndef ARDUINO_BLE_DEVICE_H
#define ARDUINO_BLE_DEVICE_H

#include <Arduino.h>

#include "BLEService.h"

enum BLEDeviceEvent {
  BLEDiscovered = 0,
  BLEConnected = 1,
  BLEDisconnected = 2,
};

typedef void (*BLEDeviceEventHandler)(BLEDevice device);

class BLEDevice
{
  public:
    BLEDevice();
    virtual ~BLEDevice();

    void begin(); // initiliaze hardware
    void poll(); // poll for events
    void end(); // deinitiliaze hardware

    bool connected(); // is the device connected
    void disconnect(); // disconnect

    String address() const; // returns the BT address of the device as a String

    // peripheral mode
    void setAdvertisedServiceUuid(const char* advertisedServiceUuid); // set the service UUID that is advertised
    void setAdvertisedService(const BLEService& service); // advertise the UUID of the provided service
    void setServiceSolicitationUuid(const char* serviceSolicitationUuid); // set the service that is solicited in the advertisement
    void setManufacturerData(const unsigned char manufacturerData[], unsigned char manufacturerDataLength); // set the manufacturer data that is advertised
    void setLocalName(const char *localName); // set the local name that is advertised

    void setAdvertisingInterval(unsigned short advertisingInterval); // set the advertising interval in ms
    void setConnectionInterval(unsigned short minimumConnectionInterval, unsigned short maximumConnectionInterval); // set the min and max connection interval in 1.25ms increments
    bool setTxPower(int txPower); // set the TX power of the radio in dBM
    void setConnectable(bool connectable); // control if the peripheral is connectable

    void setDeviceName(const char* deviceName); // set the value of the device name characteristic
    void setAppearance(unsigned short appearance); // set the value of the appearance characteristic

    void addService(BLEService& attribute); // add a service

    void startAdvertising();
    void stopAdvertising();

    BLEDevice central(); // returns the currently connected central    

    // central mode
    void startScanning(); // start scanning for peripherals
    void startScanningWithDuplicates(); // start scanning for peripherals, and report all duplicates
    void stopScanning(); // stop scanning for peripherals

    BLEDevice available(); // retrieve a discovered peripheral

    bool hasLocalName() const; // does the peripheral advertise a local name
    bool hasAdvertisedServiceUuid() const; // does the peripheral advertise a service
    bool hasAdvertisedServiceUuid(int index) const; // does the peripheral advertise a service n
    int advertisedServiceUuidCount() const; // number of services the peripheral is advertising

    String localName() const; // returns the advertised local name as a String
    String advertisedServiceUuid() const; // returns the advertised service as a UUID String
    String advertisedServiceUuid(int index) const; // returns the nth advertised service as a UUID String

    int rssi() const; // returns the RSSI of the peripheral at discovery

    bool connect(); // connect to the peripheral
    bool discoverAttributes(); // discover the peripheral's attributes

    String deviceName(); // read the device name attribute of the peripheral, and return String value
    int appearance(); // read the appearance attribute of the peripheral and return value as int

    int serviceCount() const; // returns the number of services the peripheral has
    bool hasService(const char* uuid) const; // does the peripheral have a service with the specified UUID
    bool hasService(const char* uuid, int index) const;  // does the peripheral have an nth service with the specified UUID
    BLEService service(int index) const; // return the nth service of the peripheral
    BLEService service(const char * uuid) const; // return the service with the specified UUID
    BLEService service(const char * uuid, int index) const; // return the nth service with the specified UUID

    int characteristicCount() const; // returns the number of characteristics the peripheral has
    bool hasCharacteristic(const char* uuid) const; // does the peripheral have a characteristic with the specified UUID
    bool hasCharacteristic(const char* uuid, int index) const; // does the peripheral have an nth characteristic with the specified UUID
    BLECharacteristic characteristic(int index) const; // return the nth characteristic of the peripheral
    BLECharacteristic characteristic(const char * uuid) const; // return the characteristic with the specified UUID
    BLECharacteristic characteristic(const char * uuid, int index) const; // return the nth characteristic with the specified UUID

    // event handler
    void setEventHandler(BLEDeviceEvent event, BLEDeviceEventHandler eventHandler); // set an event handler (callback)
};

#endif
