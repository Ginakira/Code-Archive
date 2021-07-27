// LeetCode 671 二叉树中第二小的节点

#include <algorithm>
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

// 暴力 set
class Solution {
   public:
    int findSecondMinimumValue(TreeNode *root) {
        set<int> st;

        function<void(TreeNode *)> order = [&](TreeNode *root) {
            if (root == nullptr) return;
            st.insert(root->val);
            order(root->left);
            order(root->right);
        };

        order(root);
        return st.size() <= 1 ? -1 : *(++st.begin());
    }
};

// 根据树的性质：
// 如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
// 所以根节点是整棵树最小的的值，那么只需要在遍历中找到第一个严格大于它的值即可
class Solution2 {
   public:
    int findSecondMinimumValue(TreeNode *root) {
        int ans = -1, root_val = root->val;

        function<void(TreeNode *)> order = [&](TreeNode *root) {
            if (root == nullptr) return;

            if (ans != -1 && root->val >= ans) {
                return;
            }

            if (root->val > root_val) {
                ans = root->val;
            }
            order(root->left);
            order(root->right);
        };

        order(root);
        return ans;
    }
};