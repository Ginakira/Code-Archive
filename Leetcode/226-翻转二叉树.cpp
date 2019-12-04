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
    // my way 8ms
    TreeNode* invertTree1(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        invertTree1(root->left);
        invertTree1(root->right);
        return root;
    }
    // other way
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* t = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(t);
        return root;
    }
};