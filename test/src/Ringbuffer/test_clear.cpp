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

TEST_CASE ("Calling 'clear' on a empty ring buffer should have no effect", "[Ringbuffer-clear-01]")
{
  arduino::RingBufferN<2> ringbuffer;
  REQUIRE(ringbuffer.available() == 0);
  ringbuffer.clear();
  REQUIRE(ringbuffer.available() == 0);
}

TEST_CASE ("Calling 'clear' on a partially filled ring buffer should \"remove\" all elements", "[Ringbuffer-clear-02]")
{
  arduino::RingBufferN<2> ringbuffer;
  ringbuffer.store_char('A');
  REQUIRE(ringbuffer.available() == 1);
  ringbuffer.clear();
  REQUIRE(ringbuffer.available() == 0);
}
