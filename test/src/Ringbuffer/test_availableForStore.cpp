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

TEST_CASE ("'availableForStore' should return ring buffer size for empty ring buffer", "[Ringbuffer-availableForStore-01]")
{
  arduino::RingBufferN<2> ringbuffer;
  REQUIRE(ringbuffer.availableForStore() == 2);
}

TEST_CASE ("'availableForStore' should return number of free elements in ringbuffer", "[Ringbuffer-availableForStore-02]")
{
  arduino::RingBufferN<2> ringbuffer;
  ringbuffer.store_char('A');
  REQUIRE(ringbuffer.availableForStore() == 1);
  ringbuffer.store_char('B');
  REQUIRE(ringbuffer.availableForStore() == 0);
}
