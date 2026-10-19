/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch2/catch_test_macros.hpp>

#include <climits>
#include <string>

#include <api/String.h>

#include "StringPrinter.h"

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Testing String::toInt when string is empty", "[String-toInt-01]")
{
  arduino::String str;
  int const val = str.toInt();
  REQUIRE(val == 0);
}

TEST_CASE ("Testing String::toInt when string contains no number", "[String-toInt-02]")
{
  arduino::String str("abc");
  int const val = str.toInt();
  REQUIRE(val == 0);
}

TEST_CASE ("Testing String::toInt when string contains a number", "[String-toInt-03]")
{
  arduino::String str("-1");
  int const val = str.toInt();
  REQUIRE(val == -1);
}

TEST_CASE ("Testing String::toInt when string does not have a buffer", "[String-toInt-04]")
{
  char *buffer = NULL;
  arduino::String str(buffer);
  REQUIRE(str.toInt() == 0);
}

TEST_CASE ("Testing String::toInt when string exceeds the long range", "[String-toInt-05]")
{
  unsigned long const minimum_magnitude = static_cast<unsigned long>(-(LONG_MIN + 1L)) + 1UL;
  std::string const one_past_maximum = std::to_string(static_cast<unsigned long>(LONG_MAX) + 1UL);
  std::string const one_past_minimum = "-" + std::to_string(minimum_magnitude + 1UL);
  arduino::String positive_boundary(one_past_maximum.c_str());
  arduino::String negative_boundary(one_past_minimum.c_str());
  arduino::String positive("999999999999999999999999999999999999");
  arduino::String negative("-999999999999999999999999999999999999");

  REQUIRE(positive_boundary.toInt() == 0);
  REQUIRE(negative_boundary.toInt() == 0);
  REQUIRE(positive.toInt() == 0);
  REQUIRE(negative.toInt() == 0);
}

TEST_CASE ("Testing String::toInt at the long range limits", "[String-toInt-06]")
{
  arduino::String maximum(std::to_string(LONG_MAX).c_str());
  arduino::String minimum(std::to_string(LONG_MIN).c_str());

  REQUIRE(maximum.toInt() == LONG_MAX);
  REQUIRE(minimum.toInt() == LONG_MIN);
}

TEST_CASE ("Testing String::toInt keeps atol parsing behavior", "[String-toInt-07]")
{
  arduino::String negative(" \t-123abc");
  arduino::String positive("+456xyz");

  REQUIRE(negative.toInt() == -123);
  REQUIRE(positive.toInt() == 456);
}
