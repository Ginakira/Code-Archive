// LeetCode 1448 统计二叉树中好节点的数目

#include <algorithm>
#include <array>
#include <limits>
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
    int dfs(TreeNode *root, int cur_max) {
        if (!root) {
            return 0;
        }
        int ret = 0;
        int max_val = cur_max;
        if (root->val >= cur_max) {
            ret = 1;
            cur_max = root->val;
        }

        ret += dfs(root->left, cur_max);
        ret += dfs(root->right, cur_max);
        return ret;
    }

   public:
    int goodNodes(TreeNode *root) {
        return dfs(root, std::numeric_limits<int>::min());
    }
};
