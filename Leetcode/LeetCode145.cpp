// LeetCode 145 二叉树的后序遍历

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        function<void(TreeNode *)> postorder = [&](TreeNode *root) -> void {
            if (root == nullptr) return;
            postorder(root->left);
            postorder(root->right);
            result.emplace_back(root->val);
        };
        postorder(root);
        return result;
    }
};