#include <iostream>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		TreeLinkNode *a1 = root, *a2 = a1->left, *a3 = a1->right;
		TreeLinkNode *left_most = a1->left;
		while (left_most) {
			a2->next = a3;
			if (a1->next) {
				a1 = a1->next;
				a3->next = a1->left;
				a2 = a1->left;
				a3 = a1->right;
			} else {
				a1 = left_most;
				left_most = a1->left;
				a2 = a1->left;
				a3 = a1->right;
			}
		}
	}
};


