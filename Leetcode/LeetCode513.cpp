// LeetCode 513 找树左下角的值

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
    TreeNode *ans_node{nullptr};
    int ans_depth{-1};

    void dfs(TreeNode *root, int depth) {
        if (root == nullptr) return;
        if (depth > ans_depth) {
            ans_depth = depth;
            ans_node = root;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

   public:
    int findBottomLeftValue(TreeNode *root) {
        dfs(root, 0);
        return ans_node->val;
    }
};