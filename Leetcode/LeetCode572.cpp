// LeetCode 572 另一颗树的子树
#include <algorithm>
#include <numeric>
#include <string>
#include <queue>
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
    bool isSameTree(TreeNode *ra, TreeNode *rb) {
        if (ra == nullptr && rb == nullptr) return true;
        if (ra == nullptr || rb == nullptr) return false;
        if (ra->val != rb->val) return false;
        return isSameTree(ra->left, rb->left) &&
               isSameTree(ra->right, rb->right);
    }

   public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) return false;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (isSameTree(node, subRoot)) return true;
            if (node->left != nullptr) {
                que.push(node->left);
            }
            if (node->right != nullptr) {
                que.push(node->right);
            }
        }
        return false;
    }
};

class Solution2 {
private:
    bool is_same(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        } else if (!a || !b) {
            return false;
        }
        if (a->val != b->val) {
            return false;
        }
        return is_same(a->left, b->left) && is_same(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return !subRoot;
        }
        return is_same(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};