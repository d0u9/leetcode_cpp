//
//  main.cpp
//  leetcode-0015
//
//  Created by Douglas Su on 4/9/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        if (num.size() <= 3) return ret;
        sort(num.begin(), num.end());
        auto cur1 = num.begin(), cur2 = num.end() - 1, left = cur1 + 1, right = cur2 - 1;
        int last1 = *cur1 + 1, last2;
        for (; cur1 <= num.end() - 4; ++cur1) {
            if (*cur1 == last1) continue;
            last2 = *(num.end() - 1) + 1;
            for (cur2 = num.end() - 1; cur1 <= cur2 - 3; --cur2) {
                if (*cur2 == last2) continue;
                left = cur1 + 1, right = cur2 - 1;
                while (right != left) {
                    if (*left + *right + *cur1 + *cur2 == target) {
                        vector<int> tmp = {*cur1, *left, *right, *cur2};
                        if (ret.empty() || tmp != *ret.rbegin()) {
                            ret.push_back(tmp);
                        }
                    }
                    if (*cur1 + *right + *left + *cur2 >= target) right --;
                    else left++;
                }
                last2 = *cur2;
            }
            last1 = *cur1;
        }
        
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    vector<int> input = {1, 0, -1, 0, -2, 2};
//    vector<int> input = {0, 0, 0, 0};
//    vector<int> input = {-3,-2,-1,0,0,1,2,3};
    vector<int> input = {2,0,3,0,1,2,4};
    
    Solution *so = new Solution;

    auto re = so->fourSum(input, 7);
    
    //    cout << re << endl;
    
    return 0;
}
