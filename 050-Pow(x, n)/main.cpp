//
//  main.cpp
//  leetcode-0050
//
//  Created by Douglas Su on 4/20/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
    double cal(double& x, int n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        double y = 1.0;
        if (n % 2) {
            y = x;
            n--;
        }
        auto re = cal(x, n / 2);
        return re * re * y;
    }
public:
    double pow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        if (n == 1 || x == 0) return x;
        if (x == -1 && n % 2 == 0) return 1;
        if (x == -1 && n % 2 != 0) return -1;
        
        bool is_negative = (n < 0) ? true : false;
        n = (n < 0) ? 0 - n : n;
        auto k = cal(x, n);
        return (is_negative) ? (1 / k) : k;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution *so = new Solution;
    auto re = so->pow(8.84372, -5);
    cout << re << endl;
    return 0;
}
