//
// Created by sneki on 18.04.24.
//

#ifndef INVALIDITERATOR_H
#define INVALIDITERATOR_H

#include "BaseException.h"

class InvalidIteratorException : public BaseException {
public:
    InvalidIteratorException(const char * filename,
                         int string_number,
                         const char * error_message = "Invalid Iterator Exception") noexcept:
            BaseException(filename, string_number, error_message)
    {
    }
};

#endif //INVALIDITERATOR_H
