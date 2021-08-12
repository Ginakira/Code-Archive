// 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
        int root_val = root->val, p_val = p->val, q_val = q->val;
        if (p_val < root_val && q_val < root_val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p_val > root_val && q_val > root_val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
        return nullptr;
    }
};