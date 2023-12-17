#include "./HttpReq.h"
#include "./General.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

namespace Storm{

/*
This function will split the HttpRequest and spawn a HttpReq Class
*/
HttpReq MakeHttpReq(const string req){
    vector<string> lines = Split(req, '\n');
    HttpReq res;
    auto FLine = Split(lines[0], ' ');
    // First line parse
    res.method = FLine[0];
    //Url for args except
    auto url = FLine[1];
    auto url_spls = Split(url, '?');
    if(url_spls.size() == 2 && res.method == "GET") {
        auto vargs = Split(url_spls[1], '&');
        for(auto i : vargs) {
            auto key = Split(i,'=')[0];
            auto value = Split(i,'=')[1];
            res.args[key] = value;
        }
    }
    res.req_url = Split(url, '?')[0];
    if(res.req_url[res.req_url.length()-1] == '/'){
        for(int i=res.req_url.size()-1;i>=0;i--) {
            if(res.req_url[i] == '/'){
                res.req_url = res.req_url.substr(0, res.req_url.size()-1);
            }else{
                break;
            }
        }
    }

    res.http_version = stof(Split(FLine[2],'/')[1]);
    map<string,string> headers;

    for(auto i=1;i<lines.size();i++) {
        auto line = Split(lines[i], ' ');
        if(line.size() != 2) continue;
        headers[line[0]] = line[1];
    }

    if(headers.find("Host:") != end(headers)) res.host = headers["Host:"];
    if(headers.find("Renferer:") != end(headers)) res.renferer = headers["Renferer:"];

    // handle the post require
    auto post_args = Split(lines[lines.size() -1],' ');
    if(post_args.size()==1 && res.method=="POST") {
        post_args = Split(post_args[0], '&');
        for(auto i : post_args) {
            auto kv = Split(i,'=');
            if(kv.size() != 2) continue;
            res.args[kv[0]] = kv[1];
        }
    }

    return res;
}

}