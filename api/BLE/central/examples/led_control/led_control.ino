/*
  Arduino BLE Central LED Control example
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

// variables for button
const int buttonPin = 2;
int oldButtonState = LOW;

// create central
BLECentral bleCentral;

void setup() {
  Serial.begin(9600);

  // configure the button pin as input
  pinMode(buttonPin, INPUT_PULLDOWN);

  // initialize the central
  bleCentral.begin();

  Serial.println("BLE Central - LED control");

  // start scanning for peripherals
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

    // see if peripheral is advertising the LED service
    if (peripheral.advertisedService() == "19b10000-e8f2-537e-4f6c-d104768a1214") {
      // stop scanning
      bleCentral.stopScanning();

      controlLed(peripheral);

      // peripheral disconnected, start scanning again
      bleCentral.startScanning();
    }
  }
}

void controlLed(BLERemotePeripheral& peripheral) {
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

  // retrieve the LED characteristic
  BLERemotePeripheralCharacteristic ledCharacteristic = peripheral.characteristic("19b10001-e8f2-537e-4f6c-d104768a1214");

  while (peripheral.connected()) {
    // while the peripheral is connection

    // read the button pin
    int buttonState = digitalRead(buttonPin);

    if (oldButtonState != buttonState) {
      // button changed
      oldButtonState = buttonState;

      if (buttonState) {
        Serial.println("button pressed");

        // button is pressed, write 0x01 to turn the LED on
        ledCharacteristic.writeChar(0x01);
      } else {
        Serial.println("button released");

        // button is released, write 0x00 to turn the LED of
        ledCharacteristic.writeChar(0x00);
      }
    }
  }
}


