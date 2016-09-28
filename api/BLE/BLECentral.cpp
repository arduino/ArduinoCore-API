/*
  BLE Central API (deprecated)
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

#include "BLECentral.h"

BLECentral(BLEDevice& device) :
  _device(&device)
{

}

bool BLECentral::connected(void)
{
  if (_device) {
    return _device->connected();
  }
}

const char* BLECentral::address(void) const
{
  if (_device) {
    return _device->address().c_str();
  }

  return "00:00:00:00:00:00";
}

bool BLECentral::disconnect(void)
{
  if (_device) {
    return _device->disconnect();
  }

  return false;
}

void BLECentral::poll(void)
{
  BLE.poll();
}

operator BLECentral::bool(void) const
{
  return (_device != NULL) && (*device);
}

bool BLECentral::operator==(const BLECentral& rhs) const
{
  return (_device == rhs._device);
}

bool BLECentral::operator!=(const BLECentral& rhs) const
{
  return (_device != rhs._device);
}
