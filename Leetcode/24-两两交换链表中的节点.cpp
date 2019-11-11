struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        int length = 0;
        ListNode *p = head;
        while(p) {
            length++;
            p = p->next;
        }
        p = head;
        ListNode *q = p->next, *k;
        for(int i = 0; i < length / 2; ++i) {
            p->next = q->next;
            q->next = p;
            if(i == 0) head = q;
            else k->next = q;
            k = p;
            p = p->next;
            if(p) q = p->next;
        }
        return head;
    }
};