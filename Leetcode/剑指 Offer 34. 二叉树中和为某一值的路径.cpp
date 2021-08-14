// 剑指 Offer 34. 二叉树中和为某一值的路径

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
    void dfs(TreeNode *root, int target, vector<int> &path,
             vector<vector<int>> &result) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr &&
            root->val == target) {
            result.push_back(path);
            path.pop_back();
            return;
        }
        dfs(root->left, target - root->val, path, result);
        dfs(root->right, target - root->val, path, result);
        path.pop_back();
    }

   public:
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        if (root == nullptr) return {};
        vector<int> path;
        vector<vector<int>> result;
        dfs(root, target, path, result);
        return result;
    }
};