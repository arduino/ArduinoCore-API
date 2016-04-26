/*
  Arduino BLE Central SensorTag button example
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

#include <ArduinoBLECentral.h>

// create central
BLECentral bleCentral;

void setup() {
  Serial.begin(9600);

  // initialize the central
  bleCentral.begin();

  Serial.println("BLE Central - SensorTag button");

  // start scanning for peripheral
  bleCentral.startScanning();
}

void loop() {
  // check if a peripheral has been discovered
  BLERemotePeripheral peripheral = bleCentral.available();

  if (peripheral) {
    // discovered a peripheral, print out address, local name, and advertised service
    Serial.print("Found ");
    Serial.print(peripheral.address());
    Serial.print(" '");
    Serial.print(peripheral.localName());
    Serial.print("' ");
    Serial.print(peripheral.advertisedService());
    Serial.println();

    // see if peripheral is a SensorTag
    if (peripheral.localName() == "SensorTag") {
      // stop scanning
      bleCentral.stopScanning();

      monitorSensorTagButtons(peripheral);

      // peripheral disconnected, start scanning again
      bleCentral.startScanning();
    }
  }
}

void monitorSensorTagButtons(BLERemotePeripheral& peripheral) {
  // connect to the peripheral
  Serial.println("Connecting ...");
  if (peripheral.connect()) {
    Serial.println("Connected");
  } else {
    Serial.println("Failed to connect!");
    return;
  }

  // discover peripheral attributes
  Serial.println("Discovering attributes ...");
  if (peripheral.discoverAttributes()) {
    Serial.println("Attributes discovered");
  } else {
    Serial.println("Attribute discovery failed!");
    peripheral.disconnect();
    return;
  }

  // retrieve the simple key characteristic
  BLERemotePeripheralCharacteristic simpleKeyCharacteristic = peripheral.characteristic("ffe1");

  // subscribe to the simple key characteristic
  Serial.println("Subscribing to simple key characteristic ...");
  if ( simpleKeyCharacteristic.subscribe()) {
    Serial.println("Subscribed");
  } else {
    Serial.println("subscription failed!");
    peripheral.disconnect();
    return;
  }

  while (peripheral.connected()) {
    // while the peripheral is connected

    // check if the value of the simple key characteristic has been updated
    if (simpleKeyCharacteristic.valueUpdated()) {
      // yes, get the value, characteristic is 1 byte so use char value
      int value = simpleKeyCharacteristic.charValue();

      if (value & 0x01) {
        // first bit corresponds to the right button
        Serial.println("Right button pressed");
      }

      if (value & 0x02) {
        // second bit corresponds to the left button
        Serial.println("Left button pressed");
      }
    }
  }
}


