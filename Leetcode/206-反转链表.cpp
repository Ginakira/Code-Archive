struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *vnode = new ListNode(-1);
        vnode->next = nullptr;
        ListNode *p = head, *q;
        while(p) {
            q = p->next;
            p->next = vnode->next;
            vnode->next = p;
            p = q;
        }
        return vnode->next;
    }
};