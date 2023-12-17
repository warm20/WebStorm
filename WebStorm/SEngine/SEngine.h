#pragma once
#include <functional>
#include <string>
#include <vector>
#include <map>

namespace Storm {
/* Type defines */
using Router_func = std::function<void(std::string&)>;
using ArgRouer_func = std::function<void(std::string&, std::vector<std::string>)>;

/* EngineInterface */
/* 
This file will give some handle web methods function
such as reg_route() reg_arg_Route() RegHostGroup()
*/
class SEngine final {
private:
    std::map<std::string, Router_func> UrlRoutes;
    std::map<std::string, ArgRouer_func> ArgRoutes;
    std::vector<std::string> pre_hosts;
public:
    // url : func
    void RegRouter(std::string, Router_func);
    // pre_host, ulr : func
    void RegRouter(std::string, std::string, Router_func);
    // shotest_url : func
    void RegArgRoute(std::string, ArgRouer_func);
    // group_host
    void RegHostGroup(std::string);
};

}
