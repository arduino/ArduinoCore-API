/*
  Arduino Wave file to I2S example
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

WaveFile waveFile;

int sampleRate;
int channels;

void setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only

  // setup the SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1); // do nothing
  }
  Serial.println("initialization done.");

  // use the file to create a WaveFile
  waveFile = WaveFile(file);

  // check if the WaveFile is valid
  if (!waveFile) {
    Serial.println("wave file is invalid!");
    while (1); // do nothing
  }

  // print out some info. about the wave file
  Serial.print("Bits per sample = ");
  Serial.println(waveFile.bitsPerSample());

  channels = waveFile.channels();
  Serial.print("Channels = ");
  Serial.println(channels);

  sampleRate = waveFile.sampleRate();
  Serial.print("Sample rate = ");
  Serial.println(sampleRate);

  // setup the I2S ouput
  if (!I2SOutput.begin()) {
    Serial.println("starting I2S output failed!");
    while (1); // do nothing
  }

  // check if playback can be done
  if (!waveFile.canPlay(I2SOutput)) {
    Serial.println("cannot play wave file on I2S output!");
    while (1); // do nothing
  }

  // start playback
  waveFile.play(I2SOutput);
}

void loop() {
  if (!waveFile.isPlaying()) {
    Serial.println("Wave file is not playing anymore, restarting");
    waveFile.play(I2SOutput);
  }
}
