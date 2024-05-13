/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <api/IPAddress.h>
#include <PrintMock.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Print IPAddress via print method", "[IPAddress-printTo-01]")
{
  PrintMock mock;
  arduino::IPAddress const ip(192,168,1,2);

  mock.print(ip);

  REQUIRE(mock._str  == "192.168.1.2");
}
