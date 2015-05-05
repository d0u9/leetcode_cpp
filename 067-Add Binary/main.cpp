//
//  main.cpp
//  leetcode-0067
//
//  Created by Douglas Su on 5/4/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret = (a.size() > b.size()) ? a : b;
        string& long_s = (a.size() > b.size()) ? a : b;
        string& short_s = (a.size() > b.size()) ? b : a;
        
        char carry = 0;
        auto beg_l = long_s.rbegin(), beg_s = short_s.rbegin(), beg = ret.rbegin();
        for (;beg_l != long_s.rend() && beg_s != short_s.rend(); ++beg_s, ++beg_l, ++beg) {
            *beg = ((*beg_l - '0') ^ (*beg_s - '0') ^ carry) + '0';
            carry = ((*beg_l - '0') & (*beg_s - '0')) | (carry & ((*beg_l - '0') ^ (*beg_s - '0')));
        }
        if (carry != 0) {
            for (;beg_l != long_s.rend() && carry != 0; ++beg_l, ++beg) {
                *beg = ((*beg_l - '0') ^ carry) + '0';
                carry = ((*beg_l - '0') & carry);
            }
            if (carry) {
                ret.push_back('0');
                for (auto beg = ret.rbegin(); beg != ret.rend() - 1; ++beg) {
                    *beg = *(beg + 1);
                }
                ret[0] = '1';
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string a = "1111";
    string b = "10";
    
    Solution *so = new Solution;
    auto re = so->addBinary(a, b);
    
    cout << re << endl;
    
    return 0;
}
