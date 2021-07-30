// LeetCode 653 两数之和IVy - 输入BST

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
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

// 遍历 + 哈希
class Solution {
   public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> st;

        function<bool(TreeNode *)> order = [&](TreeNode *root) -> bool {
            if (root == nullptr) return false;
            int target = k - root->val;
            if (st.count(target)) {
                return true;
            }
            st.insert(root->val);
            return order(root->left) || order(root->right);
        };

        return order(root);
    }
};

// 中序遍历到数组
class Solution2 {
   public:
    bool findTarget(TreeNode *root, int k) {
        vector<int> nums;

        function<void(TreeNode *)> inorder = [&](TreeNode *root) {
            if (root == nullptr) return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        };

        inorder(root);

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                ++left;
            } else {
                --right;
            }
        }
        return false;
    }
};