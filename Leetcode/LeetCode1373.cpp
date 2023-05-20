// LeetCode 1373 二叉搜索子树的最大键值和

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
    constexpr static int kINF = 0x3f3f3f;
    int ans = 0;
    struct SubTree {
        bool isBST{true};
        int minValue{kINF};
        int maxValue{-kINF};
        int sumValue{0};
    };

    SubTree dfs(TreeNode *root) {
        if (!root) {
            return SubTree{};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        SubTree tree;
        if (left.isBST && right.isBST && left.maxValue < root->val &&
            right.minValue > root->val) {
            tree.isBST = true;
            tree.minValue = min(left.minValue, root->val);
            tree.maxValue = max(right.maxValue, root->val);
            tree.sumValue = left.sumValue + right.sumValue + root->val;
            ans = max(ans, tree.sumValue);
        } else {
            tree.isBST = false;
        }
        return tree;
    }

   public:
    int maxSumBST(TreeNode *root) {
        dfs(root);
        return ans;
    }
};