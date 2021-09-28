// LeetCode 437 路径总和III

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   private:
    int dfs(TreeNode *root, int target) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 0;
        if (root->val == target) {
            ++ret;
        }
        ret += dfs(root->left, target - root->val);
        ret += dfs(root->right, target - root->val);
        return ret;
    }

   public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        int ans = dfs(root, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};
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
    int dfs(TreeNode *root, int target) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 0;
        if (root->val == target) {
            ++ret;
        }
        ret += dfs(root->left, target - root->val);
        ret += dfs(root->right, target - root->val);
        return ret;
    }

   public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        int ans = dfs(root, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};