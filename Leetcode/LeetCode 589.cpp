// LeetCode 589 N叉树的前序遍历

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

// 递归
class Solution {
   public:
    vector<int> preorder(Node *root) {
        vector<int> result;

        function<void(Node *, vector<int> &)> preorder_helper =
            [&](Node *root, vector<int> &vec) {
                if (root == nullptr) return;
                vec.push_back(root->val);
                for (auto &child : root->children) {
                    preorder_helper(child, vec);
                }
            };

        preorder_helper(root, result);
        return result;
    }
};

// 迭代
class Solution2 {
   public:
    vector<int> preorder(Node *root) {
        if (root == nullptr) return {};

        vector<int> result;
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node *node = stk.top();
            stk.pop();
            result.push_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend();
                 ++it) {
                stk.push(*it);
            }
        }
        return result;
    }
};