/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

#ifndef STREAM_MOCK_H_
#define STREAM_MOCK_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <deque>

#include <api/Stream.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class StreamMock : public arduino::Stream
{
public:

  void operator << (char const * str);

  virtual size_t write(uint8_t ch) override;
  virtual int available() override;
  virtual int read() override;
  virtual int peek() override;

private:
  std::deque<char> _stream;

};

#endif /* STREAM_MOCK_H_ */
