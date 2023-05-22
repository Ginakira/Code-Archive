// LeetCode 1080 根到叶路径上的不足节点

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
   private:
    bool CheckSufficientSubset(TreeNode *root, int sum, int limit) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return root->val + sum >= limit;
        }
        sum += root->val;
        bool left_valid = CheckSufficientSubset(root->left, sum, limit);
        bool right_valid = CheckSufficientSubset(root->right, sum, limit);
        if (!left_valid) {
            root->left = nullptr;
        }
        if (!right_valid) {
            root->right = nullptr;
        }
        return left_valid || right_valid;
    }

   public:
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        return CheckSufficientSubset(root, 0, limit) ? root : nullptr;
    }
};