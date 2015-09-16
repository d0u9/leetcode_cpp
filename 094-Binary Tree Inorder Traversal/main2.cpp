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
public:
	vector<int> inorderTraversal(TreeNode* root) {
		int PUSH = 0, POP = 1;
		vector<int> ret;
		vector<TreeNode *> stack;
		TreeNode *tmp_root = root;
		int state = PUSH;
		stack.push_back(root);
		do {
			if (state == PUSH) {
				if (!tmp_root) state = POP;
				stack.push_back(tmp_root);
				tmp_root = tmp_root->left;
			}
			if (state == POP) {
				tmp_root = stack.back();
				stack.pop_back();
				ret.push_back(tmp_root->val);
				tmp_root = PUSH;
				stack.push_back(tmp_root->righ);
			}
		} while (!stack.empty());
		return ret;
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}
