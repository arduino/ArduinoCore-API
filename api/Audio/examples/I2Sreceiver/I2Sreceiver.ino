/*
  Arduino I2S receiver example
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

  I2S.onReceive(receiveDone);
  I2S.receiveEnable();
}

void loop() {
}

void receiveDone(int samples) {
  Serial.print("Received ")
  Serial.print(samples);
  Serial.println(" samples");

  while(I2S.samplesAvailable() >= 2) {
    int32_t left;
    int32_t right;

    I2S.readSample(left);
    I2S.readSample(right);

    // do something with data quickly
  }
}
