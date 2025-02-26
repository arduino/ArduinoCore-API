/*
  binary.cpp - Definitions for binary constants
  Copyright (c) 2025 jsnkan. All right reserved.

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

#include "Binary.h"

void intToBinaryArray(unsigned char n, int *arr) {
  if (arr == 0) return;
  for (int i = 7; i >= 0; i--) {
      arr[i] = n & 1;
      n >>= 1;
  }
}

unsigned char binaryArrayToInt(int *arr) {
  if (arr == 0) return 0;
  unsigned char n = 0;
  for (int i = 0; i < 8; i++) {
      n = (n << 1) | (arr[i] & 1);
  }
  return n;
}