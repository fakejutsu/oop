//
// Created by sneki on 18.04.24.
//

#ifndef EMPTYVECTOREXCEPTION_H
#define EMPTYVECTOREXCEPTION_H

#include "BaseException.h"

class EmptyVectorException : public BaseException {
public:
    EmptyVectorException(const char * filename,
                         int string_number,
                         const char * error_message = "Operation Vector is empty!") noexcept:
            BaseException(filename, string_number, error_message)
    {
    }
};


#endif
