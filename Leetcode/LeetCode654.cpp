// LeetCode 654 最大二叉树

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

   private:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums, int start,
                                         int end) {
        if (start > end) {
            return nullptr;
        }
        int max_pos = start;
        for (int i = max_pos + 1; i <= end; ++i) {
            if (nums[i] > nums[max_pos]) {
                max_pos = i;
            }
        }
        TreeNode *root = new TreeNode(nums[max_pos]);
        root->left = constructMaximumBinaryTree(nums, start, max_pos - 1);
        root->right = constructMaximumBinaryTree(nums, max_pos + 1, end);
        return root;
    }
};