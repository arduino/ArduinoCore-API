/*
  BLE Attribute API
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

#ifndef ARDUINO_BLE_ATTRIBUTE_H
#define ARDUINO_BLE_ATTRIBUTE_H

enum BLEAttributeType {
  BLETypeService        = 0x2800,
  BLETypeCharacteristic = 0x2803,
  BLETypeDescriptor     = 0x2900
};

enum BLEProperty {
  BLEBroadcast            = 0x01,
  BLERead                 = 0x02,
  BLEWriteWithoutResponse = 0x04,
  BLEWrite                = 0x08,
  BLENotify               = 0x10,
  BLEIndicate             = 0x20
};

class BLEAttribute
{
public:
  BLEAttribute(const char* uuid, enum BLEAttributeType type);
  String uuid() const; // get the UUID as a string

  enum BLEAttributeType type() const;
};

#endif
