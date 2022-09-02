// LeetCode 687 最长同值路径

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
    int max_dis = 0;
    int helper(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left_child_dis = helper(root->left),
            right_child_dis = helper(root->right);
        int left_dis = 0, right_dis = 0;
        if (root->left && root->val == root->left->val) {
            left_dis = left_child_dis + 1;
        }
        if (root->right && root->val == root->right->val) {
            right_dis = right_child_dis + 1;
        }
        max_dis = max(max_dis, left_dis + right_dis);
        return max(left_dis, right_dis);
    }

   public:
    int longestUnivaluePath(TreeNode *root) {
        helper(root);
        return max_dis;
    }
};