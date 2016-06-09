/*
  RealTimeClock API
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

#ifndef ARDUINO_REAL_TIME_CLOCK_H
#define ARDUINO_REAL_TIME_CLOCK_H

class RealTimeClock;
class TimeProvider;

// Functions to get and set current time

int year();   // current year as an integer
int month();  // current month as an integer (1 - 12)
int day();    // current day as an integer (1 - 31)
int hour();   // current hour as an integer (0 - 23)
int minute(); // current minute as an integer (0 - 59)
int second(); // current second as an integer (0 - 59)
void setTime(int hour, int minute, int second, int day, int month, int year); // set the current time

// Functions to get and set current time with unix-timestamps

unsigned long now();           // current time as seconds since Jan 1 1970
void setTime(unsigned long t); // set the current time from seconds since Jan 1 1970

// Functions to convert time from unix-timestamp to human readable format and viceversa

int year(unsigned long t);     // year of t as an integer
int month(unsigned long t);    // month of t as an integer (1 - 12)
int day(unsigned long t);      // day of t as an integer (1 - 31)
int hour(unsigned long t);     // hour of t as an integer (0 - 23)
int minute(unsigned long t);   // minute of t as an integer (0 - 59)
int second(unsigned long t);   // second of t as an integer (0 - 59)
unsigned long convertTime(int hour, int minute, int second, int day, int month, int year);

// Synchronize the clock with a time provider
// Return true if the synchronization is successful, false otherwise.
bool setTime(TimeProvider &provider);

// Real Time Clock interface
// Clocks should implement this interface
class RealTimeClock
{
public:
  // Get the current time as unix-timestamp.
  // Return 0 if time has not been set.
  virtual unsigned long getTime() = 0;

  // Set the current time as unix-timestamp
  virtual bool setTime(unsigned long t) = 0;
};

extern RealTimeClock *arduinoSystemRTC;

// Time Provider interface
// Class that performs time synchronization with a master time (atomic clock, GPS,
// NTP, etc.) should implement this interface.
class TimeProvider
{
public:
  // Query the time provider for the current real time and return it as unix-timestamp.
  // Returns 0 if the query fails.
  virtual unsigned long getTime() = 0;
};

#endif
