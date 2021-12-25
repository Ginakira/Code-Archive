// LeetCode 1609 奇偶树

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
   private:
    unordered_map<int, int> layer_last_value;
    bool valid = true;

    void helper(TreeNode *root, int depth) {
        if (root == nullptr) return;
        if (!valid) return;

        if (depth % 2 == root->val % 2) {
            valid = false;
            return;
        }

        if (layer_last_value.count(depth)) {
            int last_value = layer_last_value[depth];
            if ((depth % 2 == 0 && root->val <= last_value) ||
                (depth % 2 == 1 && root->val >= last_value)) {
                valid = false;
                return;
            }
        }
        layer_last_value[depth] = root->val;
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
    }

   public:
    bool isEvenOddTree(TreeNode *root) {
        helper(root, 0);
        return valid;
    }
};