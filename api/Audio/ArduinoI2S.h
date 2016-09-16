/*
  I2S API
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

#ifndef ARDUINO_I2S
#define ARDUINO_I2S

#include <AudioStream.h>

typedef enum {
  PHILIPS_MODE,
  RIGHT_JST_MODE,
  LEFT_JST_MODE,
  DSP_MODE
} i2s_mode_t;

class I2SClass : public AduinoStream
{
  int begin(int mode, int bitsPerSample, long sampleRate); // setup the I2S hardware in the specified mode, bits per sample, and sample rate 
  void end(); // stop the I2S hardware

  int transmitEnable(); // enable transmit mode
  int transmitDisable(); // disable transmit mode

  int receiveEnable(); // enable receive mode
  int receiveDisable(); // disable transmit mode
  
  void onReceive(void(*)(int)); // add an event handler for when data is received
  void onTransmit(void(*)(int)); // add an event handler for when data is transmitted
  void onTransmitBufferEmpty(void(*)(void)); // add an event handler for when the transmit buffer is empty
};

extern I2SClass I2S;

#endif
