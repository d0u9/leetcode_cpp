//
//  main.cpp
//  leetcode-0058
//
//  Created by Douglas Su on 4/24/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool exist = false;
        int start_pos = (int)s.size();
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (isalpha(s[i]) && !exist) {
                exist = true;
                start_pos = i;
            }
            if (exist && !isalpha(s[i])) {
                return start_pos - i;
            }
        }
        return (exist) ? start_pos : 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    string input = "Hello ,World,";
    string input = "H";
    Solution *so = new Solution;
    auto re = so->lengthOfLastWord(input);
    cout << re << endl;
    
    
    return 0;
}
