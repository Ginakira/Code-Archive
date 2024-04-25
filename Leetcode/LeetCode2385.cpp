// LeetCode 2385 感染二叉树需要的总时间

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
    int amountOfTime(TreeNode *root, int start) {
        unordered_map<int, vector<int>> neighbour;
        unordered_set<int> not_infect;
        function<void(TreeNode *)> dfs = [&](TreeNode *root) {
            if (!root) {
                return;
            }
            not_infect.emplace(root->val);
            if (root->left) {
                neighbour[root->val].emplace_back(root->left->val);
                neighbour[root->left->val].emplace_back(root->val);
            }
            if (root->right) {
                neighbour[root->val].emplace_back(root->right->val);
                neighbour[root->right->val].emplace_back(root->val);
            }
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        int time = 0;
        queue<int> q;
        q.emplace(start);
        while (!q.empty()) {
            ++time;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int id = q.front();
                q.pop();
                not_infect.erase(id);
                for (auto nid : neighbour[id]) {
                    if (not_infect.count(nid)) {
                        q.push(nid);
                    }
                }
            }
        }
        return time - 1;
    }
};