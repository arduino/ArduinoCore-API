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

  I2S.begin(PHILIPS_MODE, 44000, 32);

  I2S.onReceive(receiveDone);
  I2S.beginReceive();
}

void loop() {
}

void receiveDone(int samples) {
  Serial.print("Received ")
  Serial.print(samples);
  Serial.println(" samples");

  while(I2S.available() >= 2) {
    long left = I2S.read();
    long right = I2S.read();

    // do something with data quickly
  }
}
