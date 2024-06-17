/*
 * Copyright (c) 2023 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <MillisFake.h>
#include <StreamMock.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Testing 'readLine' with no EOL character", "[Stream-readLine-01]")
{
    StreamMock mock;
    mock.setTimeout(10);
    millis_autoOn();
    mock << "Hello Arduino";
    REQUIRE(mock.readLine() == arduino::String("Hello Arduino"));
}

TEST_CASE ("Testing 'readLine' with Unix EOL character", "[Stream-readLine-02]")
{
    StreamMock mock;
    mock.setTimeout(10);
    millis_autoOn();
    mock << "Hello\nArduino\n";
    REQUIRE(mock.readLine() == arduino::String("Hello"));
}

TEST_CASE ("Testing 'readLine' with DOS EOL character", "[Stream-readLine-03]")
{
    StreamMock mock;
    mock.setTimeout(10);
    millis_autoOn();
    mock << "Hello\r\nArduino\r\n";
    REQUIRE(mock.readLine() == arduino::String("Hello"));
}
