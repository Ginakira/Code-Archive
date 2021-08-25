// LeetCode 199 二叉树的右视图

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <tuple>
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
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) return {};
        vector<int> result;
        queue<tuple<TreeNode *, int>> q;
        q.emplace(root, 0);

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            if (depth == result.size()) {
                result.push_back(node->val);
            } else {
                result[depth] = node->val;
            }
            if (node->left != nullptr) {
                q.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                q.emplace(node->right, depth + 1);
            }
        }
        return result;
    }
};