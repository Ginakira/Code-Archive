// LeetCode 590 N叉树的后序遍历

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
    vector<int> postorder(Node *root) {
        vector<int> result;
        function<void(Node *)> postorder_helper = [&](Node *root) {
            if (root == nullptr) return;
            for (auto &child : root->children) {
                postorder_helper(child);
            }
            result.push_back(root->val);
        };

        postorder_helper(root);
        return result;
    }
};

// 迭代
class Solution2 {
   public:
    vector<int> postorder(Node *root) {
        if (root == nullptr) return {};
        vector<int> result;
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node *node = stk.top();
            stk.pop();
            result.push_back(node->val);
            for (auto &child : node->children) {
                stk.push(child);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};