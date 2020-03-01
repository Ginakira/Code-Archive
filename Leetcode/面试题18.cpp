// 删除链表的节点

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next() {}
};

class Solution {
   public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        dummy->next = head;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return dummy->next;
    }
};