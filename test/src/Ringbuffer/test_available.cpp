/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <vector>

#include <RingBuffer.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("'available' should return 0 for empty ring buffer", "[Ringbuffer-available-01]")
{
  arduino::RingBufferN<2> ringbuffer;
  REQUIRE(ringbuffer.available() == 0);
}

TEST_CASE ("'available' should return number of elements in ringbuffer", "[Ringbuffer-available-02]")
{
  arduino::RingBufferN<2> ringbuffer;
  ringbuffer.store_char('A');
  REQUIRE(ringbuffer.available() == 1);
  REQUIRE(ringbuffer.availableForStore() == 1);
  ringbuffer.store_char('B');
  REQUIRE(ringbuffer.available() == 2);
  REQUIRE(ringbuffer.availableForStore() == 0);
}
