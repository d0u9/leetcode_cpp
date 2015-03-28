//
//  main.cpp
//  leetcode-0007
//
//  Created by Douglas Su on 3/28/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        bool has_sign = false;
        if (x < 0) {
            has_sign = true;
            x = 0 - x;
        }
        vector<int> fields = {};
        int i = 0;
        for (i = 0; x != 0; ++i) {
            fields.push_back(x % 10);
            x /= 10;
        }
        
        int last_pow = 1;
        int sum = 0, last_sum = 0;
        for (int j = 0; j < i; ++j) {
            int k = *(fields.rbegin()) * last_pow;
            sum += k;
            fields.pop_back();
            if (sum < last_pow) return 0;
            last_sum = sum;
            last_pow *= 10;
        }
        
        return (has_sign) ? (0 - sum) : sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution so;
    int n = 1534236469;
    cout << "result = " << so.reverse(n) << endl;
    
    return 0;
}
