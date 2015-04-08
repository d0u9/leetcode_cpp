//
//  main.cpp
//  leetcode-0010
//
//  Created by Douglas Su on 4/7/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int maxArea(vector<int> &height) {
//        if (height.size() < 2) return 0;
//        vector<int>::iterator end = height.end();
//        int max = 0;
//        for (auto beg = height.begin(); beg != end; ++beg)
//            for (auto beg_inner = beg + 1; beg_inner != end; ++ beg_inner) {
//                auto V = (beg_inner - beg) * ((*beg_inner > *beg) ? *beg : *beg_inner);
//                max = (int)((max > V) ? max : V);
//            }
//        return max;
//    }
//};

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0;
        for (auto beg = height.begin(), end = height.end() - 1; beg != end; ) {
            auto V = (end - beg) * ((*beg > *end) ? *end : *beg);
            max = (int)((V > max) ? V : max);
            if (*beg < *end)
                beg++;
            else
                end--;
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> input = {2, 1, 400, 3, 2, 1, 100};
    
    Solution * so = new Solution;
    auto re = so->maxArea(input);
    
    cout << re << endl;
    
    return 0;
}
