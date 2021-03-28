// LeetCode 173 二叉搜索树迭代器
#include <stack>
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

// 扁平化
class BSTIterator {
   private:
    void in_order(TreeNode *root) {
        if (root == nullptr) return;
        in_order(root->left);
        data.emplace_back(root->val);
        in_order(root->right);
    }

    vector<int> data;
    int iter;
    int n;

   public:
    BSTIterator(TreeNode *root) {
        in_order(root);
        iter = 0;
        n = data.size();
    }

    int next() { return data[iter++]; }

    bool hasNext() { return iter < n; }
};

// 迭代先序遍历
class BSTIterator2 {
   private:
    TreeNode *cur;
    stack<TreeNode *> stk;

   public:
    BSTIterator2(TreeNode *root) : cur(root) {}

    int next() {
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        int ret = cur->val;
        cur = cur->right;
        return ret;
    }

    bool hasNext() { return cur != nullptr || !stk.empty(); }
};