#include <iostream>
#include <vector>
#include "http.h"

std::ostream& operator <<(std::ostream& out, const HttpRequest& http) {
    out << "{ METHOD: " << http.method << "\n";
    for (auto p : http._header) {
        out << p.first << ": " << p.second << "\n";
    }
    out << "}";
    return out;
}

std::vector<std::string> split_request(char *c, size_t size) {
    std::vector<std::string> ans;
    std::string s;
    for (int i = 0; i < size; i++) {
        if (c[i] == '\n') {
            if (!s.empty() && s.back() == '\r') s.pop_back();
            ans.push_back(s);
            s.clear(); // reset s;
        } else {
            s += c[i];
        }
    }
    return ans;
}


std::pair<std::string,std::string> split_field(std::string& s, char delim) {
    std::pair<std::string,std::string> p;
    std::string first;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == delim) {
            p.first = first;
            p.second = s.substr(i + 1);
            while (!p.second.empty() && p.second[0] == ' ') {
                p.second.erase(0, 1);
            }
        } else {
            first += s[i];
        }
    }
    return p;
}

std::string get_method(char *c, size_t s) {
    //get just the first line of the request
    std::string method;
    for (int i = 0; i < s; i++) {
        if (c[i] == ' ') {
            return method;
        } else {
            method += c[i];
        }
    }
    return method;
}

HttpRequest *parse_to_http_request(char *c, size_t s) {
    HttpRequest *req = new HttpRequest();
    //first line is always the method.
    req->method = get_method(c,s);
    std::vector<std::string> v = split_request(c,s);
    for (std::string s : v) {
        std::pair<std::string,std::string> p = split_field(s, ':');
        if (p.first == " " || p.first == "") continue;
        req->_header[p.first] = p.second;
    }
    return req;
}
