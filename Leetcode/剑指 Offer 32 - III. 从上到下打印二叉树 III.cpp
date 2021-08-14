// 剑指 Offer 32 - III. 从上到下打印二叉树 III

#include <algorithm>
#include <deque>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) return {};
        vector<vector<int>> result;
        queue<tuple<TreeNode *, int>> q;
        deque<int> nodes;
        bool normal_order = true;
        int current_depth = 0;

        q.emplace(root, 0);
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            if (node->left != nullptr) q.emplace(node->left, depth + 1);
            if (node->right != nullptr) q.emplace(node->right, depth + 1);
            if (normal_order) {
                nodes.push_back(node->val);
            } else {
                nodes.push_front(node->val);
            }

            if (q.empty() || get<1>(q.front()) != current_depth) {
                ++current_depth;
                result.emplace_back(nodes.begin(), nodes.end());
                nodes.clear();
                normal_order = !normal_order;
            }
        }
        return result;
    }
};