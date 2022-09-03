// LeetCode 998 最大二叉树II

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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (val > root->val) {
            TreeNode *node = new TreeNode(val, root, nullptr);
            return node;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};