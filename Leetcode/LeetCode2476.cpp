// LeetCode 2476 二叉搜索树最近节点查询

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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
   public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> nums;
        function<void(TreeNode*)> inorder = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            inorder(root->left);
            nums.emplace_back(root->val);
            inorder(root->right);
        };
        inorder(root);

        ans.reserve(queries.size());
        for (auto& query : queries) {
            auto it = lower_bound(nums.begin(), nums.end(), query);
            int min_val = -1, max_val = -1;
            if (it != nums.begin()) {
                min_val = *(it - 1);
            }
            if (it != nums.end()) {
                max_val = *it;
                if (*it == query) {
                    min_val = *it;
                    ans.push_back({min_val, max_val});
                    continue;
                }
            }
            ans.push_back({min_val, max_val});
        }

        return ans;
    }
};