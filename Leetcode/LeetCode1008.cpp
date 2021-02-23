// LeetCode 1008 前序遍历构造二叉搜索树
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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[start]);
        int pos = start;
        while (pos <= end && preorder[pos] <= preorder[start]) {
            ++pos;
        }
        root->left = build(preorder, start + 1, pos - 1);
        root->right = build(preorder, pos, end);
        return root;
    }
};