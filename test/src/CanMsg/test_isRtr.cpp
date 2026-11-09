/*
 * Copyright (c) 2026 Arduino.  All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch2/catch_test_macros.hpp>

#include <api/CanMsg.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace arduino;

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("\"isRtr\" should return true for standard RTR CAN ID", "[CanMsg-isRtr-01]")
{
  CanMsg const msg_std_rtr(CanStandardRtrId(0x020), 0, nullptr);
  REQUIRE(msg_std_rtr.isRtr() == true);
  REQUIRE(msg_std_rtr.isRemote() == true);
  REQUIRE(msg_std_rtr.isStandardId() == true);
  REQUIRE(msg_std_rtr.isExtendedId() == false);
}

TEST_CASE ("\"isRtr\" should return true for extended RTR CAN ID", "[CanMsg-isRtr-02]")
{
  CanMsg const msg_ext_rtr(CanExtendedRtrId(0x020), 0, nullptr);
  REQUIRE(msg_ext_rtr.isRtr() == true);
  REQUIRE(msg_ext_rtr.isRemote() == true);
  REQUIRE(msg_ext_rtr.isStandardId() == false);
  REQUIRE(msg_ext_rtr.isExtendedId() == true);
}

TEST_CASE ("\"isRtr\" should return true when created with rtr constructor flag", "[CanMsg-isRtr-03]")
{
  CanMsg const msg_std_rtr_flag(CanStandardId(0x020), 0, nullptr, true);
  REQUIRE(msg_std_rtr_flag.isRtr() == true);
  REQUIRE(msg_std_rtr_flag.isRemote() == true);
}

TEST_CASE ("\"isRtr\" should return false for normal data frames", "[CanMsg-isRtr-04]")
{
  CanMsg const msg_std(CanStandardId(0x020), 0, nullptr);
  REQUIRE(msg_std.isRtr() == false);
  REQUIRE(msg_std.isRemote() == false);

  CanMsg const msg_ext(CanExtendedId(0x020), 0, nullptr);
  REQUIRE(msg_ext.isRtr() == false);
  REQUIRE(msg_ext.isRemote() == false);
}
