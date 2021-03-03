// LeetCode 124 二叉树中的最大路径和
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int maxGain(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int leftGain = max(maxGain(root->left), 0);
        int rightGain = max(maxGain(root->right), 0);

        maxSum = max(maxSum, root->val + leftGain + rightGain);

        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode *root) {
        maxGain(root);
        return this->maxSum;
    }

   private:
    int maxSum = INT_MIN;
};