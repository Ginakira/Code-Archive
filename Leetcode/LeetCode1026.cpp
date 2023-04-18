// LeetCode 1026 节点与其祖先之间的最大差值

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
   private:
    int ans;

    void dfs(TreeNode *root, int up, int low) {
        if (!root) {
            return;
        }
        int val = root->val;
        ans = max({ans, abs(val - up), abs(val - low)});
        up = max(up, val);
        low = min(low, val);
        dfs(root->left, up, low);
        dfs(root->right, up, low);
    }

   public:
    int maxAncestorDiff(TreeNode *root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};