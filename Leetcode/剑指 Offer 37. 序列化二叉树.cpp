// 剑指 Offer 37. 序列化二叉树

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 原理同LC297
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string result = "[";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr) {
                result += "null,";
            } else {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        result[result.size() - 1] = ']';
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        // 去掉中括号
        string data_tmp = data.substr(1, data.size() - 2);

        queue<TreeNode *> q;
        stringstream ss(data_tmp);
        string str;

        // 判断根节点
        getline(ss, str, ',');
        if (str == "null") {
            return NULL;
        }
        TreeNode *root = new TreeNode(atoi(str.c_str()));
        q.emplace(root);

        auto get_node = [&](TreeNode *&target) {
            string temp;
            TreeNode *temp_node = NULL;
            getline(ss, temp, ',');
            if (temp != "null") {
                temp_node = new TreeNode(atoi(temp.c_str()));
                target = temp_node;
                q.push(temp_node);
            }
        };

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            get_node(node->left);
            get_node(node->right);
        }

        return root;
    }
};