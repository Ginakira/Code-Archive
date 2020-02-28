// 二叉树的序列化与反序列化
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    // BFS 使用队列进行序列化
    string serialize(TreeNode *root) {
        string ans = "[";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL) {
                ans += "null,";
                continue;
            }
            ans += to_string(temp->val) + ",";
            q.push(temp->left), q.push(temp->right);
        }
        ans[ans.size() - 1] = ']';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        queue<TreeNode *> q;
        // 去掉“[]”号
        string data_tmp = data.substr(1, data.size() - 2);
        // 将“,“换为空格 方便stringstream分割
        for (auto &i : data_tmp) {
            if (i == ',') i = ' ';
        }
        stringstream ss(data_tmp);
        string str;
        ss >> str;
        // 如果根节点就是null 则是空树
        if (str == "null") return NULL;
        // 否则将节点数值转为int 构造新结点作为根节点
        TreeNode *root = new TreeNode(stoi(str));
        // 根节点入队
        q.push(root);
        // 根据层次遍历的性质 一个节点后跟着的两个节点分别是其左子树和右子树
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            // 获取其后面的第一个节点 如果是空 则指空且没有左子树 非空则构造
            // 并进入队列等待构造其子树
            ss >> str;
            if (str == "null") {
                temp->left = NULL;
            } else {
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            // 获取第二个节点 右子树 同上
            ss >> str;
            if (str == "null") {
                temp->right = NULL;
            } else {
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
    }
};