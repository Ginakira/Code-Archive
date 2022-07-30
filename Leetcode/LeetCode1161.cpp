// LeetCode 1161 最大层内元素和

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
    vector<int> sum;

    void helper(TreeNode *root, int depth) {
        if (!root) return;
        if (sum.size() <= depth) {
            sum.emplace_back(root->val);
        } else {
            sum[depth] += root->val;
        }
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
    }

   public:
    int maxLevelSum(TreeNode *root) {
        helper(root, 0);
        return max_element(sum.begin(), sum.end()) - sum.begin() + 1;
    }
};