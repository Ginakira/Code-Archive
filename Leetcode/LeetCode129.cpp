// LeetCode 129 求根节点到叶结点数字之和

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
    int sum = 0;

    void sum_tree(TreeNode *root, int cur_sum) {
        if (root == nullptr) return;
        int num = cur_sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
            return;
        }
        sum_tree(root->left, num);
        sum_tree(root->right, num);
    }

   public:
    int sumNumbers(TreeNode *root) {
        if (root == nullptr) return 0;
        sum_tree(root, 0);
        return sum;
    }
};