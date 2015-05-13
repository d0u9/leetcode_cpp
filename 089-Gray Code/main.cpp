//
//  main.cpp
//  leetcode-0089
//
//  Created by Douglas Su on 5/13/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void foo(vector<int>& ret, int deep, int& current) {
        if (!deep) {
            ret.push_back(current);
            return;
        }

        int counter = 2;
        while (counter) {
            foo (ret, deep - 1, current);
            if (!(--counter)) return;
            current ^= 1 << (deep - 1);
        }
    }
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int current = 0;

        foo(ret, n, current);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Solution *so = new Solution;
    auto re = so->grayCode(0);


    return 0;
}
