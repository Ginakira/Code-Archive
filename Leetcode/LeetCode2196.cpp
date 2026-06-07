// LeetCode 2196 根据描述创建二叉树

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
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> nodes;
    int root = 0;
    for (auto& desc : descriptions) {
      int parent = desc[0], child = desc[1], is_left = desc[2];
      root ^= child;
      if (!nodes.count(parent)) {
        nodes[parent] = new TreeNode(parent);
      }
      if (!nodes.count(child)) {
        nodes[child] = new TreeNode(child);
      }
      if (is_left) {
        nodes[parent]->left = nodes[child];
      } else {
        nodes[parent]->right = nodes[child];
      }
    }
    for (auto& [node, _] : nodes) {
      root ^= node;
    }
    return nodes[root];
  }
};