/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <catch2/catch_test_macros.hpp>
#include <api/IPAddress.h>
#include <TCPClientMock.h>

/*
 * The purpose of these tests is to highlight potential memory leaking
 * issues that may arise from the lack of virtual destructors.
 * These test cases will never fail under unit testing,
 * but they should trigger valgrind error reporting
 */

TEST_CASE("Testing polymorphic IPAddress memory free", "[ipaddress-delete-01]")
{
    arduino::Printable* p = new IPAddress();

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
    delete p;
#pragma GCC diagnostic pop
}

TEST_CASE("Testing polymorphic client memory free", "[client-delete-01]")
{
    arduino::Client* p = new TCPClientMock;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
    delete p;
#pragma GCC diagnostic pop
}
