// LeetCode 429 N叉树的层序遍历

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<vector<int>> levelOrder(Node *root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            size_t count = q.size();
            vector<int> current;
            for (size_t i = 0; i < count; ++i) {
                Node *node = q.front();
                current.push_back(node->val);
                for (auto &child : node->children) {
                    q.push(child);
                }
                q.pop();
            }
            result.emplace_back(move(current));
        }
        return result;
    }
};