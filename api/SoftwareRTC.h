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

#ifndef ARDUINO_SOFTWARE_RTC_H
#define ARDUINO_SOFTWARE_RTC_H

#include "RealTimeClock.h"

class SoftwareRTC : public RealTimeClock {
public:
  SoftwareRTC();

  // Get the current time as unix-timestamp.
  // Return 0 if time has not been set.
  virtual unsigned long getTime();

  // Set the current time as unix-timestamp
  virtual bool setTime(unsigned long t);

private:
  unsigned long lastTimestamp;
  unsigned long lastMillis; 
};

#endif
