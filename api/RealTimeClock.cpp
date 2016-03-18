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

#include "RealTimeClock.h"
#include <time.h>

#define YEAR_OFFSET     1900
#define MONTH_OFFSET    1

RealTimeClock *arduinoSystemRTC;

unsigned long now()
{
    if (arduinoSystemRTC) {
        return arduinoSystemRTC->getTime();
    } else {
        return 0;
    }
}

static struct tm* toTm(unsigned long t)
{
    time_t time = t;
    return gmtime(&time);
}

int year(unsigned long t)
{
    struct tm* tm = toTm(t);
    return (tm->tm_year + YEAR_OFFSET);
}

int year()
{
    return year(now());
}

int month(unsigned long t)
{
    struct tm* tm = toTm(t);
    return (tm->tm_mon + MONTH_OFFSET);
}

int month()
{
    return month(now());
}

int day(unsigned long t)
{
    struct tm* tm = toTm(t);
    return tm->tm_mday;
}

int day()
{
    return day(now());
}

int hour(unsigned long t)
{
    struct tm* tm = toTm(t);
    return tm->tm_hour;
}

int hour()
{
    return hour(now());
}

int minute(unsigned long t)
{
    struct tm* tm = toTm(t);
    return tm->tm_min;
}

int minute()
{
    return minute(now());
}

int second(unsigned long t)
{
    struct tm* tm = toTm(t);
    return tm->tm_sec;
}

int second()
{
    return second(now());
}

void setTime(unsigned long t)
{
  if (arduinoSystemRTC) {
    arduinoSystemRTC->setTime(t);
  }
}

unsigned long convertTime(int hour, int minute, int second, int day, int month, int year)
{
    struct tm tm;

    tm.tm_year = year - YEAR_OFFSET;
    tm.tm_mon = month - MONTH_OFFSET;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;
    tm.tm_isdst = -1;

    return mktime(&tm);
}

void setTime(int hour, int minute, int second, int day, int month, int year)
{
    time_t t = convertTime(hour, minute, second, day, month, year);

    setTime(t);
}
