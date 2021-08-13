
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 你需要返回一个指针，指向root，表示删减去若干个点后，剩下的树
     * @param root TreeNode类 指向二叉树的根
     * @return TreeNode类
     */
    TreeNode* solve(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr || root->right == nullptr) {
            root->left = root->right = nullptr;
            return root;
        }
        solve(root->left);
        solve(root->right);
        return root;
    }
};