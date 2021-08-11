// 剑指 Offer 28. 对称的二叉树

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   private:
    bool isMirror(TreeNode *root_a, TreeNode *root_b) {
        if (root_a == nullptr && root_b == nullptr) return true;
        if (root_a == nullptr || root_b == nullptr) return false;
        return root_a->val == root_b->val &&
               isMirror(root_a->left, root_b->right) &&
               isMirror(root_a->right, root_b->left);
    }

   public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};