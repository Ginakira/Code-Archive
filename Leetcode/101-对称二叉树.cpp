#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//解法1: 递归
class Solution {
   public:
    bool isMirror(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};

//解法2:迭代 类似于BFS 每次出队两个节点比较 注意入队顺序
class Solution2 {
   public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode *a = q.front();
            q.pop();
            TreeNode *b = q.front();
            q.pop();
            if (!a && !b) continue;
            if (!a || !b) return false;
            if (a->val != b->val) return false;
            q.push(a->left);
            q.push(b->right);
            q.push(a->right);
            q.push(b->left);
        }
        return true;
    }
};