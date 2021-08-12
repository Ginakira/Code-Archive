// 剑指 Offer 32 - II. 从上到下打印二叉树 II

#include <algorithm>
#include <numeric>
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
        vector<vector<int>> result;

        function<void(TreeNode *, int)> level_order = [&](TreeNode *root,
                                                          int depth) {
            if (root == nullptr) return;
            if (result.size() == depth) {
                result.emplace_back();
            }

            result[depth].push_back(root->val);
            level_order(root->left, depth + 1);
            level_order(root->right, depth + 1);
        };

        level_order(root, 0);
        return result;
    }
};