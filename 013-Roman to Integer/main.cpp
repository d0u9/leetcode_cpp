//
//  main.cpp
//  leetcode-0012
//
//  Created by Douglas Su on 4/8/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int max = 0, ret = 0;
        for (auto beg = s.rbegin(), end = s.rend(); beg != end; ++beg) {
            int current = table[*beg];
            if (current >= max) {
                ret += current;
                max = current;
            } else {
                ret -= current;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string input = "MMCMXCIV";
    
    Solution *so = new Solution;
    auto re = so->romanToInt(input);
    
    cout << re << endl;
    
    
    return 0;
}

