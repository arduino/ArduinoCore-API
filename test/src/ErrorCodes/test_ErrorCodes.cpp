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

TEST_CASE ("An ErrorCode can be evaluated as boolean and respect Arduino values", "[ErrorCodes-Evaluation]") {
  REQUIRE((bool)ErrorCode(1) == true);
  REQUIRE((bool)ErrorCode(0) == false);
}

TEST_CASE ("An error is returned with a value different from 0 and 1", "[ErrorCodes-Evaluation]") {
  THEN ("if the error is well defined the boolean evaluation of the error code respects Arduino standard") {
    arduino::error_t err = 125;
    ErrorCode ec(err);
    REQUIRE((bool)ec == false);
    REQUIRE(ec.error == err);
  }
  THEN ("if an int is provided the boolean evaluation of the error code respects Arduino standard and error is evaluated to ArduinoSuccess") {
    int err = 1;
    ErrorCode ec(err);
    REQUIRE((bool)ec == true);
    REQUIRE(ec.error == ArduinoSuccess);
  }
  THEN ("if an int is provided the boolean evaluation of the error code respects Arduino standard and error is evaluated to ArduinoError") {
    int err = 0;
    ErrorCode ec(err);
    REQUIRE((bool)ec == false);
    REQUIRE(ec.error == ArduinoError);
  }
  THEN ("if an int is provided the boolean evaluation of the error code respects Arduino standard and the value is not preserved") {
    int err = 125;
    ErrorCode ec(err);
    REQUIRE((bool)ec == false);
    REQUIRE(ec.error == ArduinoError);
  }
  THEN ("if an int is provided the boolean evaluation of the error code respects Arduino standard and the value is not preserved") {
    ErrorCode ec(ArduinoELOOP);
    REQUIRE((bool)ec == false);
    REQUIRE(ec.error == ArduinoELOOP);
  }
}

