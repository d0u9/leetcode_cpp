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
    inline vector<int> construct(int a, int b, int c) {
        vector<int> ret = {a, b, c};
        return ret;
    }
    
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        if (num.size() < 3) return ret;
        set<vector<int>> hash;
        vector<int>::iterator mid, result, beg_l, end_r;
        bool have_three_zero = false;
        
        sort(num.begin(), num.end());
        if (*(num.end() - 1) == *num.begin() && *num.begin() == 0) {ret.push_back(construct(0, 0, 0)); return ret;}
        
        for (auto beg = num.begin(), end = num.end(); beg != end; ++beg) {
            if (*beg >= 0) {
                mid = beg;
                break;
            }
        }
        if (*num.begin() > 0 || *num.rbegin() < 0) return ret;
        if (*mid == *(mid + 2) && *mid == 0 && (mid + 2) < num.end()) have_three_zero = true;
        
        int last1 = (*num.begin()) + 1, last2;
        for (beg_l = num.begin(); beg_l < mid; ++beg_l) {
            if (last1 == *beg_l) continue;
            last2 = *(num.end() - 1) + 1;
            for (end_r = num.end() - 1; end_r >= mid; --end_r) {
                if (last2 == *end_r) continue;
                auto target = 0 - *beg_l - *end_r;
                if (target >= *mid) { // find in right side
                    result = find(mid, num.end(), target);
                    if (result != end_r) //find it
                        ret.push_back(construct(*beg_l, *result, *end_r));
                } else { // find in left side
                    result = find(beg_l + 1, mid, target);
                    if (result != mid)
                        ret.push_back(construct(*beg_l, *result, *end_r));
                }
                last2 = *end_r;
            }
            last1 = *beg_l;
        }
        if (have_three_zero) ret.push_back(construct(0, 0, 0));
        return ret;
    }
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    vector<int> input = {1, -1, 3, 0, -4};
//    vector<int> input = {-1, 0, 1, 2, -1, -4};
//    vector<int> input = {0, 0, 0, 0};
//    vector<int> input = {6,-5,-6,-1,-2,8,-1,4,-10,-8,-10,-2,-4,-1,-8,-2,8,9,-5,-2,-8,-9,-3,-5};
    vector<int> input = {-10,-3,-8,-3,4,-1,-2,-4,-8,-5};
    
    Solution *so = new Solution;
    
    auto re = so->threeSum(input);
    
//    cout << re << endl;
    
    return 0;
}
