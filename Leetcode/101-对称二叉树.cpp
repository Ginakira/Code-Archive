struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool isSame(TreeNode *a, TreeNode *b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->val == b->val && isSame(a->right, b->left) &&
               isSame(a->left, b->right);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSame(root->left, root->right);
    }
};