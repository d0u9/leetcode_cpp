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
    string intToRoman(int num) {
        string ret = "";
        map<int, char> table = {{1, 'I'},
            {5, 'V'}, {10, 'X'},
            {50, 'L'}, {100, 'C'},
            {500, 'D'}, {1000, 'M'}};
        for (int i = 1000; i != 0; i /= 10) {
            int q = num / i;
            int r = num % i;
            if (q >= 1 && q <= 3) {
                while (q) {
                    ret.push_back(table[i]);
                    --q;
                }
            } else if (q == 4) {
                ret.push_back(table[i]);
                ret.push_back(table[i * 5]);
            } else if (q == 5) {
                ret.push_back(table[i * 5]);
            } else if (q >= 6 && q <= 8) {
                ret.push_back(table[i * 5]);
                int n = q - 5;
                while (n) {
                    ret.push_back(table[i]);
                    --n;
                }
            } else if (q == 9) {
                ret.push_back(table[i]);
                ret.push_back(table[i * 10]);
            }
            num = r;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int num = 4;
    
    Solution *so = new Solution;
    auto re = so->intToRoman(num);
    
    cout << re << endl;
    
    
    return 0;
}
