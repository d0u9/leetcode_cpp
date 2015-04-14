//
//  main.cpp
//  leetcode-0028
//
//  Created by Douglas Su on 4/14/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compare(int index, const string& haystack, const string& needle, int& k) {
        k = 0;
        bool found = false;
        for (int i = 0; i < needle.size(); ++i) {
            if (haystack[i + index] != needle[i]) return 0;
            if (haystack[i + index] == needle[0] && i != 0 && !found) {
                k = i + index - 1;
                found = true;
            }
        }
        return 1;
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        if (needle.size() == 0) return 0;
        if (needle.size() == haystack.size()) return (needle == haystack) ? 0 : -1;
        int i = 0, k = 0;
        for (i = 0; i < haystack.size(); ++i) {
            if (haystack[i] == needle[0]) {
                auto re = compare(i, haystack, needle, k);
                if (re)
                    return i;
                if (k) i = k;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string a = "abbabaaaabbbaabaabaabbbaaabaaaaaabbbabbaabbabaabbabaaaaababbabbaaaaabbbbaaabbaaabbbbabbbbaaabbaaaaababbaababbabaaabaabbbbbbbaabaabaabbbbababbbababbaaababbbabaabbaaabbbba";
    string b =  "bbbbbbaa";
    
    Solution *so = new Solution;
    
    cout << so->strStr(a, b) << endl;
    
    return 0;
}
