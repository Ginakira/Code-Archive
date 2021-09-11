// LeetCOde 114 二叉树展开为链表

#include <algorithm>
#include <numeric>
#include <stack>
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

// 存储先序遍历结果
class Solution {
   private:
    vector<TreeNode *> nodes;

    void preorder(TreeNode *root) {
        if (root == nullptr) return;
        nodes.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }

   public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        preorder(root);
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        return;
    }
};

// 模拟递归栈 提前记录左右节点
class Solution2 {
   public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *pre = nullptr;
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            if (pre != nullptr) {
                pre->left = nullptr;
                pre->right = node;
            }
            pre = node;
            if (node->right != nullptr) {
                stk.push(node->right);
            }
            if (node->left != nullptr) {
                stk.push(node->left);
            }
        }
    }
};

// 找前驱节点
class Solution3 {
   public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                TreeNode *precursor = cur->left;
                while (precursor->right != nullptr) {
                    precursor = precursor->right;
                }
                precursor->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};