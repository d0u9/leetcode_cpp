//
//  main.cpp
//  leetcode-0073
//
//  Created by Douglas Su on 5/7/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        int corner = matrix[0][0], i_has_zero = 0, j_has_zero = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) i_has_zero = 1;
                    if (j == 0) j_has_zero = 1;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

        
        if (j_has_zero) {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
        if (i_has_zero) {
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    vector<vector<int>> input;
//    vector<int> row = {0,0,0,5};
//    input.push_back(row);
//    row = {4,3,1,4};
//    input.push_back(row);
//    row = {0,1,1,4};
//    input.push_back(row);
//    row = {1,2,1,3};
//    input.push_back(row);
//    row = {0,0,1,1};
//    input.push_back(row);
    
    
    vector<int> row = {1,0,3};
    input.push_back(row);

    Solution *so = new Solution;
    so->setZeroes(input);


    return 0;
}
