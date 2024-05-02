//
// Created by sneki on 18.04.24.
//

#ifndef MEMORYALLOCEXCEPTION_H
#define MEMORYALLOCEXCEPTION_H

#include "BaseException.h"

class MemoryAllocException : public BaseException {
public:
    MemoryAllocException(const char * filename,
                         int string_number,
                         const char * error_message = "Memory allocation error") noexcept:
                                BaseException(filename, string_number, error_message)
    {
    }
};


#endif //OOP_LAB_2_MEMORYALLOCEXCEPTION_H
