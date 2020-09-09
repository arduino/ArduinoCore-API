/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <itoa.h>

#include <stdlib.h>

/**************************************************************************************
 * FUNCTION IMPLEMENTATION
 **************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

char * itoa(int value, char *string, int radix)
{
  return itoa(value, string, radix);
}

char * ltoa(long value, char *string, int radix)
{
  return ltoa(value, string, radix);
}

char * utoa(unsigned value, char *string, int radix)
{
  return utoa(value, string, radix);
}

char * ultoa(unsigned long value, char *string, int radix)
{
  return ultoa(value, string, radix);
}

#ifdef __cplusplus
} // extern "C"
#endif
