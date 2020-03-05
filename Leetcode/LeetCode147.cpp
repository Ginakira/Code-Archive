// 对链表进行插入排序
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 分为已排序部分与未排序部分 每次走到对应位置进行插入
class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode *ret = new ListNode(-1), *unsorted = head->next, *p, *q;
        ret->next = head, head->next = NULL;
        while (unsorted) {
            q = unsorted->next;
            p = ret;
            while (p->next && unsorted->val > p->next->val) p = p->next;
            unsorted->next = p->next;
            p->next = unsorted;
            unsorted = q;
        }
        return ret->next;
    }
};