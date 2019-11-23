#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int dfs(TreeNode *root, int cnt) {
        if (!root) return 0;
        int left = 0, right = 0;
        if (root->left) left = dfs(root->left, cnt + 1);
        if (root->right) right = dfs(root->right, cnt + 1);
        return max(max(left, right), cnt);
    }
    int maxDepth(TreeNode *root) {
        int cnt = 1;
        cnt = dfs(root, cnt);
        return cnt;
    }
};