//
//  main.cpp
//  leetcode-0077
//
//  Created by Douglas Su on 5/8/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void foo(int cur, int n, int deep, vector<int>& item, vector<vector<int>>& ret) {
        if (cur > n + 1) return;
        if (!deep) {
            ret.push_back(item);
            return;
        }
        for (int i = cur; i <= n; i++) {
            item.push_back(i);
            foo(i + 1, n, deep - 1, item, ret);
            item.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> item;
        foo(1, n, k, item, ret);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Solution *so = new Solution;
    auto re = so->combine(4, 3);



    return 0;
}
