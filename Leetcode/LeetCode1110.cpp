// LeetCode 1110 删点成林

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        function<TreeNode*(TreeNode*, bool)> dfs =
            [&to_delete_set, &ans, &dfs](TreeNode* root,
                                         int maybe_new_root) -> TreeNode* {
            if (!root) {
                return nullptr;
            }
            bool to_be_deleted = to_delete_set.count(root->val) ? true : false;
            root->left = dfs(root->left, to_be_deleted);
            root->right = dfs(root->right, to_be_deleted);
            if (to_be_deleted) {
                return nullptr;
            }
            if (maybe_new_root) {
                ans.emplace_back(root);
            }
            return root;
        };

        dfs(root, true);
        return ans;
    }
};