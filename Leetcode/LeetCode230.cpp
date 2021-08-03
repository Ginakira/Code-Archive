// LeetCode 230 二叉搜索树中第K小的元素

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 中序遍历
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
    int kthSmallest(TreeNode *root, int k) {
        vector<int> nums;

        function<void(TreeNode *)> inorder = [&](TreeNode *root) {
            if (root == nullptr) return;
            if (nums.size() == k) return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        };

        inorder(root);
        return nums[k - 1];
    }
};