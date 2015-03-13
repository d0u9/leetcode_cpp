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
        int n = (int)s.size(), block_size = (nRows - 1);
        if (n <= nRows)
            return s;
        int end_pos = n % block_size, block_num = n / block_size;
        int block_num_max = (end_pos == 0) ? block_num : block_num + 1;
        
        int pos = 0;
        vector<vector<char>> A = {};
        for (int i = 0; i < block_num * block_size; ++i) {
            vector<char> current_line = {};
            if (i % block_size == 0) {
                for (int j = 0; j < nRows; ++j) {
                    if (pos > n) {
                        current_line.push_back(0);
                    } else
                    current_line.push_back(s[pos++]);
                }
            } else {
                int j = 0;
                for (; j < nRows - (i % block_size) - 1; ++j)
                    current_line.push_back(0);
                current_line.push_back(s[pos++]);
                ++j;
                for (; j < nRows; ++j)
                    current_line.push_back(0);
            }
            A.push_back(current_line);
            if (pos > n) {
                break;
            }
        }
        
        string re = "";
        for (int i = 0; i < nRows; ++i){
            for (int j = 0; j < A.size(); ++j) {
                auto current = A[j][i];
                if (current != 0)
                    re.push_back(current);
            }
        }
        
        return re;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string input = "";
    
    Solution *so = new Solution;
    
    string output = so->convert(input, 1);
    
    cout << output << endl;
    
    return 0;
}
