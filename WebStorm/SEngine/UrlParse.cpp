#include "./UrlParse.h"
#include "./General.h"
#include <vector>
#include <string>
using namespace std;

namespace Storm {

vector<string> UrlParse(std::string original_url) {
    auto url_splits = Split(original_url, '/');
    if(url_splits.size() == 1) {
        return {"/"};
    }
    vector<string> res;
    res.push_back("/");
    for(int i=1;i<=url_splits.size()-1;i++) {
        string tmp = "";
        for(int j=1; j<=i; j++){
            tmp += ("/"+url_splits[j]);
        }
        res.push_back(tmp);
    }
    return res;
}

}