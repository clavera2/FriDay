#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "socketexception.h"
#include "http.h"

class ServerSocket;

struct Socket {
protected:
    int fd;
public:
    Socket();

    friend class ServerSocket;

    virtual ~Socket() = default;

    //for sending and recieving messages, the function calls should be abstracted using operator overload (<< and >>)
    Socket& operator <<(void *c);
    void operator >>(HttpRequest *h);
};
