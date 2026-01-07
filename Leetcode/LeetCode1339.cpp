// LeetCode 1339 分裂二叉树的最大乘积

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

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
  int maxProduct(TreeNode* root) {
    int sum = 0;
    auto cal_sum = [&](this auto&& self, TreeNode* root) {
      if (!root) {
        return;
      }
      sum += root->val;
      self(root->left);
      self(root->right);
    };
    cal_sum(root);

    long long ans = 0;
    constexpr static int MOD = 1e9 + 7;
    auto dfs = [&](this auto&& self, TreeNode* root, int cur_sum) -> long long {
      if (!root) {
        return 0;
      }
      long long l_sum = self(root->left, cur_sum);
      long long r_sum = self(root->right, cur_sum);
      ans = max({ans, l_sum * (sum - l_sum), r_sum * (sum - r_sum)});
      return l_sum + r_sum + root->val;
    };
    dfs(root, 0);
    return ans % MOD;
  }
};