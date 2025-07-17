#pragma once
#include <stdint.h>

namespace arduino {

typedef int_fast32_t error_t;

enum : error_t {
    ArduinoSuccess  = 0,
    ArduinoError    = 1,
};

/* Error Codes:
 * In Arduino if a function returns 1 is considered to have run successfully,
 * any value different from 1 is considered an error.
 * Errors are generally represented with an int type that may vary in size depending on the platform.
 * For this reason in this representation error_t type is defined with an integer type with a defined size.
 */
class ErrorCode {
public:
    constexpr ErrorCode(int value): error(value == 1? ArduinoSuccess : ArduinoError) {}
    constexpr ErrorCode(error_t value): error(value) {}
    const error_t error;

    constexpr operator bool() const {
        return error == ArduinoSuccess;
    }
};


}
