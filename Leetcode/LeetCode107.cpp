// 二叉树层次遍历II
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
        q.push(root);
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//同102题 DFS递归求得正向结果后翻转
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

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        dfs(root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 同解法2 C语言版
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
        getCount(root->left, k - 1, cnt);
        getCount(root->right, k - 1, cnt);
        return;
    }

    void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {
        if (!root) return;
        ret[k][cnt[k]++] = root->val;
        getResult(root->left, k - 1, cnt, ret);
        getResult(root->right, k - 1, cnt, ret);
        return;
    }

    int **levelOrderBottom(struct TreeNode *root, int *returnSize,
                           int **returnColumnSizes) {
        int n = getDepth(root);
        int **ret = (int **)malloc(sizeof(int *) * n);
        int *cnt = (int *)calloc(n, sizeof(int));
        getCount(root, n - 1, cnt);
        for (int i = 0; i < n; ++i) {
            ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
            cnt[i] = 0;
        }
        getResult(root, n - 1, cnt, ret);
        *returnSize = n, *returnColumnSizes = cnt;
        return ret;
    }
};