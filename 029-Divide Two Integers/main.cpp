//
//  main.cpp
//  leetcode-0029
//
//  Created by Douglas Su on 4/14/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1 || dividend == 0) return dividend;
        
        if (divisor == -1 && dividend >= -2147483647 && dividend <= 2147483647) return 0 - dividend;
        if (divisor == -1 && dividend == -2147483648) return 2147483647;
        
        bool is_negative = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) is_negative = true;
        dividend = (dividend > 0) ? (0 - dividend) : dividend;
        divisor = (divisor > 0) ? (0 - divisor) : divisor;
        
        unsigned a = (dividend == -2147483648) ? 2147483648 : (dividend >= 0) ? dividend : 0 - dividend;
        unsigned b = (divisor == -2147483648) ? 2147483648 : (divisor >= 0) ? divisor : 0 - divisor;
        
        int cur_size = 1, cur = b, counter = 0;
        while (a >= b) {
            int tmp = a - cur;
            counter += cur_size;
            if (tmp > 0 && tmp - cur - cur < 0) {
                cur = b;
                cur_size = 1;
            } else {
                cur += cur;
                cur_size += cur_size;
            }
            a = tmp;
        }
        return (is_negative) ? (0 - counter) : counter;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    cout << so->divide(2147483647, 2) << endl;
    
    return 0;
}
