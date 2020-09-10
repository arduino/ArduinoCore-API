/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <Print.h>

#include <PrintMock.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Print::print(char)", "[Print-print-01]")
{
  PrintMock mock;

  mock.print('A');
  REQUIRE(mock._str == "A");
}

TEST_CASE ("Print::print(int, int = DEC|HEX|OCT|BIN)", "[Print-print-02]")
{
  PrintMock mock;

  int const val = -1;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "-1"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "FFFFFFFFFFFFFFFF"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "1777777777777777777777"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "1111111111111111111111111111111111111111111111111111111111111111"); }
}

TEST_CASE ("Print::print(unsigned int, int = DEC|HEX|OCT|BIN)", "[Print-print-03]")
{
  PrintMock mock;

  unsigned int const val = 17;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "17"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "11"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "21"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "10001"); }
}
