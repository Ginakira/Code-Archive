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