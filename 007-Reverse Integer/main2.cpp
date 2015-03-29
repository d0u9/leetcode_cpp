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
        int i = 0, sum = 0;
        for (i = 0; x != 0; ++i) {
            int cur = x % 10;
            x /= 10;
            if (sum > 214748364 || sum < -214748364) return 0;
            sum = sum * 10 + cur;
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
