// 反转链表

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next() {}
};

// 虚拟头结点 + 头插法
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *p = head, *q;
        while (p) {
            q = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = q;
        }
        return dummy->next;
    }
};