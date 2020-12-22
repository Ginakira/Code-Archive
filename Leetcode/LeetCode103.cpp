// LeetCode 103 二叉树的锯齿形层序遍历
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution1: 递归按层存储所有二叉树节点 奇数层倒序插入（头插）
// 树根为第0层  8ms
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> nodes;
        pushNodes(nodes, root, 0);
        return nodes;
    }

    void pushNodes(vector<vector<int>> &nodes, TreeNode *root, int depth) {
        if (!root) return;
        if (nodes.size() <= depth) nodes.emplace_back();
        if (depth & 1) {
            nodes[depth].insert(nodes[depth].begin(), root->val);
        } else {
            nodes[depth].emplace_back(root->val);
        }
        pushNodes(nodes, root->left, depth + 1);
        pushNodes(nodes, root->right, depth + 1);
        return;
    }
};