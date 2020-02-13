struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next() {}
};

class Solution {
   public:
    void deleteNode(ListNode *node) {
        ListNode *p = node, *pre;
        while (p->next) {
            p->val = p->next->val;
            pre = p;
            p = p->next;
        }
        delete pre->next;
        pre->next = nullptr;
        return;
    }
};