// LeetCode 559 N叉树的最大深度
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
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        if (root->children.size() == 0) return 1;

        int max_depth = 0;
        for (auto& child : root->children) {
            max_depth = max(max_depth, maxDepth(child));
        }
        return max_depth + 1;
    }
};