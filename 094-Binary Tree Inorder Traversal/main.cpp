#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	// TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	void recursive(TreeNode *node, vector<int> &result) {
		if (node == NULL) return;
		if (node->left != NULL) {
			recursive(node->left, result);
		}
		result.push_back(node->val);
		if (node->right != NULL) {
			recursive(node->right, result);
		}
	}
       
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		recursive(root, ret);
		return ret;
	}
};

int main(int argc, char *argv[])
{
	vector<int> input = {1, #, 2, 3};
	Solution *so = new Solution;

	so->inorderTraversal(NULL);
	
	return 0;
}

