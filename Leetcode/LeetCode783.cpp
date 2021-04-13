// LeetCode 783 二叉搜索树节点最小距离
#include <algorithm>
#include <climits>
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

// 中序遍历
class Solution {
   public:
    void dfs(TreeNode *root, int &ans, int &pre) {
        if (root == nullptr) return;
        dfs(root->left, ans, pre);
        if (pre != -1) {
            ans = min(ans, root->val - pre);
        }
        pre = root->val;
        dfs(root->right, ans, pre);
        return;
    }

    int minDiffInBST(TreeNode *root) {
        if (root == nullptr) return 0;
        int ans = INT_MAX, pre = -1;
        dfs(root, ans, pre);
        return ans;
    }
};

// 写麻烦了
class Solution2 {
   private:
    int min_dis = INT_MAX;

   public:
    int minDiffInBST(TreeNode *root) {
        if (root == nullptr) return 0;
        helper(root);
        return min_dis;
    }

    void helper(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            TreeNode *node = root->left;
            while (node->right != nullptr) {
                node = node->right;
            }
            min_dis = min(root->val - node->val, min_dis);
        }
        if (root->right != nullptr) {
            TreeNode *node = root->right;
            while (node->left != nullptr) {
                node = node->left;
            }
            min_dis = min(node->val - root->val, min_dis);
        }
        helper(root->left);
        helper(root->right);
        return;
    }
};