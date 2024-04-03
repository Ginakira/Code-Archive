// LeetCode 1379 找出克隆二叉树中的相同节点

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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        if (!original) {
            return nullptr;
        }
        if (original == target) {
            return cloned;
        }
        auto left = getTargetCopy(original->left, cloned->left, target);
        if (left) {
            return left;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};