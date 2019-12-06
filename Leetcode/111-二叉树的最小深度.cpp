#include <iostream>
#define unlikely(x) __builtin_expect(!!(x), 0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (unlikely(!root)) return 0;
        if (!root->left && root->right) return 1 + minDepth(root->right);
        if (root->left && !root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};