//
//  main.cpp
//  leetcode-0060
//
//  Created by Douglas Su on 4/30/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        vector<int> factorial_table;
        string input, output;
        for (int i = 1, last = 1; i < n; ++i) {
            factorial_table.push_back(i * last);
            last *= i;
            input.push_back(i + '0');
        }
        input.push_back(n + '0');
        k--;
        for (int i = n - 2; i >= 0; --i) {
            auto q = k / factorial_table[i];
            auto r = k % factorial_table[i];
            int p = 0, j = 0;
            for (j = 0; j < n; ++j) {
                if (input[j] == 'X')    continue;
                if (p++ == q) break;
            }
            output.push_back(input[j]);
            input[j] = 'X';
            if (!r) {
                for (int j = 0; j < n; ++j) {
                    if (input[j] == 'X') continue;
                    output.push_back(input[j]);
                }
                break;
            }
            k = r;
        }
        return output;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    for (int i = 0; i < 24; ++i) {
        auto re = so->getPermutation(5, i + 1);
    
        cout << re << endl;
    }
    
    return 0;
}
