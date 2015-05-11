//
//  main.cpp
//  leetcode-0033
//
//  Created by Douglas Su on 5/11/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int reverse_point = 0, left = 0, right = (int)nums.size() - 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                reverse_point = i;
                break;
            }
        }

        while (left <= right) {
            auto l_mid = (left + right) / 2;
            auto mid = (l_mid + reverse_point) % nums.size();
            if (nums[mid] < target) left = l_mid + 1;
            else if (nums[mid] > target) right = l_mid - 1;
            else return (int)mid;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> input = {4, 5, 6, 7, 0, 1, 2, 3};
//    input = {1, 3};
    input = {3, 5, 1};

    Solution *so = new Solution;
    auto re = so->search(input, 5);

    cout << re << endl;

    return 0;
}
