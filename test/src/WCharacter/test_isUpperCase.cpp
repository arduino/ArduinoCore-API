/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <WCharacter.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("isUpperCase(...) is called with a upper case number", "[isUpperCase-01]")
{
  REQUIRE(arduino::isUpperCase('A') == true);
}

TEST_CASE ("isUpperCase(...) is called with a lower case number", "[isUpperCase-02]")
{
  REQUIRE(arduino::isUpperCase('a') == false);
}

TEST_CASE ("isUpperCase(...) is called with a non-alphabetic number", "[isUpperCase-03]")
{
  REQUIRE(arduino::isUpperCase('0') == false);
}
