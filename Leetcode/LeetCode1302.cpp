// LeetCode 1302 层数最深叶子节点的和

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
    int max_depth_ = 0;
    int max_depth_sum_ = 0;

    void dfs(TreeNode *root, int depth) {
        if (!root) {
            return;
        }
        if (depth > max_depth_) {
            max_depth_sum_ = root->val;
            max_depth_ = depth;
        } else if (depth == max_depth_) {
            max_depth_sum_ += root->val;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

   public:
    int deepestLeavesSum(TreeNode *root) {
        dfs(root, 0);
        return max_depth_sum_;
    }
};