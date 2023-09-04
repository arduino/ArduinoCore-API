/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <CanMsg.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace arduino;

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("\"isStandardId\" should return true for standard CAN ID", "[CanMsg-isStandardId-01]")
{
  CanMsg const msg_std_id(CanStandardId(0x020), 0, nullptr);
  REQUIRE(msg_std_id.isStandardId() == true);
}

TEST_CASE ("\"isStandardId\" should return false for extended CAN ID", "[CanMsg-isStandardId-02]")
{
  CanMsg const msg_ext_id(CanExtendedId(0x020), 0, nullptr);
  REQUIRE(msg_ext_id.isStandardId() == false);
}
