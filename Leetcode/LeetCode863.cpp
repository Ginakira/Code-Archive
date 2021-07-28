// LeetCode 863 二叉树中所有距离为K的结点

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

class Solution {
   private:
    unordered_map<int, TreeNode *> parents;
    vector<int> ans;

    void find_parents(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            parents[root->left->val] = root;
            find_parents(root->left);
        }
        if (root->right != nullptr) {
            parents[root->right->val] = root;
            find_parents(root->right);
        }
    }

    void find_ans(TreeNode *root, TreeNode *from, int depth, int k) {
        if (root == nullptr) return;
        if (depth == k) {
            ans.push_back(root->val);
            return;
        }

        if (root->left != from) {
            find_ans(root->left, root, depth + 1, k);
        }
        if (root->right != from) {
            find_ans(root->right, root, depth + 1, k);
        }
        if (parents[root->val] != from) {
            find_ans(parents[root->val], root, depth + 1, k);
        }
    }

   public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        // 从根节点出发 记录每个结点的父节点
        find_parents(root);

        // 以target作为根节点 进行dfs 除了向下搜索还可以向上搜索父节点
        find_ans(target, nullptr, 0, k);
        return ans;
    }
};