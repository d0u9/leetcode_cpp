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
	void F(vector<vector<int>> &ret, vector<TreeNode *> last_level) {
		if (!last_level.size()) return;
		vector<TreeNode *> level;
		vector<int> val;
		for (auto n : last_level) {
			val.push_back(n->val);
			if (n->left) level.push_back(n->left);
			if (n->right) level.push_back(n->right);
		}
		F(ret, level);
		ret.push_back(val);
		return;
	}
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root) return ret;
		vector<TreeNode *> level = {root};
		F(ret, level);
		return ret;
	}
};

int main(int argc, char *argv[])
{
	Solution *so = new Solution;
	auto re = so->levelOrderBottom(NULL);
	return 0;
}




