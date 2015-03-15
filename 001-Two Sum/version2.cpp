//
//  main.cpp
//  leetcode-0001
//
//  Created by Douglas Su on 3/3/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
#define LEN 500
        
        vector<int> result = {};
        vector<int> hash_table[LEN] = {};
        vector<int> hash_table2[LEN] = {};
        
        for (int i = 0; i < numbers.size(); ++i) {
            auto offset = (abs(target - numbers[i])) % LEN;
            auto &hash_row = hash_table[offset];
            
            auto end_pos = find(hash_row.begin(), hash_row.end(), (target - numbers[i]));
            if (end_pos != hash_row.end()) {
                /* find it */
                result.push_back(hash_table2[offset][end_pos - hash_row.begin()]);
                result.push_back(i + 1);
                break;
            } else {
                auto new_offset = abs(numbers[i]) % LEN;
                hash_table[new_offset].push_back(numbers[i]);
                hash_table2[new_offset].push_back(i + 1);
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> cases = {2,3,4};
//    vector<int> cases = {0,4,3,0};
//    vector<int> cases = {-1,-2,-3,-4,-5};
//    vector<int> cases = {2, 11, 7, 15, 9};
    
    Solution *so = new Solution;
    
    auto re = so->twoSum(cases, 6);
    
    for (auto i : re) {
        cout << i << endl;
    }
    
    return 0;
}
