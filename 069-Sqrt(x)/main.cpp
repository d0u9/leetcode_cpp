//
//  main.cpp
//  leetcode-0069
//
//  Created by Douglas Su on 5/5/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        unsigned int left = 0, right = x, mid = 0;
        while (right - left > 1) {
            mid = (left + right) / 2;
            unsigned long long l_mid = (long)mid * (long)mid;
            if (l_mid > (long)x) right = mid;
            else if (l_mid < (long)x) left = mid;
            else return mid;
        }
        return min(left, mid);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    auto re = so->mySqrt(2147395599);
    
    cout << re << endl;
    return 0;
}
