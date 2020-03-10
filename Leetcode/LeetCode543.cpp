// 每日一题 二叉树的直径
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 使用队列BFS遍历节点 判断左右子树高度加和 得到最大值 即为直径 28ms
class Solution {
   private:
    queue<TreeNode *> q;

   public:
    int get_height(TreeNode *root) {
        if (!root) return 0;
        int left = get_height(root->left);
        int right = get_height(root->right);
        return (left > right ? left : right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        int ans = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            ans = max(ans, get_height(p->left) + get_height(p->right));
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        return ans;
    }
};

// DFS 计算高度的同时 同时计算左右子树节点加和即为当前节点两边最长路径和
class Solution2 {
   private:
    int ans = 0;

   public:
    int get_depth(TreeNode *root) {
        if (!root) return 0;
        int left = get_depth(root->left);
        int right = get_depth(root->right);
        ans = max(ans, left + right);
        return (left > right ? left : right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        get_depth(root);
        return ans;
    }
};