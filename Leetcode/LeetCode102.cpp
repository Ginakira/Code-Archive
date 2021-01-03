// 二叉树的层次遍历
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q, tmp;
        if (root) q.push(root);
        while (!q.empty()) {
            vector<int> v;
            while (!q.empty()) {
                v.push_back(q.front()->val);
                if (q.front()->left) tmp.push(q.front()->left);
                if (q.front()->right) tmp.push(q.front()->right);
                q.pop();
            }
            ans.push_back(v);
            v.clear();
            while (!tmp.empty()) {
                q.push(tmp.front());
                tmp.pop();
            }
        }
        return ans;
    }
};

//解法2: DFS 根据层数存储 emplace_back()为直接构造并push
class Solution2 {
   public:
    vector<vector<int>> ans;
    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (depth == ans.size()) ans.emplace_back();
        ans[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }
};

// 思路同解法2 C语言版
class Solution2C {
   public:
    int getDepth(struct TreeNode *root) {
        if (!root) return 0;
        int l = getDepth(root->left), r = getDepth(root->right);
        return (l > r ? l : r) + 1;
    }

    void getCount(struct TreeNode *root, int k, int *cnt) {
        if (!root) return;
        cnt[k]++;
        getCount(root->left, k + 1, cnt);
        getCount(root->right, k + 1, cnt);
        return;
    }

    void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {
        if (!root) return;
        ret[k][cnt[k]++] = root->val;
        getResult(root->left, k + 1, cnt, ret);
        getResult(root->right, k + 1, cnt, ret);
        return;
    }

    int **levelOrder(struct TreeNode *root, int *returnSize,
                     int **returnColumnSizes) {
        int depth = getDepth(root);
        int **ret = (int **)malloc(sizeof(int *) * depth);
        int *cnt = (int *)calloc(depth, sizeof(int));
        getCount(root, 0, cnt);
        for (int i = 0; i < depth; ++i) {
            ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
            cnt[i] = 0;
        }
        getResult(root, 0, cnt, ret);
        *returnSize = depth;
        *returnColumnSizes = cnt;
        return ret;
    }
};