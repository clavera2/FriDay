#include "socket.h"

Socket::Socket() {
        this->fd = socket(AF_INET,SOCK_STREAM,0);
        if (this->fd < 0) {
            throw SocketException("could not create socket object");
        }
}

Socket& Socket::operator <<(void *c) {
        return *this;
}