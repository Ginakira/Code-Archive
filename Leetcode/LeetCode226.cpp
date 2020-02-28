// 翻转二叉树
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // 其实与交换左右子树同理
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* t = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(t);
        return root;
    }
};

// 0ms 交换左右子树，然后递归反转两个子树即可
class Solution2 {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};