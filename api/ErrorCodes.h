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

/* ReturnValueClass is meant to represent all the cases where with a single value
 * we want to return an error, if the value is negative, or a meaningful result
 * if greater than or equal to 0.
 * In order to be retrocompatible with the previous definition boolean evaluation:
 * - It must return true, if the value is greater than or equal 0
 * - It must return false, if the value is negatie
 * - It must be evaluable as the primitive type associated with
 */
template<typename T>
class ReturnValueClass {
public:
    constexpr ReturnValueClass(T value)
    : value(value >= 0? value : 0), error(value < 0? (error_t)value : ArduinoSuccess) {}

    // it would be nice to have a default value on error to Success
    constexpr ReturnValueClass(T value, error_t error)
    : value(value), error(error) {}

    const T value; // TODO should we leave the const modifier?
    const error_t error;

    constexpr operator bool() const {
        return error == ArduinoSuccess;
    }

    constexpr operator T() const {
        return error == ArduinoSuccess ? value : error;
    }
};

using ReturnValue       = ReturnValueClass<int>;
using ReturnLongValue   = ReturnValueClass<int64_t>;

}
