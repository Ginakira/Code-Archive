// LeetCode 938 二叉搜索树的范围和
#include <queue>
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

// DFS
class Solution {
   public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return 0;
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        return root->val + rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};

// BFS
class Solution2 {
   public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return 0;
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->val >= low && node->val <= high) {
                sum += node->val;
            }
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        return sum;
    }
};