//
//  main.cpp
//  leetcode-0066
//
//  Created by Douglas Su on 5/4/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> ret;
        for (auto beg = digits.rbegin(); beg != digits.rend() && carry; ++beg) {
            int sum = *beg + carry;
            carry = (sum > 9) ? 1 : 0;
            int p = (sum > 9) ? 0 : sum;
            *beg = p;
        }
        if (carry) {
            digits.push_back(0);
            digits[0] = carry;
//            digits.push_back(*digits.rbegin());
//            for (auto beg = digits.rbegin(); beg != digits.rend() - 1; ++beg)
//                *beg = *(beg + 1);
//            digits[0] = carry;
        }
        ret = digits;
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> input = {3, 9, 9};
    
    Solution *so = new Solution;
    
    auto re = so->plusOne(input);
    
    return 0;
}
