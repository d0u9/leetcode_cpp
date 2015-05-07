//
//  main.cpp
//  leetcode-0071
//
//  Created by Douglas Su on 5/7/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string ret = "/";
        path.push_back('/');
        for (int i = 0, n = (int)path.size(); i < n; ++i) {
            if (path[i] == '/' && i == n - 1) break;
            if (path[i] == '/') {
                int j = ++i;
                while (path[i] != '/') ++i;
                if (i - j == 0) {
                    --i;
                    continue;
                }
                string element(path, j, i - j);
                if (element == ".") {
                    --i;
                    continue;
                }
                else if (element == "..") {
                    if (stack.size() != 0) stack.pop_back();
                }
                else stack.push_back(element);
                --i;
            }
        }
        for (int i = 0, n = (int)stack.size(); i < n; ++i) {
            if (i != 0) ret += "/";
            ret += stack[i];
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    //string input = "/home//////";
    string input = "/home/of/foo/../../bar/../../is/./here/.";
    input = "/abc/...";
    
    Solution *so = new Solution;
    
    auto re = so->simplifyPath(input);
    
    cout << re << endl;
    
    return 0;
}
