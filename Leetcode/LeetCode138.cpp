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

// 哈希表
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

// 直接在原节点后面复制，复制完成后改写指向关系
class Solution2 {
   public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        Node *p = head;
        while (p != nullptr) {
            Node *new_node = new Node(p->val);
            new_node->next = p->next;
            p->next = new_node;
            p = new_node->next;
        }
        p = head;
        while (p != nullptr) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = head;
        Node *ret = p->next;
        while (p != nullptr) {
            Node *node = p->next, *q = node->next;
            if (q != nullptr) {
                node->next = q->next;
            }
            p->next = q;
            p = q;
        }
        return ret;
    }
};