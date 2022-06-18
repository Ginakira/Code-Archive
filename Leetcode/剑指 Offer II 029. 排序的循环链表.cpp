// 剑指 Offer II 029. 排序的循环链表

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (head == nullptr) {
            node->next = node;
            return node;
        }
        Node *cur = head, *next = cur->next;
        while (next != head) {
            if (cur->val <= insertVal && next->val >= insertVal) {
                break;
            }
            if (cur->val > next->val) {
                if (insertVal < next->val || insertVal > cur->val) {
                    break;
                }
            }
            cur = cur->next;
            next = next->next;
        }
        node->next = next;
        cur->next = node;
        return head;
    }
};