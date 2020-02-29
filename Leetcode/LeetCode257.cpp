// 二叉树的所有路径
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// DFS
class Solution {
    vector<string> ans;
    string path;

   public:
    vector<string> binaryTreePaths(TreeNode *root) {
        backtrack(root);
        return ans;
    }
    void backtrack(TreeNode *root) {
        if (!root) return;
        int len = path.size();  // 记录原始状态 字符串的长度
        // 在当前字符串后加上符号以及节点标号
        path += (path.empty() ? "" : "->") + to_string(root->val);
        // 如果是叶子节点，则将答案push到最终结果里
        if (!root->left && !root->right) ans.push_back(path);
        // 继续搜索左右子树
        backtrack(root->left), backtrack(root->right);
        // 搜索完成后回溯 删除掉新添加到部分，只保留原始状态的字符串
        path.erase(path.begin() + len, path.end());
        return;
    }
};

// C语言版 大致思路同上
class SolutionC {
   public:
    int getPathCount(struct TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return getPathCount(root->left) + getPathCount(root->right);
    }

    int getResult(struct TreeNode *root, int len, int k, char **ret,
                  char *buff) {
        if (!root) return 0;
        len += sprintf(buff + len, "%d", root->val);
        buff[len] = 0;
        if (!root->left && !root->right) {
            ret[k] = strdup(buff);
            return 1;
        }
        len += sprintf(buff + len, "->");
        int cnt = getResult(root->left, len, k, ret, buff);
        cnt += getResult(root->right, len, k + cnt, ret, buff);
        return cnt;
    }

    char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
        int pathCount = getPathCount(root);
        char **ret = (char **)malloc(sizeof(char *) * pathCount);
        int max_len = 1024;
        char *buff = (char *)malloc(sizeof(char) * max_len);
        getResult(root, 0, 0, ret, buff);
        *returnSize = pathCount;
        return ret;
    }
};