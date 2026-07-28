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

TEST_CASE ("Testing String::equals(const String &) with exit status PASS", "[String-equals-01]")
{
  arduino::String str1("Hello"), str2("Hello");
  REQUIRE(str1.equals(str2) == 1);
}

TEST_CASE ("Testing String::operator==(const String &) with exit status PASS", "[String-equals-01]")
{
  arduino::String str1("Hello"), str2("Hello");
  REQUIRE(str1 == str2);
}

TEST_CASE ("Testing String::operator!=(const String &) with exit status FAIL", "[String-equals-01]")
{
  arduino::String str1("Hello"), str2("Hello");
  REQUIRE_FALSE(str1 != str2);
}

TEST_CASE ("Testing String::equals(const String &) with exit status FAIL", "[String-equals-02]")
{
  arduino::String str1("Hello"), str2("World");
  REQUIRE(str1.equals(str2) == 0);
}

TEST_CASE ("Testing String::operator==(const String &) with exit status FAIL", "[String-equals-02]")
{
  arduino::String str1("Hello"), str2("World");
  REQUIRE_FALSE(str1 == str2);
}

TEST_CASE ("Testing String::operator !=(const String &) with exit status PASS", "[String-equals-02]")
{
  arduino::String str1("Hello"), str2("World");
  REQUIRE(str1 != str2);
}

TEST_CASE ("Testing String::equals(const char *) with exit status PASS", "[String-equals-03]")
{
  arduino::String str1("Hello");
  REQUIRE(str1.equals("Hello") == 1);
}

TEST_CASE ("Testing String::operator ==(const char *) with exit status PASS", "[String-equals-03]")
{
  arduino::String str1("Hello");
  REQUIRE(str1 == "Hello");
}

TEST_CASE ("Testing String::operator !=(const char *) with exit status FAIL", "[String-equals-03]")
{
  arduino::String str1("Hello");
  REQUIRE_FALSE(str1 != "Hello");
}

TEST_CASE ("Testing String::equals(const char *) with exit status FAIL", "[String-equals-04]")
{
  arduino::String str1("Hello");
  REQUIRE(str1.equals("World") == 0);
}

TEST_CASE ("Testing String::operator ==(const char *) with exit status FAIL", "[String-equals-04]")
{
  arduino::String str1("Hello");
  REQUIRE_FALSE(str1 == "World");
}

TEST_CASE ("Testing String::operator !=(const char *) with exit status PASS", "[String-equals-04]")
{
  arduino::String str1("Hello");
  REQUIRE(str1 != "World");
}

TEST_CASE ("Testing String::equalsIgnoreCase(const String &) PASS with NON-empty string", "[String-equalsIgnoreCase-05]")
{
  arduino::String str1("Hello"), str2("Hello");
  REQUIRE(str1.equalsIgnoreCase(str2) == 1);
}

TEST_CASE ("Testing String::equalsIgnoreCase(const String &) FAIL with NON-empty string", "[String-equalsIgnoreCase-06]")
{
  arduino::String str1("Hello"), str2("Hel");
  REQUIRE(str1.equalsIgnoreCase(str2) == 0);
}

TEST_CASE ("Testing String::equalsIgnoreCase(const String &) FAIL with different strings", "[String-equalsIgnoreCase-07]")
{
  arduino::String str1("Hello"), str2("World");
  REQUIRE(str1.equalsIgnoreCase(str2) == 0);
}

TEST_CASE ("Testing String::equalsIgnoreCase(const String &) PASS with same string", "[String-equalsIgnoreCase-08]")
{
  arduino::String str1("Hello");
  REQUIRE(str1.equalsIgnoreCase(str1) == 1);
}

TEST_CASE ("Testing String::startsWith(const String &)", "[String-startsWith-09]")
{
  WHEN ("str2 is larger than str1")
  {
    arduino::String str1("Hello");
    arduino::String str2("Hello World");
    REQUIRE(str1.startsWith(str2) == 0);
  }
  WHEN ("str1 starts with str2")
  {
    arduino::String str1("Hello World");
    arduino::String str2("Hello");
    REQUIRE(str1.startsWith(str2) == 1);
  }
  WHEN ("str1 does NOT start with str2")
  {
    arduino::String str1("Hello World");
    arduino::String str2("Helo");
    REQUIRE(str1.startsWith(str2) == 0);
  }
}

TEST_CASE ("Testing String::endsWith(const String &)", "[String-endsWith-10]")
{
  WHEN ("str2 is larger than str1")
  {
    arduino::String str1("Hello");
    arduino::String str2("Hello World");
    REQUIRE(str1.endsWith(str2) == 0);
  }
  WHEN ("str1 ends with str2")
  {
    arduino::String str1("Hello World");
    arduino::String str2("World");
    REQUIRE(str1.endsWith(str2) == 1);
  }
  WHEN ("str1 does NOT end with str2")
  {
    arduino::String str1("Hello World");
    arduino::String str2("Helo");
    REQUIRE(str1.endsWith(str2) == 0);
  }
}

TEST_CASE ("Testing String comparisons with embedded NUL bytes", "[String-embedded-nul-11]")
{
  WHEN ("startsWith prefix matches up to an embedded NUL but differs after it")
  {
    char buf1[] = {'A', '\0', 'B', 'C'};
    char buf2[] = {'A', '\0', 'X', 'Y'};
    arduino::String str1(buf1, sizeof(buf1));
    arduino::String str2(buf2, sizeof(buf2));
    REQUIRE(str1.startsWith(str2) == 0);
  }
  WHEN ("startsWith prefix genuinely matches, including the embedded NUL")
  {
    char buf1[] = {'A', '\0', 'B', 'C'};
    char buf2[] = {'A', '\0', 'B'};
    arduino::String str1(buf1, sizeof(buf1));
    arduino::String str2(buf2, sizeof(buf2));
    REQUIRE(str1.startsWith(str2) == 1);
  }
  WHEN ("endsWith suffix matches up to an embedded NUL but differs after it")
  {
    char buf1[] = {'X', 'Y', '\0', 'C'};
    char buf2[] = {'A', 'B', '\0', 'C'};
    arduino::String str1(buf1, sizeof(buf1));
    arduino::String str2(buf2, sizeof(buf2));
    REQUIRE(str1.endsWith(str2) == 0);
  }
  WHEN ("endsWith suffix genuinely matches, including the embedded NUL")
  {
    char buf1[] = {'X', 'Y', '\0', 'C'};
    char buf2[] = {'Y', '\0', 'C'};
    arduino::String str1(buf1, sizeof(buf1));
    arduino::String str2(buf2, sizeof(buf2));
    REQUIRE(str1.endsWith(str2) == 1);
  }
}
