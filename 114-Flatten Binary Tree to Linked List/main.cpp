#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	void F(TreeNode *root, TreeNode * &last) {
		if (!root) return;

		last = root;
		F(root->left, last);
		if (!root->right) return;
		last->left = root->right;
		root->right = nullptr;
		F(root->left, last);
	}
public:
	void flatten(TreeNode* root) {
		if (!root) return;
		TreeNode * last = nullptr;
		F(root, last);
		auto tmp = root;
		while(tmp->left) {
			tmp->right = tmp->left;
			tmp->left = nullptr;
			tmp = tmp->right;
		}
	}};

int main(int argc, char *argv[])
{
	
	return 0;
}
