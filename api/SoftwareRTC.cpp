/*
  Software RealTimeClock
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

#include "Arduino.h"
#include "SoftwareRTC.h"

SoftwareRTC::SoftwareRTC() : lastTimestamp(0), lastMillis(0)
{
  // Empty
}

unsigned long SoftwareRTC::getTime()
{
  if (lastTimestamp == 0) return 0;
  unsigned long now = millis();
  unsigned long delta = now - lastMillis;
  if (delta >= 1000) {
    delta /= 1000; // Determine the number of seconds elapsed
    lastMillis += delta * 1000;
    lastTimestamp += delta;
  }
  return lastTimestamp;
}

bool SoftwareRTC::setTime(unsigned long t)
{
  lastTimestamp = t;
  lastMillis = millis();
  return true;
}

