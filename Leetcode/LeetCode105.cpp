// LeetCode 105 从前序与中序便利序列构造二叉树
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
    int n;
    unordered_map<int, int> root_index;

   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        n = preorder.size();
        for (int i = 0; i < n; ++i) {
            root_index[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int pre_start,
                     int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) return nullptr;

        TreeNode *root = new TreeNode(preorder[pre_start]);
        int ind = root_index[root->val];
        root->left = helper(preorder, inorder, pre_start + 1,
                            pre_start + (ind - in_start), in_start, ind - 1);
        root->right =
            helper(preorder, inorder, pre_start + (ind - in_start) + 1, pre_end,
                   ind + 1, in_end);
        return root;
    }
};