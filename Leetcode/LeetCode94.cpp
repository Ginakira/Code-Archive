// LeetCode 94 二叉树的中旭遍历

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;

        function<void(TreeNode *)> inorder = [&](TreeNode *root) -> void {
            if (!root) return;
            inorder(root->left);
            result.emplace_back(root->val);
            inorder(root->right);
        };
        inorder(root);
        return result;
    }
};