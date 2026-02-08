// 平衡二叉树
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 自顶向下的递归 时间复杂度O(nlogn)
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

// 自底向上的递归 时间复杂度O(n)
class Solution2 {
 public:
  bool isBalancedHelper(TreeNode *root, int &height) {
    if (!root) {
      height = 0;
      return true;
    }
    int left = 0, right = 0;
    if (isBalancedHelper(root->left, left) &&
        isBalancedHelper(root->right, right) && abs(left - right) < 2) {
      height = max(left, right) + 1;
      return true;
    } else {
      return false;
    }
  }

  bool isBalanced(TreeNode *root) {
    int height = 0;
    return isBalancedHelper(root, height);
  }
};

class Solution3 {
 public:
  bool isBalanced(TreeNode *root) {
    auto dfs = [](this auto &&dfs, TreeNode *root) -> std::pair<bool, int> {
      if (!root) {
        return {true, 0};
      }
      bool balance = true;
      auto [bl, dl] = dfs(root->left);
      auto [br, dr] = dfs(root->right);
      if (!bl || !br) {
        balance = false;
      } else {
        balance = abs(dl - dr) <= 1;
      }
      return {balance, max(dl, dr) + 1};
    };
    return dfs(root).first;
  }
};