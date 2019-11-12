#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        for(ListNode *i = headA; i != nullptr; i = i->next, ++lena);
        for(ListNode *i = headB; i != nullptr; i = i->next, ++lenb);
        ListNode *shortp, *longp;
        if(lena > lenb) {
            shortp = headB;
            longp = headA;
        } else {
            shortp = headA;
            longp = headB;
        }
        for(int i = 0; i < abs(lena - lenb); ++i, longp = longp->next);
        while(shortp != nullptr && longp != nullptr) {
            if(shortp == longp) return shortp;
            shortp = shortp->next;
            longp = longp->next;
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while(pa != pb) {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};