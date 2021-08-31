// 剑指 Offer 54. 二叉搜索树的第k大节点

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 常规 中序遍历存储到数组中
class Solution {
   public:
    int kthLargest(TreeNode *root, int k) {
        if (root == nullptr) return -1;
        vector<int> nums;
        function<void(TreeNode *)> inorder = [&](TreeNode *root) {
            if (root == nullptr) return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        };
        inorder(root);
        return *(nums.rbegin() + k - 1);
    }
};

// 倒序中序遍历，将问题转化为找遍历到的正数第K个结点
class Solution2 {
   private:
    int ans, k;

    void reverse_inorder(TreeNode *root) {
        if (root == nullptr) return;
        reverse_inorder(root->right);
        --k;
        if (k == 0) {
            ans = root->val;
            return;
        }
        reverse_inorder(root->left);
    }

   public:
    int kthLargest(TreeNode *root, int _k) {
        k = _k;
        reverse_inorder(root);
        return ans;
    }
};