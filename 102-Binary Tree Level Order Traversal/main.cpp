//
//  main.cpp
//  leetcode-0102
//
//  Created by Douglas Su on 8/31/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    void F(vector<vector<int>> &ret, vector<TreeNode *> upper) {
        if (upper.empty()) return;
        vector<int> val;
        vector<TreeNode *> level;
        for (auto n : upper) {
            if (n) val.push_back(n->val);
            if (n->left) level.push_back(n->left);
            if (n->right) level.push_back(n->right);
        }
        ret.push_back(val);
        F(ret, level);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        vector<TreeNode *> top;
        top.push_back(root);
        F(ret, top);
        return ret;
    }
};

TreeNode * create_tree(vector<string> input) {
    TreeNode * root = new TreeNode(std::atoi(input[0].c_str()));
    vector<TreeNode *> layer1, layer2;
    layer1.push_back(root);
    for (int i = 1, layer_select = 0; ;) {
        if (layer_select % 2 == 0) {    //add to layer2
            for (auto n : layer1) {
                if (input[i] == "null") n->left = NULL;
                else {
                    n->left = new TreeNode(std::atoi(input[i].c_str()));
                    layer2.push_back(n->left);
                }
                i++;
                if (i >= input.size()) return root;
                if (input[i] == "null") n->right = NULL;
                else {
                    n->right = new TreeNode(std::atoi(input[i].c_str()));
                    layer2.push_back(n->right);
                }
                i++;
                if (i >= input.size()) return root;
            }
            layer_select++;
            layer1.clear();
        }
        if (layer_select % 2 == 1) {    //add to layer1
            for (auto n : layer2) {
                if (input[i] == "null") n->left = NULL;
                else {
                    n->left = new TreeNode(std::atoi(input[i].c_str()));
                    layer1.push_back(n->left);
                }
                i++;
                if (i >= input.size()) return root;
                if (input[i] == "null") n->right = NULL;
                else {
                    n->right = new TreeNode(std::atoi(input[i].c_str()));
                    layer1.push_back(n->right);
                }
                i++;
                if (i >= input.size()) return root;
            }
            layer_select++;
            layer2.clear();
        }
        return root;
    }
}

int main(int argc, char *argv[])
{
    vector<string> input = {"3", "9", "20", "null", "null", "15", "7"};
    TreeNode * root = create_tree(input);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution *so = new Solution;
    auto re = so->levelOrder(root);
    
    return 0;
}
