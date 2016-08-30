/*
  BLE Peripheral API
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

#ifndef ARDUINO_BLE_PERIPHERAL_H
#define ARDUINO_BLE_PERIPHERAL_H

#include <BLELocalAttribute.h>
#include <BLERemoteAttribute.h>
#include <BLERemoteCentral.h>

enum BLEPeripheralEvent {
  BLEConnected = 0,
  BLEDisconnected = 1,
  BLEBonded = 2,
  BLERemoteServicesDiscovered = 3
};

typedef void (*BLEPeripheralEventHandler)(BLERemoteCentral& central);

class BLEPeripheral
{
public:
  BLEPeripheral();
  virtual ~BLEPeripheral();

  void begin(); // initiliaze hardware, setup attributes, and start advertising
  void poll(); // poll for events
  void end();  // stop advertising and initiliaze hardware

  void setAdvertisedServiceUuid(const char* advertisedServiceUuid); // set the service UUID that is advertised
  void setServiceSolicitationUuid(const char* serviceSolicitationUuid); // set the service that is solicited in the advertisement
  void setManufacturerData(const unsigned char manufacturerData[], unsigned char manufacturerDataLength); // set the manufacturer data that is advertised
  void setLocalName(const char *localName); // set the local name that is advertised

  void setAdvertisingInterval(unsigned short advertisingInterval); // set the advertising interval in ms
  void setConnectionInterval(unsigned short minimumConnectionInterval, unsigned short maximumConnectionInterval); // set the min and max connection interval in 1.25ms increments
  bool setTxPower(int txPower); // set the TX power of the radio in dBM
  void setConnectable(bool connectable); // control if the peripheral is connectable

  void setDeviceName(const char* deviceName); // set the value of the device name characteristic
  void setAppearance(unsigned short appearance); // set the value of the appearance characteristic

  void addLocalAttribute(BLELocalAttribute& localAttribute); // add a local attribute (service, characteristic, descriptor)
  void addRemoteAttribute(BLERemoteAttribute& remoteAttribute); // add a remove attribute (service, characteristic, descriptor)

  void disconnect(); // disconnect the central that is connected

  BLERemoteCentral central(); // returns the currently connected central
  bool connected(); // is the peripheral connected to a central now

  void setEventHandler(BLEPeripheralEvent event, BLEPeripheralEventHandler eventHandler); // set an event handler (callback)
};

#endif
