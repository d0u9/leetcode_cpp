//
//  main.cpp
//  leetcode-0074
//
//  Created by Douglas Su on 5/8/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = (int)matrix.size();
        int mid = 0;
        if (matrix.size() > 1) {
            while (right - left > 1) {
                mid = (left + right) / 2;
                if (matrix[mid][0] <= target) left = mid;
                else right = mid;
            }
        }
        
        int n, row = left;
        left = 0, right = (int)matrix[0].size() - 1;
        n = right;
        while (right != left) {
            mid = (left + right) / 2;
            if (matrix[row][mid] < target) left = ++mid;
            else right = mid;
        }
        if (matrix[row][left] != target) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    vector<int> row;
    vector<vector<int>> input;
    row = {1, 3, 5, 7};
    row = {1};
    input.push_back(row);
//    row = {10, 11, 16, 20};
//    input.push_back(row);
//    row = {23, 30, 34, 50};
//    input.push_back(row);

    Solution *so = new Solution;

    auto re = so->searchMatrix(input, 1);

    cout << re << endl;

    return 0;
}
