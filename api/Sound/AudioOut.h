/*
  Audio Out API
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

#ifndef ARDUINO_AUDIO_OUT
#define ARDUINO_AUDIO_OUT

#include "AudioIn.h"

class AudioOut
{
  virtual int canPlay(AudioIn& input) = 0; // can the output device play the input
  virtual int play(AudioIn& input) = 0; // Starts playback of the input
  virtual int loop(AudioIn& input) = 0; // Starts loop playback of the input

  virtual int pause() = 0; // pause playback
  virtual int stop() = 0; // stop playback

  virtual int isPlaying(); // is the input playing now?
  virtual int isPaused(); // is the input paused

  virtual int volume(int level) = 0; // Changes the volume of playback, allowed values are between 0 and 100 (percent).
};

#endif
