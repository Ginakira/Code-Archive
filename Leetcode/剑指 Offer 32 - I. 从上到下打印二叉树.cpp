// 剑指 Offer 32 - I. 从上到下打印二叉树

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> levelOrder(TreeNode *root) {
        if (root == nullptr) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> result;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            result.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        return result;
    }
};