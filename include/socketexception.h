
//header guard-to avoid redefinitions of entities
#ifndef SOCKET_EXCEPTION_H
#define SOCKET_EXCEPTION_H

#include <iostream>
class SocketException : public std::exception {
    const char *msg;
public:
    SocketException(std::string msg) : msg(msg.c_str()) {}

    const char *what() const noexcept override {
        return msg;
    }
};
#endif