// 剑指 Offer 55 - II. 平衡二叉树

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   private:
    int max_depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(max_depth(root->left), max_depth(root->right)) + 1;
    }

   public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
               abs(max_depth(root->left) - max_depth(root->right)) <= 1;
    }
};