//
//  main.cpp
//  leetcode-0003
//
//  Created by Douglas Su on 3/11/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        
        // 记录子串起始位置的前一个位置的下标
        // 初始化为-1
        int idx = -1;
        
        // 记录字符在s中出现的位置
        int locs[256];
        memset(locs, -1, sizeof(int) * 256);
        for (int i = 0; i < s.size(); i++) {
            // 如果s[i]在当前子串中出现过
            if (locs[s[i]] > idx) {
                // 新子串的起始位置设为s[i]出现的位置+1
                // P.S. idx是记录起始位置的前一个位置的下标
                idx = locs[s[i]];
            }
            // 如果当前子串的长度大于最大值
            if (i - idx > max) {
                max = i - idx;
            }
            // 更新字符s[i]出现的位置
            locs[s[i]] = i;
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
        string input = "pwwkew";
    //    string input = "aa";
    //    string input = "advkdf";
    //    string input = "cdd";
    //    string input = "aab";
    //    string input = "abba";
    //    string input = "asljlj";
    //    string input = "dvdf";
    //    string input = "jynj";
    //    string input = "bdb";
    //    string input = "bwf";
    //    string input = "abcb";
    
    
//    string input = "aaopqxyzcopqdddxyee";
//    string input = "aaopqrstdddxyee";
//    string input = "oaapp";
//    string input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
    
    Solution *so = new Solution;
    cout << so->lengthOfLongestSubstring(input) << endl;
    
    return 0;
}
