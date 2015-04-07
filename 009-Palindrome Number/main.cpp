//
//  main.cpp
//  leetcode-0009
//
//  Created by Douglas Su on 4/7/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        
        int one_field = 0, part_a = 0, i = 0;
        while (x != 0) {
            one_field = x % 10;
            if (one_field == 0 && i == 0) return false;
            part_a = part_a * 10 + one_field;
            if (part_a == x) break;
            x /= 10;
            if (part_a == x) break;
            ++i;
        }
        return (x) ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int x = 10;
    Solution *so = new Solution;
    auto re = so->isPalindrome(x);
    cout << re << endl;
    
    return 0;
}
