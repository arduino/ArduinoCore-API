/*
  Arduino I2S to Wave file example
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

#include <SPI.h>
#include <SD.h>

#include <Sound.h>

// filename on SD card to read
const char filename = "test.wav";

// pin to use as input
const int buttonPin = 2;

// recording length in milliseconds
const int recordingTime = 30 * 1000;

WaveFile waveFile;

bool recordingInProgress = false;
unsigned long recordingStart;

void setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only

  // setup the button as an input
  pinMode(buttonPin, INPUT);

  // setup the SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1); // do nothing
  }
  Serial.println("initialization done.");

  // setup I2SInput, philips mode, 24-bits per sample, 16 kHz
  if (!I2SInput.begin(PHILIPS_MODE, 24, 16000) {
    Serial.println("error starting I2S");
    while(1); // do nothing
  }
}

void loop() {
  if (recordingInProgress) {
    // check if we've recorded for long enough
    if ((millis() - recordingStart) > recordingTime) {
      // stop recording
      Serial.println("Stopping recording");

      I2SInput.stop();

      recordingInProgress = false;
    }
  } else if (digitalRead(buttonPin) == HIGH) {
    // no recording in process but button pressed, start recording
    Serial.print("Starting recording to ");
    Serial.println(filename);

    // use the file to create a WaveFile
    waveFile = WaveFile(file);

    I2SInput.play(waveFile);
  }
}
