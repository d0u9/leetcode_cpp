//
//  main.cpp
//  leetcode-0078
//
//  Created by Douglas Su on 5/8/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void foo (int pos, vector<int>& nums, vector<int>& row, vector<vector<int>>& ret) {
        ret.push_back(row);
        if (pos == nums.size()) return;
        for (int i = pos; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] && i > 0) continue;
            row.push_back(nums[i]);
            foo (i + 1, nums, row, ret);
            row.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> row;

        foo (0, nums, row, ret);

        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> input = {};
    
    Solution *so = new Solution;
    auto re = so->subsets(input);
    return 0;
}
