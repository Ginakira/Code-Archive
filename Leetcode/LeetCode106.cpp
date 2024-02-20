// LeetCode 106 从中序与后序遍历序列构造二叉树

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
   private:
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder,
                    int in_start, int in_end, int post_start, int post_end) {
        if (in_start > in_end || post_start > post_end) {
            return nullptr;
        }
        int val = postorder[post_end];
        TreeNode* root = new TreeNode(val);
        int ind = find(inorder.begin() + in_start, inorder.begin() + in_end + 1,
                       val) -
                  inorder.begin();
        int left_count = ind - in_start;
        int right_count = in_end - ind;
        root->left =
            build(inorder, postorder, in_start, in_start + left_count - 1,
                  post_start, post_start + left_count - 1);
        root->right = build(inorder, postorder, ind + 1, in_end,
                            post_start + left_count, post_end - 1);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0,
                     postorder.size() - 1);
    }
};