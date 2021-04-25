// LeetCode 897 递增顺序搜索树

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   private:
    TreeNode* pre_node;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        root->left = nullptr;
        pre_node->right = root;
        pre_node = root;
        dfs(root->right);
        return;
    }

   public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode d_node, *dummy = &d_node;
        this->pre_node = dummy;
        dfs(root);
        return dummy->right;
    }
};