/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <IPAddress.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Testing IPAddress::operator = (const uint8_t * a)", "[IPAddress-Operator-=-01]")
{
  arduino::IPAddress ip1;
  uint8_t const ip2[] = {192,168,1,2};

  ip1 = ip2;
  REQUIRE(ip1 == arduino::IPAddress(192,168,1,2));
}

TEST_CASE ("Testing IPAddress::operator = (uint32_t a)", "[IPAddress-Operator-=-02]")
{
  arduino::IPAddress ip1;
  uint32_t const ip2 = 192 | (168 << 8) | (1 << 16) | (2 << 24);

  ip1 = ip2;
  REQUIRE(ip1 == arduino::IPAddress(192,168,1,2));
}
