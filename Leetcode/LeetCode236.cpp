// LeetCode 236 二叉树的最近公共祖先

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        // 如果root不是 则分别假定二者的最近公共祖先在左子树和右子树 递归查询
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
        return nullptr;
    }
};