#include "socket.h"

#define MAX_CONNECTION_REQUESTS 100

struct ServerSocket : public Socket {
private:
    sockaddr_in addr;
    int client; //initialized when connected to client
public:
    ServerSocket(int port);
    //default port is 8080
    ServerSocket();
    Socket accept();
    ~ServerSocket();
};