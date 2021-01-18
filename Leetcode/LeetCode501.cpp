// LeetCode 501 二叉搜索树中的众数
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历 24ms
// 因为是BST，所以中序遍历的结果一定是非递减序列，众数一定相邻
// 所以我们按照中序的顺序遍历，同时更新计数和答案数组
// base存储当前正在计数的数字 count为出现次数 maxCount为最大出现次数
// 如果当前数与base相等，则计数器加一，同时与maxCount作比较
// 如果其当前的出现次数与maxCount相等，则将该数push进答案数组
// 如果大于maxCount，则更新maxCount，同时将答案数组清空，将这个数加入进去
// 如果遇到一个与base不相等的数字，则计数清零，base改变为这个数字
class Solution {
   private:
    vector<int> ans;
    int base, count, maxCount;

   public:
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        update(root->val);
        dfs(root->right);
        return;
    }

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            base = x;
            count = 1;
        }
        if (count == maxCount) {
            ans.emplace_back(x);
        } else if (count > maxCount) {
            maxCount = count;
            ans = vector<int>{base};
        }
        return;
    }
};