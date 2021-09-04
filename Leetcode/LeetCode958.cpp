// LeetCode 958 二叉树的完全性检验

#include <algorithm>
#include <numeric>
#include <queue>
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
    bool isCompleteTree(TreeNode *root) {
        if (root == nullptr) return true;
        queue<tuple<TreeNode *, int>> q;
        q.emplace(root, 1);

        int node_count = 0;
        while (!q.empty()) {
            auto [node, serial] = q.front();
            q.pop();
            ++node_count;
            if (serial != node_count) {
                return false;
            }
            if (node->left != nullptr) {
                q.emplace(node->left, serial * 2);
            }
            if (node->right != nullptr) {
                q.emplace(node->right, serial * 2 + 1);
            }
        }
        return true;
    }
};