/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdio>
#include <cfloat>

/**************************************************************************************
 * FUNCTION IMPLEMENTATION
 **************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/*
 * A fundamental issue with dtostrf is the risk of buffer overflow as the size of the
 * output buffer is not passed in. Previous implementation relied on sprintf which has
 * the same issue and has now been deprecated, leading to compilation warnings that are
 * considered fatal. Here, we use snprintf to avoid those warnings, with a limit
 * set large enough for the longest buffer used by the String class. The risk
 * of buffer overflow remains when a smaller buffer is passed in.
 *
 * TODO Refactor String not to rely on this function.
 */
char *dtostrf (double val, signed char width, unsigned char prec, char *sout) {

    // From String.h - DOUBLE_BUF_SIZE is the largest it could use
    static size_t const FLT_MAX_DECIMAL_PLACES = 10;
    static size_t const DBL_MAX_DECIMAL_PLACES = FLT_MAX_DECIMAL_PLACES;
    static size_t const DOUBLE_BUF_SIZE = DBL_MAX_10_EXP + DBL_MAX_DECIMAL_PLACES + 1 /* '-' */ + 1 /* '.' */ + 1 /* '\0' */;

    char fmt[20];
    snprintf(fmt, sizeof(fmt), "%%%d.%df", width, prec);
    snprintf(sout, DOUBLE_BUF_SIZE, fmt, val);
    return sout;
}

#ifdef __cplusplus
} // extern "C"
#endif
