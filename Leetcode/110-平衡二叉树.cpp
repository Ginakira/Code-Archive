#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//自顶向下的递归 时间复杂度O(nlogn)
class Solution {
   public:
    int countDeep(TreeNode *root) {
        if (!root) return 0;
        return max(countDeep(root->left), countDeep(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
               abs(countDeep(root->left) - countDeep(root->right)) <= 1;
    }
};