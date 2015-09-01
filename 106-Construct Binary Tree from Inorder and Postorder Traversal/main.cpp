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
    typedef vector<int>::reverse_iterator rit;
    TreeNode * F(it in_begin, it in_end, rit po_begin, rit po_end) {
        if (in_begin == in_end) return NULL;
        TreeNode *root = new TreeNode(*po_begin);
        auto mid = find(in_begin, in_end, *po_begin);
        auto right = in_end - mid - 1;
        
        root->right = F(mid + 1, in_end, po_begin + 1, po_begin + 1 + right);
        root->left = F(in_begin, mid, po_begin + right + 1, po_end);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!inorder.size()) return NULL;
        return F(inorder.begin(), inorder.end(), postorder.rbegin(), postorder.rend());
    }
};

int main(int argc, char *argv[])
{
    Solution *so = new Solution;
    vector<int> inorder   = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> postorder = {0, 2, 4, 3, 1, 7, 8, 6, 5};
    auto re = so->buildTree(inorder, postorder);
    return 0;
}
