//
// Created by sneki on 24.04.24.
//

#ifndef RANGEERROR_H
#define RANGEERROR_H

#include "BaseException.h"

class RangeError : public BaseException {
public:
    RangeError(const char * filename,
                           int string_number,
                           const char * error_message = "Range Error") noexcept:
            BaseException(filename, string_number, error_message)
    {
    }
};


#endif //RANGEERROR_H
