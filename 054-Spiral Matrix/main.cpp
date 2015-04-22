//
//  main.cpp
//  leetcode-0054
//
//  Created by Douglas Su on 4/21/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (matrix.size() == 0) return ret;
        int n = 1, N1 = (int)matrix.size(), N2 = (int)(matrix[0].size());
        int counter = N1 * N2;
        while (counter > 0) {
            for (int i = n - 1; i <= N2 - n && counter; ++i) {
                ret.push_back(matrix[n - 1][i]);
                counter--;
            }
            for (int i = n; i <= N1 - n && counter; ++i) {
                ret.push_back(matrix[i][N2 - n]);
                counter--;
            }
            for (int i = N2 - n - 1; i >= n - 1 && counter; --i) {
                ret.push_back(matrix[N1 - n][i]);
                counter--;
            }
            for (int i = N1 - n - 1; i >= n && counter; --i) {
                ret.push_back(matrix[i][n - 1]);
                counter--;
            }
            ++n;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> ret;
    vector<int> r1 = {1, 2, 3, 4};
    ret.push_back(r1);
    vector<int> r2 = {5, 6, 7, 8};
    ret.push_back(r2);
    vector<int> r3 = {9, 10, 11, 12};
    ret.push_back(r3);
//    vector<int> r4 = {16, 17, 18, 19, 20};
//    ret.push_back(r4);
//    vector<int> r5 = {21, 22, 23, 24, 25};
//    ret.push_back(r5);
    
    
    Solution *so = new Solution;
    auto re = so->spiralOrder(ret);
    
    return 0;
}
