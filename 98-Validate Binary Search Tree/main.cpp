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
	bool F(struct TreeNode *node, int &maxx, int &minx) {
		if (node->left == NULL && node->right == NULL) {
			minx = maxx = node->val;
			return true;
		}
		int m1, m2, m3, m4;
		m1 = m2 = m3 = m4 = node->val;
		if (node->left != NULL) {
			int a, i;
			auto ret = F(node->left, a, i);
			if (!ret) return false;
			if (a >= node->val) return false;
			m1 = max(node->val, a);
			m2 = min(node->val, i);
		}
		if (node->right != NULL) {
			int a, i;
			auto ret = F(node->right, a, i);
			if (!ret) return false;
			if (i <= node->val) return false;
			m3 = max(node->val, a);
			m4 = min(node->val, i);
		}
		maxx = max(m1, m3);
		minx = min(m2, m4);
		return true;
	}
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		int a, b;
		return F(root, a, b);
	}
};

int main(int argc, char *argv[])
{
	Solution *so = new Solution;
	auto re = so->isValidBST(NULL);
	cout << re << endl;
	return 0;
}
