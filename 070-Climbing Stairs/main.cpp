//
//  main.cpp
//  leetcode-0070
//
//  Created by Douglas Su on 5/7/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int array[3] = {1, 2, 0};

        if (n == 0) return 0;
        if (n < 3) return array[n - 1];

        for (int i = 3; i < n + 1; ++i) {
            array[2] = array[1] + array[0];
            array[0] = array[1];
            array[1] = array[2];
        }
        return array[2];

    }

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Solution *so = new Solution;
    auto re = so->climbStairs(3);

    cout << re << endl;


    return 0;
}
