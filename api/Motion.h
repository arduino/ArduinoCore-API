/*
  MotionSense API
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

#ifndef ARDUINO_MOTION_SENSE_H
#define ARDUINO_MOTION_SENSE_H

class Accelerometer {
  virtual bool readAcceleration(float &x, float &y, float &z) = 0;
  virtual unsigned int availableAcceleration() = 0;
  virtual unsigned long sampleRateAcceleration() = 0;
};

class Gyro {
  virtual bool readGyro(float &x, float &y, float &z) = 0;
  virtual unsigned int availableGyro() = 0;
  virtual unsigned long sampleRateGyro() = 0;
};

struct Rotation {
  float yaw;
  float pitch;
  float roll;
};

struct Quaternion {
  union {
    float q[4];
    struct {
      float x;
      float y;
      float z;
      float w;
    };
  };
};

#endif
