//
//  main.cpp
//  leetcode-0064
//
//  Created by Douglas Su on 5/5/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> row (grid[0].size(), 0);
        vector<vector<int>> ret;
        for (int i = 0; i < grid.size(); ++i)
            ret.push_back(row);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j != 0)
                    ret[i][j] = grid[i][j - 1] + ret[i][j - 1];
                else if (j == 0 && i != 0)
                    ret[i][j] = grid[i - 1][j] + ret[i - 1][j];
                else if (i == 0 && j == 0)
                    ret[i][j] = 0;
                else
                    ret[i][j] = min(ret[i - 1][j] + grid[i - 1][j], ret[i][j - 1] + grid[i][j - 1]);
            }
        }

        return *(*ret.rbegin()).rbegin() + *(*grid.rbegin()).rbegin();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<vector<int>> input;
    vector<int> row1 = {1, 2}; //, 3, 4};
    input.push_back(row1);
    vector<int> row2 = {1, 1}; //, 7, 8};
    input.push_back(row2);
//    vector<int> row3 = {9, 10, 11, 12};
//    input.push_back(row3);
    
    Solution *so = new Solution;
    auto re = so->minPathSum(input);
    
    cout << re << endl;
    
    return 0;
}
