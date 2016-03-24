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

// Sensors that doesn't implement a FIFO can use the default
// implementation of availableXxx() and sampleRateXxx()

// Base class for accelerometers
class Accelerometer {
  // read an acceleration sample from the FIFO or wait until one is available
  virtual bool readAcceleration(float &x, float &y, float &z) = 0;

  // number of samples in the FIFO
  virtual unsigned int availableAcceleration()   { return 1; }

  // sampling rate of the sensor
  virtual unsigned long sampleRateAcceleration() { return 0; }
};

// Base class for gyro
class Gyro {
  // read a gyro sample from the FIFO or wait until one is available
  virtual bool readGyro(float &x, float &y, float &z) = 0;

  // number of samples in the FIFO
  virtual unsigned int availableGyro()   { return 1; }

  // sampling rate of the sensor
  virtual unsigned long sampleRateGyro() { return 0; }
};

// Base class for magnetometers
class Magnetometer {
  // read a magnetometer sample from the FIFO or wait until one is available
  virtual bool readMagneticField(float &x, float &y, float &z) = 0;

  // Number of samples in the FIFO.
  virtual unsigned int availableMagneticField()   { return 1; }

  // Sampling rate of the sensor.
  virtual unsigned long sampleRateMagneticField() { return 0; }
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
