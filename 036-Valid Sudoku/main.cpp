//
//  main.cpp
//  leetcode-0036
//
//  Created by Douglas Su on 4/16/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unsigned char current_line[9] = {0}, blocks_line[3][9] = {0}, blocks[9][9] = {0};
        for (int i = 0; i < board.size(); ++i) {
            memset(current_line, 0, 9);
            if (i % 3 == 0) {
                memset(blocks_line, 0, 27);
            }
            for (int j = 0; j < board[i].size(); ++j) {
                char current_char = board[i][j];
                if (board[i][j] != '.') {
                    if (current_line[current_char - 0x31]) return false;
                    else current_line[current_char - 0x31] = 1;
                    if (blocks_line[j / 3][current_char - 0x31]) return false;
                    else blocks_line[j / 3][current_char - 0x31] = 1;
                    if (blocks[j][current_char - 0x31]) return false;
                    else blocks[j][current_char - 0x31] = 1;
                }
            }
        }

        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> T = {"....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"};
    vector<vector<char>> input;
    for (int i = 0; i < 9; ++i) {
        vector<char> tmp;
        for (int j = 0; j < 9; ++j) {
            auto k = T[i][j];
            tmp.push_back(k);
        }
        input.push_back(tmp);
    }
    
    Solution *so = new Solution;
    cout << so->isValidSudoku(input) << endl;
    return 0;
}
