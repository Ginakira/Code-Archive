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
        unordered_map<Node *, Node *> mp;
        Node *p = head;
        while (p != nullptr) {
            mp[p] = new Node(p->val);
            p = p->next;
        }
        for (auto &[old_node, new_node] : mp) {
            if (old_node->next != nullptr) {
                new_node->next = mp[old_node->next];
            }
            if (old_node->random != nullptr) {
                new_node->random = mp[old_node->random];
            }
        }

        return mp[head];
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