// LeetCode 337 打家劫舍III

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
    unordered_map<TreeNode *, int> select, unselect;

    void dfs(TreeNode *node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        select[node] = node->val + unselect[node->left] + unselect[node->right];
        unselect[node] = max(select[node->left], unselect[node->left]) +
                         max(select[node->right], unselect[node->right]);
    }

   public:
    int rob(TreeNode *root) {
        dfs(root);
        return max(select[root], unselect[root]);
    }
};

class Solution2 {
   private:
    struct Result {
        int selected;
        int not_selected;
    };

    Result dfs(TreeNode *node) {
        if (!node) {
            return {};
        }
        auto lres = dfs(node->left);
        auto rres = dfs(node->right);
        Result result;
        result.selected = node->val + lres.not_selected + rres.not_selected;
        result.not_selected = max(lres.selected, lres.not_selected) +
                              max(rres.selected, rres.not_selected);
        return result;
    }

   public:
    int rob(TreeNode *root) {
        auto result = dfs(root);
        return max(result.selected, result.not_selected);
    }
};