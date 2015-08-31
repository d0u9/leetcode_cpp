#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool left = true, right = false;
	void F(vector<vector<int>> &ret, deque<TreeNode *> last_level, bool direction) {
		if (last_level.size() == 0) return;
		deque<TreeNode *> level;
		vector<int> l;
		while (last_level.size()) {
			TreeNode *cur = NULL, *left = NULL, *right = NULL;
			if (direction) { // start from the left, i.e. the front of level
				cur = last_level.front();
				last_level.pop_front();
				if (cur->left) level.push_back(cur->left);
				if (cur->right) level.push_back(cur->right);
			} else {
				cur = last_level.back();
				last_level.pop_back();
				if (cur->right) level.push_front(cur->right);
				if (cur->left) level.push_front(cur->left);
			}
			l.push_back(cur->val);
		}
		ret.push_back(l);
		F(ret, level, !direction);
	}
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root) return ret;
		deque<TreeNode *> top;
		top.push_back(root);
		F(ret, top, left);
		return ret;
	}
};

TreeNode * create_tree(vector<string> input) {
	TreeNode * root = new TreeNode(std::atoi(input[0].c_str()));
	vector<TreeNode *> layer1, layer2;
	layer1.push_back(root);
	for (int i = 1, layer_select = 0; ;) {
		if (layer_select % 2 == 0) {    //add to layer2
			for (auto n : layer1) {
				if (input[i] == "null") n->left = NULL;
				else {
					n->left = new TreeNode(std::atoi(input[i].c_str()));
					layer2.push_back(n->left);
				}
				i++;
				if (i >= input.size()) return root;
				if (input[i] == "null") n->right = NULL;
				else {
					n->right = new TreeNode(std::atoi(input[i].c_str()));
					layer2.push_back(n->right);
				}
				i++;
				if (i >= input.size()) return root;
			}
			layer_select++;
			layer1.clear();
		}
		if (layer_select % 2 == 1) {    //add to layer1
			for (auto n : layer2) {
				if (input[i] == "null") n->left = NULL;
				else {
					n->left = new TreeNode(std::atoi(input[i].c_str()));
					layer1.push_back(n->left);
				}
				i++;
				if (i >= input.size()) return root;
				if (input[i] == "null") n->right = NULL;
				else {
					n->right = new TreeNode(std::atoi(input[i].c_str()));
					layer1.push_back(n->right);
				}
				i++;
				if (i >= input.size()) return root;
			}
			layer_select++;
			layer2.clear();
		}
		return root;
	}
}

int main(int argc, char *argv[])
{
	vector<string> input = {"1","2", "3","4","null","null","5"};
	TreeNode * root = create_tree(input);
    
	// insert code here...
	std::cout << "Hello, World!\n";
	Solution *so = new Solution;
	auto re = so->zigzagLevelOrder(root);
    
	return 0;
}
