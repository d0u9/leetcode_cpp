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
private:
    vector<vector<string>> my_dict = {{}, {}, {"a", "b", "c"}, {"d","e","f"},
        {"g","h","i"}, {"j","k","l"}, {"m","n","o"},
        {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"},
    };
public:
    inline vector<string> cross_combine(vector<string> A, vector<string> B) {
        vector<string> ret;
        for (auto beg1 = A.begin(), end1 = A.end(); beg1 != end1; ++beg1)
            for (auto beg2 = B.begin(), end2 = B.end(); beg2 != end2; ++beg2) {
                ret.push_back(*beg1 + *beg2);
            }
        return ret;
    }
    
    inline vector<string> convert(string input) {
        return my_dict[input[0] - 0x30];
    }
    
    vector<string> merge_it(string &digits) {
        vector<string> ret, tmpA, tmpB;
        string partA = digits.substr(0, 1), partB = digits.substr(1);
        tmpA = convert(partA);
        if (partB.size() > 1) tmpB = merge_it(partB);
        else tmpB = convert(partB);
        return cross_combine(tmpA, tmpB);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size() == 0) return ret;
        if (digits.size() == 1) return convert(digits);
        return merge_it(digits);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string input = "234";
    
    Solution *so = new Solution;
    
    auto re = so->letterCombinations(input);
    
//    cout << re << endl;
    
    return 0;
}
