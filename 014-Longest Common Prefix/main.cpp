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
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        string ret = "";
        int i = 0;
        while (i < strs[0].size()) {
            bool first = true;
            char current = '\0';
            for (auto beg = strs.begin(), end = strs.end(); beg != end; ++beg) {
                if (first) {
                    current = (*beg)[i];
                    if (!current) goto finish;
                    first = false;
                    continue;
                } else if (current != (*beg)[i]) {
                        goto finish;
                }
            }
            ++i;
            ret.push_back(current);
        }
    finish:
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    vector<string> input = {"aaber", "aabd", "aabde"};
//    vector<string> input = {""};
    vector<string> input = {};
//    vector<string> input = {"abca", "abc"};
    cout << input.size() << endl;
    
    Solution *so = new Solution;
    string re = so->longestCommonPrefix(input);
    
    if (re == input[0])
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << re << re.size() << endl;
    
    
    return 0;
}


