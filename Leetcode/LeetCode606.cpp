// LeetCode 606 根据二叉树创建字符串

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
    string tree2str(TreeNode *root) {
        if (root == nullptr) return {};
        string result = to_string(root->val);
        if (root->left || root->right) {
            result += "(" + tree2str(root->left) + ")";
        }
        if (root->right) {
            result += "(" + tree2str(root->right) + ")";
        }
        return result;
    }
};