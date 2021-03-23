// 剑指 Offer 07. 重建二叉树

#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   private:
    unordered_map<int, int> inorder_pos;

   public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pre_start,
                    int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) return nullptr;

        int root_elem = preorder[pre_start];
        TreeNode *root = new TreeNode(root_elem);
        int root_index = inorder_pos[root_elem];

        root->left = build(preorder, inorder, pre_start + 1,
                           pre_start + (root_index - in_start), in_start,
                           root_index - 1);
        root->right =
            build(preorder, inorder, pre_start + (root_index - in_start) + 1,
                  pre_end, root_index + 1, in_end);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_pos[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
    }
};