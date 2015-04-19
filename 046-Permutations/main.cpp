//  leetcode-0046
//
//  Created by Douglas Su on 4/19/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    void go(vector<int>& input, vector<int>& haved ,vector<vector<int>>& ret, vector<int>& statistics) {
        if (haved.size() == input.size()) {
            ret.push_back(haved);
            return;
        }
        
        vector<int> hash;
        for (int i = 0; i < input.size(); ++i) {
            if (statistics[i] == 1) continue;
            if (find(hash.begin(), hash.end(), input[i]) != hash.end()) continue;
            hash.push_back(input[i]);
            haved.push_back(input[i]);
            statistics[i] = 1;
            go(input, haved, ret, statistics);
            haved.pop_back();
            statistics[i] = 0;
        }
        return;
    }
    
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> ret;
        vector<int> haved, using_statistics (num.size(), 0);
        
        go(num, haved, ret, using_statistics);
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> input = {1, 3, 3};
    
    Solution *so = new Solution;
    
    auto re = so->permute(input);
    
    return 0;
}
