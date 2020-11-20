// 对链表进行插入排序
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 分为已排序部分与未排序部分 每次遍历走到对应位置进行插入 48ms
class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode *ret = new ListNode(-0x3f3f3f3f), *unsorted = head->next, *p,
                 *q;
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

// 记录上一次插入的位置 如果下次插入比这个位置大 则从这个位置向后搜索
// 否则从头搜索 大幅节省时间 16ms
class Solution2 {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode *ret = new ListNode(-0x3f3f3f3f), *unsorted = head->next, *p,
                 *q, *pre;
        ret->next = head, head->next = NULL, pre = ret;
        while (unsorted) {
            q = unsorted->next;
            p = unsorted->val >= pre->val ? pre : ret;
            while (p->next && unsorted->val > p->next->val) p = p->next;
            unsorted->next = p->next;
            p->next = unsorted;
            unsorted = q, pre = p;
        }
        return ret->next;
    }
};