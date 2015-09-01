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
    typedef vector<int>::iterator it;
    TreeNode * F(it pre_begin, it pre_end, it in_begin, it in_end) {
        if (pre_begin == pre_end) return NULL;
        TreeNode *root = new TreeNode(*pre_begin);
        it mid = find(in_begin, in_end, *pre_begin);
        auto left = mid - in_begin;
        
        root->left = F(pre_begin + 1, pre_begin + 1 + left, in_begin, mid);
        root->right = F(pre_begin + 1 + left, pre_end, mid + 1, in_end);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) return NULL;
        return F(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};



int main(int argc, char *argv[])
{
    Solution *so = new Solution;
    vector<int> pre = {5, 1, 0, 3, 2, 4, 6, 8, 7};
    vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto r = so->buildTree(pre, in);
    return 0;
}
