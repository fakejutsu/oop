#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H
#include <exception>
#include <string.h>
#include <stdio.h>

class BaseException : std::exception
{
protected:
    static const int messageLen = 1000;
    char message[messageLen + 1] = {0};
public:
    BaseException(const char *filename,
    int string_number,
    const char *error_message = "Undefined error") noexcept
    {
        snprintf(message, messageLen, "Filename: %s\nAt row: %d\nError: %s", filename, string_number, error_message);
    }

    virtual const char* what() const noexcept override
    {
        return message;
    }

    virtual ~BaseException() = default;
};

#endif