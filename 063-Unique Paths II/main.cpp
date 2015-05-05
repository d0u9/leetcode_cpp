//
//  main.cpp
//  leetcode-0063
//
//  Created by Douglas Su on 5/3/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void find_next(vector<vector<int>> &obstacleGrid, vector<vector<int>> &map, int& counter, int x, int y) {
        if (x == obstacleGrid.size() - 1 && y == obstacleGrid[0].size() - 1) {
            counter++;
            return;
        }
        
        if (map[x][y] == -1) return;
        if (map[x][y] > 0) {
            counter += map[x][y];
            return;
        } else {
            auto tmp = counter;
            if (x < obstacleGrid.size()- 1 && obstacleGrid[x + 1][y] != 1)
                find_next(obstacleGrid, map, counter, x + 1, y);
            if (y < obstacleGrid[0].size() - 1 && obstacleGrid[x][y + 1] != 1)
                find_next(obstacleGrid, map, counter, x, y + 1);
            map[x][y] = (counter - tmp) ? (counter - tmp) : -1;
        }
        return;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> map;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            auto k = obstacleGrid[0].size();
            vector<int> row (k, 0);
            map.push_back(row);
        }
        
        int counter = 0;
        find_next(obstacleGrid, map, counter, 0, 0);
        return counter;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<vector<int>> obstacleGrid;
    vector<int> row1 = {0,0,0,0,0};
    obstacleGrid.push_back(row1);
    vector<int> row2 = {0,0,0,0,1};
    obstacleGrid.push_back(row2);
    vector<int> row3 = {0,0,0,1,0};
    obstacleGrid.push_back(row3);
    vector<int> row4 = {0,0,1,0,0};
    obstacleGrid.push_back(row4);
    
    Solution *so = new Solution;
    auto re =  so->uniquePathsWithObstacles(obstacleGrid);
    
    cout << re << endl;
    
    return 0;
}
