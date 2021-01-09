// LeetCode 404 左叶子之和
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归
class Solution {
   public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) return 0;
        return (root->left && !root->left->left && !root->left->right
                    ? root->left->val
                    : sumOfLeftLeaves(root->left)) +
               sumOfLeftLeaves(root->right);
    }
};