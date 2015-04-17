//
//  main.cpp
//  leetcode-0039
//
//  Created by Douglas Su on 4/17/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void go(vector<int>::iterator start, vector<int>::iterator end, int target, vector<vector<int>>& result, vector<int>& haved) {
        for (auto beg = start; beg != end; ++beg) {
            if (haved[0] + *beg > target) return;
            if (haved[0] + *beg == target) {
                haved.push_back(*beg);
                vector<int> tmp (haved.begin() + 1, haved.end());
                result.push_back(tmp);
                haved.pop_back();
                return;
            }
            if (haved[0] + *beg < target) {
                haved[0] += *beg;
                haved.push_back(*beg);
                go(beg, end, target, result, haved);
                haved.pop_back();
                haved[0] -= *beg;
            }
        }
        
        return;
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        vector<int> haved = {0};
        
        go(candidates.begin(), candidates.end(), target, ret, haved);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    vector<int> input = {1};
    int target = 0;

    auto re = so->combinationSum(input, target);
    
                                 
    return 0;
}
