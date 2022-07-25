// LeetCode 919 完全二叉树插入器

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class CBTInserter {
   private:
    queue<TreeNode *> insertable_nodes_;
    TreeNode *root_;

   public:
    CBTInserter(TreeNode *root) : root_(root) {
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left) {
                q.emplace(node->left);
            }
            if (node->right) {
                q.emplace(node->right);
            }
            if (!(node->left && node->right)) {
                insertable_nodes_.emplace(node);
            }
        }
    }

    int insert(int val) {
        TreeNode *node = new TreeNode(val);
        TreeNode *fa = insertable_nodes_.front();
        if (!fa->left) {
            fa->left = node;
        } else {
            fa->right = node;
            insertable_nodes_.pop();
        }
        insertable_nodes_.emplace(node);
        return fa->val;
    }

    TreeNode *get_root() { return root_; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */