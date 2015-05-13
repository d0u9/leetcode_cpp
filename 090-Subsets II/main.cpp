//
//  main.cpp
//  leetcode-0090
//
//  Created by Douglas Su on 5/13/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void foo(vector<int>& nums, vector<vector<int>>& ret, vector<int>& current, int start) {
        if (start == (int)nums.size()) return;
        int have_processed = false;

        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] && i != 0 && have_processed) continue;
            current.push_back(nums[i]);
            ret.push_back(current);
            foo(nums, ret, current, i + 1);
            current.pop_back();
            have_processed = true;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> ret (1, current);
        sort(nums.begin(), nums.end());

        foo(nums, ret, current, 0);

        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    vector<int> input = {1, 2, 2, 2, 2, 3};
    input = {1, 1};

    Solution *so = new Solution;
    auto re = so->subsetsWithDup(input);

    return 0;
}
