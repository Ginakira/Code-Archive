// LeetCode 449 序列化和反序列化二叉搜索树
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 先序遍历序列化 使用#标记空节点
class Codec {
   public:
    void build(TreeNode *root, stringstream &ss) {
        if (root == nullptr) {
            ss << "# ";
            return;
        }
        ss << root->val << " ";
        build(root->left, ss);
        build(root->right, ss);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        stringstream ss;
        build(root, ss);
        return ss.str();
    }

    void rebuild(TreeNode *&root, stringstream &ss) {
        if (!ss) return;
        string val;
        ss >> val;
        if (val == "#") {
            root = nullptr;
            return;
        }
        root = new TreeNode(stoi(val));
        rebuild(root->left, ss);
        rebuild(root->right, ss);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        TreeNode *root = nullptr;
        rebuild(root, ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;