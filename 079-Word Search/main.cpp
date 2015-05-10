//
//  main.cpp
//  leetcode-0079
//
//  Created by Douglas Su on 5/10/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    bool foo(vector<vector<char>>& board, int i, int j, string& word, int pos, set<pair<int, int>>& path) {
        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1)
            return false;
        if (board[i][j] != word[pos]) return false;
        if (!path.insert(make_pair(i, j)).second) return false;
        if (pos == word.size() - 1) return true;
        for (int k = 0; k < 4; ++k) {
            if (k == 0) {
                if (foo(board, i - 1, j, word, pos + 1, path))
                    return true;
            }
            else if (k == 1) {
                if (foo(board, i + 1, j, word, pos + 1, path))
                    return true;
            }
            else if (k == 2) {
                if (foo(board, i, j - 1, word, pos + 1, path))
                    return true;
            }
            else if (k == 3) {
                if (foo(board, i, j + 1, word, pos + 1, path))
                    return true;
            }
        }
        path.erase(make_pair(i, j));
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> path;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (foo(board, i, j, word, 0, path))
                        return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    vector<vector<char>> input;
    vector<char> row;
    row = {'A', 'B', 'C', 'E'};
    input.push_back(row);
//    row = {'S', 'F', 'C', 'S'};
//    input.push_back(row);
//    row = {'A', 'D', 'E', 'E'};
//    input.push_back(row);

    Solution *so = new Solution;
    auto re = so->exist(input, "A");

    cout << re <<endl;

    return 0;
}
