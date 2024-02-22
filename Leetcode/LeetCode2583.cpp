// LeetCode 2583 二叉树中的第K大层和

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
    long long kthLargestLevelSum(TreeNode *root, int k) {
        using LL = long long;
        if (!root) {
            return -1;
        }
        queue<TreeNode *> q;
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        q.emplace(root);
        while (!q.empty()) {
            int n = q.size();
            LL sum = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
            pq.push(sum);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.size() < k ? -1 : pq.top();
    }
};


class Solution2 {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        using LL = long long;
        if (!root) {
            return -1;
        }
        queue<TreeNode *> q;
        vector<LL> sums;
        q.emplace(root);
        while (!q.empty()) {
            int n = q.size();
            LL sum = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
            sums.push_back(sum);
        }
        int n = sums.size();
        if (n < k) {
            return -1;
        }
        std::nth_element(sums.begin(), sums.begin() + n - k, sums.end());
        return sums[n - k];
    }
};