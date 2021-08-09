// LeetCode 98 验证二叉搜索树
#include <climits>
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

// Solution1：中序遍历存至数组，验证数组有序性
// 24ms 21.9MB
class Solution {
   public:
    void inorder(TreeNode *root, vector<int> &vec) {
        if (root == nullptr) return;
        inorder(root->left, vec);
        vec.emplace_back(root->val);
        inorder(root->right, vec);
        return;
    }
    bool isValidBST(TreeNode *root) {
        vector<int> vec;
        inorder(root, vec);
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};

// Solution2: 递归，规定该棵树节点值的上下界
// 12ms 21.2MB
class Solution2 {
   public:
    bool helper(TreeNode *root, long lower, long upper) {
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return helper(root->left, lower, root->val) &&
               helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root) { return helper(root, LONG_MIN, LONG_MAX); }
};

// Solution3: 判断前驱节点和后继结点
class Solution3 {
   public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;
        if (!isValidBST(root->left) || !isValidBST(root->right)) {
            return false;
        }

        if (root->left) {
            TreeNode *pre = root->left;
            while (pre->right != nullptr) pre = pre->right;
            if (pre->val >= root->val) return false;
        }

        if (root->right) {
            TreeNode *next = root->right;
            while (next->left != nullptr) next = next->left;
            if (next->val <= root->val) return false;
        }

        return true;
    }
};