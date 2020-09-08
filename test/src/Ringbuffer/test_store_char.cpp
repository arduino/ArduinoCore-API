/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <RingBuffer.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Data is put into the ring buffer via 'store_char'", "[Ringbuffer-store_char-01]")
{
  arduino::RingBufferN<2> ringbuffer;
  ringbuffer.store_char('A');
  REQUIRE(ringbuffer._aucBuffer[0] == 'A');
  ringbuffer.store_char('B');
  REQUIRE(ringbuffer._aucBuffer[1] == 'B');
}
