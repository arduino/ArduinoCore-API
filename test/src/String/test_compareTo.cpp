/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch2/catch_test_macros.hpp>

#include <api/String.h>

#include "StringPrinter.h"

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Testing String::compareTo(const String &)", "[String-compareTo-01]")
{
  WHEN ("Strings are equal")
  {
    arduino::String str1("Hello"), str2("Hello");
    REQUIRE(str1.compareTo(str2) == 0);
  }

  WHEN ("str2 is empty")
  {
    arduino::String str1("Hello"), str2;
    REQUIRE(str1.compareTo(str2) > 0);
  }

  WHEN ("str1 is empty")
  {
    arduino::String str1, str2("Hello");
    REQUIRE(str1.compareTo(str2) < 0);
  }

  WHEN ("Strings are the same length but differ only after an embedded NUL byte")
  {
    char buf1[] = {'A', '\0', 'B'};
    char buf2[] = {'A', '\0', 'C'};
    arduino::String str1(buf1, sizeof(buf1));
    arduino::String str2(buf2, sizeof(buf2));
    REQUIRE(str1.compareTo(str2) != 0);
  }

  WHEN ("Strings are equal and both contain an embedded NUL byte")
  {
    char buf1[] = {'A', '\0', 'B'};
    char buf2[] = {'A', '\0', 'B'};
    arduino::String str1(buf1, sizeof(buf1));
    arduino::String str2(buf2, sizeof(buf2));
    REQUIRE(str1.compareTo(str2) == 0);
    REQUIRE(str1 == str2);
  }
}

TEST_CASE ("Testing String::compareTo(const char *)", "[String-compareTo-02]")
{
  WHEN ("Strings are equal")
  {
    arduino::String str("Hello");
    REQUIRE(str.compareTo("Hello") == 0);
  }

  WHEN ("Passed string is empty")
  {
    arduino::String str("Hello");
    REQUIRE(str.compareTo("") > 0);
  }

  WHEN ("Passed string is compared with empty string")
  {
    arduino::String str;
    REQUIRE(str.compareTo("") == 0);
  }
}

TEST_CASE ("Testing String::compareTo(const char *) with empty buffer", "[String-compareTo-03]")
{
  WHEN ("First string has a valid buffer")
  {
    char *buffer = NULL;

    arduino::String str("Hello");
    REQUIRE(str.compareTo(buffer) != 0);
  }

  WHEN ("First string does NOT have a valid buffer")
  {
    char *buffer1 = NULL;
    char *buffer2 = NULL;

    arduino::String str(buffer1);
    REQUIRE(str.compareTo(buffer2) == 0);
  }
}


TEST_CASE ("Testing String::compareTo(const String &) with empty buffer", "[String-compareTo-04]")
{
  WHEN ("First string has a valid buffer")
  {
    char *buffer = NULL;

    arduino::String str1("Hello");
    arduino::String str2(buffer);
    REQUIRE(str1.compareTo(str2) != 0);
  }

  WHEN ("First string does NOT have a valid buffer")
  {
    char *buffer1 = NULL;
    char *buffer2 = NULL;

    arduino::String str1(buffer1);
    arduino::String str2(buffer2);
    REQUIRE(str1.compareTo(str2) == 0);
  }
}
