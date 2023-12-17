#pragma once
#include <string>
#include <vector>
#include <map>

namespace Storm {

struct HttpReq {
    float http_version;
    std::map<std::string, std::string> args;
    std::string req_url;
    std::string method;
    std::string host;
    std::string renferer;
    std::vector<std::string> accept;
};

HttpReq MakeHttpReq(const std::string);

}
