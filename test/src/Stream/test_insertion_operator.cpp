/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <StreamMock.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Testing 'Format' initialisation", "[Stream-insertion-operator-01]") {
  arduino::Format<char> fmt {'a', 2};
  REQUIRE(fmt.data == 'a');
  REQUIRE(fmt.modifier == 2);
}

TEST_CASE ("Testing 'format' helper function", "[Stream-insertion-operator-02]") {
  arduino::Format<char> fmt {arduino::format('a', 2)};
  REQUIRE(fmt.data == 'a');
  REQUIRE(fmt.modifier == 2);
}

TEST_CASE ("Testing basic insertion operator", "[Stream-insertion-operator-03]") {
  StreamMock mock;
  mock << 'a' << 12 << 'b' << 34;  // Note we cannot test C strings because `StreamMock` has its own << operator.
  REQUIRE(mock.available() == 6);

  char buf[10] {};
  mock.readBytes(buf, 6);
  REQUIRE(not strncmp(buf, "a12b34", 6));
}

TEST_CASE ("Testing insertion operator with modifiers", "[Stream-insertion-operator-04]") {
  StreamMock mock;
  mock << arduino::format(1.2, 4);
  REQUIRE(mock.available() == 6);

  char buf[10] {};
  mock.readBytes(buf, 6);
  REQUIRE(not strncmp(buf, "1.2000", 6));

  mock << arduino::format(12, BIN);
  REQUIRE(mock.available() == 4);

  mock.readBytes(buf, 4);
  REQUIRE(not strncmp(buf, "1100", 4));
}
