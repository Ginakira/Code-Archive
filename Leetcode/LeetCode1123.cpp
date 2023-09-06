// LeetCode 1123 最深叶节点的最近公共祖先

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
    std::tuple<int, TreeNode *> dfs(TreeNode *root) {
        if (!root) {
            return {0, nullptr};
        }
        auto [l_depth, l_node] = dfs(root->left);
        auto [r_depth, r_node] = dfs(root->right);
        if (l_depth > r_depth) {
            return {l_depth + 1, l_node};
        } else if (l_depth < r_depth) {
            return {r_depth + 1, r_node};
        }
        return {l_depth + 1, root};
    }

   public:
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        auto [_, node] = dfs(root);
        return node;
    }
};
