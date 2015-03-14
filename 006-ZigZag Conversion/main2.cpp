//
//  main.cpp
//  leetcode-0006
//
//  Created by Douglas Su on 3/13/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int n = (int)s.size();
        if (n <= nRows || nRows == 1)
            return s;
        
        string re = "";
        
        int len = nRows - 2 + nRows;
        
        for (int left = len, right = 0, i = 0; i < nRows; ++i) {
            bool is_left = false;
            char current = 0;
            int offset = 0;
            
            while (i + offset < n) {
                if (!is_left) {
                    if (left != 0) {
                        current = s[i + offset];
                        re.push_back(current);
                    }
                    offset += left;
                    is_left = true;
                } else {
                    if (right != 0) {
                        current = s[i + offset];
                        re.push_back(current);
                    }
                    offset += right;
                    is_left = false;
                }
            }
            left -= 2;
            right = len - left;
        }
        
        return re;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string input = "ABC";

    cout << " " << input.size()  << endl;
    
    Solution *so = new Solution;
    
    string output = so->convert(input, 2);
    
    cout << "$" << output << "$" << " " << output.size() << endl;
    
    return 0;
}
