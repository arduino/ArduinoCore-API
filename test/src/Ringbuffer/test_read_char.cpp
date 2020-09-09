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

TEST_CASE ("Data is removed from the ring buffer via 'read_char'", "[Ringbuffer-read_char-01]")
{
  arduino::RingBufferN<2> ringbuffer;

  WHEN("The ringbuffer is empty")
    THEN("'read_char' should return -1")
      REQUIRE(ringbuffer.read_char() == -1);

  WHEN("The ringbuffer contains data")
  {
    ringbuffer.store_char('A');
    ringbuffer.store_char('B');
    THEN("'read_char' should return first inserted element first (FIFO)")
    {
      REQUIRE(ringbuffer.read_char() == 'A');
      REQUIRE(ringbuffer.read_char() == 'B');
    }
  }
}
