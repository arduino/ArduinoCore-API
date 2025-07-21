/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch2/catch_test_macros.hpp>

#include <api/ErrorCodes.h>

using namespace arduino;

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

int test_int(int i) {
  return i;
}

ReturnValue test(int i) {
  return i;
}

TEST_CASE ("A ReturnValue can be evaluated as boolean", "[ReturnValues-Evaluation]") {
  // Default constructor takes an integer implicitly, if negative it means error
  REQUIRE((bool)ReturnValue(1) == true);
  REQUIRE((bool)ReturnValue(-12) == false);
}

TEST_CASE ("A ReturnValue can be substituted to int in a function return value", "[ReturnValues-Evaluation]") {
  REQUIRE((bool)test(1)     == true);
  REQUIRE((bool)test(-123)  == false);
  REQUIRE(test_int(1)       == (int)test(1));
  REQUIRE(test_int(-123)    == (int)test(-123));
}

TEST_CASE ("A ReturnValue can be instantiated with explicit error code and value", "[ReturnValues-Evaluation]") {
  THEN("It can take a negative value as value and still be successful") {
    auto rv = ReturnValue(-1231, ArduinoSuccess);

    REQUIRE((bool)rv == true);
  }
  THEN("It can take both a value and an error code ") {
    auto rv = ReturnValue(-1231, ArduinoError);

    REQUIRE((bool)rv == false);
    REQUIRE(rv.value == -1231);
    REQUIRE(rv.error == ArduinoError);
  }
}
