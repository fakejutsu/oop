//
// Created by sneki on 18.04.24.
//

#ifndef ZERODIV_H
#define ZERODIV_H

#include "BaseException.h"

class ZeroDivException : public BaseException {
public:
    ZeroDivException(const char* filename,
        int string_number,
        const char* error_message = "Zero Div Exception") noexcept :
        BaseException(filename, string_number, error_message)
    {
    }
};

#endif //ZERODIV_H
