/*
  Arduino I2S sender example
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


#include <ArduinoI2S.h>

void setup() {
  Serial.begin(9600);

  I2S.begin(PHILIPS_MODE, 32, 44000);

  I2S.onTransmit(transmitDone);
  I2S.onTransmitBufferEmpty(transmitBufferEmpty);
}

void loop() {
  Serial.println("Sending I2S data");

  I2S.transmitEnable(); // enable transmit mode

  // send 100ms of data, 44 words per channel
  // -> each loop iteration sends 2 words per channel
  for (int i = 0; i < 22; i++) {
    I2S.writeSample(0xFFFFFFFF); // left channel
    I2S.writeSample(0x00000000); // right channel

    I2S.writeSample(0xDEADFACE); // left channel
    I2S.writeSample(0x10101010); // right channel
  }

  I2S.transmitDisable(); // disable transmit mode
  delay(100);
}

void transmitDone(int samples) {
  Serial.print(samples)
  Serial.println(" samples sent");
}

void transmitBufferEmpty() {
  Serial.println("transmit buffer is empty!");
}
