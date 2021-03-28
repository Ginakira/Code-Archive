// LeetCode 138 复制带随机指针的链表
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
   public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node *, Node *> old_to_new;
        Node *p = head;
        while (p != nullptr) {
            Node *new_node = new Node(p->val);
            old_to_new[p] = new_node;
            p = p->next;
        }
        p = head;
        while (p != nullptr) {
            Node *node = old_to_new[p];
            node->next = old_to_new[p->next];
            if (p->random != nullptr) {
                node->random = old_to_new[p->random];
            }
            p = p->next;
        }
        return old_to_new[head];
    }
};