// LeetCode 865 具有所有最深节点的最小子树

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
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int max_depth = -1;
    TreeNode* ans = nullptr;
    auto dfs = [&](this auto&& dfs, TreeNode* root, int cur_depth) {
      if (!root) {
        max_depth = max(max_depth, cur_depth);
        return cur_depth;
      }
      int left_depth = dfs(root->left, cur_depth + 1);
      int right_depth = dfs(root->right, cur_depth + 1);

      if (left_depth == right_depth && left_depth == max_depth) {
        ans = root;
      }
      return max(left_depth, right_depth);
    };
    dfs(root, 0);
    return ans;
  }
};