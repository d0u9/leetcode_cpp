#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool F(TreeNode *left, TreeNode *right) {
        if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) return false;
        if (left == NULL && right == NULL) return true;
        if (left->val != right->val) return false;
        return (F(left->left, right->right) && F(left->right, right->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return F(root->left, root->right);
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
    vector<string> input = {"1", "2", "3"};
    TreeNode * root = create_tree(input);
    Solution *so = new Solution;
    auto ret = so->isSymmetric(root);
    
    cout << ret << endl;
    return 0;
}
