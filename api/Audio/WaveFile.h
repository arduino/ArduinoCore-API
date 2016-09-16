/*
  Wave File API
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

#ifndef ARDUINO_WAVE_FILE
#define ARDUINO_WAVE_FILE

#include <SD.h>

#include <AudioStream.h>

class WaveFile : public AudioStream
{
  WaveFile();
  WaveFile(File& file);

  operator bool();

  int beginWrite(int bitsPerSample, int channels, long sampleRate);
  int endWrite();
  void close();

  long sampleRate();
  long sampleCount(); // total number of samples in the file

  int seek(long n); // seek to sample n
  long position(); // returns position in samples

  // from AudioStream
  virtual int bitsPerSample();
  virtual int channels();
};

#endif
