//
// Created by sneki on 18.04.24.
//

#ifndef INVALIDITERATOREXCEPTION_H
#define INVALIDITERATOREXCEPTION_H

#include "BaseException.h"

class OperationInvalidParams : public BaseException {
public:
    OperationInvalidParams(const char * filename,
                         int string_number,
                         const char * error_message = "Operation Invalid Params") noexcept:
            BaseException(filename, string_number, error_message)
    {
    }
};

#endif //OOP_LAB_2_INVALIDITERATOREXCEPTION_H
