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
	vector<TreeNode *> F(int start, int end) {
		vector<TreeNode *> ret;
		if(start >= end) {
			ret.push_back(nullptr);
			return ret;
		} else {
			for (int i = start; i < end; ++i) {
				auto left = F(start, i);
				auto right = F(i + 1, end);
				for (auto l : left)
					for (auto r : right) {
						TreeNode *node = new TreeNode(i);
						node->left = l;
						node->right = r;
						ret.push_back(node);
					}
			}
		}
		return ret;
	}
    
public:
	vector<TreeNode*> generateTrees(int n) {
		auto ret = F(1, n + 1);
		return ret;
	}
};

int main(int argc, char *argv[])
{
	Solution *so = new Solution;
	auto k = so->generateTrees(3);
	return 0;
}

