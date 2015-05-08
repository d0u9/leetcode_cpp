//
//  main.cpp
//  leetcode-0075
//
//  Created by Douglas Su on 5/8/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1) return;
        int pos_0 = 0, pos_2 = (int)nums.size() - 1;
        while (nums[pos_0] == 0) pos_0++;
        while (nums[pos_2] == 2) pos_2--;

        int cur = pos_0;
        for (; cur <= pos_2; ) {
            if (nums[cur] == 0 && cur >= pos_0) {
                swap(nums[pos_0++], nums[cur]);
            } else if (nums[cur] == 2) {
                swap(nums[pos_2--], nums[cur]);
            } else {
                cur++;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

//    vector<int> input = {2, 1, 0, 2, 1, 0, 2};
//    vector<int> input = {2, 0, 1};
    vector<int> input = {0, 2, 1};

    Solution *so = new Solution;
    so->sortColors(input);
    return 0;
}
