//
//  main.cpp
//  leetcode-0038
//
//  Created by Douglas Su on 4/17/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
    inline string say(string& str) {
        char cur = str[0];
        string ret;
        for (int i = 0, j = 0; i <= str.size(); ++i) {
            if (str[i] != cur || i == str.size()) {
                ret.push_back((i - j) + '0');
                ret.push_back(cur);
                j = i;
                cur = str[i];
            }
        }
        return ret;
    }
public:
    string countAndSay(int n) {
        if (n-- == 1) return "1";
        
        string ret = "1";
        while (n--) {
            ret = say(ret);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    cout << so->countAndSay(2) << endl;
    
    return 0;
}
