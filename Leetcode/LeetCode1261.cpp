// LeetCode 1261 在受污染的二叉树中查找元素

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
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

class FindElements {
   private:
    TreeNode *root_;

    bool find(TreeNode *root, int target) {
        if (!root) {
            return false;
        }
        if (root->val == target) {
            return true;
        }
        if (root->left) {
            root->left->val = root->val * 2 + 1;
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
        }
        return find(root->left, target) || find(root->right, target);
    }

   public:
    FindElements(TreeNode *root) {
        root->val = 0;
        root_ = root;
    }

    bool find(int target) { return find(root_, target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */