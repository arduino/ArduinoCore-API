/*
  Audio Stream API
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

#ifndef ARDUINO_AUDIO_STREAM
#define ARDUINO_AUDIO_STREAM

#include <Stream.h>

class AudioStream : public Stream
{
  // from Stream
  virtual int available();
  virtual int read();
  virtual int peek();
  virtual void flush();

  // from Print
  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *buffer, size_t size);

  // AudioStream specific
  virtual size_t availableForWrite();

  virtual int bitsPerSample() = 0; // the number of bits in a sample (8, 16, 24, 32, 48, etc)
  virtual int samplesAvailable(); // returns the number of samples (of bitsPerSample) that are available for reading
  virtual int samplesAvailableForWrite(); // returns the number of samples (of bitsPerSample) that can be written

  // read a sample, returns 1 on success, 0 if no samples available to read
  virtual int readSample(uint8_t& sample); // 8-bit
  virtual int readSample(uint16_t& sample); // 16-bit
  virtual int readSample(uint32_t& sample); // 24-bit or 32-bit
  virtual int readSample(uint64_t& sample); // 48-bit or 64-bit

  // peek a sample, returns 1 on success, 0 if no samples available to peek
  virtual int peekSample(uint8_t& sample); // 8-bit
  virtual int peekSample(uint16_t& sample); // 16-bit
  virtual int peekSample(uint32_t& sample); // 24-bit or 32-bit
  virtual int peekSample(uint64_t& sample); // 48-bit or 64-bit

  // read count samples, returns the number of samples read
  virtual int readSamples(uint8_t[] samples, int count); // 8-bit
  virtual int readSamples(uint16_t[] samples, int count); // 16-bit
  virtual int readSamples(uint32_t[] samples, int count); // 24-bit or 32-bit
  virtual int readSamples(uint64_t[] samples, int count); // 48-bit or 64-bit

  // write a sample, returns 1 on success, 0 if no sample written
  virtual int writeSample(uint8_t sample); // 8-bit
  virtual int writeSample(uint16_t sample); // 16-bit
  virtual int writeSample(uint32_t sample); // 24-bit or 32-bit
  virtual int writeSample(uint64_t sample); // 48-bit or 64-bit

  // write count samples, returns the number of samples written
  virtual int writeSamples(const uint8_t[] samples, int count); // 8-bit
  virtual int writeSamples(const uint16_t[] samples, int count); // 16-bit
  virtual int writeSamples(const uint32_t[] samples, int count); // 24-bit or 32-bit
  virtual int writeSamples(const uint64_t[] samples, int count); // 48-bit or 64-bit
};

#endif
