// LeetCode 563 二叉树的坡度
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
    int sum = 0;

    int helper(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        sum += abs(left - right);
        return left + right + root->val;
    }

   public:
    int findTilt(TreeNode *root) {
        if (root == nullptr) return 0;
        helper(root);
        return sum;
    }
};