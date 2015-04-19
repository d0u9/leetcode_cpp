//
//  main.cpp
//  leetcode-0043
//
//  Created by Douglas Su on 4/18/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
    string multiply_one_field(string num, char ch) {
        int carry = 0;
        for (auto beg = num.rbegin(), end = num.rend(); beg != end; ++beg) {
            unsigned int k = (*beg - '0') * (ch - '0') + carry;
            *beg = k % 10 + '0';
            carry = k / 10;
        }
        if (carry) {
            string tmp;
            tmp.push_back(carry + '0');
            return tmp + num;
        }
        return num;
    }
    
    string sum (string num1, string num2) {
        int i, long_size, short_size, carry = 0;
        string *long_s, *short_s;
        if (num1.size() > num2.size()) {
            long_size = (int)num1.size();
            long_s = &num1;
            short_size = (int)num2.size();
            short_s = &num2;
        } else {
            long_size = (int)num2.size();
            long_s = &num2;
            short_size = (int)num1.size();
            short_s = &num1;
        }
        for (i = short_size - 1; i >= 0; --i) {
            int k = ((*short_s)[i] - '0') + ((*long_s)[--long_size] - '0') + carry;
            (*long_s)[long_size] = k % 10 + '0';
            carry = k / 10;
        }
        --long_size;
        for (;long_size >=0;) {
            int k = ((*long_s)[long_size]) - '0' + carry;
            (*long_s)[long_size--] = k % 10 + '0';
            carry = k / 10;
        }
        if (carry) {
            string tmp;
            tmp.push_back(carry + '0');
            return tmp + (*long_s);
        }
        return (*long_s);
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string cur_base = num1, ret = "0";
        while (num2.size()) {
            auto ch = num2.back();
            num2.pop_back();
            auto tmp = multiply_one_field(cur_base, ch);
            ret.empty();
            ret = sum(tmp, ret);
            cur_base.push_back('0');
        }
        
//        auto p = multiply_one_field("123", '9');
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    string num1 = "0", num2 = "1";
    auto re = so->multiply(num1, num2);
    
    cout << re << endl;
    
    return 0;
}
