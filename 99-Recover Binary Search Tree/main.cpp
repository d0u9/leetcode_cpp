#inlcude <iostream>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL || q == NULL) {
			return (p == q);
		}
		if (p->val != q->val) return false;
		auto left = isSameTree(p->left, q->left);
		auto right = isSameTree(p->right, q->right);
		if(left && right) return true;
		else return false;
	}
};


int main(int argc, char *argv[])
{
	
	return 0;
}
