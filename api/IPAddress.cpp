/*
  IPAddress.cpp - Base class that provides IPAddress
  Copyright (c) 2011 Adrian McEwen.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "IPAddress.h"
#include "Print.h"
#include <cstdint>
#include <new>

using namespace arduino;

IPAddress::IPAddress() = default;

IPAddress::IPAddress(IPType ip_type) : _type(ip_type) {}

IPAddress::IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet)
{
    _address[IPADDRESS_V4_BYTES_INDEX] = first_octet;
    _address[IPADDRESS_V4_BYTES_INDEX + 1] = second_octet;
    _address[IPADDRESS_V4_BYTES_INDEX + 2] = third_octet;
    _address[IPADDRESS_V4_BYTES_INDEX + 3] = fourth_octet;
}

IPAddress::IPAddress(uint8_t o1, uint8_t o2, uint8_t o3, uint8_t o4, uint8_t o5, uint8_t o6, uint8_t o7, uint8_t o8, uint8_t o9, uint8_t o10, uint8_t o11, uint8_t o12, uint8_t o13, uint8_t o14, uint8_t o15, uint8_t o16) : _address{o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16}, _type(IPv6) {}

// IPv4 only
IPAddress::IPAddress(uint32_t address) 
{
    // memcpy(raw_address(), &address, 4); // This method guarantees a defined behavior. 
                                           // But lifetime started when:
                                           // [basic.life#2] https://eel.is/c++draft/basic.life#2
                                           //(2.1) -- storage with the proper alignment and size for type T is obtained, and
                                           //(2.2) -- its initialization (if any) is complete (including vacuous initialization) ([dcl.init]),
                                           //
                                           // The statement: {#Any pointer conversions to write to ADDRESS storage (as a multibyte integer) 
                                           // are undefined behavior when the lifetime of the multibyte type has not previously started.#} 
                                           // only apply to c++17 and earlier. Since C++20 array of bytes implicitly creates the inner objects.

// C++20: https://timsong-cpp.github.io/cppwp/n4861/intro.object#13
// 13 An operation that begins the lifetime of an array of char, unsigned char, or std::byte implicitly creates objects within 
// the region of storage occupied by the array. [ Note: The array object provides storage for these objects. — end note ]

// C++23: https://timsong-cpp.github.io/cppwp/n4950/intro.object#13
// 13 An operation that begins the lifetime of an array of unsigned char or std::byte implicitly creates objects within the 
// region of storage occupied by the array.
// [Note 5: The array object provides storage for these objects. — end note]

// Current draft: https://eel.is/c++draft/intro.object#14
// 14 Except during constant evaluation, an operation that begins the lifetime of an array of unsigned char or std::byte implicitly 
// creates objects within the region of storage occupied by the array.
// [Note 5: The array object provides storage for these objects. — end note]

// *reinterpret_cast<uint32_t*>(_address[IPADDRESS_V4_BYTES_INDEX]) = address; // This valid initialization in the `_address` storage since C++20.
                                                                            // now the pointer `_address[IPADDRESS_V4_BYTES_INDEX]` points to a multibyte int.

    new (&_address[IPADDRESS_V4_BYTES_INDEX]) uint32_t (address); // But the new-expression is better for understanding and looks nicer (for trivial types, the 
                                                                  // new expression only begins its lifetime and does not perform any other actions).
    // NOTE: https://en.cppreference.com/w/cpp/language/new#Notes

    // NOTE: new-expression and reinterpret_cast require alignment of the storage, but memcpy does not.

// C++ standard draft [basic.life#7](https://eel.is/c++draft/basic.life#7)
// Before the lifetime of an object has started but after the storage which the object 
// will occupy has been allocated or, after the lifetime of an object has ended and 
// before the storage which the object occupied is reused or released, any pointer that 
// represents the address of the storage location where the object will be or was 
// located may be used but only in limited ways. For an object under construction or 
// destruction, see [class.cdtor]. Otherwise, such a pointer refers to allocated storage 
// ([basic.stc.dynamic.allocation]), and using the pointer as if the pointer were of 
// type void* is well-defined. Indirection through such a pointer is permitted but the 
// resulting lvalue may only be used in limited ways, as described below. 
// The program has undefined behavior if
//  --the pointer is used as the operand of a delete-expression,
//  --the pointer is used as the operand of a static_cast ([expr.static.cast]), except 
//  when the conversion is to pointer to cv void, or to pointer to cv void and subsequently 
//  to pointer to cv char, cv unsigned char, or cv std::byte ([cstddef.syn]), or

// C++ standard draft [basic.life#8](https://eel.is/c++draft/basic.life#8)
// Similarly, before the lifetime of an object has started but after the storage which 
// the object will occupy has been allocated or, after the lifetime of an object has 
// ended and before the storage which the object occupied is reused or released, any 
// glvalue that refers to the original object may be used but only in limited ways. 
// For an object under construction or destruction, see [class.cdtor]. Otherwise, such 
// a glvalue refers to allocated storage ([basic.stc.dynamic.allocation]), and using 
// the properties of the glvalue that do not depend on its value is well-defined. 
// The program has undefined behavior if
//  -- the glvalue is used to access the object, or

    // NOTE on conversion/comparison and uint32_t:
    // These conversions are host platform dependent.
    // There is a defined integer representation of IPv4 addresses,
    // based on network byte order (will be the value on big endian systems),
    // e.g. http://2398766798 is the same as http://142.250.70.206,
    // However on little endian systems the octets 0x83, 0xFA, 0x46, 0xCE,
    // in that order, will form the integer (uint32_t) 3460758158 .
}

IPAddress::IPAddress(const uint8_t *address) : IPAddress(IPv4, address) {}

IPAddress::IPAddress(IPType ip_type, const uint8_t *address) : _type(ip_type)
{
    const size_t copy_size = (ip_type == IPv4) ? sizeof(uint32_t) : sizeof(_address);
    memcpy(raw_address(), address, copy_size);
}

IPAddress::IPAddress(const char *address)
{
    fromString(address);
}

String IPAddress::toString4() const
{
    char szRet[16];
    snprintf(szRet, sizeof(szRet), "%u.%u.%u.%u", _address[IPADDRESS_V4_BYTES_INDEX], _address[IPADDRESS_V4_BYTES_INDEX + 1], _address[IPADDRESS_V4_BYTES_INDEX + 2], _address[IPADDRESS_V4_BYTES_INDEX + 3]);
    return String(szRet);
}

String IPAddress::toString6() const
{
    char szRet[40];
    snprintf(szRet, sizeof(szRet), "%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x",
            _address[0], _address[1], _address[2], _address[3],
            _address[4], _address[5], _address[6], _address[7],
            _address[8], _address[9], _address[10], _address[11],
            _address[12], _address[13], _address[14], _address[15]);
    return String(szRet);
}

String IPAddress::toString() const
{
    if (_type == IPv4) {
        return toString4();
    } else {
        return toString6();
    }
}

bool IPAddress::fromString(const char *address) {
    if (!fromString4(address)) {
        return fromString6(address);
    }
    return true;
}

bool IPAddress::fromString4(const char *address)
{
    // TODO: add support for "a", "a.b", "a.b.c" formats

    int16_t acc = -1; // Accumulator
    uint8_t dots = 0;

    memset(_address, 0, sizeof(_address));
    while (*address)
    {
        char c = *address++;
        if (c >= '0' && c <= '9')
        {
            acc = (acc < 0) ? (c - '0') : acc * 10 + (c - '0');
            if (acc > 255) {
                // Value out of [0..255] range
                return false;
            }
        }
        else if (c == '.')
        {
            if (dots == 3) {
                // Too many dots (there must be 3 dots)
                return false;
            }
            if (acc < 0) {
                /* No value between dots, e.g. '1..' */
                return false;
            }
            _address[IPADDRESS_V4_BYTES_INDEX + dots++] = acc;
            acc = -1;
        }
        else
        {
            // Invalid char
            return false;
        }
    }

    if (dots != 3) {
        // Too few dots (there must be 3 dots)
        return false;
    }
    if (acc < 0) {
        /* No value between dots, e.g. '1..' */
        return false;
    }
    _address[IPADDRESS_V4_BYTES_INDEX + 3] = acc;
    _type = IPv4;
    return true;
}

bool IPAddress::fromString6(const char *address) {
    uint32_t acc = 0; // Accumulator
    int colons = 0, double_colons = -1;

    while (*address)
    {
        char c = tolower(*address++);
        if (isalnum(c) && c <= 'f') {
            if (c >= 'a')
                c -= 'a' - '0' - 10;
            acc = acc * 16 + (c - '0');
            if (acc > 0xffff)
                // Value out of range
                return false;
        }
        else if (c == ':') {
            if (*address == ':') {
                if (double_colons >= 0) {
                    // :: allowed once
                    return false;
                }
                if (*address != '\0' && *(address + 1) == ':') {
                    // ::: not allowed
                    return false;
                }
                // remember location
                double_colons = colons + !!acc;
                address++;
            } else if (*address == '\0') {
                // can't end with a single colon
                return false;
            }
            if (colons == 7)
                // too many separators
                return false;
            _address[colons * 2] = acc >> 8;
            _address[colons * 2 + 1] = acc & 0xff;
            colons++;
            acc = 0;
        }
        else
            // Invalid char
            return false;
    }

    if (double_colons == -1 && colons != 7) {
        // Too few separators
        return false;
    }
    if (double_colons > -1 && colons > 6) {
        // Too many segments (double colon must be at least one zero field)
        return false;
    }
    _address[colons * 2] = acc >> 8;
    _address[colons * 2 + 1] = acc & 0xff;
    colons++;

    if (double_colons != -1) {
        for (int i = colons * 2 - double_colons * 2 - 1; i >= 0; i--)
            _address[16 - colons * 2 + double_colons * 2 + i] = _address[double_colons * 2 + i];
        for (int i = double_colons * 2; i < 16 - colons * 2 + double_colons * 2; i++)
            _address[i] = 0;
    }

    _type = IPv6;
    return true;
}

IPAddress& IPAddress::operator=(const uint8_t *address)
{
    // IPv4 only conversion from byte pointer
    _type = IPv4;

    memset(_address, 0, sizeof(_address));
    memcpy(raw_address(), address, sizeof(uint32_t));

    return *this;
}

IPAddress& IPAddress::operator=(const char *address)
{
    fromString(address);
    return *this;
}

IPAddress& IPAddress::operator=(uint32_t address)
{
    // IPv4 conversion
    // See note on conversion/comparison and uint32_t
    _type = IPv4;
    memset(_address, 0, sizeof(_address));
    new (raw_address()) uint32_t (address); // See the comments in corresponding constructor.
    return *this;
}

bool IPAddress::operator==(const IPAddress& addr) const {
    return (addr._type == _type)
        && (memcmp(addr._address, _address, sizeof(_address)) == 0);
}

bool IPAddress::operator==(const uint8_t* addr) const
{
    // IPv4 only comparison to byte pointer
    // Can't support IPv6 as we know our type, but not the length of the pointer
    return _type == IPv4 && memcmp(addr, raw_address(), sizeof(uint32_t)) == 0;
}

uint8_t IPAddress::operator[](int index) const {
    return *(raw_address() + index);
}

uint8_t& IPAddress::operator[](int index) {
    return *(raw_address() + index);
}

size_t IPAddress::printTo(Print& p) const
{
    size_t n = 0;

    if (_type == IPv6) {
        // IPv6 IETF canonical format: compress left-most longest run of two or more zero fields, lower case
        int8_t longest_start = -1;
        int8_t longest_length = 1;
        int8_t current_start = -1;
        int8_t current_length = 0;
        for (int8_t f = 0; f < 8; f++) {
            if (_address[f * 2] == 0 && _address[f * 2 + 1] == 0) {
                if (current_start == -1) {
                    current_start = f;
                    current_length = 1;
                } else {
                    current_length++;
                }
                if (current_length > longest_length) {
                    longest_start = current_start;
                    longest_length = current_length;
                }
            } else {
                current_start = -1;
            }
        }
        for (int f = 0; f < 8; f++) {
            if (f < longest_start || f >= longest_start + longest_length) {
                uint8_t c1 = _address[f * 2] >> 4;
                uint8_t c2 = _address[f * 2] & 0xf;
                uint8_t c3 = _address[f * 2 + 1] >> 4;
                uint8_t c4 = _address[f * 2 + 1] & 0xf;
                if (c1 > 0) {
                    n += p.print((char)(c1 < 10 ? '0' + c1 : 'a' + c1 - 10));
                }
                if (c1 > 0 || c2 > 0) {
                    n += p.print((char)(c2 < 10 ? '0' + c2 : 'a' + c2 - 10));
                }
                if (c1 > 0 || c2 > 0 || c3 > 0) {
                    n += p.print((char)(c3 < 10 ? '0' + c3 : 'a' + c3 - 10));
                }
                n += p.print((char)(c4 < 10 ? '0' + c4 : 'a' + c4 - 10));
                if (f < 7) {
                    n += p.print(':');
                }
            } else if (f == longest_start) {
                if (longest_start == 0) {
                    n += p.print(':');
                }
                n += p.print(':');
            }
        }
        return n;
    }

    // IPv4
    for (int i =0; i < 3; i++)
    {
        n += p.print(_address[IPADDRESS_V4_BYTES_INDEX + i], DEC);
        n += p.print('.');
    }
    n += p.print(_address[IPADDRESS_V4_BYTES_INDEX + 3], DEC);
    return n;
}

const IPAddress arduino::IN6ADDR_ANY(IPv6);
const IPAddress arduino::INADDR_NONE(0,0,0,0);
