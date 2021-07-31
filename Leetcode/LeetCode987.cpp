// LeetCode 987 二叉树的垂序遍历

#include <algorithm>
#include <map>
#include <numeric>
#include <set>
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
   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        map<int, map<int, multiset<int>>> mp;

        function<void(TreeNode *, int, int)> order = [&](TreeNode *root,
                                                         int row, int col) {
            if (root == nullptr) return;
            mp[col][row].insert(root->val);
            order(root->left, row + 1, col - 1);
            order(root->right, row + 1, col + 1);
        };

        order(root, 0, 0);

        vector<vector<int>> result;
        for (auto &[_, item] : mp) {
            vector<int> vec;
            for (auto &[_, ms] : item) {
                vector<int> temp(ms.begin(), ms.end());
                for (auto &val : temp) {
                    vec.push_back(val);
                }
            }
            result.emplace_back(move(vec));
        }
        return result;
    }
};