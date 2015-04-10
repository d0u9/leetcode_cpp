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
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() == 3) return (num[0] + num[1] + num[2]);
        sort(num.begin(), num.end());
        int min = 500000, a = num[0], b = num[1], c = num [2];;
        for (auto beg = num.begin(), end = num.end(); beg != end - 2; ++beg) {
            auto left = beg + 1, right = num.end() - 1;
            while (left != right) {
                int current = abs(*beg + *left + * right - target);
                if (!current) return (*beg + *left + * right);
                if (current < min) {
                    min = current;
                    a = *beg;
                    b = *left;
                    c = *right;
                }
                if (*beg + *left + * right >= target)
                    right --;
                else
                    left ++;
            }
        }
        return (a + b + c);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    vector<int> input = {-4, -1, 2, 3, 6};
//    vector<int> input = {-1, 2, 1, -4};
//    vector<int> input = {0, 1, 2};
//    vector<int> input = {0, 0, 0};
    vector<int> input = {1, 1, 1, 0};
    
    Solution *so = new Solution;
    
    auto re = so->threeSumClosest(input, 100);
    
    cout << re << endl;
    
    return 0;
}
