// LeetCode 508 出现次数最多的子树元素和

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
    unordered_map<int, int> sums;
    int max_cnt = 0;

    int cal_tree_sum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = root->val;
        sum += cal_tree_sum(root->left);
        sum += cal_tree_sum(root->right);
        ++sums[sum];
        if (sums[sum] > max_cnt) {
            max_cnt = sums[sum];
        }
        return sum;
    }

   public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        cal_tree_sum(root);
        vector<int> res;
        for (auto &[sum, cnt] : sums) {
            if (cnt == max_cnt) {
                res.emplace_back(sum);
            }
        }
        return res;
    }
};