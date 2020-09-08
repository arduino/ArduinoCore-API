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

TEST_CASE ("isLowerCase(...) is called with a upper case number", "[isLowerCase-01]")
{
  REQUIRE(arduino::isLowerCase('A') == false);
}

TEST_CASE ("isLowerCase(...) is called with a lower case number", "[isLowerCase-02]")
{
  REQUIRE(arduino::isLowerCase('a') == true);
}

TEST_CASE ("isLowerCase(...) is called with a non-alphabetic number", "[isLowerCase-03]")
{
  REQUIRE(arduino::isLowerCase('0') == false);
}
