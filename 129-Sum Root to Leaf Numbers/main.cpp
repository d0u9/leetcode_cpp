#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool F(string &val, int &sum, TreeNode *root) {
        if (!root) return true;
        bool left = false, right = false;
        val.push_back(root->val + '0');
        left = F(val,sum, root->left);
        right = F(val, sum, root->right);
        
        if (left && right) {
            
            sum += atoi(val.c_str());
        }
        val.pop_back();
        
        return false;
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string val;
        F(val, sum, root);
        return sum;
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution *so = new Solution;
    TreeNode *root = new TreeNode(1);
    auto re = so->sumNumbers(root);
    return 0;
}
