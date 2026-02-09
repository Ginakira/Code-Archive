// LeetCode 1382 将二叉搜索树变平衡

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
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    auto inorder = [&nums](this auto&& inorder, TreeNode* root) {
      if (!root) {
        return;
      }
      inorder(root->left);
      nums.emplace_back(root->val);
      inorder(root->right);
    };
    inorder(root);

    auto build = [&nums](this auto&& build, int start, int end) -> TreeNode* {
      if (start == end) {
        return nullptr;
      }
      int mid = (start + end) / 2;
      auto root = new TreeNode(nums[mid]);
      root->left = build(start, mid);
      root->right = build(mid + 1, end);
      return root;
    };
    return build(0, nums.size());
  }
};