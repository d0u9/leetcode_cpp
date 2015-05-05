//
//  main.cpp
//  leetcode-0059
//
//  Created by Douglas Su on 4/24/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret;
        vector<int> tmp (n, -1);
        for (int i = 0; i < n; ++i) {
            ret.push_back(tmp);
        }
        
        int total_elements = 1;
        for (int k = 0; total_elements <= n * n; ++k) {
            for (int i = k; i < n - k; ++i)
                ret[k][i] = total_elements ++;
            for (int i = k + 1; i < n - k; ++i)
                ret[i][n - k - 1] = total_elements ++;
            for (int i = n - k - 2; i >= k ; --i)
                ret[n - k - 1][i] = total_elements ++;
            for (int i = n - k - 2; i > k; --i)
                ret[i][k] = total_elements ++;
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    auto re = so->generateMatrix(3);
    
    
    
    return 0;
}
