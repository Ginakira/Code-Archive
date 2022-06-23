// LeetCode 515 在每个树行中找最大值

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

class Solution {
   private:
    void level_order(TreeNode *root, int depth, vector<int> &max_vals) {
        if (root == nullptr) {
            return;
        }
        if (max_vals.size() == depth) {
            max_vals.emplace_back(numeric_limits<int>::min());
        }
        max_vals[depth] = max(max_vals[depth], root->val);
        level_order(root->left, depth + 1, max_vals);
        level_order(root->right, depth + 1, max_vals);
    }

   public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> max_vals;
        level_order(root, 0, max_vals);
        return max_vals;
    }
};