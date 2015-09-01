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
	typedef vector<int>::iterator it;
	TreeNode *F(it begin, it end) {
		if (begin == end) return NULL;
		auto mid = begin + (end - begin) / 2;
		TreeNode *root = new TreeNode(*mid);
		root->left = F(begin, mid);
		root->right = F(mid + 1, end);
		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return F(nums.begin(), nums.end());
	}
};



int main(int argc, char *argv[])
{
	Solution *so = new Solution;
	vector<int> nums = {1, 3, 4, 5, 6, 9, 10};
	auto re = so->sortedArrayToBST(nums);
	return 0;
}
