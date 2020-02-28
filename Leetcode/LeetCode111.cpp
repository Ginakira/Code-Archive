// 二叉树的最小深度
#include <iostream>
#include <queue>
#define unlikely(x) __builtin_expect(!!(x), 0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (unlikely(!root)) return 0;
        if (!root->left && root->right) return 1 + minDepth(root->right);
        if (root->left && !root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

//解法2： BFS
//使用队列按层次遍历，每次入队深度加一，遇到第一个叶子节点则为最近的叶子节点，输出其深度即可
class Solution2 {
   public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int min_dep = 0x3f3f3f3f;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            pair<TreeNode *, int> temp;
            temp = q.front();
            q.pop();
            if (temp.first->left == NULL && temp.first->right == NULL) {
                min_dep = temp.second;
                break;
            }
            if (temp.first->left != NULL) {
                q.push(make_pair(temp.first->left, temp.second + 1));
            }
            if (temp.first->right != NULL) {
                q.push(make_pair(temp.first->right, temp.second + 1));
            }
        }
        return min_dep;
    }
};