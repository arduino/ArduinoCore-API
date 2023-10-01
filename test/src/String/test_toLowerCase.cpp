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

TEST_CASE ("Testing String::toLowerCase", "[String-toLowerCase-01]")
{
  arduino::String str("HELLO ARDUINO");
  str.toLowerCase();
  REQUIRE(str == "hello arduino");
}
