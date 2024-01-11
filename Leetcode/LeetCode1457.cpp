// LeetCode 1457 二叉树中的伪回文路径

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
    void dfs(TreeNode *root, int &ans, uint16_t cur_state) {
        if (!root) {
            return;
        }
        cur_state ^= (1 << root->val);
        if (!root->left && !root->right) {
            if (__builtin_popcount(cur_state) <= 1) {
                ++ans;
            }
        } else {
            dfs(root->left, ans, cur_state);
            dfs(root->right, ans, cur_state);
        }
    }

   public:
    int pseudoPalindromicPaths(TreeNode *root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
};