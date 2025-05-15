#include "serversocket.h"

#define MAX_CONNECTION_REQUESTS 100


ServerSocket::ServerSocket(int port) : Socket() {
    this->addr.sin_port = port;
    this->addr.sin_family = AF_INET;
    this->addr.sin_addr.s_addr = INADDR_ANY;
    bind(this->fd,(const sockaddr*)&(this->addr),sizeof(this->addr));
    listen(this->fd,MAX_CONNECTION_REQUESTS);
    client = -1;
}

//default port is 8080
ServerSocket::ServerSocket() : ServerSocket(8080) {}

Socket ServerSocket::accept() {
    this->client = ::accept(this->fd,nullptr,nullptr);
    if (this->client < 0) {
        throw SocketException("client connection could not be established");
    }
    Socket s;
    s.fd = this->client;
    return s;
}

ServerSocket::~ServerSocket() {
    //cleanup resources e.g file desctiptors
    close(this->fd);
}
