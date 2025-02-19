/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef TCPCLIENT_MOCK_H_
#define TCPCLIENT_MOCK_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <api/Client.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

/*
 * The purpose of this class is currently to highlight the effects of lacking virtual destructor
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

class TCPClientMock : public arduino::Client {
public:
  virtual int connect(IPAddress ip, uint16_t port) { return 0; }
  virtual int connect(const char *host, uint16_t port) { return 0; }
  virtual size_t write(uint8_t) { return 0; }
  virtual size_t write(const uint8_t *buf, size_t size) { return 0;}
  virtual int available() { return 0; }
  virtual int read() { return 0; }
  virtual int read(uint8_t *buf, size_t size) { return 0;}
  virtual int peek() { return 0; }
  virtual void flush() {}
  virtual void stop() {}
  virtual uint8_t connected() { return 0;}
  virtual operator bool() { return true; }
};
#pragma GCC diagnostic pop


#endif /* TCPCLIENT_MOCK_H_ */
