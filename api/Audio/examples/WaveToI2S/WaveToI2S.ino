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

#include <ArduinoI2S.h>
#include <WaveFile.h>

// filename on SD card to read
const char filename = "test.wav";

File file;
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

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  file = SD.open(filename);

  // check if the file opened sucessfully
  if (!file) {
    Serial.print("error opening ");
    Serial.println(filename);
    while (1); // do nothing
  }

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

  int mode;

  if (channels == 1) {
    // only one channel in wave file, use right mode
    mode = RIGHT_JST_MODE;
  } else if (channels == 2) {
    // wave file has two channels, use philips mode
    mode = PHILIPS_MODE;
  } else {
    Serial.print("Wave file contains more than two channels!");
    while (1); // do nothing
  }

  // start I2S
  if (!I2S.begin(mode, waveFile.bitsPerSample(), waveFile.sampleRate()) {
    Serial.println("error starting I2S");
    while(1); // do nothing
  }

  // enable transmit
  I2S.transmitEnable();
}

void loop() {
  if (!waveFile.available()) {
    // no sample, go back to start
    waveFile.seek(0);
  }

  if (I2S.availableForWrite() && waveFile.available()) {
    // read a byte from the wave file
    int b = waveFile.read();

    // write the byte to I2S
    I2S.write(b);
  }
}
