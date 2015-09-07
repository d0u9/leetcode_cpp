#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int F(TreeNode *root) {
		if (!root->left && !root->right) return 1;
		int left = (root->left)? F(root->left) : 0;
		if (left < 0) return -1;
		int right = (root->right) ? F(root->right) : 0;
		if (right < 0) return -1;
		if (abs(left - right) > 1) return -1;
		else return max(left, right) + 1;
	}
public:
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		return (F(root) > 0);
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}

