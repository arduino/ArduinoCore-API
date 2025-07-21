#pragma once
#include <stdint.h>

namespace arduino {

typedef int_fast32_t error_t;

enum : error_t {
    ArduinoSuccess  = 0,
    ArduinoError    = -1,

    // TODO better names
    ArduinoEPERM           = -1,                /**< Not owner */
    ArduinoENOENT          = -2,                /**< No such file or directory */
    ArduinoESRCH           = -3,                /**< No such context */
    ArduinoEINTR           = -4,                /**< Interrupted system call */
    ArduinoEIO             = -5,                /**< I/O error */
    ArduinoENXIO           = -6,                /**< No such device or address */
    ArduinoE2BIG           = -7,                /**< Arg list too long */
    ArduinoENOEXEC         = -8,                /**< Exec format error */
    ArduinoEBADF           = -9,                /**< Bad file number */
    ArduinoECHILD          = -10,               /**< No children */
    ArduinoEAGAIN          = -11,               /**< No more contexts */
    ArduinoENOMEM          = -12,               /**< Not enough core */
    ArduinoEACCES          = -13,               /**< Permission denied */
    ArduinoEFAULT          = -14,               /**< Bad address */
    ArduinoENOTBLK         = -15,               /**< Block device required */
    ArduinoEBUSY           = -16,               /**< Mount device busy */
    ArduinoEEXIST          = -17,               /**< File exists */
    ArduinoEXDEV           = -18,               /**< Cross-device link */
    ArduinoENODEV          = -19,               /**< No such device */
    ArduinoENOTDIR         = -20,               /**< Not a directory */
    ArduinoEISDIR          = -21,               /**< Is a directory */
    ArduinoEINVAL          = -22,               /**< Invalid argument */
    ArduinoENFILE          = -23,               /**< File table overflow */
    ArduinoEMFILE          = -24,               /**< Too many open files */
    ArduinoENOTTY          = -25,               /**< Not a typewriter */
    ArduinoETXTBSY         = -26,               /**< Text file busy */
    ArduinoEFBIG           = -27,               /**< File too large */
    ArduinoENOSPC          = -28,               /**< No space left on device */
    ArduinoESPIPE          = -29,               /**< Illegal seek */
    ArduinoEROFS           = -30,               /**< Read-only file system */
    ArduinoEMLINK          = -31,               /**< Too many links */
    ArduinoEPIPE           = -32,               /**< Broken pipe */
    ArduinoENOMSG          = -35,               /**< Unexpected message type */
    ArduinoEDEADLK         = -45,               /**< Resource deadlock avoided */
    ArduinoENOLCK          = -46,               /**< No locks available */
    ArduinoENOSTR          = -60,               /**< STREAMS device required */
    ArduinoENODATA         = -61,               /**< Missing expected message data */
    ArduinoETIME           = -62,               /**< STREAMS timeout occurred */
    ArduinoENOSR           = -63,               /**< Insufficient memory */
    ArduinoEPROTO          = -71,               /**< Generic STREAMS error */
    ArduinoEBADMSG         = -77,               /**< Invalid STREAMS message */
    ArduinoENOSYS          = -88,               /**< Function not implemented */
    ArduinoENOTEMPTY       = -90,               /**< Directory not empty */
    ArduinoENAMETOOLONG    = -91,               /**< File name too long */
    ArduinoELOOP           = -92,               /**< Too many levels of symbolic links */
    ArduinoEOPNOTSUPP      = -95,               /**< Operation not supported on socket */
    ArduinoEPFNOSUPPORT    = -96,               /**< Protocol family not supported */
    ArduinoECONNRESET      = -104,              /**< Connection reset by peer */
    ArduinoENOBUFS         = -105,              /**< No buffer space available */
    ArduinoEAFNOSUPPORT    = -106,              /**< Addr family not supported */
    ArduinoEPROTOTYPE      = -107,              /**< Protocol wrong type for socket */
    ArduinoENOTSOCK        = -108,              /**< Socket operation on non-socket */
    ArduinoENOPROTOOPT     = -109,              /**< Protocol not available */
    ArduinoESHUTDOWN       = -110,              /**< Can't send after socket shutdown */
    ArduinoECONNREFUSED    = -111,              /**< Connection refused */
    ArduinoEADDRINUSE      = -112,              /**< Address already in use */
    ArduinoECONNABORTED    = -113,              /**< Software caused connection abort */
    ArduinoENETUNREACH     = -114,              /**< Network is unreachable */
    ArduinoENETDOWN        = -115,              /**< Network is down */
    ArduinoETIMEDOUT       = -116,              /**< Connection timed out */
    ArduinoEHOSTDOWN       = -117,              /**< Host is down */
    ArduinoEHOSTUNREACH    = -118,              /**< No route to host */
    ArduinoEINPROGRESS     = -119,              /**< Operation now in progress */
    ArduinoEALREADY        = -120,              /**< Operation already in progress */
    ArduinoEDESTADDRREQ    = -121,              /**< Destination address required */
    ArduinoEMSGSIZE        = -122,              /**< Message size */
    ArduinoEPROTONOSUPPORT = -123,              /**< Protocol not supported */
    ArduinoESOCKTNOSUPPORT = -124,              /**< Socket type not supported */
    ArduinoEADDRNOTAVAIL   = -125,              /**< Can't assign requested address */
    ArduinoENETRESET       = -126,              /**< Network dropped connection on reset */
    ArduinoEISCONN         = -127,              /**< Socket is already connected */
    ArduinoENOTCONN        = -128,              /**< Socket is not connected */
    ArduinoETOOMANYREFS    = -129,              /**< Too many references: can't splice */
    ArduinoENOTSUP         = -134,              /**< Unsupported value */
    ArduinoEOVERFLOW       = -139,              /**< Value overflow */
    ArduinoECANCELED       = -140,              /**< Operation canceled */
    ArduinoEWOULDBLOCK     = ArduinoEAGAIN,     /**< Operation would block */
};

/* Error Codes:
 * In Arduino if a function returns 0 is considered to have failed,
 * while any value different from 0 is considered success.
 * Errors are generally represented with an int type that may vary in size depending on the platform.
 * For this reason in this representation error_t type is defined with an integer type with a defined size.
 */
class ErrorCode {
public:
    constexpr ErrorCode(int value): error(value != 0? ArduinoSuccess : ArduinoError) {}
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
