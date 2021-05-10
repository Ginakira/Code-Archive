// LeetCode 872 叶子相似的树
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   private:
    void helper(TreeNode* root, vector<int>& leaf) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            leaf.emplace_back(root->val);
            return;
        }
        helper(root->left, leaf);
        helper(root->right, leaf);
        return;
    }

   public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        helper(root1, leaf1);
        helper(root2, leaf2);
        return leaf1 == leaf2;
    }
};