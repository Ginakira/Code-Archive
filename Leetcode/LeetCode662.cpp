// LeetCode 662 二叉树最大宽度

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
   public:
    int widthOfBinaryTree(TreeNode *root) {
        using TNI = tuple<TreeNode *, unsigned long long>;
        vector<TNI> arr;
        unsigned long long res = 0;
        arr.emplace_back(root, 1);
        while (!arr.empty()) {
            vector<TNI> tmp;
            for (auto &[node, id] : arr) {
                if (node->left) {
                    tmp.emplace_back(node->left, id * 2);
                }
                if (node->right) {
                    tmp.emplace_back(node->right, id * 2 + 1);
                }
            }
            res = max(res, get<1>(arr.back()) - get<1>(arr[0]) + 1);
            arr = move(tmp);
        }
        return res;
    }
};