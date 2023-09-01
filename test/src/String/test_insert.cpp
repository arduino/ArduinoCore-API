/*
 * Copyright (c) 2023 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <String.h>

#include "StringPrinter.h"

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Testing String::insert(char, index)", "[String-insert-01]")
{
  arduino::String str = "ello";
  str.insert('h', 0);
  REQUIRE(str == String("hello"));
}

TEST_CASE ("Testing String::insert(char, index) with index > length", "[String-insert-02]")
{
  arduino::String str = "Hello Arduino";
  str.insert('!', str.length() + 1);
  REQUIRE(str == String("Hello Arduino"));
}


TEST_CASE ("Testing String::insert(String, index, length) with length >= inserted length", "[String-insert-03]")
{
    arduino::String str = "hello ";
    str.insert("world", str.length(), 5);
    REQUIRE(str == String("hello world"));
}

TEST_CASE ("Testing String::insert(String, index, length) with length < inserted length", "[String-insert-04]")
{
    arduino::String str = "Hello ";
    str.insert("Arduino 1234", str.length(), 7);
    REQUIRE(str == String("Hello Arduino"));
}

