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

#include <Stream.h>

typedef enum {
  PHILIPS_MODE,
  RIGHT_JST_MODE,
  LEFT_JST_MODE,
  DSP_MODE
} i2s_mode_t;

class I2SClass : public Stream
{
  int begin(int mode, long sampleRate, int bitsPerSample); // setup the I2S hardware in the specified mode, sample rate, and bits per sample

  // alternative to above
  int beginPhilips(long sampleRate, int bitsPerSample); 
  int beginRightJustified(long sampleRate, int bitsPerSample); 
  int beginLeftJustified(long sampleRate, int bitsPerSample);
  int beginDsp(long sampleRate, int bitsPerSample);

  void end(); // stop the I2S hardware

  // from Stream (these will start RX mode, if not enabled)
  virtual int available();
  virtual int read();
  virtual int peek();
  virtual void flush();

  // from Print (these will start TX mode, if not enabled)
  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *buffer, size_t size);

  virtual size_t availableForWrite();

  // read an array of data
  int read(uint8_t data[], int size);
  int read(uint16_t data[], int size);
  int read(uint32_t data[], int size);
  int read(uint64_t data[], int size);

  // write an array of data
  int write(const uint8_t data[], int size);
  int write(const uint16_t data[], int size);
  int write(const uint32_t data[], int size);
  int write(const uint64_t data[], int size);

  // call backs
  void onReceive(void(*)(int)); // add an event handler for when data is received
  void onTransmit(void(*)(int)); // add an event handler for when data is transmitted

  // override default pins, must be called before begin(...) (optional)
  void setTxPins(int clock, int wordSelect, int data);
  void setRxPins(int clock, int wordSelect, int data);
};

extern I2SClass I2S;

#endif
