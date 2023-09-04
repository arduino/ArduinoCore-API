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

TEST_CASE ("\"isExtendedId\" should return true for extended CAN ID", "[CanMsg-isExtendedId-01]")
{
  CanMsg const msg_ext_id(CanExtendedId(0x020), 0, nullptr);
  REQUIRE(msg_ext_id.isExtendedId() == true);
}

TEST_CASE ("\"isExtendedId\" should return false for standard CAN ID", "[CanMsg-isExtendedId-02]")
{
  CanMsg const msg_std_id(CanStandardId(0x020), 0, nullptr);
  REQUIRE(msg_std_id.isExtendedId() == false);
}
