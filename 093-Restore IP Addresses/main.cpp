//
//  main.cpp
//  leetcode-0093
//
//  Created by Douglas Su on 5/14/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    void foo(int deep, string& current, vector<string>& ret, int pos, string& s) {
        if (!deep) {
            if (current.size() - 3 == s.size())
                ret.push_back(current);
            return;
        }

        if (deep != 4)
            current.push_back('.');
        for (int i = 0; i < 3; ++i) {
            string field = s.substr(pos, i + 1);
            if (field[0] == '0' && field.size() > 1) continue;
            if (field.size() != i + 1) break;
            int val = 0;
            for (int j = 0, k = (int)field.size() - 1; j < field.size(); ++j, --k)
                val = val * 10 + (field[j] - '0');
            if (val > 255)
                continue;
            current += field;
            foo(deep - 1, current, ret, pos + i + 1, s);
            current = current.substr(0, current.size() - field.size());
        }
        if (deep != 4)
            current.pop_back();
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string current;
        vector<string> ret;

        foo(4, current, ret, 0, s);

        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    string input = "010010";

    Solution *so = new Solution;
    auto re = so->restoreIpAddresses(input);

    return 0;
}
