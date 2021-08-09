// LeetCode 116 填充每个节点的下一个右侧节点指针

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        vector<vector<Node*>> nodes;
        function<void(Node*, int)> level_order = [&](Node* root, int depth) {
            if (root == nullptr) return;

            if (nodes.size() == depth) {
                nodes.emplace_back();
            }
            nodes[depth].push_back(root);
            level_order(root->left, depth + 1);
            level_order(root->right, depth + 1);
        };

        level_order(root, 0);

        for (auto& level_nodes : nodes) {
            int n = level_nodes.size();
            for (int i = 0; i < n; ++i) {
                if (i == n - 1) {
                    level_nodes[i]->next = nullptr;
                } else {
                    level_nodes[i]->next = level_nodes[i + 1];
                }
            }
        }
        return root;
    }
};