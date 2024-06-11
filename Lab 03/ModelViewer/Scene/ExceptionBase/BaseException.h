//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_BASEEXCEPTION_H
#define MODELVIEWER_BASEEXCEPTION_H

#include <exception>
#include <string>

class BaseException : public std::exception {
public:
    BaseException(std::string message, std::string file = "", int line = -1);

    explicit BaseException(const char * message) : message(message) {};
    explicit BaseException(const std::string & message) : message(message) {};

    virtual ~BaseException() noexcept {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }

    virtual std::string errorMessage() const noexcept {
        return (message + "\nIn file: \n" + file + ":\n" + std::to_string(line));
    }

protected:
    std::string message;
    std::string file;
    int line;
};


#endif //MODELVIEWER_BASEEXCEPTION_H
