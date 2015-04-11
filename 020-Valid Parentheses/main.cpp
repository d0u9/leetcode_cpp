//
//  main.cpp
//  leetcode-0020
//
//  Created by Douglas Su on 4/11/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<char, char> table = {
        {'[', ']'}, {']', '['},
        {'{', '}'}, {'}', '{'},
        {'(', ')'}, {')', '('}
    };
public:
    inline bool is_match(char a, char b) {
        return (table[a] == b) ? true : false;
    }
    
    bool isValid(string s) {
        vector<char> stack;
        for (auto cur : s) {
            if (stack.empty()) stack.push_back(cur);
            else {
                if (is_match(*stack.rbegin(), cur)) stack.pop_back();
                else stack.push_back(cur);
            }
        }
        return (stack.empty()) ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string input = "[[]]]";
    
    Solution * so = new Solution;
    auto re = so->isValid(input);
    
    cout << re << endl;
    
    return 0;
}
