// LeetCode 889 根据前序和后序遍历构造二叉树

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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   private:
    TreeNode* build(const vector<int>& preorder, const vector<int>& postorder,
                    int pre_start, int pre_end, int post_start, int post_end) {
        if (pre_start > pre_end || post_start > post_end) {
            return nullptr;
        }
        int val = preorder[pre_start];
        TreeNode* node = new TreeNode(val);
        if (pre_start == pre_end) {
            return node;
        }
        int ind = find(postorder.begin() + post_start,
                       postorder.begin() + post_end, preorder[pre_start + 1]) -
                  postorder.begin();
        int left_count = ind - post_start + 1;
        node->left = build(preorder, postorder, pre_start + 1,
                           pre_start + left_count, post_start, ind);
        node->right = build(preorder, postorder, pre_start + left_count + 1,
                            pre_end, ind + 1, post_end);
        return node;
    }

   public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        return build(preorder, postorder, 0, preorder.size() - 1, 0,
                     postorder.size() - 1);
    }
};