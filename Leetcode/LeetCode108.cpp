// LeetCode 108 将有序数组转换为二叉搜索树
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution1：每次分隔左右两部分递归建树 28ms
class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (right < left) return nullptr;
        int ind = (left + right + 1) >> 1;
        TreeNode* root = new TreeNode(nums[ind]);
        root->left = helper(nums, left, ind - 1);
        root->right = helper(nums, ind + 1, right);
        return root;
    }
};