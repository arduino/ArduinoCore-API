/*
  BLE Characteristic API
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

#ifndef ARDUINO_BLE_CHARACTERISTIC_H
#define ARDUINO_BLE_CHARACTERISTIC_H

#include "BLELocalAttribute.h"

enum BLECharacteristicEvent {
  BLEWritten = 0,
  BLESubscribed = 1,
  BLEUnsubscribed = 2
};

typedef void (*BLECharacteristicEventHandler)(BLECentral& central, BLECharacteristic& characteristic);

class BLECharacteristic : public BLELocalAttribute
{
public:
  BLECharacteristic(const char* uuid, unsigned char properties, unsigned char valueSize); // create a characteristic with specified value size
  BLECharacteristic(const char* uuid, unsigned char properties, const char* value); // create a characteristic with string value

  virtual ~BLECharacteristic();

  unsigned char properties() const; // returns the property mask of the characteristic

  virtual unsigned char valueSize() const; // returns the maximum size of the value
  virtual const unsigned char* value() const; // returns the value buffer
  virtual unsigned char valueLength() const; // returns the current length of the value
  virtual unsigned char operator[] (int offset) const; // returns a byte of the value at the specified offset

  virtual bool fixedLength() const; // does the characteristic have a fixed length (valueSize always equals length)

  virtual bool setValue(const unsigned char value[], unsigned char length); // set the value of the characteristc
  virtual bool setValue(const char* value); // set the value of the characteristic from a string

  bool broadcast(); // broadcast the characteristic value in the advertisement data

  bool written(); // has the central written a new value
  bool subscribed(); // is the central subscribed
  bool canNotify(); // can a notification be sent to the central
  bool canIndicate(); // can a indication be sent to the central

  void setEventHandler(BLECharacteristicEvent event, BLECharacteristicEventHandler eventHandler); // set an event handler (callback)
};


// Fixed length characteristic, value size is constant
class BLEFixedLengthCharacteristic : public BLECharacteristic {
public:
  BLEFixedLengthCharacteristic(const char* uuid, unsigned char properties, unsigned char valueSize);
  BLEFixedLengthCharacteristic(const char* uuid, unsigned char properties, const char* value);

  virtual bool fixedLength() const;
};

#endif

// Characteristic type to represent a bool type
class BLEBoolCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEBoolCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(bool value);
  bool value();
};

// Characteristic type to represent a char type
class BLECharCharacteristic : public BLETypedCharacteristic<char> {
public:
  BLECharCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(char value);
  char value();
};

// Characteristic type to represent an unsigned char type
class BLEUnsignedCharCharacteristic : BLEFixedLengthCharacteristic {
public:
  BLEUnsignedCharCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(unsigned char value);
  unsigned char value();
};

// Characteristic type to represent a short type
class BLEShortCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEShortCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(short value);
  short value();

  bool setValueLE(short value);
  short valueLE();

  bool setValueBE(short value);
  short valueBE();
};

// Characteristic type to represent a unsigned short type
class BLEUnsignedShortCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEUnsignedShortCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(unsigned short value);
  unsigned short value();

  bool setValueLE(unsigned short value);
  unsigned short valueLE();

  bool setValueBE(unsigned short value);
  unsigned short valueBE();
};

// Characteristic type to represent a int type
class BLEIntCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEIntCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(int value);
  int value();

  bool setValueLE(int value);
  int valueLE();

  bool setValueBE(int value);
  int valueBE();
};

// Characteristic type to represent a unsigned int type
class BLEUnsignedIntCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEUnsignedIntCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(unsigned int value);
  unsigned int value();

  bool setValueLE(unsigned int value);
  unsigned int valueLE();

  bool setValueBE(unsigned int value);
  unsigned int valueBE();
};

// Characteristic type to represent a long type
class BLELongCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLELongCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(long value);
  long value();

  bool setValueLE(long value);
  long valueLE();

  bool setValueBE(long value);
  long valueBE();
};

// Characteristic type to represent a unsigned long type
class BLEUnsignedLongCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEUnsignedLongCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(unsigned long value);
  unsigned long value();

  bool setValueLE(unsigned long value);
  unsigned long valueLE();

  bool setValueBE(unsigned long value);
  unsigned long valueBE();
};

// Characteristic type to represent a float type
class BLEFloatCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEFloatCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(float value);
  float value();

  bool setValueLE(float value);
  float valueLE();

  bool setValueBE(float value);
  float valueBE();
};

// Characteristic type to represent a double type
class BLEDoubleCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEDoubleCharacteristic(const char* uuid, unsigned char properties);

  bool setValue(double value);
  double value();

  bool setValueLE(double value);
  double valueLE();

  bool setValueBE(double value);
  double valueBE();
};
