/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <api/String.h>

#include "StringPrinter.h"

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Testing String::length when string is empty", "[String-length-01]")
{
  arduino::String str;
  REQUIRE(str.length() == 0);
}

TEST_CASE ("Testing String::length when string contains characters", "[String-length-02]")
{
  arduino::String str("Testing String::length");
  REQUIRE(str.length() == strlen("Testing String::length"));
}
