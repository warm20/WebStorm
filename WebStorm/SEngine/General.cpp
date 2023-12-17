#include "./General.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

namespace Storm {
    vector<string> Split(string str,const char spl_Str){
        vector<string> res;
        istringstream iss(str);
        string temp;
        while(getline(iss, temp, spl_Str)) {
            res.push_back(temp);
        }
        return res;
    };
};