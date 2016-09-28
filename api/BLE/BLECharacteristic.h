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

#include "BLEAttributeWithValue.h"
#include "BLEDescriptor.h"

enum BLECharacteristicEvent {
  BLEWritten = 0,
  BLESubscribed = 1,
  BLEUnsubscribed = 2,
  BLEValueUpdated = 3
};

enum BLEProperty {
  BLEBroadcast            = 0x01,
  BLERead                 = 0x02,
  BLEWriteWithoutResponse = 0x04,
  BLEWrite                = 0x08,
  BLENotify               = 0x10,
  BLEIndicate             = 0x20
};

typedef void (*BLECharacteristicEventHandler)(BLEDevice central, BLECharacteristic characteristic);

class BLECharacteristic : public BLEAttributeWithValue
{
public:
  BLECharacteristic();
  BLECharacteristic(const char* uuid, unsigned char properties, unsigned char valueSize); // create a characteristic with specified value size
  BLECharacteristic(const char* uuid, unsigned char properties, const char* value); // create a characteristic with string value

  virtual ~BLECharacteristic();

  virtual operator bool() const; // is the characteristic valid

  const char* uuid() const;

  unsigned char properties() const; // returns the property mask of the characteristic

  int valueSize() const; // returns the maximum size of the value
  virtual const byte* value() const; // returns the value buffer
  virtual int valueLength() const; // returns the current length of the value
  virtual byte operator[] (int offset) const; // returns a byte of the value at the specified offset

  // write the value of the characteristic
  virtual bool writeValue(const byte value[], int length);
  bool writeValue(const byte value[], int length, int offset);
  bool writeValue(const char* value);

  virtual bool read(); // read the characteristic value
  virtual bool write(const unsigned char* value, int length); // write the charcteristic value

  // peripheral mode
  bool broadcast(); // broadcast the characteristic value in the advertisement data

  bool written(); // has the central written a new value
  bool subscribed(); // is the central subscribed
  bool canNotify(); // can a notification be sent to the central
  bool canIndicate(); // can a indication be sent to the central


  // central mode
  bool canRead(); // can the characteristic be read (based on properties)
  bool canWrite(); // can the characteristic be written (based on properties)
  bool canSubscribe(); // can the characteristic be subscribed to (based on properties)
  bool canUnsubscribe(); // can the characteristic be unsubscribed to (based on properties)

  bool read(); // read the characteristic value
  bool subscribe(); // subscribe to the characteristic
  bool unsubscribe(); // unsubscribe to the characteristic

  bool valueUpdated(); 

  int descriptorCount() const; // returns the number of descriptors the characteristic has
  bool hasDescriptor(const char* uuid) const; // does the characteristic have a descriptor with the specified UUID
  bool hasDescriptor(const char* uuid, int index) const; // does the characteristic have an nth descriptor with the specified UUID
  BLEDescriptor descriptor(int index) const; // return the nth descriptor of the characteristic
  BLEDescriptor descriptor(const char * uuid) const; // return the descriptor with the specified UUID
  BLEDescriptor descriptor(const char * uuid, int index) const; // return the nth descriptor with the specified UUIDb

  void setEventHandler(BLECharacteristicEvent event, BLECharacteristicEventHandler eventHandler); // set an event handler (callback)
};


// Fixed length characteristic, value size is constant
class BLEFixedLengthCharacteristic : public BLECharacteristic {
public:
  BLEFixedLengthCharacteristic(const char* uuid, unsigned char properties, unsigned char valueSize);
  BLEFixedLengthCharacteristic(const char* uuid, unsigned char properties, const char* value);
};

#endif

// Characteristic type to represent a bool type
class BLEBoolCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEBoolCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(bool value);
  bool value();
};

// Characteristic type to represent a char type
class BLECharCharacteristic : public BLETypedCharacteristic<char> {
public:
  BLECharCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(char value);
  char value();
};

// Characteristic type to represent an unsigned char type
class BLEUnsignedCharCharacteristic : BLEFixedLengthCharacteristic {
public:
  BLEUnsignedCharCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(unsigned char value);
  unsigned char value();
};

// Characteristic type to represent a short type
class BLEShortCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEShortCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(short value);
  short value();

  bool writeValueLE(short value);
  short valueLE();

  bool writeValueBE(short value);
  short valueBE();
};

// Characteristic type to represent a unsigned short type
class BLEUnsignedShortCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEUnsignedShortCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(unsigned short value);
  unsigned short value();

  bool writeValueLE(unsigned short value);
  unsigned short valueLE();

  bool writeValueBE(unsigned short value);
  unsigned short valueBE();
};

// Characteristic type to represent a int type
class BLEIntCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEIntCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(int value);
  int value();

  bool writeValueLE(int value);
  int valueLE();

  bool writeValueBE(int value);
  int valueBE();
};

// Characteristic type to represent a unsigned int type
class BLEUnsignedIntCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEUnsignedIntCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(unsigned int value);
  unsigned int value();

  bool writeValueLE(unsigned int value);
  unsigned int valueLE();

  bool writeValueBE(unsigned int value);
  unsigned int valueBE();
};

// Characteristic type to represent a long type
class BLELongCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLELongCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(long value);
  long value();

  bool writeValueLE(long value);
  long valueLE();

  bool writeValueBE(long value);
  long valueBE();
};

// Characteristic type to represent a unsigned long type
class BLEUnsignedLongCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEUnsignedLongCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(unsigned long value);
  unsigned long value();

  bool writeValueLE(unsigned long value);
  unsigned long valueLE();

  bool writeValueBE(unsigned long value);
  unsigned long valueBE();
};

// Characteristic type to represent a float type
class BLEFloatCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEFloatCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(float value);
  float value();

  bool writeValueLE(float value);
  float valueLE();

  bool writeValueBE(float value);
  float valueBE();
};

// Characteristic type to represent a double type
class BLEDoubleCharacteristic : public BLEFixedLengthCharacteristic {
public:
  BLEDoubleCharacteristic(const char* uuid, unsigned char properties);

  bool writeValue(double value);
  double value();

  bool writeValueLE(double value);
  double valueLE();

  bool writeValueBE(double value);
  double valueBE();
};
