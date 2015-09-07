#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool hasPathSum(TreeNode *root, int sum, int already) {
		if (!root) return false;
		already += root->val;
		if (already == sum && !root->left && !root->right) return true;
		//left first
		bool left = hasPathSum(root->left, sum, already);
		if (left) return true;
		bool right = hasPathSum(root->right, sum, already);
		if (right) return true;

		return false;
	}
	
public:
	bool hasPathSum(TreeNode* root, int sum) {
		return hasPathSum(root, sum, 0);
	}

};

int main(int argc, char *argv[])
{
	
	return 0;
}



