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

TEST_CASE ("'isFull' should return false for empty ring buffer", "[Ringbuffer-isFull-01]")
{
  arduino::RingBufferN<2> ringbuffer;
  REQUIRE(ringbuffer.isFull() == false);
}

TEST_CASE ("'isFull' should return false for a partial full ring buffer", "[Ringbuffer-isFull-02]")
{
  arduino::RingBufferN<2> ringbuffer;
  ringbuffer.store_char('A');
  REQUIRE(ringbuffer.isFull() == false);
}

TEST_CASE ("'isFull' should return true for full ring buffer", "[Ringbuffer-isFull-03]")
{
  arduino::RingBufferN<2> ringbuffer;
  ringbuffer.store_char('A');
  ringbuffer.store_char('B');
  REQUIRE(ringbuffer.isFull() == true);
}
