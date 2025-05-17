#include <iostream>
#include <unordered_map>

struct HttpRequest {
    std::string method;
    std::unordered_map<std::string, std::string> _header;
};

struct HttpResponse {
    std::string status_code;
    std::string server_name;
    std::string data; //uses ascitime and time_t
    long content_length;
    std::string content_type;
};


