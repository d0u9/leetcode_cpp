//
//  main.cpp
//  leetcode-0005
//
//  Created by Douglas Su on 3/12/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)(s.length());
        if (n == 0) return "";
        string longest = s.substr(0, 1);  // a single char itself is a palindrome
        for (int i = 0; i < n-1; i++) {
            string p1 = this->expandAroundCenter(s, i, i);
            if (p1.length() > longest.length())
                longest = p1;
            
            string p2 = this->expandAroundCenter(s, i, i+1);
            if (p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
    
private:
    string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2;
        int n = (int)(s.length());
        while (l >= 0 && r <= n-1 && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    string input = "ccc";
    
    string output = so->longestPalindrome(input);
    cout << output << endl;
    
    return 0;
}
