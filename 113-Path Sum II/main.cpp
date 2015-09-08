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
	bool F(TreeNode *root, vector<vector<int>> &ret, vector<int> &haved, int sum, int haved_sum) {
		if (!root) {
			return false;
		}
		haved.push_back(root->val);
		if (!root->left && !root->right) {
			if (haved_sum + root->val == sum) {ret.push_back(haved); haved.pop_back(); return true;}
			else { haved.pop_back(); return false; }
		}
		auto left = F(root->left, ret, haved, sum, haved_sum + root->val);
		auto right = F(root->right, ret, haved, sum, haved_sum + root->val);
		haved.pop_back();
		return true;
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		vector<int> haved;
		if (!root) return ret;
		F(root, ret, haved, sum, 0);
		return ret;
	}
};
