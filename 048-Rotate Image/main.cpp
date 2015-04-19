//
//  main.cpp
//  leetcode-0048
//
//  Created by Douglas Su on 4/19/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = (int)(matrix.size());
        for (int i = 0; i < (n / 2); ++i) {
            for (int y = i, x = i; y < (n - i - 1); ++ y) {
                auto tmp = matrix[x][y];
                matrix[x][y] = matrix[n - 1 - y][x];
                matrix[n - 1 - y][x] = matrix[n - 1 - x][n - 1 - y];
                matrix[n - 1 - x][n - 1 - y] = matrix[y][n - 1 - x];
                matrix[y][n - 1 - x] = tmp;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    vector<int> r1 = {1, 2, 3};
//    vector<int> r2 = {4, 5, 6};
//    vector<int> r3 = {7, 8, 9};
    
    vector<int> r1 = {11, 12, 13, 14};
    vector<int> r2 = {21, 22, 23, 24};
    vector<int> r3 = {31, 32, 33, 34};
    vector<int> r4 = {41, 42, 43, 44};
    
    vector<vector<int>> input;
    input.push_back(r1);
    input.push_back(r2);
    input.push_back(r3);
    input.push_back(r4);
    
    Solution *so = new Solution;
    so->rotate(input);
    
    return 0;
}
