// LeetCode 1145 二叉树着色游戏

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
   public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        int x_l_count, x_r_count;
        function<int(TreeNode * root)> dfs = [&](TreeNode *root) {
            if (!root) {
                return 0;
            }
            int l_cnt = dfs(root->left);
            int r_cnt = dfs(root->right);
            if (root->val == x) {
                x_l_count = l_cnt;
                x_r_count = r_cnt;
            }
            return l_cnt + r_cnt + 1;
        };
        dfs(root);
        return max({x_l_count, x_r_count, n - x_l_count - x_r_count - 1}) >
               n / 2;
    }
};