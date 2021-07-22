// LeetCode 530 二叉搜索树的最小绝对差

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

// 中序遍历 存储到数组中再遍历
class Solution {
   public:
    int getMinimumDifference(TreeNode *root) {
        vector<int> nums;

        function<void(TreeNode *)> inorder = [&](TreeNode *root) -> void {
            if (root == nullptr) return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        };

        inorder(root);
        int min_val = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            min_val = min(min_val, nums[i] - nums[i - 1]);
        }
        return min_val;
    }
};

// 中序遍历的过程中求解 无需存储
class Solution2 {
   public:
    int getMinimumDifference(TreeNode *root) {
        int pre = -1, ans = INT_MAX;

        function<void(TreeNode *)> inorder = [&](TreeNode *root) -> void {
            if (root == nullptr) return;
            inorder(root->left);
            if (pre == -1) {
                pre = root->val;
            } else {
                ans = min(ans, root->val - pre);
                pre = root->val;
            };
            inorder(root->right);
        };

        inorder(root);

        return ans;
    }
};