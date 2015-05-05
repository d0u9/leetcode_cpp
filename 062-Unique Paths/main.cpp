//
//  main.cpp
//  leetcode-0062
//
//  Created by Douglas Su on 4/30/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
    void find_next(int m, int n, int i, int j, int& counter, map<pair<int, int>, int>& hash_table) {
        if (i == m && j == n) {
            counter++;
            return;
        }
        auto search = hash_table.find(make_pair(i, j));
        if (search != hash_table.end()) {
            counter += hash_table[make_pair(i, j)];
            return;
        } else {
            auto tmp_counter = counter;
            if (i < m) find_next(m, n, i + 1, j, counter, hash_table);
            if (j < n) find_next(m, n, i, j + 1, counter, hash_table);
            hash_table[make_pair(i, j)] = counter - tmp_counter;
        }
        return;
    }
public:
    int uniquePaths(int m, int n) {
        int counter = 0, i = 1, j = 1;
        map<pair<int, int>, int> hash_table;
        find_next(m, n, i, j, counter, hash_table);
        
        return counter;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    cout << so->uniquePaths(20, 20) << endl;
    
    return 0;
}
