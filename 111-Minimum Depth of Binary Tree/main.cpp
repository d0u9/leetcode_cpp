#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		int right = (root->right) ? minDepth(root->right) : -1;
		int left = (root->left) ? minDepth(root->left) : -1;

		if (right < 0 && left < 0) return 1;
		if (right < 0) return left + 1;
		if (left < 0) return right + 1;
		return min(left, right) + 1;
	}
};


int main(int argc, char *argv[])
{
	
	return 0;
}
