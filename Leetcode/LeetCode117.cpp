// LeetCode 117 填充每个节点的下一个右侧节点指针II

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   private:
    void helper(Node *&last, Node *cur, Node *&next_start) {
        if (last) {
            last->next = cur;
        }
        if (!next_start) {
            next_start = cur;
        }
        last = cur;
    }

   public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }
        Node *start = root;
        while (start) {
            Node *last = nullptr, *next_start = nullptr;
            for (auto p = start; p; p = p->next) {
                if (p->left) {
                    helper(last, p->left, next_start);
                }
                if (p->right) {
                    helper(last, p->right, next_start);
                }
            }
            start = next_start;
        }
        return root;
    }
};
