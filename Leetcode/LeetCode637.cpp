// LeetCode 637 二叉树的层平均值

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// 先层次遍历 存储
class Solution {
   public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<vector<int>> nodes;

        function<void(TreeNode *, int)> level_order = [&](TreeNode *root,
                                                          int depth) {
            if (root == nullptr) return;
            if (nodes.size() <= depth) {
                nodes.emplace_back(vector<int>{});
            }
            nodes[depth].push_back(root->val);
            level_order(root->left, depth + 1);
            level_order(root->right, depth + 1);
        };

        level_order(root, 0);

        vector<double> result;
        for (auto &level : nodes) {
            int n = level.size();
            double aver =
                accumulate(level.begin(), level.end(), 0.0) / (double)n;
            result.push_back(aver);
        }
        return result;
    }
};

// 边遍历边计算
class Solution2 {
   public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<int> count;
        vector<double> sum;

        function<void(TreeNode *, int)> order = [&](TreeNode *root, int depth) {
            if (root == nullptr) return;
            if (depth == count.size()) {
                count.push_back(0);
                sum.push_back(0.0);
            }
            ++count[depth];
            sum[depth] += root->val;

            order(root->left, depth + 1);
            order(root->right, depth + 1);
        };

        order(root, 0);

        for (int i = 0; i < count.size(); ++i) {
            sum[i] /= count[i];
        }
        return sum;
    }
};