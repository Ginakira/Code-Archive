// LeetCode 894 所有可能的真二叉树

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
    vector<TreeNode *> allPossibleFBT(int n) {
        if (!(n & 1)) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode *> trees;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode *> left_trees = allPossibleFBT(i);
            vector<TreeNode *> right_trees = allPossibleFBT(n - i - 1);
            for (auto left : left_trees) {
                for (auto right : right_trees) {
                    TreeNode *root = new TreeNode(0, left, right);
                    trees.emplace_back(root);
                }
            }
        }
        return trees;
    }
};