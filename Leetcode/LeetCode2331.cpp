// LeetCode 2331 计算布尔二叉树的值

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
   public:
    bool evaluateTree(TreeNode *root) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return root->val;
        }
        bool left_val = evaluateTree(root->left);
        bool right_val = evaluateTree(root->right);
        switch (root->val) {
            case 2:
                return left_val || right_val;
            case 3:
                return left_val && right_val;
            default:
                break;
        }
        return false;
    }
};