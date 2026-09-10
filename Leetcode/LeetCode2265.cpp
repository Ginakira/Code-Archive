// LeetCode 2265 统计值等于子树平均值的节点数

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int averageOfSubtree(TreeNode* root) {
    int ans = 0;
    auto helper = [&ans](this auto&& helper, TreeNode* root) -> pair<int, int> {
      if (!root) {
        return {0, 0};
      }
      int sum = root->val;
      int cnt = 1;
      auto [sl, cl] = helper(root->left);
      auto [sr, cr] = helper(root->right);
      sum += sl + sr;
      cnt += cl + cr;
      if (root->val == floor(sum / cnt)) {
        ++ans;
      }
      return {sum, cnt};
    };
    helper(root);
    return ans;
  }
};