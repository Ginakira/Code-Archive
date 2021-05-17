// LeetCOde 993 二叉树的堂兄弟节点
#include <queue>
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

// BFS
class Solution {
   private:
    int x;
    TreeNode *x_father = nullptr;
    int x_depth;
    bool x_found = false;

    int y;
    TreeNode *y_father = nullptr;
    int y_depth;
    bool y_found = false;

    void update(int val, TreeNode *father, int depth) {
        if (val == x) {
            tie(x_father, x_depth, x_found) = tuple{father, depth, true};
        }
        if (val == y) {
            tie(y_father, y_depth, y_found) = tuple{father, depth, true};
        }
        return;
    }

   public:
    bool isCousins(TreeNode *root, int x, int y) {
        this->x = x;
        this->y = y;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        update(root->val, nullptr, 0);
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            if (node->left != nullptr) {
                q.push({node->left, depth + 1});
                update(node->left->val, node, depth + 1);
            }
            if (node->right != nullptr) {
                q.push({node->right, depth + 1});
                update(node->right->val, node, depth + 1);
            }
            if (x_found && y_found) {
                break;
            }
        }
        return x_depth == y_depth && x_father != y_father;
    }
};

// DFS
class Solution2 {
   private:
    int x;
    TreeNode *x_father = nullptr;
    int x_depth;
    bool x_found;

    int y;
    TreeNode *y_father = nullptr;
    int y_depth;
    bool y_found;

    void update(int val, TreeNode *father, int depth) {
        if (val == x) {
            tie(x_father, x_depth, x_found) = tuple{father, depth, true};
        }
        if (val == y) {
            tie(y_father, y_depth, y_found) = tuple{father, depth, true};
        }
    }

    void dfs(TreeNode *root, int depth) {
        if (root == nullptr) return;
        if (x_found && y_found) {
            return;
        }
        if (root->left != nullptr) {
            update(root->left->val, root, depth + 1);
            dfs(root->left, depth + 1);
        }
        if (root->right != nullptr) {
            update(root->right->val, root, depth + 1);
            dfs(root->right, depth + 1);
        }
        return;
    }

   public:
    bool isCousins(TreeNode *root, int x, int y) {
        this->x = x;
        this->y = y;
        update(root->val, nullptr, 0);
        dfs(root, 0);
        return x_depth == y_depth && x_father != y_father;
    }
};