struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    // Way 2
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        bool lflag = hasPathSum(root->left, sum - root->val);
        bool rflag = hasPathSum(root->right, sum - root->val);
        return lflag || rflag;
    }
    // Way 1
    bool myPath(TreeNode *root, int sum) {
        if (!root->left && !root->right) {
            if (sum == 0)
                return true;
            else
                return false;
        }
        if (!root->left) {
            return myPath(root->right, sum - root->right->val);
        } else if (!root->right) {
            return myPath(root->left, sum - root->left->val);
        } else {
            return myPath(root->left, sum - root->left->val) ||
                   myPath(root->right, sum - root->right->val);
        }
    }

    bool hasPathSum1(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        return myPath(root, sum - root->val);
    }
};