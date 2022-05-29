// LeetCode 1022 从根到叶的二进制数之和

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
   private:
    int sum_;

    void helper(TreeNode *root, int cur_num) {
        if (root == nullptr) {
            return;
        }
        cur_num <<= 1;
        cur_num |= root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum_ += cur_num;
        }
        if (root->left) {
            helper(root->left, cur_num);
        }
        if (root->right) {
            helper(root->right, cur_num);
        }
    }

   public:
    int sumRootToLeaf(TreeNode *root) {
        helper(root, 0);
        return sum_;
    }
};