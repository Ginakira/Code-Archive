// LeetCode 103 二叉树的锯齿形层序遍历
#include <algorithm>
#include <deque>
#include <queue>
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

// Solution2: BFS + 双端队列
class Solution2 {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};

        queue<TreeNode *> que;
        vector<vector<int>> result;
        que.push(root);

        bool is_normal_order = true;
        while (!que.empty()) {
            deque<int> dq;
            int node_count = que.size();
            for (int i = 0; i < node_count; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (is_normal_order) {
                    dq.push_back(node->val);
                } else {
                    dq.push_front(node->val);
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            is_normal_order = !is_normal_order;
            result.emplace_back(dq.begin(), dq.end());
        }
        return result;
    }
};