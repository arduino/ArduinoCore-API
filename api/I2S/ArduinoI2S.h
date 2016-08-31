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

typedef enum {
  PHILIPS_MODE,
  RIGHT_JST_MODE,
  LEFT_JST_MODE,
  DSP_MODE
} i2s_mode_t;

class I2SClass
{
  void begin(int mode, long sampleRate, int resolution); // setup the I2S hardware in the specified mode, sample rate and resolution
  void end(); // stop the I2S hardware

  void beginTransmit(); // enable transmit mode
  void endTransmit(); // disable transmit mode

  void beginReceive(); // enable receive mode
  void endReceive(); // disable transmit mode

  // Stream/Print like
  int available(void); // returns how many words are available for reading
  long read(void); // read the next word in the RX queue, -1 if no words available for reading
  long peek(void); // peek at the next work in the RX queue, -1 if no words available for peeking
  void flush(void); // flush the TX queue

  int availableForWrite(void); // returns how many words can be written
  size_t write(uint32_t data); // write a words, returns 1 on success, 0 on failure (buffer full)
  size_t write(uint32_t left, uint32_t right); // write a left channel and right channel word
  size_t write(const uint32_t data[], size_t quantity); // write an array of words, return the number of words written (0 on failure)
  
  void onReceive(void(*)(int)); // add an event handler for when data is received
  void onTransmit(void(*)(int)); // add an event handler for when data is transmitted
  void onTransmitBufferEmpty(void(*)(void)); // add an event handler for when the transmit buffer is empty
};

extern I2SClass I2S;

#endif
