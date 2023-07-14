// LeetCode 979 在二叉树中分配硬币

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

class Solution {
   public:
    int distributeCoins(TreeNode *root) {
        int move = 0;

        function<int(const TreeNode *)> dfs = [&](const TreeNode *root) -> int {
            int move_left = 0, move_right = 0;
            if (root == nullptr) {
                return 0;
            }
            if (root->left) {
                move_left = dfs(root->left);
            }
            if (root->right) {
                move_right = dfs(root->right);
            }
            move += abs(move_left) + abs(move_right);
            return move_left + move_right + root->val - 1;
        };

        dfs(root);
        return move;
    }
};