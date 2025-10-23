/*
  Client.h - Base class that provides Client
  Copyright (c) 2011 Adrian McEwen.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#include "Stream.h"
#include "IPAddress.h"

namespace arduino {

// The objective of this interface is to split the definition of a Client that
// works with streams and one that works with discrete sized messages
class ClientConnect {
public:
  virtual ~ClientConnect() = default;

  virtual int connect(IPAddress ip, uint16_t port) = 0;
  virtual int connect(const char *host, uint16_t port) = 0;
  virtual void disconnect() = 0;

  virtual uint8_t connected() = 0;
  virtual operator bool() = 0;
};

class Client : public Stream, ClientConnect {
public:
  virtual size_t write(uint8_t) = 0;
  virtual size_t write(const uint8_t *buf, size_t size) = 0;
  virtual int read(uint8_t *buf, size_t size) = 0;
  virtual void stop() = 0;
protected:
  uint8_t* rawIPAddress(IPAddress& addr) { return addr.raw_address(); }; // FIXME this is a utility function
};

}
