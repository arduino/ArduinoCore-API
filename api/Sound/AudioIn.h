/*
  Audio In API
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

#ifndef ARDUINO_AUDIO_IN
#define ARDUINO_AUDIO_IN

class AudioIn
{
public:
  AudioIn();

  virtual long sampleRate() = 0; // Returns the sample rate
  virtual int bitsPerSample(); // returns the bits per sample
  virtual int channels() = 0; // Returns the number of channels

  virtual int pause() = 0; // pause playback
  virtual int stop() = 0; // stop playback

  virtual int isPlaying(); // is the input playing now?
  virtual int isPaused(); // is the input paused
};



#endif
