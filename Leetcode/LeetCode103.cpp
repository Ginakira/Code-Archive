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

// Solution1: 先递归按层存储所有二叉树节点 然后翻转下标奇数层
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> nodes;
        pushNodes(nodes, root, 0);
        for (int i = 0; i < nodes.size(); ++i) {
            if (i % 2) reverse(nodes[i].begin(), nodes[i].end());
        }
        return nodes;
    }

    void pushNodes(vector<vector<int>> &nodes, TreeNode *root, int depth) {
        if (!root) return;
        if (nodes.size() <= depth) nodes.emplace_back();
        nodes[depth].emplace_back(root->val);
        pushNodes(nodes, root->left, depth + 1);
        pushNodes(nodes, root->right, depth + 1);
        return;
    }
};