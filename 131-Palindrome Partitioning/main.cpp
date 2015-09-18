//
//  main.cpp
//  leetcode-0131
//
//  Created by Douglas Su on 9/18/15.
//  Copyright © 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    inline bool isP(string s) {
        for (int i = 0, j = (int)s.size() - 1; i <= j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    
    bool F(string s, vector<vector<string>> &ret, vector<string> &haved) {
        if (s.empty()) { ret.push_back(haved); return true;}
        for (int i = 1; i <= s.size(); ++i) {
            string tmp(s.c_str() + 0, s.c_str() + i);
            if (isP(tmp)) {
                haved.push_back(tmp);
                string sub(s.c_str() + i, s.c_str() + s.size());
                auto r = F(sub, ret, haved);
                haved.pop_back();
                if (!r) return false;
            }
        }
            
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> haved;
        
        F(s, ret, haved);
        
        
        return ret;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution *so = new Solution;
    auto re = so->partition("aa");
    return 0;
}
