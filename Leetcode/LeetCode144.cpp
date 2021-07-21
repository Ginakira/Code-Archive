// LeetCode 144 二叉树的前序遍历

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        function<void(TreeNode *)> preorder = [&](TreeNode *root) -> void {
            if (root == nullptr) {
                return;
            }
            result.emplace_back(root->val);
            preorder(root->left);
            preorder(root->right);
        };
        preorder(root);
        return result;
    }
};