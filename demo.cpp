#include "./WebStorm/SEngine/HttpReq.h"
#include "./WebStorm/SEngine/UrlParse.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using namespace Storm;

int main(){
    auto req = MakeHttpReq("GET /A/?a=10&b=10 HTTP/1.1\nHost: www.hello.com\nRenferer: cn.bing.com\n");
    auto v = UrlParse(req.req_url);
    for(auto i : v) {
        cout << i << endl;
    }
    return 0;
}