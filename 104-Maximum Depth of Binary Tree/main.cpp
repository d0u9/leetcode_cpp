#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int F(TreeNode * root) {
		if (!root) return 0;
		auto a = F(root->left);
		auto b = F(root->right);
		return max(a, b) + 1;
	}
public:
	int maxDepth(TreeNode* root) {
		return F(root);
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}
